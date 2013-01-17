(use xlib)

(define-record Rule
			   class instance title tags isfloating monitor)

(define-record Layout
			   symbol arrange-function)

(define tile (lambda () #f))
(define monocle (lambda () #f))

(define *config* "config.scm")
(when (file-exists? *config*)
  (load *config*))



(let ((display (xopendisplay #f)))
  (assert display)
  (let* ((screen (xdefaultscreen display))
		 (root (xrootwindow display screen))
		 (window (xcreatesimplewindow
				   display root 100 200 300 50 0
				   (xblackpixel display screen)
				   (xwhitepixel display screen))))
	(assert window)
	(let ((font (xloadfont display "10x20")))
	  (assert font)
	  (let ((gc (xcreategc display window 0 #f))
			(event (make-xevent)))
		(xsetforeground display gc (xblackpixel display screen))
		(xsetbackground display gc (xwhitepixel display screen))
		(xsetfunction display gc GXCOPY)
		(xsetfont display gc font)
		(xselectinput display window
					  (bitwise-ior EXPOSUREMASK BUTTONPRESSMASK KEYPRESSMASK))
		(xmapwindow display window)
		(xnextevent display event)
		(xdrawstring display window gc 100 30 *disp-string* (string-length *disp-string*))
		(xflush display)
		(xnextevent display event)))))
