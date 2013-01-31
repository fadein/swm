#include <X11/Xlib.h>
#include <assert.h>

#define BUTTONMASK  ButtonPressMask | ButtonReleaseMask | ExposureMask


int main(void) {
	Display *display;
	Window root, window;
	int screen;
	Font font;
	GC gc;
	XEvent event;

	display = XOpenDisplay(NULL);
	assert(NULL != display);

	screen = DefaultScreen(display);
	root = RootWindow(display, screen);

	window = XCreateSimpleWindow(display, root, 100, 200, 300, 50, 0,
			BlackPixel(display, screen),
			WhitePixel(display, screen));
	assert(0 != window);

	font = XLoadFont(display, "10x20");
	assert(font);

	gc = XCreateGC(display, window, 0, NULL);
	XSetForeground(display, gc, BlackPixel(display, screen));
	XSetBackground(display, gc, WhitePixel(display, screen));
	XSetFunction(display, gc, GXcopy);
	XSetFont(display, gc, font);
	XSelectInput(display, window, BUTTONMASK);
	XMapWindow(display, window);
	XNextEvent(display, &event);
	XDrawString(display, window, gc, 100, 30, "Hello World!", 12);
	XFlush(display);
	XNextEvent(display, &event);

	XCloseDisplay(display);
	return 0;
}
