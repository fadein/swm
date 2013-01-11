 ;;; Shows a window and terminates after a button-press 
;   (or after the second exposure event)

(require-extension xlib)

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
		(xselectinput display window (bitwise-ior EXPOSUREMASK BUTTONPRESSMASK))
		(xmapwindow display window)
		(xnextevent display event)
		(xdrawstring display window gc 100 30 "Hello World!" 12)
		(xflush display)
		(xnextevent display event)))))
