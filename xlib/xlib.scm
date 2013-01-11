;;;; xlib.scm


(declare
  (no-bound-checks)
  (no-procedure-checks)
  (disable-interrupts) )


#>
#include "xlib-c.c"

#define C_free_xptr(p)          (XFree((void *)C_block_item(p, 0)), C_SCHEME_UNDEFINED)
#define C_fetch_c_strlen(b)     C_fix(strlen((char *)C_block_item(b, 0)))
#define C_peek_c_string(b, to, len) (C_memcpy(C_data_pointer(to), (char *)C_block_item(b, 0), C_unfix(len)), C_SCHEME_UNDEFINED)
<#


(module xlib ()
  (import scheme chicken foreign srfi-13 data-structures)
  (begin-for-syntax (require-library matchable))
  (import-for-syntax matchable chicken)

(define-for-syntax (xlate-type t cn)
  (match (strip-syntax t)		; punt
    [('POINTER 'FUNCTION) (xlate-warn t 'c-pointer cn)]
    [('POINTER (or 'STRUCT 'UNION 'VOID)) 'c-pointer]
    [('POINTER (? string? s)) `(c-pointer ,s)]
    [('POINTER t) `(c-pointer ,(xlate-type t cn))]
    ['POINTER 'c-pointer]
    [(or 'CHAR 'SIGNED-CHAR) 'char]
    [(or 'UNSIGNED-CHAR 'UNSIGNED-SHORT 'UNSIGNED-LONG 'FLOAT 'DOUBLE)
     (string->symbol (string-downcase (->string t))) ]
    [(or 'SHORT 'SIGNED-SHORT) 'short]
    [(or 'LONG 'SIGNED-LONG) 'long]
    [(or 'UNSIGNED-INT 'UNSIGNED) 'unsigned-integer]
    ['INT 'integer] 
    [_ (syntax-error "type not supported" t cn)] ) )

(define-for-syntax (xlate-warn t t2 cn)
  (cond-expand
   [pickytypes (fprintf (current-error-port) "Warning: ~s type in ~s.~%" t cn)]
   [else] )
  t2)

(define-for-syntax (xlate-rtype t cn)
  (match t
    ['VOID 'void]
    [(or 'xstring* 'c-string) t]
    ['STRING (xlate-warn t 'c-string cn)]
    [_ (xlate-type t cn)] ) )

(define-for-syntax (xlate-atype t cn)
  (match t
    [(or 'c-string 'STRING) 'c-string]
    [_ (xlate-type t cn)] ) )

(define peek-and-free-c-string
  (lambda (b)
    (and (not (##sys#null-pointer? b))
	 (let* ([len (##core#inline "C_fetch_c_strlen" b)]
		[str2 (##sys#make-string len)] )
	   (##core#inline "C_peek_c_string" b str2 len)
	   (##core#inline "C_free_xptr" b)
	   str2) ) ) )

(define-foreign-type xstring* c-pointer
  #f
  peek-and-free-c-string)

(eval-when (compile)
  (print "Compiling xlib (this may take a while) ..."))

(define-syntax (foreign-function x r c)
  (match (cdr x)
    ((name args result cname)
     `(,(r 'begin)
       (,(r 'export) ,name)
       (,(r 'define) ,name
	(,(r 'foreign-lambda)
	 ,(xlate-rtype result cname)
	 ,cname
	 ,@(map (cut xlate-atype <> cname) args)) ) ))))

(define-syntax (foreign-cb-function x r c)
  (match (cdr x)
    ((name args result cname)
     `(,(r 'begin)
       (,(r 'export) ,name)
       (,(r 'define) ,name
	(,(r 'foreign-safe-lambda)
	 ,(xlate-rtype result cname)
	 ,cname 
	 ,@(map (cut xlate-atype <> cname) args)) ) ) ) ))

(define-syntax foreign-define
  (syntax-rules ()
    ((_ name val) 
     (begin
       (export name)
       (define name val)))))

(include "xlib-original.scm")

)
