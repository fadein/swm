#include <stdlib.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

/*
 * Richard Mann
 * 31 October 1996
 * 18 May 1998
 *
 * Copyright 1996 and 1997 University of Toronto. All rights reserved.
 * Copyright 1998 NEC Research Institute, Inc. All rights reserved.
 *
 */

/*
 * Macros
 *
 */

/*
 * Structs
 *
 */

static void *alloc_XExtData(void) {XExtData *_p = (XExtData *)malloc(sizeof(XExtData)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XExtData(void *_p) {if (_p==NULL) abort(); free((XExtData *)_p);}
static int get_XExtData_number(void *_p) {return (int)((XExtData *)_p)->number;}
static void set_XExtData_number(void *_p, int _v) {((XExtData *)_p)->number = (int)_v;}
static void *get_XExtData_next(void *_p) {return (void *)((XExtData *)_p)->next;}
static void set_XExtData_next(void *_p, void *_v) {((XExtData *)_p)->next = (XExtData *)_v;}
static void *get_XExtData_free_private(void *_p) {return (void *)((XExtData *)_p)->free_private;}
static void set_XExtData_free_private(void *_p, void *_v) {((XExtData *)_p)->free_private = (int( *)())_v;}
static void *get_XExtData_private_data(void *_p) {return (void *)((XExtData *)_p)->private_data;}
static void set_XExtData_private_data(void *_p, void *_v) {((XExtData *)_p)->private_data = (char *)_v;}
static void *alloc_XExtCodes(void) {XExtCodes *_p = (XExtCodes *)malloc(sizeof(XExtCodes)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XExtCodes(void *_p) {if (_p==NULL) abort(); free((XExtCodes *)_p);}
static int get_XExtCodes_extension(void *_p) {return (int)((XExtCodes *)_p)->extension;}
static void set_XExtCodes_extension(void *_p, int _v) {((XExtCodes *)_p)->extension = (int)_v;}
static int get_XExtCodes_major_opcode(void *_p) {return (int)((XExtCodes *)_p)->major_opcode;}
static void set_XExtCodes_major_opcode(void *_p, int _v) {((XExtCodes *)_p)->major_opcode = (int)_v;}
static int get_XExtCodes_first_event(void *_p) {return (int)((XExtCodes *)_p)->first_event;}
static void set_XExtCodes_first_event(void *_p, int _v) {((XExtCodes *)_p)->first_event = (int)_v;}
static int get_XExtCodes_first_error(void *_p) {return (int)((XExtCodes *)_p)->first_error;}
static void set_XExtCodes_first_error(void *_p, int _v) {((XExtCodes *)_p)->first_error = (int)_v;}
static void *alloc_XPixmapFormatValues(void) {XPixmapFormatValues *_p = (XPixmapFormatValues *)malloc(sizeof(XPixmapFormatValues)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XPixmapFormatValues(void *_p) {if (_p==NULL) abort(); free((XPixmapFormatValues *)_p);}
static int get_XPixmapFormatValues_depth(void *_p) {return (int)((XPixmapFormatValues *)_p)->depth;}
static void set_XPixmapFormatValues_depth(void *_p, int _v) {((XPixmapFormatValues *)_p)->depth = (int)_v;}
static int get_XPixmapFormatValues_bits_per_pixel(void *_p) {return (int)((XPixmapFormatValues *)_p)->bits_per_pixel;}
static void set_XPixmapFormatValues_bits_per_pixel(void *_p, int _v) {((XPixmapFormatValues *)_p)->bits_per_pixel = (int)_v;}
static int get_XPixmapFormatValues_scanline_pad(void *_p) {return (int)((XPixmapFormatValues *)_p)->scanline_pad;}
static void set_XPixmapFormatValues_scanline_pad(void *_p, int _v) {((XPixmapFormatValues *)_p)->scanline_pad = (int)_v;}
static void *alloc_XGCValues(void) {XGCValues *_p = (XGCValues *)malloc(sizeof(XGCValues)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XGCValues(void *_p) {if (_p==NULL) abort(); free((XGCValues *)_p);}
static int get_XGCValues_function(void *_p) {return (int)((XGCValues *)_p)->function;}
static void set_XGCValues_function(void *_p, int _v) {((XGCValues *)_p)->function = (int)_v;}
static unsigned long get_XGCValues_plane_mask(void *_p) {return (unsigned long)((XGCValues *)_p)->plane_mask;}
static void set_XGCValues_plane_mask(void *_p, unsigned long _v) {((XGCValues *)_p)->plane_mask = (unsigned long)_v;}
static unsigned long get_XGCValues_foreground(void *_p) {return (unsigned long)((XGCValues *)_p)->foreground;}
static void set_XGCValues_foreground(void *_p, unsigned long _v) {((XGCValues *)_p)->foreground = (unsigned long)_v;}
static unsigned long get_XGCValues_background(void *_p) {return (unsigned long)((XGCValues *)_p)->background;}
static void set_XGCValues_background(void *_p, unsigned long _v) {((XGCValues *)_p)->background = (unsigned long)_v;}
static int get_XGCValues_line_width(void *_p) {return (int)((XGCValues *)_p)->line_width;}
static void set_XGCValues_line_width(void *_p, int _v) {((XGCValues *)_p)->line_width = (int)_v;}
static int get_XGCValues_line_style(void *_p) {return (int)((XGCValues *)_p)->line_style;}
static void set_XGCValues_line_style(void *_p, int _v) {((XGCValues *)_p)->line_style = (int)_v;}
static int get_XGCValues_cap_style(void *_p) {return (int)((XGCValues *)_p)->cap_style;}
static void set_XGCValues_cap_style(void *_p, int _v) {((XGCValues *)_p)->cap_style = (int)_v;}
static int get_XGCValues_join_style(void *_p) {return (int)((XGCValues *)_p)->join_style;}
static void set_XGCValues_join_style(void *_p, int _v) {((XGCValues *)_p)->join_style = (int)_v;}
static int get_XGCValues_fill_style(void *_p) {return (int)((XGCValues *)_p)->fill_style;}
static void set_XGCValues_fill_style(void *_p, int _v) {((XGCValues *)_p)->fill_style = (int)_v;}
static int get_XGCValues_fill_rule(void *_p) {return (int)((XGCValues *)_p)->fill_rule;}
static void set_XGCValues_fill_rule(void *_p, int _v) {((XGCValues *)_p)->fill_rule = (int)_v;}
static int get_XGCValues_arc_mode(void *_p) {return (int)((XGCValues *)_p)->arc_mode;}
static void set_XGCValues_arc_mode(void *_p, int _v) {((XGCValues *)_p)->arc_mode = (int)_v;}
static unsigned long get_XGCValues_tile(void *_p) {return (unsigned long)((XGCValues *)_p)->tile;}
static void set_XGCValues_tile(void *_p, unsigned long _v) {((XGCValues *)_p)->tile = (unsigned long)_v;}
static unsigned long get_XGCValues_stipple(void *_p) {return (unsigned long)((XGCValues *)_p)->stipple;}
static void set_XGCValues_stipple(void *_p, unsigned long _v) {((XGCValues *)_p)->stipple = (unsigned long)_v;}
static int get_XGCValues_ts_x_origin(void *_p) {return (int)((XGCValues *)_p)->ts_x_origin;}
static void set_XGCValues_ts_x_origin(void *_p, int _v) {((XGCValues *)_p)->ts_x_origin = (int)_v;}
static int get_XGCValues_ts_y_origin(void *_p) {return (int)((XGCValues *)_p)->ts_y_origin;}
static void set_XGCValues_ts_y_origin(void *_p, int _v) {((XGCValues *)_p)->ts_y_origin = (int)_v;}
static unsigned long get_XGCValues_font(void *_p) {return (unsigned long)((XGCValues *)_p)->font;}
static void set_XGCValues_font(void *_p, unsigned long _v) {((XGCValues *)_p)->font = (unsigned long)_v;}
static int get_XGCValues_subwindow_mode(void *_p) {return (int)((XGCValues *)_p)->subwindow_mode;}
static void set_XGCValues_subwindow_mode(void *_p, int _v) {((XGCValues *)_p)->subwindow_mode = (int)_v;}
static int get_XGCValues_graphics_exposures(void *_p) {return (int)((XGCValues *)_p)->graphics_exposures;}
static void set_XGCValues_graphics_exposures(void *_p, int _v) {((XGCValues *)_p)->graphics_exposures = (int)_v;}
static int get_XGCValues_clip_x_origin(void *_p) {return (int)((XGCValues *)_p)->clip_x_origin;}
static void set_XGCValues_clip_x_origin(void *_p, int _v) {((XGCValues *)_p)->clip_x_origin = (int)_v;}
static int get_XGCValues_clip_y_origin(void *_p) {return (int)((XGCValues *)_p)->clip_y_origin;}
static void set_XGCValues_clip_y_origin(void *_p, int _v) {((XGCValues *)_p)->clip_y_origin = (int)_v;}
static unsigned long get_XGCValues_clip_mask(void *_p) {return (unsigned long)((XGCValues *)_p)->clip_mask;}
static void set_XGCValues_clip_mask(void *_p, unsigned long _v) {((XGCValues *)_p)->clip_mask = (unsigned long)_v;}
static int get_XGCValues_dash_offset(void *_p) {return (int)((XGCValues *)_p)->dash_offset;}
static void set_XGCValues_dash_offset(void *_p, int _v) {((XGCValues *)_p)->dash_offset = (int)_v;}
static char get_XGCValues_dashes(void *_p) {return (char)((XGCValues *)_p)->dashes;}
static void set_XGCValues_dashes(void *_p, char _v) {((XGCValues *)_p)->dashes = (char)_v;}
static void *alloc_Visual(void) {Visual *_p = (Visual *)malloc(sizeof(Visual)); if (_p==NULL) abort(); return (void *)_p;}
static void free_Visual(void *_p) {if (_p==NULL) abort(); free((Visual *)_p);}
static void *get_Visual_ext_data(void *_p) {return (void *)((Visual *)_p)->ext_data;}
static void set_Visual_ext_data(void *_p, void *_v) {((Visual *)_p)->ext_data = (XExtData *)_v;}
static unsigned long get_Visual_visualid(void *_p) {return (unsigned long)((Visual *)_p)->visualid;}
static void set_Visual_visualid(void *_p, unsigned long _v) {((Visual *)_p)->visualid = (unsigned long)_v;}
static int get_Visual_class(void *_p) {return (int)((Visual *)_p)->class;}
static void set_Visual_class(void *_p, int _v) {((Visual *)_p)->class = (int)_v;}
static unsigned long get_Visual_red_mask(void *_p) {return (unsigned long)((Visual *)_p)->red_mask;}
static void set_Visual_red_mask(void *_p, unsigned long _v) {((Visual *)_p)->red_mask = (unsigned long)_v;}
static unsigned long get_Visual_green_mask(void *_p) {return (unsigned long)((Visual *)_p)->green_mask;}
static void set_Visual_green_mask(void *_p, unsigned long _v) {((Visual *)_p)->green_mask = (unsigned long)_v;}
static unsigned long get_Visual_blue_mask(void *_p) {return (unsigned long)((Visual *)_p)->blue_mask;}
static void set_Visual_blue_mask(void *_p, unsigned long _v) {((Visual *)_p)->blue_mask = (unsigned long)_v;}
static int get_Visual_bits_per_rgb(void *_p) {return (int)((Visual *)_p)->bits_per_rgb;}
static void set_Visual_bits_per_rgb(void *_p, int _v) {((Visual *)_p)->bits_per_rgb = (int)_v;}
static int get_Visual_map_entries(void *_p) {return (int)((Visual *)_p)->map_entries;}
static void set_Visual_map_entries(void *_p, int _v) {((Visual *)_p)->map_entries = (int)_v;}
static void *alloc_Depth(void) {Depth *_p = (Depth *)malloc(sizeof(Depth)); if (_p==NULL) abort(); return (void *)_p;}
static void free_Depth(void *_p) {if (_p==NULL) abort(); free((Depth *)_p);}
static int get_Depth_depth(void *_p) {return (int)((Depth *)_p)->depth;}
static void set_Depth_depth(void *_p, int _v) {((Depth *)_p)->depth = (int)_v;}
static int get_Depth_nvisuals(void *_p) {return (int)((Depth *)_p)->nvisuals;}
static void set_Depth_nvisuals(void *_p, int _v) {((Depth *)_p)->nvisuals = (int)_v;}
static void *get_Depth_visuals(void *_p) {return (void *)((Depth *)_p)->visuals;}
static void set_Depth_visuals(void *_p, void *_v) {((Depth *)_p)->visuals = (Visual *)_v;}
static void *alloc_Screen(void) {Screen *_p = (Screen *)malloc(sizeof(Screen)); if (_p==NULL) abort(); return (void *)_p;}
static void free_Screen(void *_p) {if (_p==NULL) abort(); free((Screen *)_p);}
static void *get_Screen_ext_data(void *_p) {return (void *)((Screen *)_p)->ext_data;}
static void set_Screen_ext_data(void *_p, void *_v) {((Screen *)_p)->ext_data = (XExtData *)_v;}
static void *get_Screen_display(void *_p) {return (void *)((Screen *)_p)->display;}
static void set_Screen_display(void *_p, void *_v) {((Screen *)_p)->display = (Display *)_v;}
static unsigned long get_Screen_root(void *_p) {return (unsigned long)((Screen *)_p)->root;}
static void set_Screen_root(void *_p, unsigned long _v) {((Screen *)_p)->root = (unsigned long)_v;}
static int get_Screen_width(void *_p) {return (int)((Screen *)_p)->width;}
static void set_Screen_width(void *_p, int _v) {((Screen *)_p)->width = (int)_v;}
static int get_Screen_height(void *_p) {return (int)((Screen *)_p)->height;}
static void set_Screen_height(void *_p, int _v) {((Screen *)_p)->height = (int)_v;}
static int get_Screen_mwidth(void *_p) {return (int)((Screen *)_p)->mwidth;}
static void set_Screen_mwidth(void *_p, int _v) {((Screen *)_p)->mwidth = (int)_v;}
static int get_Screen_mheight(void *_p) {return (int)((Screen *)_p)->mheight;}
static void set_Screen_mheight(void *_p, int _v) {((Screen *)_p)->mheight = (int)_v;}
static int get_Screen_ndepths(void *_p) {return (int)((Screen *)_p)->ndepths;}
static void set_Screen_ndepths(void *_p, int _v) {((Screen *)_p)->ndepths = (int)_v;}
static void *get_Screen_depths(void *_p) {return (void *)((Screen *)_p)->depths;}
static void set_Screen_depths(void *_p, void *_v) {((Screen *)_p)->depths = (Depth *)_v;}
static int get_Screen_root_depth(void *_p) {return (int)((Screen *)_p)->root_depth;}
static void set_Screen_root_depth(void *_p, int _v) {((Screen *)_p)->root_depth = (int)_v;}
static void *get_Screen_root_visual(void *_p) {return (void *)((Screen *)_p)->root_visual;}
static void set_Screen_root_visual(void *_p, void *_v) {((Screen *)_p)->root_visual = (Visual *)_v;}
static void *get_Screen_default_gc(void *_p) {return (void *)((Screen *)_p)->default_gc;}
static void set_Screen_default_gc(void *_p, void *_v) {((Screen *)_p)->default_gc = (void *)_v;}
static unsigned long get_Screen_cmap(void *_p) {return (unsigned long)((Screen *)_p)->cmap;}
static void set_Screen_cmap(void *_p, unsigned long _v) {((Screen *)_p)->cmap = (unsigned long)_v;}
static unsigned long get_Screen_white_pixel(void *_p) {return (unsigned long)((Screen *)_p)->white_pixel;}
static void set_Screen_white_pixel(void *_p, unsigned long _v) {((Screen *)_p)->white_pixel = (unsigned long)_v;}
static unsigned long get_Screen_black_pixel(void *_p) {return (unsigned long)((Screen *)_p)->black_pixel;}
static void set_Screen_black_pixel(void *_p, unsigned long _v) {((Screen *)_p)->black_pixel = (unsigned long)_v;}
static int get_Screen_max_maps(void *_p) {return (int)((Screen *)_p)->max_maps;}
static void set_Screen_max_maps(void *_p, int _v) {((Screen *)_p)->max_maps = (int)_v;}
static int get_Screen_min_maps(void *_p) {return (int)((Screen *)_p)->min_maps;}
static void set_Screen_min_maps(void *_p, int _v) {((Screen *)_p)->min_maps = (int)_v;}
static int get_Screen_backing_store(void *_p) {return (int)((Screen *)_p)->backing_store;}
static void set_Screen_backing_store(void *_p, int _v) {((Screen *)_p)->backing_store = (int)_v;}
static int get_Screen_save_unders(void *_p) {return (int)((Screen *)_p)->save_unders;}
static void set_Screen_save_unders(void *_p, int _v) {((Screen *)_p)->save_unders = (int)_v;}
static long get_Screen_root_input_mask(void *_p) {return (long)((Screen *)_p)->root_input_mask;}
static void set_Screen_root_input_mask(void *_p, long _v) {((Screen *)_p)->root_input_mask = (long)_v;}
static void *alloc_ScreenFormat(void) {ScreenFormat *_p = (ScreenFormat *)malloc(sizeof(ScreenFormat)); if (_p==NULL) abort(); return (void *)_p;}
static void free_ScreenFormat(void *_p) {if (_p==NULL) abort(); free((ScreenFormat *)_p);}
static void *get_ScreenFormat_ext_data(void *_p) {return (void *)((ScreenFormat *)_p)->ext_data;}
static void set_ScreenFormat_ext_data(void *_p, void *_v) {((ScreenFormat *)_p)->ext_data = (XExtData *)_v;}
static int get_ScreenFormat_depth(void *_p) {return (int)((ScreenFormat *)_p)->depth;}
static void set_ScreenFormat_depth(void *_p, int _v) {((ScreenFormat *)_p)->depth = (int)_v;}
static int get_ScreenFormat_bits_per_pixel(void *_p) {return (int)((ScreenFormat *)_p)->bits_per_pixel;}
static void set_ScreenFormat_bits_per_pixel(void *_p, int _v) {((ScreenFormat *)_p)->bits_per_pixel = (int)_v;}
static int get_ScreenFormat_scanline_pad(void *_p) {return (int)((ScreenFormat *)_p)->scanline_pad;}
static void set_ScreenFormat_scanline_pad(void *_p, int _v) {((ScreenFormat *)_p)->scanline_pad = (int)_v;}
static void *alloc_XSetWindowAttributes(void) {XSetWindowAttributes *_p = (XSetWindowAttributes *)malloc(sizeof(XSetWindowAttributes)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XSetWindowAttributes(void *_p) {if (_p==NULL) abort(); free((XSetWindowAttributes *)_p);}
static unsigned long get_XSetWindowAttributes_background_pixmap(void *_p) {return (unsigned long)((XSetWindowAttributes *)_p)->background_pixmap;}
static void set_XSetWindowAttributes_background_pixmap(void *_p, unsigned long _v) {((XSetWindowAttributes *)_p)->background_pixmap = (unsigned long)_v;}
static unsigned long get_XSetWindowAttributes_background_pixel(void *_p) {return (unsigned long)((XSetWindowAttributes *)_p)->background_pixel;}
static void set_XSetWindowAttributes_background_pixel(void *_p, unsigned long _v) {((XSetWindowAttributes *)_p)->background_pixel = (unsigned long)_v;}
static unsigned long get_XSetWindowAttributes_border_pixmap(void *_p) {return (unsigned long)((XSetWindowAttributes *)_p)->border_pixmap;}
static void set_XSetWindowAttributes_border_pixmap(void *_p, unsigned long _v) {((XSetWindowAttributes *)_p)->border_pixmap = (unsigned long)_v;}
static unsigned long get_XSetWindowAttributes_border_pixel(void *_p) {return (unsigned long)((XSetWindowAttributes *)_p)->border_pixel;}
static void set_XSetWindowAttributes_border_pixel(void *_p, unsigned long _v) {((XSetWindowAttributes *)_p)->border_pixel = (unsigned long)_v;}
static int get_XSetWindowAttributes_bit_gravity(void *_p) {return (int)((XSetWindowAttributes *)_p)->bit_gravity;}
static void set_XSetWindowAttributes_bit_gravity(void *_p, int _v) {((XSetWindowAttributes *)_p)->bit_gravity = (int)_v;}
static int get_XSetWindowAttributes_win_gravity(void *_p) {return (int)((XSetWindowAttributes *)_p)->win_gravity;}
static void set_XSetWindowAttributes_win_gravity(void *_p, int _v) {((XSetWindowAttributes *)_p)->win_gravity = (int)_v;}
static int get_XSetWindowAttributes_backing_store(void *_p) {return (int)((XSetWindowAttributes *)_p)->backing_store;}
static void set_XSetWindowAttributes_backing_store(void *_p, int _v) {((XSetWindowAttributes *)_p)->backing_store = (int)_v;}
static unsigned long get_XSetWindowAttributes_backing_planes(void *_p) {return (unsigned long)((XSetWindowAttributes *)_p)->backing_planes;}
static void set_XSetWindowAttributes_backing_planes(void *_p, unsigned long _v) {((XSetWindowAttributes *)_p)->backing_planes = (unsigned long)_v;}
static unsigned long get_XSetWindowAttributes_backing_pixel(void *_p) {return (unsigned long)((XSetWindowAttributes *)_p)->backing_pixel;}
static void set_XSetWindowAttributes_backing_pixel(void *_p, unsigned long _v) {((XSetWindowAttributes *)_p)->backing_pixel = (unsigned long)_v;}
static int get_XSetWindowAttributes_save_under(void *_p) {return (int)((XSetWindowAttributes *)_p)->save_under;}
static void set_XSetWindowAttributes_save_under(void *_p, int _v) {((XSetWindowAttributes *)_p)->save_under = (int)_v;}
static long get_XSetWindowAttributes_event_mask(void *_p) {return (long)((XSetWindowAttributes *)_p)->event_mask;}
static void set_XSetWindowAttributes_event_mask(void *_p, long _v) {((XSetWindowAttributes *)_p)->event_mask = (long)_v;}
static long get_XSetWindowAttributes_do_not_propagate_mask(void *_p) {return (long)((XSetWindowAttributes *)_p)->do_not_propagate_mask;}
static void set_XSetWindowAttributes_do_not_propagate_mask(void *_p, long _v) {((XSetWindowAttributes *)_p)->do_not_propagate_mask = (long)_v;}
static int get_XSetWindowAttributes_override_redirect(void *_p) {return (int)((XSetWindowAttributes *)_p)->override_redirect;}
static void set_XSetWindowAttributes_override_redirect(void *_p, int _v) {((XSetWindowAttributes *)_p)->override_redirect = (int)_v;}
static unsigned long get_XSetWindowAttributes_colormap(void *_p) {return (unsigned long)((XSetWindowAttributes *)_p)->colormap;}
static void set_XSetWindowAttributes_colormap(void *_p, unsigned long _v) {((XSetWindowAttributes *)_p)->colormap = (unsigned long)_v;}
static unsigned long get_XSetWindowAttributes_cursor(void *_p) {return (unsigned long)((XSetWindowAttributes *)_p)->cursor;}
static void set_XSetWindowAttributes_cursor(void *_p, unsigned long _v) {((XSetWindowAttributes *)_p)->cursor = (unsigned long)_v;}
static void *alloc_XWindowAttributes(void) {XWindowAttributes *_p = (XWindowAttributes *)malloc(sizeof(XWindowAttributes)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XWindowAttributes(void *_p) {if (_p==NULL) abort(); free((XWindowAttributes *)_p);}
static int get_XWindowAttributes_x(void *_p) {return (int)((XWindowAttributes *)_p)->x;}
static void set_XWindowAttributes_x(void *_p, int _v) {((XWindowAttributes *)_p)->x = (int)_v;}
static int get_XWindowAttributes_y(void *_p) {return (int)((XWindowAttributes *)_p)->y;}
static void set_XWindowAttributes_y(void *_p, int _v) {((XWindowAttributes *)_p)->y = (int)_v;}
static int get_XWindowAttributes_width(void *_p) {return (int)((XWindowAttributes *)_p)->width;}
static void set_XWindowAttributes_width(void *_p, int _v) {((XWindowAttributes *)_p)->width = (int)_v;}
static int get_XWindowAttributes_height(void *_p) {return (int)((XWindowAttributes *)_p)->height;}
static void set_XWindowAttributes_height(void *_p, int _v) {((XWindowAttributes *)_p)->height = (int)_v;}
static int get_XWindowAttributes_border_width(void *_p) {return (int)((XWindowAttributes *)_p)->border_width;}
static void set_XWindowAttributes_border_width(void *_p, int _v) {((XWindowAttributes *)_p)->border_width = (int)_v;}
static int get_XWindowAttributes_depth(void *_p) {return (int)((XWindowAttributes *)_p)->depth;}
static void set_XWindowAttributes_depth(void *_p, int _v) {((XWindowAttributes *)_p)->depth = (int)_v;}
static void *get_XWindowAttributes_visual(void *_p) {return (void *)((XWindowAttributes *)_p)->visual;}
static void set_XWindowAttributes_visual(void *_p, void *_v) {((XWindowAttributes *)_p)->visual = (Visual *)_v;}
static unsigned long get_XWindowAttributes_root(void *_p) {return (unsigned long)((XWindowAttributes *)_p)->root;}
static void set_XWindowAttributes_root(void *_p, unsigned long _v) {((XWindowAttributes *)_p)->root = (unsigned long)_v;}
static int get_XWindowAttributes_class(void *_p) {return (int)((XWindowAttributes *)_p)->class;}
static void set_XWindowAttributes_class(void *_p, int _v) {((XWindowAttributes *)_p)->class = (int)_v;}
static int get_XWindowAttributes_bit_gravity(void *_p) {return (int)((XWindowAttributes *)_p)->bit_gravity;}
static void set_XWindowAttributes_bit_gravity(void *_p, int _v) {((XWindowAttributes *)_p)->bit_gravity = (int)_v;}
static int get_XWindowAttributes_win_gravity(void *_p) {return (int)((XWindowAttributes *)_p)->win_gravity;}
static void set_XWindowAttributes_win_gravity(void *_p, int _v) {((XWindowAttributes *)_p)->win_gravity = (int)_v;}
static int get_XWindowAttributes_backing_store(void *_p) {return (int)((XWindowAttributes *)_p)->backing_store;}
static void set_XWindowAttributes_backing_store(void *_p, int _v) {((XWindowAttributes *)_p)->backing_store = (int)_v;}
static unsigned long get_XWindowAttributes_backing_planes(void *_p) {return (unsigned long)((XWindowAttributes *)_p)->backing_planes;}
static void set_XWindowAttributes_backing_planes(void *_p, unsigned long _v) {((XWindowAttributes *)_p)->backing_planes = (unsigned long)_v;}
static unsigned long get_XWindowAttributes_backing_pixel(void *_p) {return (unsigned long)((XWindowAttributes *)_p)->backing_pixel;}
static void set_XWindowAttributes_backing_pixel(void *_p, unsigned long _v) {((XWindowAttributes *)_p)->backing_pixel = (unsigned long)_v;}
static int get_XWindowAttributes_save_under(void *_p) {return (int)((XWindowAttributes *)_p)->save_under;}
static void set_XWindowAttributes_save_under(void *_p, int _v) {((XWindowAttributes *)_p)->save_under = (int)_v;}
static unsigned long get_XWindowAttributes_colormap(void *_p) {return (unsigned long)((XWindowAttributes *)_p)->colormap;}
static void set_XWindowAttributes_colormap(void *_p, unsigned long _v) {((XWindowAttributes *)_p)->colormap = (unsigned long)_v;}
static int get_XWindowAttributes_map_installed(void *_p) {return (int)((XWindowAttributes *)_p)->map_installed;}
static void set_XWindowAttributes_map_installed(void *_p, int _v) {((XWindowAttributes *)_p)->map_installed = (int)_v;}
static int get_XWindowAttributes_map_state(void *_p) {return (int)((XWindowAttributes *)_p)->map_state;}
static void set_XWindowAttributes_map_state(void *_p, int _v) {((XWindowAttributes *)_p)->map_state = (int)_v;}
static long get_XWindowAttributes_all_event_masks(void *_p) {return (long)((XWindowAttributes *)_p)->all_event_masks;}
static void set_XWindowAttributes_all_event_masks(void *_p, long _v) {((XWindowAttributes *)_p)->all_event_masks = (long)_v;}
static long get_XWindowAttributes_your_event_mask(void *_p) {return (long)((XWindowAttributes *)_p)->your_event_mask;}
static void set_XWindowAttributes_your_event_mask(void *_p, long _v) {((XWindowAttributes *)_p)->your_event_mask = (long)_v;}
static long get_XWindowAttributes_do_not_propagate_mask(void *_p) {return (long)((XWindowAttributes *)_p)->do_not_propagate_mask;}
static void set_XWindowAttributes_do_not_propagate_mask(void *_p, long _v) {((XWindowAttributes *)_p)->do_not_propagate_mask = (long)_v;}
static int get_XWindowAttributes_override_redirect(void *_p) {return (int)((XWindowAttributes *)_p)->override_redirect;}
static void set_XWindowAttributes_override_redirect(void *_p, int _v) {((XWindowAttributes *)_p)->override_redirect = (int)_v;}
static void *get_XWindowAttributes_screen(void *_p) {return (void *)((XWindowAttributes *)_p)->screen;}
static void set_XWindowAttributes_screen(void *_p, void *_v) {((XWindowAttributes *)_p)->screen = (Screen *)_v;}
static void *alloc_XHostAddress(void) {XHostAddress *_p = (XHostAddress *)malloc(sizeof(XHostAddress)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XHostAddress(void *_p) {if (_p==NULL) abort(); free((XHostAddress *)_p);}
static int get_XHostAddress_family(void *_p) {return (int)((XHostAddress *)_p)->family;}
static void set_XHostAddress_family(void *_p, int _v) {((XHostAddress *)_p)->family = (int)_v;}
static int get_XHostAddress_length(void *_p) {return (int)((XHostAddress *)_p)->length;}
static void set_XHostAddress_length(void *_p, int _v) {((XHostAddress *)_p)->length = (int)_v;}
static void *get_XHostAddress_address(void *_p) {return (void *)((XHostAddress *)_p)->address;}
static void set_XHostAddress_address(void *_p, void *_v) {((XHostAddress *)_p)->address = (char *)_v;}
static void *alloc_XImage(void) {XImage *_p = (XImage *)malloc(sizeof(XImage)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XImage(void *_p) {if (_p==NULL) abort(); free((XImage *)_p);}
static int get_XImage_width(void *_p) {return (int)((XImage *)_p)->width;}
static void set_XImage_width(void *_p, int _v) {((XImage *)_p)->width = (int)_v;}
static int get_XImage_height(void *_p) {return (int)((XImage *)_p)->height;}
static void set_XImage_height(void *_p, int _v) {((XImage *)_p)->height = (int)_v;}
static int get_XImage_xoffset(void *_p) {return (int)((XImage *)_p)->xoffset;}
static void set_XImage_xoffset(void *_p, int _v) {((XImage *)_p)->xoffset = (int)_v;}
static int get_XImage_format(void *_p) {return (int)((XImage *)_p)->format;}
static void set_XImage_format(void *_p, int _v) {((XImage *)_p)->format = (int)_v;}
static void *get_XImage_data(void *_p) {return (void *)((XImage *)_p)->data;}
static void set_XImage_data(void *_p, void *_v) {((XImage *)_p)->data = (char *)_v;}
static int get_XImage_byte_order(void *_p) {return (int)((XImage *)_p)->byte_order;}
static void set_XImage_byte_order(void *_p, int _v) {((XImage *)_p)->byte_order = (int)_v;}
static int get_XImage_bitmap_unit(void *_p) {return (int)((XImage *)_p)->bitmap_unit;}
static void set_XImage_bitmap_unit(void *_p, int _v) {((XImage *)_p)->bitmap_unit = (int)_v;}
static int get_XImage_bitmap_bit_order(void *_p) {return (int)((XImage *)_p)->bitmap_bit_order;}
static void set_XImage_bitmap_bit_order(void *_p, int _v) {((XImage *)_p)->bitmap_bit_order = (int)_v;}
static int get_XImage_bitmap_pad(void *_p) {return (int)((XImage *)_p)->bitmap_pad;}
static void set_XImage_bitmap_pad(void *_p, int _v) {((XImage *)_p)->bitmap_pad = (int)_v;}
static int get_XImage_depth(void *_p) {return (int)((XImage *)_p)->depth;}
static void set_XImage_depth(void *_p, int _v) {((XImage *)_p)->depth = (int)_v;}
static int get_XImage_bytes_per_line(void *_p) {return (int)((XImage *)_p)->bytes_per_line;}
static void set_XImage_bytes_per_line(void *_p, int _v) {((XImage *)_p)->bytes_per_line = (int)_v;}
static int get_XImage_bits_per_pixel(void *_p) {return (int)((XImage *)_p)->bits_per_pixel;}
static void set_XImage_bits_per_pixel(void *_p, int _v) {((XImage *)_p)->bits_per_pixel = (int)_v;}
static unsigned long get_XImage_red_mask(void *_p) {return (unsigned long)((XImage *)_p)->red_mask;}
static void set_XImage_red_mask(void *_p, unsigned long _v) {((XImage *)_p)->red_mask = (unsigned long)_v;}
static unsigned long get_XImage_green_mask(void *_p) {return (unsigned long)((XImage *)_p)->green_mask;}
static void set_XImage_green_mask(void *_p, unsigned long _v) {((XImage *)_p)->green_mask = (unsigned long)_v;}
static unsigned long get_XImage_blue_mask(void *_p) {return (unsigned long)((XImage *)_p)->blue_mask;}
static void set_XImage_blue_mask(void *_p, unsigned long _v) {((XImage *)_p)->blue_mask = (unsigned long)_v;}
static void *get_XImage_obdata(void *_p) {return (void *)((XImage *)_p)->obdata;}
static void set_XImage_obdata(void *_p, void *_v) {((XImage *)_p)->obdata = (char *)_v;}
static void *get_XImage_f_create_image(void *_p) {return (void *)((XImage *)_p)->f.create_image;}
static void set_XImage_f_create_image(void *_p, void *_v) {((XImage *)_p)->f.create_image = (XImage *( *)())_v;}
static void *get_XImage_f_destroy_image(void *_p) {return (void *)((XImage *)_p)->f.destroy_image;}
static void set_XImage_f_destroy_image(void *_p, void *_v) {((XImage *)_p)->f.destroy_image = (int( *)(XImage *))_v;}
static void *get_XImage_f_get_pixel(void *_p) {return (void *)((XImage *)_p)->f.get_pixel;}
static void set_XImage_f_get_pixel(void *_p, void *_v) {((XImage *)_p)->f.get_pixel = (unsigned long( *)(XImage *,int,int))_v;}
static void *get_XImage_f_put_pixel(void *_p) {return (void *)((XImage *)_p)->f.put_pixel;}
static void set_XImage_f_put_pixel(void *_p, void *_v) {((XImage *)_p)->f.put_pixel = (int( *)(XImage *,int,int,unsigned long))_v;}
static void *get_XImage_f_sub_image(void *_p) {return (void *)((XImage *)_p)->f.sub_image;}
static void set_XImage_f_sub_image(void *_p, void *_v) {((XImage *)_p)->f.sub_image = (XImage *( *)(XImage *,int,int,unsigned,unsigned))_v;}
static void *get_XImage_f_add_pixel(void *_p) {return (void *)((XImage *)_p)->f.add_pixel;}
static void set_XImage_f_add_pixel(void *_p, void *_v) {((XImage *)_p)->f.add_pixel = (int( *)(XImage *,long))_v;}
static void *alloc_XWindowChanges(void) {XWindowChanges *_p = (XWindowChanges *)malloc(sizeof(XWindowChanges)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XWindowChanges(void *_p) {if (_p==NULL) abort(); free((XWindowChanges *)_p);}
static int get_XWindowChanges_x(void *_p) {return (int)((XWindowChanges *)_p)->x;}
static void set_XWindowChanges_x(void *_p, int _v) {((XWindowChanges *)_p)->x = (int)_v;}
static int get_XWindowChanges_y(void *_p) {return (int)((XWindowChanges *)_p)->y;}
static void set_XWindowChanges_y(void *_p, int _v) {((XWindowChanges *)_p)->y = (int)_v;}
static int get_XWindowChanges_width(void *_p) {return (int)((XWindowChanges *)_p)->width;}
static void set_XWindowChanges_width(void *_p, int _v) {((XWindowChanges *)_p)->width = (int)_v;}
static int get_XWindowChanges_height(void *_p) {return (int)((XWindowChanges *)_p)->height;}
static void set_XWindowChanges_height(void *_p, int _v) {((XWindowChanges *)_p)->height = (int)_v;}
static int get_XWindowChanges_border_width(void *_p) {return (int)((XWindowChanges *)_p)->border_width;}
static void set_XWindowChanges_border_width(void *_p, int _v) {((XWindowChanges *)_p)->border_width = (int)_v;}
static unsigned long get_XWindowChanges_sibling(void *_p) {return (unsigned long)((XWindowChanges *)_p)->sibling;}
static void set_XWindowChanges_sibling(void *_p, unsigned long _v) {((XWindowChanges *)_p)->sibling = (unsigned long)_v;}
static int get_XWindowChanges_stack_mode(void *_p) {return (int)((XWindowChanges *)_p)->stack_mode;}
static void set_XWindowChanges_stack_mode(void *_p, int _v) {((XWindowChanges *)_p)->stack_mode = (int)_v;}
static void *alloc_XColor(void) {XColor *_p = (XColor *)malloc(sizeof(XColor)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XColor(void *_p) {if (_p==NULL) abort(); free((XColor *)_p);}
static unsigned long get_XColor_pixel(void *_p) {return (unsigned long)((XColor *)_p)->pixel;}
static void set_XColor_pixel(void *_p, unsigned long _v) {((XColor *)_p)->pixel = (unsigned long)_v;}
static unsigned short get_XColor_red(void *_p) {return (unsigned short)((XColor *)_p)->red;}
static void set_XColor_red(void *_p, unsigned short _v) {((XColor *)_p)->red = (unsigned short)_v;}
static unsigned short get_XColor_green(void *_p) {return (unsigned short)((XColor *)_p)->green;}
static void set_XColor_green(void *_p, unsigned short _v) {((XColor *)_p)->green = (unsigned short)_v;}
static unsigned short get_XColor_blue(void *_p) {return (unsigned short)((XColor *)_p)->blue;}
static void set_XColor_blue(void *_p, unsigned short _v) {((XColor *)_p)->blue = (unsigned short)_v;}
static char get_XColor_flags(void *_p) {return (char)((XColor *)_p)->flags;}
static void set_XColor_flags(void *_p, char _v) {((XColor *)_p)->flags = (char)_v;}
static char get_XColor_pad(void *_p) {return (char)((XColor *)_p)->pad;}
static void set_XColor_pad(void *_p, char _v) {((XColor *)_p)->pad = (char)_v;}
static void *alloc_XSegment(void) {XSegment *_p = (XSegment *)malloc(sizeof(XSegment)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XSegment(void *_p) {if (_p==NULL) abort(); free((XSegment *)_p);}
static short get_XSegment_x1(void *_p) {return (short)((XSegment *)_p)->x1;}
static void set_XSegment_x1(void *_p, short _v) {((XSegment *)_p)->x1 = (short)_v;}
static short get_XSegment_y1(void *_p) {return (short)((XSegment *)_p)->y1;}
static void set_XSegment_y1(void *_p, short _v) {((XSegment *)_p)->y1 = (short)_v;}
static short get_XSegment_x2(void *_p) {return (short)((XSegment *)_p)->x2;}
static void set_XSegment_x2(void *_p, short _v) {((XSegment *)_p)->x2 = (short)_v;}
static short get_XSegment_y2(void *_p) {return (short)((XSegment *)_p)->y2;}
static void set_XSegment_y2(void *_p, short _v) {((XSegment *)_p)->y2 = (short)_v;}
static void *alloc_XPoint(void) {XPoint *_p = (XPoint *)malloc(sizeof(XPoint)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XPoint(void *_p) {if (_p==NULL) abort(); free((XPoint *)_p);}
static short get_XPoint_x(void *_p) {return (short)((XPoint *)_p)->x;}
static void set_XPoint_x(void *_p, short _v) {((XPoint *)_p)->x = (short)_v;}
static short get_XPoint_y(void *_p) {return (short)((XPoint *)_p)->y;}
static void set_XPoint_y(void *_p, short _v) {((XPoint *)_p)->y = (short)_v;}
static void *alloc_XRectangle(void) {XRectangle *_p = (XRectangle *)malloc(sizeof(XRectangle)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XRectangle(void *_p) {if (_p==NULL) abort(); free((XRectangle *)_p);}
static short get_XRectangle_x(void *_p) {return (short)((XRectangle *)_p)->x;}
static void set_XRectangle_x(void *_p, short _v) {((XRectangle *)_p)->x = (short)_v;}
static short get_XRectangle_y(void *_p) {return (short)((XRectangle *)_p)->y;}
static void set_XRectangle_y(void *_p, short _v) {((XRectangle *)_p)->y = (short)_v;}
static unsigned short get_XRectangle_width(void *_p) {return (unsigned short)((XRectangle *)_p)->width;}
static void set_XRectangle_width(void *_p, unsigned short _v) {((XRectangle *)_p)->width = (unsigned short)_v;}
static unsigned short get_XRectangle_height(void *_p) {return (unsigned short)((XRectangle *)_p)->height;}
static void set_XRectangle_height(void *_p, unsigned short _v) {((XRectangle *)_p)->height = (unsigned short)_v;}
static void *alloc_XArc(void) {XArc *_p = (XArc *)malloc(sizeof(XArc)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XArc(void *_p) {if (_p==NULL) abort(); free((XArc *)_p);}
static short get_XArc_x(void *_p) {return (short)((XArc *)_p)->x;}
static void set_XArc_x(void *_p, short _v) {((XArc *)_p)->x = (short)_v;}
static short get_XArc_y(void *_p) {return (short)((XArc *)_p)->y;}
static void set_XArc_y(void *_p, short _v) {((XArc *)_p)->y = (short)_v;}
static unsigned short get_XArc_width(void *_p) {return (unsigned short)((XArc *)_p)->width;}
static void set_XArc_width(void *_p, unsigned short _v) {((XArc *)_p)->width = (unsigned short)_v;}
static unsigned short get_XArc_height(void *_p) {return (unsigned short)((XArc *)_p)->height;}
static void set_XArc_height(void *_p, unsigned short _v) {((XArc *)_p)->height = (unsigned short)_v;}
static short get_XArc_angle1(void *_p) {return (short)((XArc *)_p)->angle1;}
static void set_XArc_angle1(void *_p, short _v) {((XArc *)_p)->angle1 = (short)_v;}
static short get_XArc_angle2(void *_p) {return (short)((XArc *)_p)->angle2;}
static void set_XArc_angle2(void *_p, short _v) {((XArc *)_p)->angle2 = (short)_v;}
static void *alloc_XKeyboardControl(void) {XKeyboardControl *_p = (XKeyboardControl *)malloc(sizeof(XKeyboardControl)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XKeyboardControl(void *_p) {if (_p==NULL) abort(); free((XKeyboardControl *)_p);}
static int get_XKeyboardControl_key_click_percent(void *_p) {return (int)((XKeyboardControl *)_p)->key_click_percent;}
static void set_XKeyboardControl_key_click_percent(void *_p, int _v) {((XKeyboardControl *)_p)->key_click_percent = (int)_v;}
static int get_XKeyboardControl_bell_percent(void *_p) {return (int)((XKeyboardControl *)_p)->bell_percent;}
static void set_XKeyboardControl_bell_percent(void *_p, int _v) {((XKeyboardControl *)_p)->bell_percent = (int)_v;}
static int get_XKeyboardControl_bell_pitch(void *_p) {return (int)((XKeyboardControl *)_p)->bell_pitch;}
static void set_XKeyboardControl_bell_pitch(void *_p, int _v) {((XKeyboardControl *)_p)->bell_pitch = (int)_v;}
static int get_XKeyboardControl_bell_duration(void *_p) {return (int)((XKeyboardControl *)_p)->bell_duration;}
static void set_XKeyboardControl_bell_duration(void *_p, int _v) {((XKeyboardControl *)_p)->bell_duration = (int)_v;}
static int get_XKeyboardControl_led(void *_p) {return (int)((XKeyboardControl *)_p)->led;}
static void set_XKeyboardControl_led(void *_p, int _v) {((XKeyboardControl *)_p)->led = (int)_v;}
static int get_XKeyboardControl_led_mode(void *_p) {return (int)((XKeyboardControl *)_p)->led_mode;}
static void set_XKeyboardControl_led_mode(void *_p, int _v) {((XKeyboardControl *)_p)->led_mode = (int)_v;}
static int get_XKeyboardControl_key(void *_p) {return (int)((XKeyboardControl *)_p)->key;}
static void set_XKeyboardControl_key(void *_p, int _v) {((XKeyboardControl *)_p)->key = (int)_v;}
static int get_XKeyboardControl_auto_repeat_mode(void *_p) {return (int)((XKeyboardControl *)_p)->auto_repeat_mode;}
static void set_XKeyboardControl_auto_repeat_mode(void *_p, int _v) {((XKeyboardControl *)_p)->auto_repeat_mode = (int)_v;}
static void *alloc_XKeyboardState(void) {XKeyboardState *_p = (XKeyboardState *)malloc(sizeof(XKeyboardState)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XKeyboardState(void *_p) {if (_p==NULL) abort(); free((XKeyboardState *)_p);}
static int get_XKeyboardState_key_click_percent(void *_p) {return (int)((XKeyboardState *)_p)->key_click_percent;}
static void set_XKeyboardState_key_click_percent(void *_p, int _v) {((XKeyboardState *)_p)->key_click_percent = (int)_v;}
static int get_XKeyboardState_bell_percent(void *_p) {return (int)((XKeyboardState *)_p)->bell_percent;}
static void set_XKeyboardState_bell_percent(void *_p, int _v) {((XKeyboardState *)_p)->bell_percent = (int)_v;}
static unsigned get_XKeyboardState_bell_pitch(void *_p) {return (unsigned)((XKeyboardState *)_p)->bell_pitch;}
static void set_XKeyboardState_bell_pitch(void *_p, unsigned _v) {((XKeyboardState *)_p)->bell_pitch = (unsigned)_v;}
static unsigned get_XKeyboardState_bell_duration(void *_p) {return (unsigned)((XKeyboardState *)_p)->bell_duration;}
static void set_XKeyboardState_bell_duration(void *_p, unsigned _v) {((XKeyboardState *)_p)->bell_duration = (unsigned)_v;}
static unsigned long get_XKeyboardState_led_mask(void *_p) {return (unsigned long)((XKeyboardState *)_p)->led_mask;}
static void set_XKeyboardState_led_mask(void *_p, unsigned long _v) {((XKeyboardState *)_p)->led_mask = (unsigned long)_v;}
static int get_XKeyboardState_global_auto_repeat(void *_p) {return (int)((XKeyboardState *)_p)->global_auto_repeat;}
static void set_XKeyboardState_global_auto_repeat(void *_p, int _v) {((XKeyboardState *)_p)->global_auto_repeat = (int)_v;}
static void *get_XKeyboardState_auto_repeats(void *_p) {return (void *)(((XKeyboardState *)_p)->auto_repeats);}
static void *alloc_XTimeCoord(void) {XTimeCoord *_p = (XTimeCoord *)malloc(sizeof(XTimeCoord)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XTimeCoord(void *_p) {if (_p==NULL) abort(); free((XTimeCoord *)_p);}
static unsigned long get_XTimeCoord_time(void *_p) {return (unsigned long)((XTimeCoord *)_p)->time;}
static void set_XTimeCoord_time(void *_p, unsigned long _v) {((XTimeCoord *)_p)->time = (unsigned long)_v;}
static short get_XTimeCoord_x(void *_p) {return (short)((XTimeCoord *)_p)->x;}
static void set_XTimeCoord_x(void *_p, short _v) {((XTimeCoord *)_p)->x = (short)_v;}
static short get_XTimeCoord_y(void *_p) {return (short)((XTimeCoord *)_p)->y;}
static void set_XTimeCoord_y(void *_p, short _v) {((XTimeCoord *)_p)->y = (short)_v;}
static void *alloc_XModifierKeymap(void) {XModifierKeymap *_p = (XModifierKeymap *)malloc(sizeof(XModifierKeymap)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XModifierKeymap(void *_p) {if (_p==NULL) abort(); free((XModifierKeymap *)_p);}
static int get_XModifierKeymap_max_keypermod(void *_p) {return (int)((XModifierKeymap *)_p)->max_keypermod;}
static void set_XModifierKeymap_max_keypermod(void *_p, int _v) {((XModifierKeymap *)_p)->max_keypermod = (int)_v;}
static void *get_XModifierKeymap_modifiermap(void *_p) {return (void *)((XModifierKeymap *)_p)->modifiermap;}
static void set_XModifierKeymap_modifiermap(void *_p, void *_v) {((XModifierKeymap *)_p)->modifiermap = (unsigned char *)_v;}
static void *alloc_XKeyReleasedEvent(void) {XKeyReleasedEvent *_p = (XKeyReleasedEvent *)malloc(sizeof(XKeyReleasedEvent)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XKeyReleasedEvent(void *_p) {if (_p==NULL) abort(); free((XKeyReleasedEvent *)_p);}
static int get_XKeyReleasedEvent_type(void *_p) {return (int)((XKeyReleasedEvent *)_p)->type;}
static void set_XKeyReleasedEvent_type(void *_p, int _v) {((XKeyReleasedEvent *)_p)->type = (int)_v;}
static unsigned long get_XKeyReleasedEvent_serial(void *_p) {return (unsigned long)((XKeyReleasedEvent *)_p)->serial;}
static void set_XKeyReleasedEvent_serial(void *_p, unsigned long _v) {((XKeyReleasedEvent *)_p)->serial = (unsigned long)_v;}
static int get_XKeyReleasedEvent_send_event(void *_p) {return (int)((XKeyReleasedEvent *)_p)->send_event;}
static void set_XKeyReleasedEvent_send_event(void *_p, int _v) {((XKeyReleasedEvent *)_p)->send_event = (int)_v;}
static void *get_XKeyReleasedEvent_display(void *_p) {return (void *)((XKeyReleasedEvent *)_p)->display;}
static void set_XKeyReleasedEvent_display(void *_p, void *_v) {((XKeyReleasedEvent *)_p)->display = (Display *)_v;}
static unsigned long get_XKeyReleasedEvent_window(void *_p) {return (unsigned long)((XKeyReleasedEvent *)_p)->window;}
static void set_XKeyReleasedEvent_window(void *_p, unsigned long _v) {((XKeyReleasedEvent *)_p)->window = (unsigned long)_v;}
static unsigned long get_XKeyReleasedEvent_root(void *_p) {return (unsigned long)((XKeyReleasedEvent *)_p)->root;}
static void set_XKeyReleasedEvent_root(void *_p, unsigned long _v) {((XKeyReleasedEvent *)_p)->root = (unsigned long)_v;}
static unsigned long get_XKeyReleasedEvent_subwindow(void *_p) {return (unsigned long)((XKeyReleasedEvent *)_p)->subwindow;}
static void set_XKeyReleasedEvent_subwindow(void *_p, unsigned long _v) {((XKeyReleasedEvent *)_p)->subwindow = (unsigned long)_v;}
static unsigned long get_XKeyReleasedEvent_time(void *_p) {return (unsigned long)((XKeyReleasedEvent *)_p)->time;}
static void set_XKeyReleasedEvent_time(void *_p, unsigned long _v) {((XKeyReleasedEvent *)_p)->time = (unsigned long)_v;}
static int get_XKeyReleasedEvent_x(void *_p) {return (int)((XKeyReleasedEvent *)_p)->x;}
static void set_XKeyReleasedEvent_x(void *_p, int _v) {((XKeyReleasedEvent *)_p)->x = (int)_v;}
static int get_XKeyReleasedEvent_y(void *_p) {return (int)((XKeyReleasedEvent *)_p)->y;}
static void set_XKeyReleasedEvent_y(void *_p, int _v) {((XKeyReleasedEvent *)_p)->y = (int)_v;}
static int get_XKeyReleasedEvent_x_root(void *_p) {return (int)((XKeyReleasedEvent *)_p)->x_root;}
static void set_XKeyReleasedEvent_x_root(void *_p, int _v) {((XKeyReleasedEvent *)_p)->x_root = (int)_v;}
static int get_XKeyReleasedEvent_y_root(void *_p) {return (int)((XKeyReleasedEvent *)_p)->y_root;}
static void set_XKeyReleasedEvent_y_root(void *_p, int _v) {((XKeyReleasedEvent *)_p)->y_root = (int)_v;}
static unsigned get_XKeyReleasedEvent_state(void *_p) {return (unsigned)((XKeyReleasedEvent *)_p)->state;}
static void set_XKeyReleasedEvent_state(void *_p, unsigned _v) {((XKeyReleasedEvent *)_p)->state = (unsigned)_v;}
static unsigned get_XKeyReleasedEvent_keycode(void *_p) {return (unsigned)((XKeyReleasedEvent *)_p)->keycode;}
static void set_XKeyReleasedEvent_keycode(void *_p, unsigned _v) {((XKeyReleasedEvent *)_p)->keycode = (unsigned)_v;}
static int get_XKeyReleasedEvent_same_screen(void *_p) {return (int)((XKeyReleasedEvent *)_p)->same_screen;}
static void set_XKeyReleasedEvent_same_screen(void *_p, int _v) {((XKeyReleasedEvent *)_p)->same_screen = (int)_v;}
static void *alloc_XKeyPressedEvent(void) {XKeyPressedEvent *_p = (XKeyPressedEvent *)malloc(sizeof(XKeyPressedEvent)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XKeyPressedEvent(void *_p) {if (_p==NULL) abort(); free((XKeyPressedEvent *)_p);}
static int get_XKeyPressedEvent_type(void *_p) {return (int)((XKeyPressedEvent *)_p)->type;}
static void set_XKeyPressedEvent_type(void *_p, int _v) {((XKeyPressedEvent *)_p)->type = (int)_v;}
static unsigned long get_XKeyPressedEvent_serial(void *_p) {return (unsigned long)((XKeyPressedEvent *)_p)->serial;}
static void set_XKeyPressedEvent_serial(void *_p, unsigned long _v) {((XKeyPressedEvent *)_p)->serial = (unsigned long)_v;}
static int get_XKeyPressedEvent_send_event(void *_p) {return (int)((XKeyPressedEvent *)_p)->send_event;}
static void set_XKeyPressedEvent_send_event(void *_p, int _v) {((XKeyPressedEvent *)_p)->send_event = (int)_v;}
static void *get_XKeyPressedEvent_display(void *_p) {return (void *)((XKeyPressedEvent *)_p)->display;}
static void set_XKeyPressedEvent_display(void *_p, void *_v) {((XKeyPressedEvent *)_p)->display = (Display *)_v;}
static unsigned long get_XKeyPressedEvent_window(void *_p) {return (unsigned long)((XKeyPressedEvent *)_p)->window;}
static void set_XKeyPressedEvent_window(void *_p, unsigned long _v) {((XKeyPressedEvent *)_p)->window = (unsigned long)_v;}
static unsigned long get_XKeyPressedEvent_root(void *_p) {return (unsigned long)((XKeyPressedEvent *)_p)->root;}
static void set_XKeyPressedEvent_root(void *_p, unsigned long _v) {((XKeyPressedEvent *)_p)->root = (unsigned long)_v;}
static unsigned long get_XKeyPressedEvent_subwindow(void *_p) {return (unsigned long)((XKeyPressedEvent *)_p)->subwindow;}
static void set_XKeyPressedEvent_subwindow(void *_p, unsigned long _v) {((XKeyPressedEvent *)_p)->subwindow = (unsigned long)_v;}
static unsigned long get_XKeyPressedEvent_time(void *_p) {return (unsigned long)((XKeyPressedEvent *)_p)->time;}
static void set_XKeyPressedEvent_time(void *_p, unsigned long _v) {((XKeyPressedEvent *)_p)->time = (unsigned long)_v;}
static int get_XKeyPressedEvent_x(void *_p) {return (int)((XKeyPressedEvent *)_p)->x;}
static void set_XKeyPressedEvent_x(void *_p, int _v) {((XKeyPressedEvent *)_p)->x = (int)_v;}
static int get_XKeyPressedEvent_y(void *_p) {return (int)((XKeyPressedEvent *)_p)->y;}
static void set_XKeyPressedEvent_y(void *_p, int _v) {((XKeyPressedEvent *)_p)->y = (int)_v;}
static int get_XKeyPressedEvent_x_root(void *_p) {return (int)((XKeyPressedEvent *)_p)->x_root;}
static void set_XKeyPressedEvent_x_root(void *_p, int _v) {((XKeyPressedEvent *)_p)->x_root = (int)_v;}
static int get_XKeyPressedEvent_y_root(void *_p) {return (int)((XKeyPressedEvent *)_p)->y_root;}
static void set_XKeyPressedEvent_y_root(void *_p, int _v) {((XKeyPressedEvent *)_p)->y_root = (int)_v;}
static unsigned get_XKeyPressedEvent_state(void *_p) {return (unsigned)((XKeyPressedEvent *)_p)->state;}
static void set_XKeyPressedEvent_state(void *_p, unsigned _v) {((XKeyPressedEvent *)_p)->state = (unsigned)_v;}
static unsigned get_XKeyPressedEvent_keycode(void *_p) {return (unsigned)((XKeyPressedEvent *)_p)->keycode;}
static void set_XKeyPressedEvent_keycode(void *_p, unsigned _v) {((XKeyPressedEvent *)_p)->keycode = (unsigned)_v;}
static int get_XKeyPressedEvent_same_screen(void *_p) {return (int)((XKeyPressedEvent *)_p)->same_screen;}
static void set_XKeyPressedEvent_same_screen(void *_p, int _v) {((XKeyPressedEvent *)_p)->same_screen = (int)_v;}
static void *alloc_XKeyEvent(void) {XKeyEvent *_p = (XKeyEvent *)malloc(sizeof(XKeyEvent)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XKeyEvent(void *_p) {if (_p==NULL) abort(); free((XKeyEvent *)_p);}
static int get_XKeyEvent_type(void *_p) {return (int)((XKeyEvent *)_p)->type;}
static void set_XKeyEvent_type(void *_p, int _v) {((XKeyEvent *)_p)->type = (int)_v;}
static unsigned long get_XKeyEvent_serial(void *_p) {return (unsigned long)((XKeyEvent *)_p)->serial;}
static void set_XKeyEvent_serial(void *_p, unsigned long _v) {((XKeyEvent *)_p)->serial = (unsigned long)_v;}
static int get_XKeyEvent_send_event(void *_p) {return (int)((XKeyEvent *)_p)->send_event;}
static void set_XKeyEvent_send_event(void *_p, int _v) {((XKeyEvent *)_p)->send_event = (int)_v;}
static void *get_XKeyEvent_display(void *_p) {return (void *)((XKeyEvent *)_p)->display;}
static void set_XKeyEvent_display(void *_p, void *_v) {((XKeyEvent *)_p)->display = (Display *)_v;}
static unsigned long get_XKeyEvent_window(void *_p) {return (unsigned long)((XKeyEvent *)_p)->window;}
static void set_XKeyEvent_window(void *_p, unsigned long _v) {((XKeyEvent *)_p)->window = (unsigned long)_v;}
static unsigned long get_XKeyEvent_root(void *_p) {return (unsigned long)((XKeyEvent *)_p)->root;}
static void set_XKeyEvent_root(void *_p, unsigned long _v) {((XKeyEvent *)_p)->root = (unsigned long)_v;}
static unsigned long get_XKeyEvent_subwindow(void *_p) {return (unsigned long)((XKeyEvent *)_p)->subwindow;}
static void set_XKeyEvent_subwindow(void *_p, unsigned long _v) {((XKeyEvent *)_p)->subwindow = (unsigned long)_v;}
static unsigned long get_XKeyEvent_time(void *_p) {return (unsigned long)((XKeyEvent *)_p)->time;}
static void set_XKeyEvent_time(void *_p, unsigned long _v) {((XKeyEvent *)_p)->time = (unsigned long)_v;}
static int get_XKeyEvent_x(void *_p) {return (int)((XKeyEvent *)_p)->x;}
static void set_XKeyEvent_x(void *_p, int _v) {((XKeyEvent *)_p)->x = (int)_v;}
static int get_XKeyEvent_y(void *_p) {return (int)((XKeyEvent *)_p)->y;}
static void set_XKeyEvent_y(void *_p, int _v) {((XKeyEvent *)_p)->y = (int)_v;}
static int get_XKeyEvent_x_root(void *_p) {return (int)((XKeyEvent *)_p)->x_root;}
static void set_XKeyEvent_x_root(void *_p, int _v) {((XKeyEvent *)_p)->x_root = (int)_v;}
static int get_XKeyEvent_y_root(void *_p) {return (int)((XKeyEvent *)_p)->y_root;}
static void set_XKeyEvent_y_root(void *_p, int _v) {((XKeyEvent *)_p)->y_root = (int)_v;}
static unsigned get_XKeyEvent_state(void *_p) {return (unsigned)((XKeyEvent *)_p)->state;}
static void set_XKeyEvent_state(void *_p, unsigned _v) {((XKeyEvent *)_p)->state = (unsigned)_v;}
static unsigned get_XKeyEvent_keycode(void *_p) {return (unsigned)((XKeyEvent *)_p)->keycode;}
static void set_XKeyEvent_keycode(void *_p, unsigned _v) {((XKeyEvent *)_p)->keycode = (unsigned)_v;}
static int get_XKeyEvent_same_screen(void *_p) {return (int)((XKeyEvent *)_p)->same_screen;}
static void set_XKeyEvent_same_screen(void *_p, int _v) {((XKeyEvent *)_p)->same_screen = (int)_v;}
static void *alloc_XButtonReleasedEvent(void) {XButtonReleasedEvent *_p = (XButtonReleasedEvent *)malloc(sizeof(XButtonReleasedEvent)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XButtonReleasedEvent(void *_p) {if (_p==NULL) abort(); free((XButtonReleasedEvent *)_p);}
static int get_XButtonReleasedEvent_type(void *_p) {return (int)((XButtonReleasedEvent *)_p)->type;}
static void set_XButtonReleasedEvent_type(void *_p, int _v) {((XButtonReleasedEvent *)_p)->type = (int)_v;}
static unsigned long get_XButtonReleasedEvent_serial(void *_p) {return (unsigned long)((XButtonReleasedEvent *)_p)->serial;}
static void set_XButtonReleasedEvent_serial(void *_p, unsigned long _v) {((XButtonReleasedEvent *)_p)->serial = (unsigned long)_v;}
static int get_XButtonReleasedEvent_send_event(void *_p) {return (int)((XButtonReleasedEvent *)_p)->send_event;}
static void set_XButtonReleasedEvent_send_event(void *_p, int _v) {((XButtonReleasedEvent *)_p)->send_event = (int)_v;}
static void *get_XButtonReleasedEvent_display(void *_p) {return (void *)((XButtonReleasedEvent *)_p)->display;}
static void set_XButtonReleasedEvent_display(void *_p, void *_v) {((XButtonReleasedEvent *)_p)->display = (Display *)_v;}
static unsigned long get_XButtonReleasedEvent_window(void *_p) {return (unsigned long)((XButtonReleasedEvent *)_p)->window;}
static void set_XButtonReleasedEvent_window(void *_p, unsigned long _v) {((XButtonReleasedEvent *)_p)->window = (unsigned long)_v;}
static unsigned long get_XButtonReleasedEvent_root(void *_p) {return (unsigned long)((XButtonReleasedEvent *)_p)->root;}
static void set_XButtonReleasedEvent_root(void *_p, unsigned long _v) {((XButtonReleasedEvent *)_p)->root = (unsigned long)_v;}
static unsigned long get_XButtonReleasedEvent_subwindow(void *_p) {return (unsigned long)((XButtonReleasedEvent *)_p)->subwindow;}
static void set_XButtonReleasedEvent_subwindow(void *_p, unsigned long _v) {((XButtonReleasedEvent *)_p)->subwindow = (unsigned long)_v;}
static unsigned long get_XButtonReleasedEvent_time(void *_p) {return (unsigned long)((XButtonReleasedEvent *)_p)->time;}
static void set_XButtonReleasedEvent_time(void *_p, unsigned long _v) {((XButtonReleasedEvent *)_p)->time = (unsigned long)_v;}
static int get_XButtonReleasedEvent_x(void *_p) {return (int)((XButtonReleasedEvent *)_p)->x;}
static void set_XButtonReleasedEvent_x(void *_p, int _v) {((XButtonReleasedEvent *)_p)->x = (int)_v;}
static int get_XButtonReleasedEvent_y(void *_p) {return (int)((XButtonReleasedEvent *)_p)->y;}
static void set_XButtonReleasedEvent_y(void *_p, int _v) {((XButtonReleasedEvent *)_p)->y = (int)_v;}
static int get_XButtonReleasedEvent_x_root(void *_p) {return (int)((XButtonReleasedEvent *)_p)->x_root;}
static void set_XButtonReleasedEvent_x_root(void *_p, int _v) {((XButtonReleasedEvent *)_p)->x_root = (int)_v;}
static int get_XButtonReleasedEvent_y_root(void *_p) {return (int)((XButtonReleasedEvent *)_p)->y_root;}
static void set_XButtonReleasedEvent_y_root(void *_p, int _v) {((XButtonReleasedEvent *)_p)->y_root = (int)_v;}
static unsigned get_XButtonReleasedEvent_state(void *_p) {return (unsigned)((XButtonReleasedEvent *)_p)->state;}
static void set_XButtonReleasedEvent_state(void *_p, unsigned _v) {((XButtonReleasedEvent *)_p)->state = (unsigned)_v;}
static unsigned get_XButtonReleasedEvent_button(void *_p) {return (unsigned)((XButtonReleasedEvent *)_p)->button;}
static void set_XButtonReleasedEvent_button(void *_p, unsigned _v) {((XButtonReleasedEvent *)_p)->button = (unsigned)_v;}
static int get_XButtonReleasedEvent_same_screen(void *_p) {return (int)((XButtonReleasedEvent *)_p)->same_screen;}
static void set_XButtonReleasedEvent_same_screen(void *_p, int _v) {((XButtonReleasedEvent *)_p)->same_screen = (int)_v;}
static void *alloc_XButtonPressedEvent(void) {XButtonPressedEvent *_p = (XButtonPressedEvent *)malloc(sizeof(XButtonPressedEvent)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XButtonPressedEvent(void *_p) {if (_p==NULL) abort(); free((XButtonPressedEvent *)_p);}
static int get_XButtonPressedEvent_type(void *_p) {return (int)((XButtonPressedEvent *)_p)->type;}
static void set_XButtonPressedEvent_type(void *_p, int _v) {((XButtonPressedEvent *)_p)->type = (int)_v;}
static unsigned long get_XButtonPressedEvent_serial(void *_p) {return (unsigned long)((XButtonPressedEvent *)_p)->serial;}
static void set_XButtonPressedEvent_serial(void *_p, unsigned long _v) {((XButtonPressedEvent *)_p)->serial = (unsigned long)_v;}
static int get_XButtonPressedEvent_send_event(void *_p) {return (int)((XButtonPressedEvent *)_p)->send_event;}
static void set_XButtonPressedEvent_send_event(void *_p, int _v) {((XButtonPressedEvent *)_p)->send_event = (int)_v;}
static void *get_XButtonPressedEvent_display(void *_p) {return (void *)((XButtonPressedEvent *)_p)->display;}
static void set_XButtonPressedEvent_display(void *_p, void *_v) {((XButtonPressedEvent *)_p)->display = (Display *)_v;}
static unsigned long get_XButtonPressedEvent_window(void *_p) {return (unsigned long)((XButtonPressedEvent *)_p)->window;}
static void set_XButtonPressedEvent_window(void *_p, unsigned long _v) {((XButtonPressedEvent *)_p)->window = (unsigned long)_v;}
static unsigned long get_XButtonPressedEvent_root(void *_p) {return (unsigned long)((XButtonPressedEvent *)_p)->root;}
static void set_XButtonPressedEvent_root(void *_p, unsigned long _v) {((XButtonPressedEvent *)_p)->root = (unsigned long)_v;}
static unsigned long get_XButtonPressedEvent_subwindow(void *_p) {return (unsigned long)((XButtonPressedEvent *)_p)->subwindow;}
static void set_XButtonPressedEvent_subwindow(void *_p, unsigned long _v) {((XButtonPressedEvent *)_p)->subwindow = (unsigned long)_v;}
static unsigned long get_XButtonPressedEvent_time(void *_p) {return (unsigned long)((XButtonPressedEvent *)_p)->time;}
static void set_XButtonPressedEvent_time(void *_p, unsigned long _v) {((XButtonPressedEvent *)_p)->time = (unsigned long)_v;}
static int get_XButtonPressedEvent_x(void *_p) {return (int)((XButtonPressedEvent *)_p)->x;}
static void set_XButtonPressedEvent_x(void *_p, int _v) {((XButtonPressedEvent *)_p)->x = (int)_v;}
static int get_XButtonPressedEvent_y(void *_p) {return (int)((XButtonPressedEvent *)_p)->y;}
static void set_XButtonPressedEvent_y(void *_p, int _v) {((XButtonPressedEvent *)_p)->y = (int)_v;}
static int get_XButtonPressedEvent_x_root(void *_p) {return (int)((XButtonPressedEvent *)_p)->x_root;}
static void set_XButtonPressedEvent_x_root(void *_p, int _v) {((XButtonPressedEvent *)_p)->x_root = (int)_v;}
static int get_XButtonPressedEvent_y_root(void *_p) {return (int)((XButtonPressedEvent *)_p)->y_root;}
static void set_XButtonPressedEvent_y_root(void *_p, int _v) {((XButtonPressedEvent *)_p)->y_root = (int)_v;}
static unsigned get_XButtonPressedEvent_state(void *_p) {return (unsigned)((XButtonPressedEvent *)_p)->state;}
static void set_XButtonPressedEvent_state(void *_p, unsigned _v) {((XButtonPressedEvent *)_p)->state = (unsigned)_v;}
static unsigned get_XButtonPressedEvent_button(void *_p) {return (unsigned)((XButtonPressedEvent *)_p)->button;}
static void set_XButtonPressedEvent_button(void *_p, unsigned _v) {((XButtonPressedEvent *)_p)->button = (unsigned)_v;}
static int get_XButtonPressedEvent_same_screen(void *_p) {return (int)((XButtonPressedEvent *)_p)->same_screen;}
static void set_XButtonPressedEvent_same_screen(void *_p, int _v) {((XButtonPressedEvent *)_p)->same_screen = (int)_v;}
static void *alloc_XButtonEvent(void) {XButtonEvent *_p = (XButtonEvent *)malloc(sizeof(XButtonEvent)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XButtonEvent(void *_p) {if (_p==NULL) abort(); free((XButtonEvent *)_p);}
static int get_XButtonEvent_type(void *_p) {return (int)((XButtonEvent *)_p)->type;}
static void set_XButtonEvent_type(void *_p, int _v) {((XButtonEvent *)_p)->type = (int)_v;}
static unsigned long get_XButtonEvent_serial(void *_p) {return (unsigned long)((XButtonEvent *)_p)->serial;}
static void set_XButtonEvent_serial(void *_p, unsigned long _v) {((XButtonEvent *)_p)->serial = (unsigned long)_v;}
static int get_XButtonEvent_send_event(void *_p) {return (int)((XButtonEvent *)_p)->send_event;}
static void set_XButtonEvent_send_event(void *_p, int _v) {((XButtonEvent *)_p)->send_event = (int)_v;}
static void *get_XButtonEvent_display(void *_p) {return (void *)((XButtonEvent *)_p)->display;}
static void set_XButtonEvent_display(void *_p, void *_v) {((XButtonEvent *)_p)->display = (Display *)_v;}
static unsigned long get_XButtonEvent_window(void *_p) {return (unsigned long)((XButtonEvent *)_p)->window;}
static void set_XButtonEvent_window(void *_p, unsigned long _v) {((XButtonEvent *)_p)->window = (unsigned long)_v;}
static unsigned long get_XButtonEvent_root(void *_p) {return (unsigned long)((XButtonEvent *)_p)->root;}
static void set_XButtonEvent_root(void *_p, unsigned long _v) {((XButtonEvent *)_p)->root = (unsigned long)_v;}
static unsigned long get_XButtonEvent_subwindow(void *_p) {return (unsigned long)((XButtonEvent *)_p)->subwindow;}
static void set_XButtonEvent_subwindow(void *_p, unsigned long _v) {((XButtonEvent *)_p)->subwindow = (unsigned long)_v;}
static unsigned long get_XButtonEvent_time(void *_p) {return (unsigned long)((XButtonEvent *)_p)->time;}
static void set_XButtonEvent_time(void *_p, unsigned long _v) {((XButtonEvent *)_p)->time = (unsigned long)_v;}
static int get_XButtonEvent_x(void *_p) {return (int)((XButtonEvent *)_p)->x;}
static void set_XButtonEvent_x(void *_p, int _v) {((XButtonEvent *)_p)->x = (int)_v;}
static int get_XButtonEvent_y(void *_p) {return (int)((XButtonEvent *)_p)->y;}
static void set_XButtonEvent_y(void *_p, int _v) {((XButtonEvent *)_p)->y = (int)_v;}
static int get_XButtonEvent_x_root(void *_p) {return (int)((XButtonEvent *)_p)->x_root;}
static void set_XButtonEvent_x_root(void *_p, int _v) {((XButtonEvent *)_p)->x_root = (int)_v;}
static int get_XButtonEvent_y_root(void *_p) {return (int)((XButtonEvent *)_p)->y_root;}
static void set_XButtonEvent_y_root(void *_p, int _v) {((XButtonEvent *)_p)->y_root = (int)_v;}
static unsigned get_XButtonEvent_state(void *_p) {return (unsigned)((XButtonEvent *)_p)->state;}
static void set_XButtonEvent_state(void *_p, unsigned _v) {((XButtonEvent *)_p)->state = (unsigned)_v;}
static unsigned get_XButtonEvent_button(void *_p) {return (unsigned)((XButtonEvent *)_p)->button;}
static void set_XButtonEvent_button(void *_p, unsigned _v) {((XButtonEvent *)_p)->button = (unsigned)_v;}
static int get_XButtonEvent_same_screen(void *_p) {return (int)((XButtonEvent *)_p)->same_screen;}
static void set_XButtonEvent_same_screen(void *_p, int _v) {((XButtonEvent *)_p)->same_screen = (int)_v;}
static void *alloc_XPointerMovedEvent(void) {XPointerMovedEvent *_p = (XPointerMovedEvent *)malloc(sizeof(XPointerMovedEvent)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XPointerMovedEvent(void *_p) {if (_p==NULL) abort(); free((XPointerMovedEvent *)_p);}
static int get_XPointerMovedEvent_type(void *_p) {return (int)((XPointerMovedEvent *)_p)->type;}
static void set_XPointerMovedEvent_type(void *_p, int _v) {((XPointerMovedEvent *)_p)->type = (int)_v;}
static unsigned long get_XPointerMovedEvent_serial(void *_p) {return (unsigned long)((XPointerMovedEvent *)_p)->serial;}
static void set_XPointerMovedEvent_serial(void *_p, unsigned long _v) {((XPointerMovedEvent *)_p)->serial = (unsigned long)_v;}
static int get_XPointerMovedEvent_send_event(void *_p) {return (int)((XPointerMovedEvent *)_p)->send_event;}
static void set_XPointerMovedEvent_send_event(void *_p, int _v) {((XPointerMovedEvent *)_p)->send_event = (int)_v;}
static void *get_XPointerMovedEvent_display(void *_p) {return (void *)((XPointerMovedEvent *)_p)->display;}
static void set_XPointerMovedEvent_display(void *_p, void *_v) {((XPointerMovedEvent *)_p)->display = (Display *)_v;}
static unsigned long get_XPointerMovedEvent_window(void *_p) {return (unsigned long)((XPointerMovedEvent *)_p)->window;}
static void set_XPointerMovedEvent_window(void *_p, unsigned long _v) {((XPointerMovedEvent *)_p)->window = (unsigned long)_v;}
static unsigned long get_XPointerMovedEvent_root(void *_p) {return (unsigned long)((XPointerMovedEvent *)_p)->root;}
static void set_XPointerMovedEvent_root(void *_p, unsigned long _v) {((XPointerMovedEvent *)_p)->root = (unsigned long)_v;}
static unsigned long get_XPointerMovedEvent_subwindow(void *_p) {return (unsigned long)((XPointerMovedEvent *)_p)->subwindow;}
static void set_XPointerMovedEvent_subwindow(void *_p, unsigned long _v) {((XPointerMovedEvent *)_p)->subwindow = (unsigned long)_v;}
static unsigned long get_XPointerMovedEvent_time(void *_p) {return (unsigned long)((XPointerMovedEvent *)_p)->time;}
static void set_XPointerMovedEvent_time(void *_p, unsigned long _v) {((XPointerMovedEvent *)_p)->time = (unsigned long)_v;}
static int get_XPointerMovedEvent_x(void *_p) {return (int)((XPointerMovedEvent *)_p)->x;}
static void set_XPointerMovedEvent_x(void *_p, int _v) {((XPointerMovedEvent *)_p)->x = (int)_v;}
static int get_XPointerMovedEvent_y(void *_p) {return (int)((XPointerMovedEvent *)_p)->y;}
static void set_XPointerMovedEvent_y(void *_p, int _v) {((XPointerMovedEvent *)_p)->y = (int)_v;}
static int get_XPointerMovedEvent_x_root(void *_p) {return (int)((XPointerMovedEvent *)_p)->x_root;}
static void set_XPointerMovedEvent_x_root(void *_p, int _v) {((XPointerMovedEvent *)_p)->x_root = (int)_v;}
static int get_XPointerMovedEvent_y_root(void *_p) {return (int)((XPointerMovedEvent *)_p)->y_root;}
static void set_XPointerMovedEvent_y_root(void *_p, int _v) {((XPointerMovedEvent *)_p)->y_root = (int)_v;}
static unsigned get_XPointerMovedEvent_state(void *_p) {return (unsigned)((XPointerMovedEvent *)_p)->state;}
static void set_XPointerMovedEvent_state(void *_p, unsigned _v) {((XPointerMovedEvent *)_p)->state = (unsigned)_v;}
static char get_XPointerMovedEvent_is_hint(void *_p) {return (char)((XPointerMovedEvent *)_p)->is_hint;}
static void set_XPointerMovedEvent_is_hint(void *_p, char _v) {((XPointerMovedEvent *)_p)->is_hint = (char)_v;}
static int get_XPointerMovedEvent_same_screen(void *_p) {return (int)((XPointerMovedEvent *)_p)->same_screen;}
static void set_XPointerMovedEvent_same_screen(void *_p, int _v) {((XPointerMovedEvent *)_p)->same_screen = (int)_v;}
static void *alloc_XMotionEvent(void) {XMotionEvent *_p = (XMotionEvent *)malloc(sizeof(XMotionEvent)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XMotionEvent(void *_p) {if (_p==NULL) abort(); free((XMotionEvent *)_p);}
static int get_XMotionEvent_type(void *_p) {return (int)((XMotionEvent *)_p)->type;}
static void set_XMotionEvent_type(void *_p, int _v) {((XMotionEvent *)_p)->type = (int)_v;}
static unsigned long get_XMotionEvent_serial(void *_p) {return (unsigned long)((XMotionEvent *)_p)->serial;}
static void set_XMotionEvent_serial(void *_p, unsigned long _v) {((XMotionEvent *)_p)->serial = (unsigned long)_v;}
static int get_XMotionEvent_send_event(void *_p) {return (int)((XMotionEvent *)_p)->send_event;}
static void set_XMotionEvent_send_event(void *_p, int _v) {((XMotionEvent *)_p)->send_event = (int)_v;}
static void *get_XMotionEvent_display(void *_p) {return (void *)((XMotionEvent *)_p)->display;}
static void set_XMotionEvent_display(void *_p, void *_v) {((XMotionEvent *)_p)->display = (Display *)_v;}
static unsigned long get_XMotionEvent_window(void *_p) {return (unsigned long)((XMotionEvent *)_p)->window;}
static void set_XMotionEvent_window(void *_p, unsigned long _v) {((XMotionEvent *)_p)->window = (unsigned long)_v;}
static unsigned long get_XMotionEvent_root(void *_p) {return (unsigned long)((XMotionEvent *)_p)->root;}
static void set_XMotionEvent_root(void *_p, unsigned long _v) {((XMotionEvent *)_p)->root = (unsigned long)_v;}
static unsigned long get_XMotionEvent_subwindow(void *_p) {return (unsigned long)((XMotionEvent *)_p)->subwindow;}
static void set_XMotionEvent_subwindow(void *_p, unsigned long _v) {((XMotionEvent *)_p)->subwindow = (unsigned long)_v;}
static unsigned long get_XMotionEvent_time(void *_p) {return (unsigned long)((XMotionEvent *)_p)->time;}
static void set_XMotionEvent_time(void *_p, unsigned long _v) {((XMotionEvent *)_p)->time = (unsigned long)_v;}
static int get_XMotionEvent_x(void *_p) {return (int)((XMotionEvent *)_p)->x;}
static void set_XMotionEvent_x(void *_p, int _v) {((XMotionEvent *)_p)->x = (int)_v;}
static int get_XMotionEvent_y(void *_p) {return (int)((XMotionEvent *)_p)->y;}
static void set_XMotionEvent_y(void *_p, int _v) {((XMotionEvent *)_p)->y = (int)_v;}
static int get_XMotionEvent_x_root(void *_p) {return (int)((XMotionEvent *)_p)->x_root;}
static void set_XMotionEvent_x_root(void *_p, int _v) {((XMotionEvent *)_p)->x_root = (int)_v;}
static int get_XMotionEvent_y_root(void *_p) {return (int)((XMotionEvent *)_p)->y_root;}
static void set_XMotionEvent_y_root(void *_p, int _v) {((XMotionEvent *)_p)->y_root = (int)_v;}
static unsigned get_XMotionEvent_state(void *_p) {return (unsigned)((XMotionEvent *)_p)->state;}
static void set_XMotionEvent_state(void *_p, unsigned _v) {((XMotionEvent *)_p)->state = (unsigned)_v;}
static char get_XMotionEvent_is_hint(void *_p) {return (char)((XMotionEvent *)_p)->is_hint;}
static void set_XMotionEvent_is_hint(void *_p, char _v) {((XMotionEvent *)_p)->is_hint = (char)_v;}
static int get_XMotionEvent_same_screen(void *_p) {return (int)((XMotionEvent *)_p)->same_screen;}
static void set_XMotionEvent_same_screen(void *_p, int _v) {((XMotionEvent *)_p)->same_screen = (int)_v;}
static void *alloc_XLeaveWindowEvent(void) {XLeaveWindowEvent *_p = (XLeaveWindowEvent *)malloc(sizeof(XLeaveWindowEvent)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XLeaveWindowEvent(void *_p) {if (_p==NULL) abort(); free((XLeaveWindowEvent *)_p);}
static int get_XLeaveWindowEvent_type(void *_p) {return (int)((XLeaveWindowEvent *)_p)->type;}
static void set_XLeaveWindowEvent_type(void *_p, int _v) {((XLeaveWindowEvent *)_p)->type = (int)_v;}
static unsigned long get_XLeaveWindowEvent_serial(void *_p) {return (unsigned long)((XLeaveWindowEvent *)_p)->serial;}
static void set_XLeaveWindowEvent_serial(void *_p, unsigned long _v) {((XLeaveWindowEvent *)_p)->serial = (unsigned long)_v;}
static int get_XLeaveWindowEvent_send_event(void *_p) {return (int)((XLeaveWindowEvent *)_p)->send_event;}
static void set_XLeaveWindowEvent_send_event(void *_p, int _v) {((XLeaveWindowEvent *)_p)->send_event = (int)_v;}
static void *get_XLeaveWindowEvent_display(void *_p) {return (void *)((XLeaveWindowEvent *)_p)->display;}
static void set_XLeaveWindowEvent_display(void *_p, void *_v) {((XLeaveWindowEvent *)_p)->display = (Display *)_v;}
static unsigned long get_XLeaveWindowEvent_window(void *_p) {return (unsigned long)((XLeaveWindowEvent *)_p)->window;}
static void set_XLeaveWindowEvent_window(void *_p, unsigned long _v) {((XLeaveWindowEvent *)_p)->window = (unsigned long)_v;}
static unsigned long get_XLeaveWindowEvent_root(void *_p) {return (unsigned long)((XLeaveWindowEvent *)_p)->root;}
static void set_XLeaveWindowEvent_root(void *_p, unsigned long _v) {((XLeaveWindowEvent *)_p)->root = (unsigned long)_v;}
static unsigned long get_XLeaveWindowEvent_subwindow(void *_p) {return (unsigned long)((XLeaveWindowEvent *)_p)->subwindow;}
static void set_XLeaveWindowEvent_subwindow(void *_p, unsigned long _v) {((XLeaveWindowEvent *)_p)->subwindow = (unsigned long)_v;}
static unsigned long get_XLeaveWindowEvent_time(void *_p) {return (unsigned long)((XLeaveWindowEvent *)_p)->time;}
static void set_XLeaveWindowEvent_time(void *_p, unsigned long _v) {((XLeaveWindowEvent *)_p)->time = (unsigned long)_v;}
static int get_XLeaveWindowEvent_x(void *_p) {return (int)((XLeaveWindowEvent *)_p)->x;}
static void set_XLeaveWindowEvent_x(void *_p, int _v) {((XLeaveWindowEvent *)_p)->x = (int)_v;}
static int get_XLeaveWindowEvent_y(void *_p) {return (int)((XLeaveWindowEvent *)_p)->y;}
static void set_XLeaveWindowEvent_y(void *_p, int _v) {((XLeaveWindowEvent *)_p)->y = (int)_v;}
static int get_XLeaveWindowEvent_x_root(void *_p) {return (int)((XLeaveWindowEvent *)_p)->x_root;}
static void set_XLeaveWindowEvent_x_root(void *_p, int _v) {((XLeaveWindowEvent *)_p)->x_root = (int)_v;}
static int get_XLeaveWindowEvent_y_root(void *_p) {return (int)((XLeaveWindowEvent *)_p)->y_root;}
static void set_XLeaveWindowEvent_y_root(void *_p, int _v) {((XLeaveWindowEvent *)_p)->y_root = (int)_v;}
static int get_XLeaveWindowEvent_mode(void *_p) {return (int)((XLeaveWindowEvent *)_p)->mode;}
static void set_XLeaveWindowEvent_mode(void *_p, int _v) {((XLeaveWindowEvent *)_p)->mode = (int)_v;}
static int get_XLeaveWindowEvent_detail(void *_p) {return (int)((XLeaveWindowEvent *)_p)->detail;}
static void set_XLeaveWindowEvent_detail(void *_p, int _v) {((XLeaveWindowEvent *)_p)->detail = (int)_v;}
static int get_XLeaveWindowEvent_same_screen(void *_p) {return (int)((XLeaveWindowEvent *)_p)->same_screen;}
static void set_XLeaveWindowEvent_same_screen(void *_p, int _v) {((XLeaveWindowEvent *)_p)->same_screen = (int)_v;}
static int get_XLeaveWindowEvent_focus(void *_p) {return (int)((XLeaveWindowEvent *)_p)->focus;}
static void set_XLeaveWindowEvent_focus(void *_p, int _v) {((XLeaveWindowEvent *)_p)->focus = (int)_v;}
static unsigned get_XLeaveWindowEvent_state(void *_p) {return (unsigned)((XLeaveWindowEvent *)_p)->state;}
static void set_XLeaveWindowEvent_state(void *_p, unsigned _v) {((XLeaveWindowEvent *)_p)->state = (unsigned)_v;}
static void *alloc_XEnterWindowEvent(void) {XEnterWindowEvent *_p = (XEnterWindowEvent *)malloc(sizeof(XEnterWindowEvent)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XEnterWindowEvent(void *_p) {if (_p==NULL) abort(); free((XEnterWindowEvent *)_p);}
static int get_XEnterWindowEvent_type(void *_p) {return (int)((XEnterWindowEvent *)_p)->type;}
static void set_XEnterWindowEvent_type(void *_p, int _v) {((XEnterWindowEvent *)_p)->type = (int)_v;}
static unsigned long get_XEnterWindowEvent_serial(void *_p) {return (unsigned long)((XEnterWindowEvent *)_p)->serial;}
static void set_XEnterWindowEvent_serial(void *_p, unsigned long _v) {((XEnterWindowEvent *)_p)->serial = (unsigned long)_v;}
static int get_XEnterWindowEvent_send_event(void *_p) {return (int)((XEnterWindowEvent *)_p)->send_event;}
static void set_XEnterWindowEvent_send_event(void *_p, int _v) {((XEnterWindowEvent *)_p)->send_event = (int)_v;}
static void *get_XEnterWindowEvent_display(void *_p) {return (void *)((XEnterWindowEvent *)_p)->display;}
static void set_XEnterWindowEvent_display(void *_p, void *_v) {((XEnterWindowEvent *)_p)->display = (Display *)_v;}
static unsigned long get_XEnterWindowEvent_window(void *_p) {return (unsigned long)((XEnterWindowEvent *)_p)->window;}
static void set_XEnterWindowEvent_window(void *_p, unsigned long _v) {((XEnterWindowEvent *)_p)->window = (unsigned long)_v;}
static unsigned long get_XEnterWindowEvent_root(void *_p) {return (unsigned long)((XEnterWindowEvent *)_p)->root;}
static void set_XEnterWindowEvent_root(void *_p, unsigned long _v) {((XEnterWindowEvent *)_p)->root = (unsigned long)_v;}
static unsigned long get_XEnterWindowEvent_subwindow(void *_p) {return (unsigned long)((XEnterWindowEvent *)_p)->subwindow;}
static void set_XEnterWindowEvent_subwindow(void *_p, unsigned long _v) {((XEnterWindowEvent *)_p)->subwindow = (unsigned long)_v;}
static unsigned long get_XEnterWindowEvent_time(void *_p) {return (unsigned long)((XEnterWindowEvent *)_p)->time;}
static void set_XEnterWindowEvent_time(void *_p, unsigned long _v) {((XEnterWindowEvent *)_p)->time = (unsigned long)_v;}
static int get_XEnterWindowEvent_x(void *_p) {return (int)((XEnterWindowEvent *)_p)->x;}
static void set_XEnterWindowEvent_x(void *_p, int _v) {((XEnterWindowEvent *)_p)->x = (int)_v;}
static int get_XEnterWindowEvent_y(void *_p) {return (int)((XEnterWindowEvent *)_p)->y;}
static void set_XEnterWindowEvent_y(void *_p, int _v) {((XEnterWindowEvent *)_p)->y = (int)_v;}
static int get_XEnterWindowEvent_x_root(void *_p) {return (int)((XEnterWindowEvent *)_p)->x_root;}
static void set_XEnterWindowEvent_x_root(void *_p, int _v) {((XEnterWindowEvent *)_p)->x_root = (int)_v;}
static int get_XEnterWindowEvent_y_root(void *_p) {return (int)((XEnterWindowEvent *)_p)->y_root;}
static void set_XEnterWindowEvent_y_root(void *_p, int _v) {((XEnterWindowEvent *)_p)->y_root = (int)_v;}
static int get_XEnterWindowEvent_mode(void *_p) {return (int)((XEnterWindowEvent *)_p)->mode;}
static void set_XEnterWindowEvent_mode(void *_p, int _v) {((XEnterWindowEvent *)_p)->mode = (int)_v;}
static int get_XEnterWindowEvent_detail(void *_p) {return (int)((XEnterWindowEvent *)_p)->detail;}
static void set_XEnterWindowEvent_detail(void *_p, int _v) {((XEnterWindowEvent *)_p)->detail = (int)_v;}
static int get_XEnterWindowEvent_same_screen(void *_p) {return (int)((XEnterWindowEvent *)_p)->same_screen;}
static void set_XEnterWindowEvent_same_screen(void *_p, int _v) {((XEnterWindowEvent *)_p)->same_screen = (int)_v;}
static int get_XEnterWindowEvent_focus(void *_p) {return (int)((XEnterWindowEvent *)_p)->focus;}
static void set_XEnterWindowEvent_focus(void *_p, int _v) {((XEnterWindowEvent *)_p)->focus = (int)_v;}
static unsigned get_XEnterWindowEvent_state(void *_p) {return (unsigned)((XEnterWindowEvent *)_p)->state;}
static void set_XEnterWindowEvent_state(void *_p, unsigned _v) {((XEnterWindowEvent *)_p)->state = (unsigned)_v;}
static void *alloc_XCrossingEvent(void) {XCrossingEvent *_p = (XCrossingEvent *)malloc(sizeof(XCrossingEvent)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XCrossingEvent(void *_p) {if (_p==NULL) abort(); free((XCrossingEvent *)_p);}
static int get_XCrossingEvent_type(void *_p) {return (int)((XCrossingEvent *)_p)->type;}
static void set_XCrossingEvent_type(void *_p, int _v) {((XCrossingEvent *)_p)->type = (int)_v;}
static unsigned long get_XCrossingEvent_serial(void *_p) {return (unsigned long)((XCrossingEvent *)_p)->serial;}
static void set_XCrossingEvent_serial(void *_p, unsigned long _v) {((XCrossingEvent *)_p)->serial = (unsigned long)_v;}
static int get_XCrossingEvent_send_event(void *_p) {return (int)((XCrossingEvent *)_p)->send_event;}
static void set_XCrossingEvent_send_event(void *_p, int _v) {((XCrossingEvent *)_p)->send_event = (int)_v;}
static void *get_XCrossingEvent_display(void *_p) {return (void *)((XCrossingEvent *)_p)->display;}
static void set_XCrossingEvent_display(void *_p, void *_v) {((XCrossingEvent *)_p)->display = (Display *)_v;}
static unsigned long get_XCrossingEvent_window(void *_p) {return (unsigned long)((XCrossingEvent *)_p)->window;}
static void set_XCrossingEvent_window(void *_p, unsigned long _v) {((XCrossingEvent *)_p)->window = (unsigned long)_v;}
static unsigned long get_XCrossingEvent_root(void *_p) {return (unsigned long)((XCrossingEvent *)_p)->root;}
static void set_XCrossingEvent_root(void *_p, unsigned long _v) {((XCrossingEvent *)_p)->root = (unsigned long)_v;}
static unsigned long get_XCrossingEvent_subwindow(void *_p) {return (unsigned long)((XCrossingEvent *)_p)->subwindow;}
static void set_XCrossingEvent_subwindow(void *_p, unsigned long _v) {((XCrossingEvent *)_p)->subwindow = (unsigned long)_v;}
static unsigned long get_XCrossingEvent_time(void *_p) {return (unsigned long)((XCrossingEvent *)_p)->time;}
static void set_XCrossingEvent_time(void *_p, unsigned long _v) {((XCrossingEvent *)_p)->time = (unsigned long)_v;}
static int get_XCrossingEvent_x(void *_p) {return (int)((XCrossingEvent *)_p)->x;}
static void set_XCrossingEvent_x(void *_p, int _v) {((XCrossingEvent *)_p)->x = (int)_v;}
static int get_XCrossingEvent_y(void *_p) {return (int)((XCrossingEvent *)_p)->y;}
static void set_XCrossingEvent_y(void *_p, int _v) {((XCrossingEvent *)_p)->y = (int)_v;}
static int get_XCrossingEvent_x_root(void *_p) {return (int)((XCrossingEvent *)_p)->x_root;}
static void set_XCrossingEvent_x_root(void *_p, int _v) {((XCrossingEvent *)_p)->x_root = (int)_v;}
static int get_XCrossingEvent_y_root(void *_p) {return (int)((XCrossingEvent *)_p)->y_root;}
static void set_XCrossingEvent_y_root(void *_p, int _v) {((XCrossingEvent *)_p)->y_root = (int)_v;}
static int get_XCrossingEvent_mode(void *_p) {return (int)((XCrossingEvent *)_p)->mode;}
static void set_XCrossingEvent_mode(void *_p, int _v) {((XCrossingEvent *)_p)->mode = (int)_v;}
static int get_XCrossingEvent_detail(void *_p) {return (int)((XCrossingEvent *)_p)->detail;}
static void set_XCrossingEvent_detail(void *_p, int _v) {((XCrossingEvent *)_p)->detail = (int)_v;}
static int get_XCrossingEvent_same_screen(void *_p) {return (int)((XCrossingEvent *)_p)->same_screen;}
static void set_XCrossingEvent_same_screen(void *_p, int _v) {((XCrossingEvent *)_p)->same_screen = (int)_v;}
static int get_XCrossingEvent_focus(void *_p) {return (int)((XCrossingEvent *)_p)->focus;}
static void set_XCrossingEvent_focus(void *_p, int _v) {((XCrossingEvent *)_p)->focus = (int)_v;}
static unsigned get_XCrossingEvent_state(void *_p) {return (unsigned)((XCrossingEvent *)_p)->state;}
static void set_XCrossingEvent_state(void *_p, unsigned _v) {((XCrossingEvent *)_p)->state = (unsigned)_v;}
static void *alloc_XFocusOutEvent(void) {XFocusOutEvent *_p = (XFocusOutEvent *)malloc(sizeof(XFocusOutEvent)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XFocusOutEvent(void *_p) {if (_p==NULL) abort(); free((XFocusOutEvent *)_p);}
static int get_XFocusOutEvent_type(void *_p) {return (int)((XFocusOutEvent *)_p)->type;}
static void set_XFocusOutEvent_type(void *_p, int _v) {((XFocusOutEvent *)_p)->type = (int)_v;}
static unsigned long get_XFocusOutEvent_serial(void *_p) {return (unsigned long)((XFocusOutEvent *)_p)->serial;}
static void set_XFocusOutEvent_serial(void *_p, unsigned long _v) {((XFocusOutEvent *)_p)->serial = (unsigned long)_v;}
static int get_XFocusOutEvent_send_event(void *_p) {return (int)((XFocusOutEvent *)_p)->send_event;}
static void set_XFocusOutEvent_send_event(void *_p, int _v) {((XFocusOutEvent *)_p)->send_event = (int)_v;}
static void *get_XFocusOutEvent_display(void *_p) {return (void *)((XFocusOutEvent *)_p)->display;}
static void set_XFocusOutEvent_display(void *_p, void *_v) {((XFocusOutEvent *)_p)->display = (Display *)_v;}
static unsigned long get_XFocusOutEvent_window(void *_p) {return (unsigned long)((XFocusOutEvent *)_p)->window;}
static void set_XFocusOutEvent_window(void *_p, unsigned long _v) {((XFocusOutEvent *)_p)->window = (unsigned long)_v;}
static int get_XFocusOutEvent_mode(void *_p) {return (int)((XFocusOutEvent *)_p)->mode;}
static void set_XFocusOutEvent_mode(void *_p, int _v) {((XFocusOutEvent *)_p)->mode = (int)_v;}
static int get_XFocusOutEvent_detail(void *_p) {return (int)((XFocusOutEvent *)_p)->detail;}
static void set_XFocusOutEvent_detail(void *_p, int _v) {((XFocusOutEvent *)_p)->detail = (int)_v;}
static void *alloc_XFocusInEvent(void) {XFocusInEvent *_p = (XFocusInEvent *)malloc(sizeof(XFocusInEvent)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XFocusInEvent(void *_p) {if (_p==NULL) abort(); free((XFocusInEvent *)_p);}
static int get_XFocusInEvent_type(void *_p) {return (int)((XFocusInEvent *)_p)->type;}
static void set_XFocusInEvent_type(void *_p, int _v) {((XFocusInEvent *)_p)->type = (int)_v;}
static unsigned long get_XFocusInEvent_serial(void *_p) {return (unsigned long)((XFocusInEvent *)_p)->serial;}
static void set_XFocusInEvent_serial(void *_p, unsigned long _v) {((XFocusInEvent *)_p)->serial = (unsigned long)_v;}
static int get_XFocusInEvent_send_event(void *_p) {return (int)((XFocusInEvent *)_p)->send_event;}
static void set_XFocusInEvent_send_event(void *_p, int _v) {((XFocusInEvent *)_p)->send_event = (int)_v;}
static void *get_XFocusInEvent_display(void *_p) {return (void *)((XFocusInEvent *)_p)->display;}
static void set_XFocusInEvent_display(void *_p, void *_v) {((XFocusInEvent *)_p)->display = (Display *)_v;}
static unsigned long get_XFocusInEvent_window(void *_p) {return (unsigned long)((XFocusInEvent *)_p)->window;}
static void set_XFocusInEvent_window(void *_p, unsigned long _v) {((XFocusInEvent *)_p)->window = (unsigned long)_v;}
static int get_XFocusInEvent_mode(void *_p) {return (int)((XFocusInEvent *)_p)->mode;}
static void set_XFocusInEvent_mode(void *_p, int _v) {((XFocusInEvent *)_p)->mode = (int)_v;}
static int get_XFocusInEvent_detail(void *_p) {return (int)((XFocusInEvent *)_p)->detail;}
static void set_XFocusInEvent_detail(void *_p, int _v) {((XFocusInEvent *)_p)->detail = (int)_v;}
static void *alloc_XFocusChangeEvent(void) {XFocusChangeEvent *_p = (XFocusChangeEvent *)malloc(sizeof(XFocusChangeEvent)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XFocusChangeEvent(void *_p) {if (_p==NULL) abort(); free((XFocusChangeEvent *)_p);}
static int get_XFocusChangeEvent_type(void *_p) {return (int)((XFocusChangeEvent *)_p)->type;}
static void set_XFocusChangeEvent_type(void *_p, int _v) {((XFocusChangeEvent *)_p)->type = (int)_v;}
static unsigned long get_XFocusChangeEvent_serial(void *_p) {return (unsigned long)((XFocusChangeEvent *)_p)->serial;}
static void set_XFocusChangeEvent_serial(void *_p, unsigned long _v) {((XFocusChangeEvent *)_p)->serial = (unsigned long)_v;}
static int get_XFocusChangeEvent_send_event(void *_p) {return (int)((XFocusChangeEvent *)_p)->send_event;}
static void set_XFocusChangeEvent_send_event(void *_p, int _v) {((XFocusChangeEvent *)_p)->send_event = (int)_v;}
static void *get_XFocusChangeEvent_display(void *_p) {return (void *)((XFocusChangeEvent *)_p)->display;}
static void set_XFocusChangeEvent_display(void *_p, void *_v) {((XFocusChangeEvent *)_p)->display = (Display *)_v;}
static unsigned long get_XFocusChangeEvent_window(void *_p) {return (unsigned long)((XFocusChangeEvent *)_p)->window;}
static void set_XFocusChangeEvent_window(void *_p, unsigned long _v) {((XFocusChangeEvent *)_p)->window = (unsigned long)_v;}
static int get_XFocusChangeEvent_mode(void *_p) {return (int)((XFocusChangeEvent *)_p)->mode;}
static void set_XFocusChangeEvent_mode(void *_p, int _v) {((XFocusChangeEvent *)_p)->mode = (int)_v;}
static int get_XFocusChangeEvent_detail(void *_p) {return (int)((XFocusChangeEvent *)_p)->detail;}
static void set_XFocusChangeEvent_detail(void *_p, int _v) {((XFocusChangeEvent *)_p)->detail = (int)_v;}
static void *alloc_XKeymapEvent(void) {XKeymapEvent *_p = (XKeymapEvent *)malloc(sizeof(XKeymapEvent)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XKeymapEvent(void *_p) {if (_p==NULL) abort(); free((XKeymapEvent *)_p);}
static int get_XKeymapEvent_type(void *_p) {return (int)((XKeymapEvent *)_p)->type;}
static void set_XKeymapEvent_type(void *_p, int _v) {((XKeymapEvent *)_p)->type = (int)_v;}
static unsigned long get_XKeymapEvent_serial(void *_p) {return (unsigned long)((XKeymapEvent *)_p)->serial;}
static void set_XKeymapEvent_serial(void *_p, unsigned long _v) {((XKeymapEvent *)_p)->serial = (unsigned long)_v;}
static int get_XKeymapEvent_send_event(void *_p) {return (int)((XKeymapEvent *)_p)->send_event;}
static void set_XKeymapEvent_send_event(void *_p, int _v) {((XKeymapEvent *)_p)->send_event = (int)_v;}
static void *get_XKeymapEvent_display(void *_p) {return (void *)((XKeymapEvent *)_p)->display;}
static void set_XKeymapEvent_display(void *_p, void *_v) {((XKeymapEvent *)_p)->display = (Display *)_v;}
static unsigned long get_XKeymapEvent_window(void *_p) {return (unsigned long)((XKeymapEvent *)_p)->window;}
static void set_XKeymapEvent_window(void *_p, unsigned long _v) {((XKeymapEvent *)_p)->window = (unsigned long)_v;}
static void *get_XKeymapEvent_key_vector(void *_p) {return (void *)(((XKeymapEvent *)_p)->key_vector);}
static void *alloc_XExposeEvent(void) {XExposeEvent *_p = (XExposeEvent *)malloc(sizeof(XExposeEvent)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XExposeEvent(void *_p) {if (_p==NULL) abort(); free((XExposeEvent *)_p);}
static int get_XExposeEvent_type(void *_p) {return (int)((XExposeEvent *)_p)->type;}
static void set_XExposeEvent_type(void *_p, int _v) {((XExposeEvent *)_p)->type = (int)_v;}
static unsigned long get_XExposeEvent_serial(void *_p) {return (unsigned long)((XExposeEvent *)_p)->serial;}
static void set_XExposeEvent_serial(void *_p, unsigned long _v) {((XExposeEvent *)_p)->serial = (unsigned long)_v;}
static int get_XExposeEvent_send_event(void *_p) {return (int)((XExposeEvent *)_p)->send_event;}
static void set_XExposeEvent_send_event(void *_p, int _v) {((XExposeEvent *)_p)->send_event = (int)_v;}
static void *get_XExposeEvent_display(void *_p) {return (void *)((XExposeEvent *)_p)->display;}
static void set_XExposeEvent_display(void *_p, void *_v) {((XExposeEvent *)_p)->display = (Display *)_v;}
static unsigned long get_XExposeEvent_window(void *_p) {return (unsigned long)((XExposeEvent *)_p)->window;}
static void set_XExposeEvent_window(void *_p, unsigned long _v) {((XExposeEvent *)_p)->window = (unsigned long)_v;}
static int get_XExposeEvent_x(void *_p) {return (int)((XExposeEvent *)_p)->x;}
static void set_XExposeEvent_x(void *_p, int _v) {((XExposeEvent *)_p)->x = (int)_v;}
static int get_XExposeEvent_y(void *_p) {return (int)((XExposeEvent *)_p)->y;}
static void set_XExposeEvent_y(void *_p, int _v) {((XExposeEvent *)_p)->y = (int)_v;}
static int get_XExposeEvent_width(void *_p) {return (int)((XExposeEvent *)_p)->width;}
static void set_XExposeEvent_width(void *_p, int _v) {((XExposeEvent *)_p)->width = (int)_v;}
static int get_XExposeEvent_height(void *_p) {return (int)((XExposeEvent *)_p)->height;}
static void set_XExposeEvent_height(void *_p, int _v) {((XExposeEvent *)_p)->height = (int)_v;}
static int get_XExposeEvent_count(void *_p) {return (int)((XExposeEvent *)_p)->count;}
static void set_XExposeEvent_count(void *_p, int _v) {((XExposeEvent *)_p)->count = (int)_v;}
static void *alloc_XGraphicsExposeEvent(void) {XGraphicsExposeEvent *_p = (XGraphicsExposeEvent *)malloc(sizeof(XGraphicsExposeEvent)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XGraphicsExposeEvent(void *_p) {if (_p==NULL) abort(); free((XGraphicsExposeEvent *)_p);}
static int get_XGraphicsExposeEvent_type(void *_p) {return (int)((XGraphicsExposeEvent *)_p)->type;}
static void set_XGraphicsExposeEvent_type(void *_p, int _v) {((XGraphicsExposeEvent *)_p)->type = (int)_v;}
static unsigned long get_XGraphicsExposeEvent_serial(void *_p) {return (unsigned long)((XGraphicsExposeEvent *)_p)->serial;}
static void set_XGraphicsExposeEvent_serial(void *_p, unsigned long _v) {((XGraphicsExposeEvent *)_p)->serial = (unsigned long)_v;}
static int get_XGraphicsExposeEvent_send_event(void *_p) {return (int)((XGraphicsExposeEvent *)_p)->send_event;}
static void set_XGraphicsExposeEvent_send_event(void *_p, int _v) {((XGraphicsExposeEvent *)_p)->send_event = (int)_v;}
static void *get_XGraphicsExposeEvent_display(void *_p) {return (void *)((XGraphicsExposeEvent *)_p)->display;}
static void set_XGraphicsExposeEvent_display(void *_p, void *_v) {((XGraphicsExposeEvent *)_p)->display = (Display *)_v;}
static unsigned long get_XGraphicsExposeEvent_drawable(void *_p) {return (unsigned long)((XGraphicsExposeEvent *)_p)->drawable;}
static void set_XGraphicsExposeEvent_drawable(void *_p, unsigned long _v) {((XGraphicsExposeEvent *)_p)->drawable = (unsigned long)_v;}
static int get_XGraphicsExposeEvent_x(void *_p) {return (int)((XGraphicsExposeEvent *)_p)->x;}
static void set_XGraphicsExposeEvent_x(void *_p, int _v) {((XGraphicsExposeEvent *)_p)->x = (int)_v;}
static int get_XGraphicsExposeEvent_y(void *_p) {return (int)((XGraphicsExposeEvent *)_p)->y;}
static void set_XGraphicsExposeEvent_y(void *_p, int _v) {((XGraphicsExposeEvent *)_p)->y = (int)_v;}
static int get_XGraphicsExposeEvent_width(void *_p) {return (int)((XGraphicsExposeEvent *)_p)->width;}
static void set_XGraphicsExposeEvent_width(void *_p, int _v) {((XGraphicsExposeEvent *)_p)->width = (int)_v;}
static int get_XGraphicsExposeEvent_height(void *_p) {return (int)((XGraphicsExposeEvent *)_p)->height;}
static void set_XGraphicsExposeEvent_height(void *_p, int _v) {((XGraphicsExposeEvent *)_p)->height = (int)_v;}
static int get_XGraphicsExposeEvent_count(void *_p) {return (int)((XGraphicsExposeEvent *)_p)->count;}
static void set_XGraphicsExposeEvent_count(void *_p, int _v) {((XGraphicsExposeEvent *)_p)->count = (int)_v;}
static int get_XGraphicsExposeEvent_major_code(void *_p) {return (int)((XGraphicsExposeEvent *)_p)->major_code;}
static void set_XGraphicsExposeEvent_major_code(void *_p, int _v) {((XGraphicsExposeEvent *)_p)->major_code = (int)_v;}
static int get_XGraphicsExposeEvent_minor_code(void *_p) {return (int)((XGraphicsExposeEvent *)_p)->minor_code;}
static void set_XGraphicsExposeEvent_minor_code(void *_p, int _v) {((XGraphicsExposeEvent *)_p)->minor_code = (int)_v;}
static void *alloc_XNoExposeEvent(void) {XNoExposeEvent *_p = (XNoExposeEvent *)malloc(sizeof(XNoExposeEvent)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XNoExposeEvent(void *_p) {if (_p==NULL) abort(); free((XNoExposeEvent *)_p);}
static int get_XNoExposeEvent_type(void *_p) {return (int)((XNoExposeEvent *)_p)->type;}
static void set_XNoExposeEvent_type(void *_p, int _v) {((XNoExposeEvent *)_p)->type = (int)_v;}
static unsigned long get_XNoExposeEvent_serial(void *_p) {return (unsigned long)((XNoExposeEvent *)_p)->serial;}
static void set_XNoExposeEvent_serial(void *_p, unsigned long _v) {((XNoExposeEvent *)_p)->serial = (unsigned long)_v;}
static int get_XNoExposeEvent_send_event(void *_p) {return (int)((XNoExposeEvent *)_p)->send_event;}
static void set_XNoExposeEvent_send_event(void *_p, int _v) {((XNoExposeEvent *)_p)->send_event = (int)_v;}
static void *get_XNoExposeEvent_display(void *_p) {return (void *)((XNoExposeEvent *)_p)->display;}
static void set_XNoExposeEvent_display(void *_p, void *_v) {((XNoExposeEvent *)_p)->display = (Display *)_v;}
static unsigned long get_XNoExposeEvent_drawable(void *_p) {return (unsigned long)((XNoExposeEvent *)_p)->drawable;}
static void set_XNoExposeEvent_drawable(void *_p, unsigned long _v) {((XNoExposeEvent *)_p)->drawable = (unsigned long)_v;}
static int get_XNoExposeEvent_major_code(void *_p) {return (int)((XNoExposeEvent *)_p)->major_code;}
static void set_XNoExposeEvent_major_code(void *_p, int _v) {((XNoExposeEvent *)_p)->major_code = (int)_v;}
static int get_XNoExposeEvent_minor_code(void *_p) {return (int)((XNoExposeEvent *)_p)->minor_code;}
static void set_XNoExposeEvent_minor_code(void *_p, int _v) {((XNoExposeEvent *)_p)->minor_code = (int)_v;}
static void *alloc_XVisibilityEvent(void) {XVisibilityEvent *_p = (XVisibilityEvent *)malloc(sizeof(XVisibilityEvent)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XVisibilityEvent(void *_p) {if (_p==NULL) abort(); free((XVisibilityEvent *)_p);}
static int get_XVisibilityEvent_type(void *_p) {return (int)((XVisibilityEvent *)_p)->type;}
static void set_XVisibilityEvent_type(void *_p, int _v) {((XVisibilityEvent *)_p)->type = (int)_v;}
static unsigned long get_XVisibilityEvent_serial(void *_p) {return (unsigned long)((XVisibilityEvent *)_p)->serial;}
static void set_XVisibilityEvent_serial(void *_p, unsigned long _v) {((XVisibilityEvent *)_p)->serial = (unsigned long)_v;}
static int get_XVisibilityEvent_send_event(void *_p) {return (int)((XVisibilityEvent *)_p)->send_event;}
static void set_XVisibilityEvent_send_event(void *_p, int _v) {((XVisibilityEvent *)_p)->send_event = (int)_v;}
static void *get_XVisibilityEvent_display(void *_p) {return (void *)((XVisibilityEvent *)_p)->display;}
static void set_XVisibilityEvent_display(void *_p, void *_v) {((XVisibilityEvent *)_p)->display = (Display *)_v;}
static unsigned long get_XVisibilityEvent_window(void *_p) {return (unsigned long)((XVisibilityEvent *)_p)->window;}
static void set_XVisibilityEvent_window(void *_p, unsigned long _v) {((XVisibilityEvent *)_p)->window = (unsigned long)_v;}
static int get_XVisibilityEvent_state(void *_p) {return (int)((XVisibilityEvent *)_p)->state;}
static void set_XVisibilityEvent_state(void *_p, int _v) {((XVisibilityEvent *)_p)->state = (int)_v;}
static void *alloc_XCreateWindowEvent(void) {XCreateWindowEvent *_p = (XCreateWindowEvent *)malloc(sizeof(XCreateWindowEvent)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XCreateWindowEvent(void *_p) {if (_p==NULL) abort(); free((XCreateWindowEvent *)_p);}
static int get_XCreateWindowEvent_type(void *_p) {return (int)((XCreateWindowEvent *)_p)->type;}
static void set_XCreateWindowEvent_type(void *_p, int _v) {((XCreateWindowEvent *)_p)->type = (int)_v;}
static unsigned long get_XCreateWindowEvent_serial(void *_p) {return (unsigned long)((XCreateWindowEvent *)_p)->serial;}
static void set_XCreateWindowEvent_serial(void *_p, unsigned long _v) {((XCreateWindowEvent *)_p)->serial = (unsigned long)_v;}
static int get_XCreateWindowEvent_send_event(void *_p) {return (int)((XCreateWindowEvent *)_p)->send_event;}
static void set_XCreateWindowEvent_send_event(void *_p, int _v) {((XCreateWindowEvent *)_p)->send_event = (int)_v;}
static void *get_XCreateWindowEvent_display(void *_p) {return (void *)((XCreateWindowEvent *)_p)->display;}
static void set_XCreateWindowEvent_display(void *_p, void *_v) {((XCreateWindowEvent *)_p)->display = (Display *)_v;}
static unsigned long get_XCreateWindowEvent_parent(void *_p) {return (unsigned long)((XCreateWindowEvent *)_p)->parent;}
static void set_XCreateWindowEvent_parent(void *_p, unsigned long _v) {((XCreateWindowEvent *)_p)->parent = (unsigned long)_v;}
static unsigned long get_XCreateWindowEvent_window(void *_p) {return (unsigned long)((XCreateWindowEvent *)_p)->window;}
static void set_XCreateWindowEvent_window(void *_p, unsigned long _v) {((XCreateWindowEvent *)_p)->window = (unsigned long)_v;}
static int get_XCreateWindowEvent_x(void *_p) {return (int)((XCreateWindowEvent *)_p)->x;}
static void set_XCreateWindowEvent_x(void *_p, int _v) {((XCreateWindowEvent *)_p)->x = (int)_v;}
static int get_XCreateWindowEvent_y(void *_p) {return (int)((XCreateWindowEvent *)_p)->y;}
static void set_XCreateWindowEvent_y(void *_p, int _v) {((XCreateWindowEvent *)_p)->y = (int)_v;}
static int get_XCreateWindowEvent_width(void *_p) {return (int)((XCreateWindowEvent *)_p)->width;}
static void set_XCreateWindowEvent_width(void *_p, int _v) {((XCreateWindowEvent *)_p)->width = (int)_v;}
static int get_XCreateWindowEvent_height(void *_p) {return (int)((XCreateWindowEvent *)_p)->height;}
static void set_XCreateWindowEvent_height(void *_p, int _v) {((XCreateWindowEvent *)_p)->height = (int)_v;}
static int get_XCreateWindowEvent_border_width(void *_p) {return (int)((XCreateWindowEvent *)_p)->border_width;}
static void set_XCreateWindowEvent_border_width(void *_p, int _v) {((XCreateWindowEvent *)_p)->border_width = (int)_v;}
static int get_XCreateWindowEvent_override_redirect(void *_p) {return (int)((XCreateWindowEvent *)_p)->override_redirect;}
static void set_XCreateWindowEvent_override_redirect(void *_p, int _v) {((XCreateWindowEvent *)_p)->override_redirect = (int)_v;}
static void *alloc_XDestroyWindowEvent(void) {XDestroyWindowEvent *_p = (XDestroyWindowEvent *)malloc(sizeof(XDestroyWindowEvent)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XDestroyWindowEvent(void *_p) {if (_p==NULL) abort(); free((XDestroyWindowEvent *)_p);}
static int get_XDestroyWindowEvent_type(void *_p) {return (int)((XDestroyWindowEvent *)_p)->type;}
static void set_XDestroyWindowEvent_type(void *_p, int _v) {((XDestroyWindowEvent *)_p)->type = (int)_v;}
static unsigned long get_XDestroyWindowEvent_serial(void *_p) {return (unsigned long)((XDestroyWindowEvent *)_p)->serial;}
static void set_XDestroyWindowEvent_serial(void *_p, unsigned long _v) {((XDestroyWindowEvent *)_p)->serial = (unsigned long)_v;}
static int get_XDestroyWindowEvent_send_event(void *_p) {return (int)((XDestroyWindowEvent *)_p)->send_event;}
static void set_XDestroyWindowEvent_send_event(void *_p, int _v) {((XDestroyWindowEvent *)_p)->send_event = (int)_v;}
static void *get_XDestroyWindowEvent_display(void *_p) {return (void *)((XDestroyWindowEvent *)_p)->display;}
static void set_XDestroyWindowEvent_display(void *_p, void *_v) {((XDestroyWindowEvent *)_p)->display = (Display *)_v;}
static unsigned long get_XDestroyWindowEvent_event(void *_p) {return (unsigned long)((XDestroyWindowEvent *)_p)->event;}
static void set_XDestroyWindowEvent_event(void *_p, unsigned long _v) {((XDestroyWindowEvent *)_p)->event = (unsigned long)_v;}
static unsigned long get_XDestroyWindowEvent_window(void *_p) {return (unsigned long)((XDestroyWindowEvent *)_p)->window;}
static void set_XDestroyWindowEvent_window(void *_p, unsigned long _v) {((XDestroyWindowEvent *)_p)->window = (unsigned long)_v;}
static void *alloc_XUnmapEvent(void) {XUnmapEvent *_p = (XUnmapEvent *)malloc(sizeof(XUnmapEvent)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XUnmapEvent(void *_p) {if (_p==NULL) abort(); free((XUnmapEvent *)_p);}
static int get_XUnmapEvent_type(void *_p) {return (int)((XUnmapEvent *)_p)->type;}
static void set_XUnmapEvent_type(void *_p, int _v) {((XUnmapEvent *)_p)->type = (int)_v;}
static unsigned long get_XUnmapEvent_serial(void *_p) {return (unsigned long)((XUnmapEvent *)_p)->serial;}
static void set_XUnmapEvent_serial(void *_p, unsigned long _v) {((XUnmapEvent *)_p)->serial = (unsigned long)_v;}
static int get_XUnmapEvent_send_event(void *_p) {return (int)((XUnmapEvent *)_p)->send_event;}
static void set_XUnmapEvent_send_event(void *_p, int _v) {((XUnmapEvent *)_p)->send_event = (int)_v;}
static void *get_XUnmapEvent_display(void *_p) {return (void *)((XUnmapEvent *)_p)->display;}
static void set_XUnmapEvent_display(void *_p, void *_v) {((XUnmapEvent *)_p)->display = (Display *)_v;}
static unsigned long get_XUnmapEvent_event(void *_p) {return (unsigned long)((XUnmapEvent *)_p)->event;}
static void set_XUnmapEvent_event(void *_p, unsigned long _v) {((XUnmapEvent *)_p)->event = (unsigned long)_v;}
static unsigned long get_XUnmapEvent_window(void *_p) {return (unsigned long)((XUnmapEvent *)_p)->window;}
static void set_XUnmapEvent_window(void *_p, unsigned long _v) {((XUnmapEvent *)_p)->window = (unsigned long)_v;}
static int get_XUnmapEvent_from_configure(void *_p) {return (int)((XUnmapEvent *)_p)->from_configure;}
static void set_XUnmapEvent_from_configure(void *_p, int _v) {((XUnmapEvent *)_p)->from_configure = (int)_v;}
static void *alloc_XMapEvent(void) {XMapEvent *_p = (XMapEvent *)malloc(sizeof(XMapEvent)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XMapEvent(void *_p) {if (_p==NULL) abort(); free((XMapEvent *)_p);}
static int get_XMapEvent_type(void *_p) {return (int)((XMapEvent *)_p)->type;}
static void set_XMapEvent_type(void *_p, int _v) {((XMapEvent *)_p)->type = (int)_v;}
static unsigned long get_XMapEvent_serial(void *_p) {return (unsigned long)((XMapEvent *)_p)->serial;}
static void set_XMapEvent_serial(void *_p, unsigned long _v) {((XMapEvent *)_p)->serial = (unsigned long)_v;}
static int get_XMapEvent_send_event(void *_p) {return (int)((XMapEvent *)_p)->send_event;}
static void set_XMapEvent_send_event(void *_p, int _v) {((XMapEvent *)_p)->send_event = (int)_v;}
static void *get_XMapEvent_display(void *_p) {return (void *)((XMapEvent *)_p)->display;}
static void set_XMapEvent_display(void *_p, void *_v) {((XMapEvent *)_p)->display = (Display *)_v;}
static unsigned long get_XMapEvent_event(void *_p) {return (unsigned long)((XMapEvent *)_p)->event;}
static void set_XMapEvent_event(void *_p, unsigned long _v) {((XMapEvent *)_p)->event = (unsigned long)_v;}
static unsigned long get_XMapEvent_window(void *_p) {return (unsigned long)((XMapEvent *)_p)->window;}
static void set_XMapEvent_window(void *_p, unsigned long _v) {((XMapEvent *)_p)->window = (unsigned long)_v;}
static int get_XMapEvent_override_redirect(void *_p) {return (int)((XMapEvent *)_p)->override_redirect;}
static void set_XMapEvent_override_redirect(void *_p, int _v) {((XMapEvent *)_p)->override_redirect = (int)_v;}
static void *alloc_XMapRequestEvent(void) {XMapRequestEvent *_p = (XMapRequestEvent *)malloc(sizeof(XMapRequestEvent)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XMapRequestEvent(void *_p) {if (_p==NULL) abort(); free((XMapRequestEvent *)_p);}
static int get_XMapRequestEvent_type(void *_p) {return (int)((XMapRequestEvent *)_p)->type;}
static void set_XMapRequestEvent_type(void *_p, int _v) {((XMapRequestEvent *)_p)->type = (int)_v;}
static unsigned long get_XMapRequestEvent_serial(void *_p) {return (unsigned long)((XMapRequestEvent *)_p)->serial;}
static void set_XMapRequestEvent_serial(void *_p, unsigned long _v) {((XMapRequestEvent *)_p)->serial = (unsigned long)_v;}
static int get_XMapRequestEvent_send_event(void *_p) {return (int)((XMapRequestEvent *)_p)->send_event;}
static void set_XMapRequestEvent_send_event(void *_p, int _v) {((XMapRequestEvent *)_p)->send_event = (int)_v;}
static void *get_XMapRequestEvent_display(void *_p) {return (void *)((XMapRequestEvent *)_p)->display;}
static void set_XMapRequestEvent_display(void *_p, void *_v) {((XMapRequestEvent *)_p)->display = (Display *)_v;}
static unsigned long get_XMapRequestEvent_parent(void *_p) {return (unsigned long)((XMapRequestEvent *)_p)->parent;}
static void set_XMapRequestEvent_parent(void *_p, unsigned long _v) {((XMapRequestEvent *)_p)->parent = (unsigned long)_v;}
static unsigned long get_XMapRequestEvent_window(void *_p) {return (unsigned long)((XMapRequestEvent *)_p)->window;}
static void set_XMapRequestEvent_window(void *_p, unsigned long _v) {((XMapRequestEvent *)_p)->window = (unsigned long)_v;}
static void *alloc_XReparentEvent(void) {XReparentEvent *_p = (XReparentEvent *)malloc(sizeof(XReparentEvent)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XReparentEvent(void *_p) {if (_p==NULL) abort(); free((XReparentEvent *)_p);}
static int get_XReparentEvent_type(void *_p) {return (int)((XReparentEvent *)_p)->type;}
static void set_XReparentEvent_type(void *_p, int _v) {((XReparentEvent *)_p)->type = (int)_v;}
static unsigned long get_XReparentEvent_serial(void *_p) {return (unsigned long)((XReparentEvent *)_p)->serial;}
static void set_XReparentEvent_serial(void *_p, unsigned long _v) {((XReparentEvent *)_p)->serial = (unsigned long)_v;}
static int get_XReparentEvent_send_event(void *_p) {return (int)((XReparentEvent *)_p)->send_event;}
static void set_XReparentEvent_send_event(void *_p, int _v) {((XReparentEvent *)_p)->send_event = (int)_v;}
static void *get_XReparentEvent_display(void *_p) {return (void *)((XReparentEvent *)_p)->display;}
static void set_XReparentEvent_display(void *_p, void *_v) {((XReparentEvent *)_p)->display = (Display *)_v;}
static unsigned long get_XReparentEvent_event(void *_p) {return (unsigned long)((XReparentEvent *)_p)->event;}
static void set_XReparentEvent_event(void *_p, unsigned long _v) {((XReparentEvent *)_p)->event = (unsigned long)_v;}
static unsigned long get_XReparentEvent_window(void *_p) {return (unsigned long)((XReparentEvent *)_p)->window;}
static void set_XReparentEvent_window(void *_p, unsigned long _v) {((XReparentEvent *)_p)->window = (unsigned long)_v;}
static unsigned long get_XReparentEvent_parent(void *_p) {return (unsigned long)((XReparentEvent *)_p)->parent;}
static void set_XReparentEvent_parent(void *_p, unsigned long _v) {((XReparentEvent *)_p)->parent = (unsigned long)_v;}
static int get_XReparentEvent_x(void *_p) {return (int)((XReparentEvent *)_p)->x;}
static void set_XReparentEvent_x(void *_p, int _v) {((XReparentEvent *)_p)->x = (int)_v;}
static int get_XReparentEvent_y(void *_p) {return (int)((XReparentEvent *)_p)->y;}
static void set_XReparentEvent_y(void *_p, int _v) {((XReparentEvent *)_p)->y = (int)_v;}
static int get_XReparentEvent_override_redirect(void *_p) {return (int)((XReparentEvent *)_p)->override_redirect;}
static void set_XReparentEvent_override_redirect(void *_p, int _v) {((XReparentEvent *)_p)->override_redirect = (int)_v;}
static void *alloc_XConfigureEvent(void) {XConfigureEvent *_p = (XConfigureEvent *)malloc(sizeof(XConfigureEvent)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XConfigureEvent(void *_p) {if (_p==NULL) abort(); free((XConfigureEvent *)_p);}
static int get_XConfigureEvent_type(void *_p) {return (int)((XConfigureEvent *)_p)->type;}
static void set_XConfigureEvent_type(void *_p, int _v) {((XConfigureEvent *)_p)->type = (int)_v;}
static unsigned long get_XConfigureEvent_serial(void *_p) {return (unsigned long)((XConfigureEvent *)_p)->serial;}
static void set_XConfigureEvent_serial(void *_p, unsigned long _v) {((XConfigureEvent *)_p)->serial = (unsigned long)_v;}
static int get_XConfigureEvent_send_event(void *_p) {return (int)((XConfigureEvent *)_p)->send_event;}
static void set_XConfigureEvent_send_event(void *_p, int _v) {((XConfigureEvent *)_p)->send_event = (int)_v;}
static void *get_XConfigureEvent_display(void *_p) {return (void *)((XConfigureEvent *)_p)->display;}
static void set_XConfigureEvent_display(void *_p, void *_v) {((XConfigureEvent *)_p)->display = (Display *)_v;}
static unsigned long get_XConfigureEvent_event(void *_p) {return (unsigned long)((XConfigureEvent *)_p)->event;}
static void set_XConfigureEvent_event(void *_p, unsigned long _v) {((XConfigureEvent *)_p)->event = (unsigned long)_v;}
static unsigned long get_XConfigureEvent_window(void *_p) {return (unsigned long)((XConfigureEvent *)_p)->window;}
static void set_XConfigureEvent_window(void *_p, unsigned long _v) {((XConfigureEvent *)_p)->window = (unsigned long)_v;}
static int get_XConfigureEvent_x(void *_p) {return (int)((XConfigureEvent *)_p)->x;}
static void set_XConfigureEvent_x(void *_p, int _v) {((XConfigureEvent *)_p)->x = (int)_v;}
static int get_XConfigureEvent_y(void *_p) {return (int)((XConfigureEvent *)_p)->y;}
static void set_XConfigureEvent_y(void *_p, int _v) {((XConfigureEvent *)_p)->y = (int)_v;}
static int get_XConfigureEvent_width(void *_p) {return (int)((XConfigureEvent *)_p)->width;}
static void set_XConfigureEvent_width(void *_p, int _v) {((XConfigureEvent *)_p)->width = (int)_v;}
static int get_XConfigureEvent_height(void *_p) {return (int)((XConfigureEvent *)_p)->height;}
static void set_XConfigureEvent_height(void *_p, int _v) {((XConfigureEvent *)_p)->height = (int)_v;}
static int get_XConfigureEvent_border_width(void *_p) {return (int)((XConfigureEvent *)_p)->border_width;}
static void set_XConfigureEvent_border_width(void *_p, int _v) {((XConfigureEvent *)_p)->border_width = (int)_v;}
static unsigned long get_XConfigureEvent_above(void *_p) {return (unsigned long)((XConfigureEvent *)_p)->above;}
static void set_XConfigureEvent_above(void *_p, unsigned long _v) {((XConfigureEvent *)_p)->above = (unsigned long)_v;}
static int get_XConfigureEvent_override_redirect(void *_p) {return (int)((XConfigureEvent *)_p)->override_redirect;}
static void set_XConfigureEvent_override_redirect(void *_p, int _v) {((XConfigureEvent *)_p)->override_redirect = (int)_v;}
static void *alloc_XGravityEvent(void) {XGravityEvent *_p = (XGravityEvent *)malloc(sizeof(XGravityEvent)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XGravityEvent(void *_p) {if (_p==NULL) abort(); free((XGravityEvent *)_p);}
static int get_XGravityEvent_type(void *_p) {return (int)((XGravityEvent *)_p)->type;}
static void set_XGravityEvent_type(void *_p, int _v) {((XGravityEvent *)_p)->type = (int)_v;}
static unsigned long get_XGravityEvent_serial(void *_p) {return (unsigned long)((XGravityEvent *)_p)->serial;}
static void set_XGravityEvent_serial(void *_p, unsigned long _v) {((XGravityEvent *)_p)->serial = (unsigned long)_v;}
static int get_XGravityEvent_send_event(void *_p) {return (int)((XGravityEvent *)_p)->send_event;}
static void set_XGravityEvent_send_event(void *_p, int _v) {((XGravityEvent *)_p)->send_event = (int)_v;}
static void *get_XGravityEvent_display(void *_p) {return (void *)((XGravityEvent *)_p)->display;}
static void set_XGravityEvent_display(void *_p, void *_v) {((XGravityEvent *)_p)->display = (Display *)_v;}
static unsigned long get_XGravityEvent_event(void *_p) {return (unsigned long)((XGravityEvent *)_p)->event;}
static void set_XGravityEvent_event(void *_p, unsigned long _v) {((XGravityEvent *)_p)->event = (unsigned long)_v;}
static unsigned long get_XGravityEvent_window(void *_p) {return (unsigned long)((XGravityEvent *)_p)->window;}
static void set_XGravityEvent_window(void *_p, unsigned long _v) {((XGravityEvent *)_p)->window = (unsigned long)_v;}
static int get_XGravityEvent_x(void *_p) {return (int)((XGravityEvent *)_p)->x;}
static void set_XGravityEvent_x(void *_p, int _v) {((XGravityEvent *)_p)->x = (int)_v;}
static int get_XGravityEvent_y(void *_p) {return (int)((XGravityEvent *)_p)->y;}
static void set_XGravityEvent_y(void *_p, int _v) {((XGravityEvent *)_p)->y = (int)_v;}
static void *alloc_XResizeRequestEvent(void) {XResizeRequestEvent *_p = (XResizeRequestEvent *)malloc(sizeof(XResizeRequestEvent)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XResizeRequestEvent(void *_p) {if (_p==NULL) abort(); free((XResizeRequestEvent *)_p);}
static int get_XResizeRequestEvent_type(void *_p) {return (int)((XResizeRequestEvent *)_p)->type;}
static void set_XResizeRequestEvent_type(void *_p, int _v) {((XResizeRequestEvent *)_p)->type = (int)_v;}
static unsigned long get_XResizeRequestEvent_serial(void *_p) {return (unsigned long)((XResizeRequestEvent *)_p)->serial;}
static void set_XResizeRequestEvent_serial(void *_p, unsigned long _v) {((XResizeRequestEvent *)_p)->serial = (unsigned long)_v;}
static int get_XResizeRequestEvent_send_event(void *_p) {return (int)((XResizeRequestEvent *)_p)->send_event;}
static void set_XResizeRequestEvent_send_event(void *_p, int _v) {((XResizeRequestEvent *)_p)->send_event = (int)_v;}
static void *get_XResizeRequestEvent_display(void *_p) {return (void *)((XResizeRequestEvent *)_p)->display;}
static void set_XResizeRequestEvent_display(void *_p, void *_v) {((XResizeRequestEvent *)_p)->display = (Display *)_v;}
static unsigned long get_XResizeRequestEvent_window(void *_p) {return (unsigned long)((XResizeRequestEvent *)_p)->window;}
static void set_XResizeRequestEvent_window(void *_p, unsigned long _v) {((XResizeRequestEvent *)_p)->window = (unsigned long)_v;}
static int get_XResizeRequestEvent_width(void *_p) {return (int)((XResizeRequestEvent *)_p)->width;}
static void set_XResizeRequestEvent_width(void *_p, int _v) {((XResizeRequestEvent *)_p)->width = (int)_v;}
static int get_XResizeRequestEvent_height(void *_p) {return (int)((XResizeRequestEvent *)_p)->height;}
static void set_XResizeRequestEvent_height(void *_p, int _v) {((XResizeRequestEvent *)_p)->height = (int)_v;}
static void *alloc_XConfigureRequestEvent(void) {XConfigureRequestEvent *_p = (XConfigureRequestEvent *)malloc(sizeof(XConfigureRequestEvent)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XConfigureRequestEvent(void *_p) {if (_p==NULL) abort(); free((XConfigureRequestEvent *)_p);}
static int get_XConfigureRequestEvent_type(void *_p) {return (int)((XConfigureRequestEvent *)_p)->type;}
static void set_XConfigureRequestEvent_type(void *_p, int _v) {((XConfigureRequestEvent *)_p)->type = (int)_v;}
static unsigned long get_XConfigureRequestEvent_serial(void *_p) {return (unsigned long)((XConfigureRequestEvent *)_p)->serial;}
static void set_XConfigureRequestEvent_serial(void *_p, unsigned long _v) {((XConfigureRequestEvent *)_p)->serial = (unsigned long)_v;}
static int get_XConfigureRequestEvent_send_event(void *_p) {return (int)((XConfigureRequestEvent *)_p)->send_event;}
static void set_XConfigureRequestEvent_send_event(void *_p, int _v) {((XConfigureRequestEvent *)_p)->send_event = (int)_v;}
static void *get_XConfigureRequestEvent_display(void *_p) {return (void *)((XConfigureRequestEvent *)_p)->display;}
static void set_XConfigureRequestEvent_display(void *_p, void *_v) {((XConfigureRequestEvent *)_p)->display = (Display *)_v;}
static unsigned long get_XConfigureRequestEvent_parent(void *_p) {return (unsigned long)((XConfigureRequestEvent *)_p)->parent;}
static void set_XConfigureRequestEvent_parent(void *_p, unsigned long _v) {((XConfigureRequestEvent *)_p)->parent = (unsigned long)_v;}
static unsigned long get_XConfigureRequestEvent_window(void *_p) {return (unsigned long)((XConfigureRequestEvent *)_p)->window;}
static void set_XConfigureRequestEvent_window(void *_p, unsigned long _v) {((XConfigureRequestEvent *)_p)->window = (unsigned long)_v;}
static int get_XConfigureRequestEvent_x(void *_p) {return (int)((XConfigureRequestEvent *)_p)->x;}
static void set_XConfigureRequestEvent_x(void *_p, int _v) {((XConfigureRequestEvent *)_p)->x = (int)_v;}
static int get_XConfigureRequestEvent_y(void *_p) {return (int)((XConfigureRequestEvent *)_p)->y;}
static void set_XConfigureRequestEvent_y(void *_p, int _v) {((XConfigureRequestEvent *)_p)->y = (int)_v;}
static int get_XConfigureRequestEvent_width(void *_p) {return (int)((XConfigureRequestEvent *)_p)->width;}
static void set_XConfigureRequestEvent_width(void *_p, int _v) {((XConfigureRequestEvent *)_p)->width = (int)_v;}
static int get_XConfigureRequestEvent_height(void *_p) {return (int)((XConfigureRequestEvent *)_p)->height;}
static void set_XConfigureRequestEvent_height(void *_p, int _v) {((XConfigureRequestEvent *)_p)->height = (int)_v;}
static int get_XConfigureRequestEvent_border_width(void *_p) {return (int)((XConfigureRequestEvent *)_p)->border_width;}
static void set_XConfigureRequestEvent_border_width(void *_p, int _v) {((XConfigureRequestEvent *)_p)->border_width = (int)_v;}
static unsigned long get_XConfigureRequestEvent_above(void *_p) {return (unsigned long)((XConfigureRequestEvent *)_p)->above;}
static void set_XConfigureRequestEvent_above(void *_p, unsigned long _v) {((XConfigureRequestEvent *)_p)->above = (unsigned long)_v;}
static int get_XConfigureRequestEvent_detail(void *_p) {return (int)((XConfigureRequestEvent *)_p)->detail;}
static void set_XConfigureRequestEvent_detail(void *_p, int _v) {((XConfigureRequestEvent *)_p)->detail = (int)_v;}
static unsigned long get_XConfigureRequestEvent_value_mask(void *_p) {return (unsigned long)((XConfigureRequestEvent *)_p)->value_mask;}
static void set_XConfigureRequestEvent_value_mask(void *_p, unsigned long _v) {((XConfigureRequestEvent *)_p)->value_mask = (unsigned long)_v;}
static void *alloc_XCirculateEvent(void) {XCirculateEvent *_p = (XCirculateEvent *)malloc(sizeof(XCirculateEvent)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XCirculateEvent(void *_p) {if (_p==NULL) abort(); free((XCirculateEvent *)_p);}
static int get_XCirculateEvent_type(void *_p) {return (int)((XCirculateEvent *)_p)->type;}
static void set_XCirculateEvent_type(void *_p, int _v) {((XCirculateEvent *)_p)->type = (int)_v;}
static unsigned long get_XCirculateEvent_serial(void *_p) {return (unsigned long)((XCirculateEvent *)_p)->serial;}
static void set_XCirculateEvent_serial(void *_p, unsigned long _v) {((XCirculateEvent *)_p)->serial = (unsigned long)_v;}
static int get_XCirculateEvent_send_event(void *_p) {return (int)((XCirculateEvent *)_p)->send_event;}
static void set_XCirculateEvent_send_event(void *_p, int _v) {((XCirculateEvent *)_p)->send_event = (int)_v;}
static void *get_XCirculateEvent_display(void *_p) {return (void *)((XCirculateEvent *)_p)->display;}
static void set_XCirculateEvent_display(void *_p, void *_v) {((XCirculateEvent *)_p)->display = (Display *)_v;}
static unsigned long get_XCirculateEvent_event(void *_p) {return (unsigned long)((XCirculateEvent *)_p)->event;}
static void set_XCirculateEvent_event(void *_p, unsigned long _v) {((XCirculateEvent *)_p)->event = (unsigned long)_v;}
static unsigned long get_XCirculateEvent_window(void *_p) {return (unsigned long)((XCirculateEvent *)_p)->window;}
static void set_XCirculateEvent_window(void *_p, unsigned long _v) {((XCirculateEvent *)_p)->window = (unsigned long)_v;}
static int get_XCirculateEvent_place(void *_p) {return (int)((XCirculateEvent *)_p)->place;}
static void set_XCirculateEvent_place(void *_p, int _v) {((XCirculateEvent *)_p)->place = (int)_v;}
static void *alloc_XCirculateRequestEvent(void) {XCirculateRequestEvent *_p = (XCirculateRequestEvent *)malloc(sizeof(XCirculateRequestEvent)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XCirculateRequestEvent(void *_p) {if (_p==NULL) abort(); free((XCirculateRequestEvent *)_p);}
static int get_XCirculateRequestEvent_type(void *_p) {return (int)((XCirculateRequestEvent *)_p)->type;}
static void set_XCirculateRequestEvent_type(void *_p, int _v) {((XCirculateRequestEvent *)_p)->type = (int)_v;}
static unsigned long get_XCirculateRequestEvent_serial(void *_p) {return (unsigned long)((XCirculateRequestEvent *)_p)->serial;}
static void set_XCirculateRequestEvent_serial(void *_p, unsigned long _v) {((XCirculateRequestEvent *)_p)->serial = (unsigned long)_v;}
static int get_XCirculateRequestEvent_send_event(void *_p) {return (int)((XCirculateRequestEvent *)_p)->send_event;}
static void set_XCirculateRequestEvent_send_event(void *_p, int _v) {((XCirculateRequestEvent *)_p)->send_event = (int)_v;}
static void *get_XCirculateRequestEvent_display(void *_p) {return (void *)((XCirculateRequestEvent *)_p)->display;}
static void set_XCirculateRequestEvent_display(void *_p, void *_v) {((XCirculateRequestEvent *)_p)->display = (Display *)_v;}
static unsigned long get_XCirculateRequestEvent_parent(void *_p) {return (unsigned long)((XCirculateRequestEvent *)_p)->parent;}
static void set_XCirculateRequestEvent_parent(void *_p, unsigned long _v) {((XCirculateRequestEvent *)_p)->parent = (unsigned long)_v;}
static unsigned long get_XCirculateRequestEvent_window(void *_p) {return (unsigned long)((XCirculateRequestEvent *)_p)->window;}
static void set_XCirculateRequestEvent_window(void *_p, unsigned long _v) {((XCirculateRequestEvent *)_p)->window = (unsigned long)_v;}
static int get_XCirculateRequestEvent_place(void *_p) {return (int)((XCirculateRequestEvent *)_p)->place;}
static void set_XCirculateRequestEvent_place(void *_p, int _v) {((XCirculateRequestEvent *)_p)->place = (int)_v;}
static void *alloc_XPropertyEvent(void) {XPropertyEvent *_p = (XPropertyEvent *)malloc(sizeof(XPropertyEvent)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XPropertyEvent(void *_p) {if (_p==NULL) abort(); free((XPropertyEvent *)_p);}
static int get_XPropertyEvent_type(void *_p) {return (int)((XPropertyEvent *)_p)->type;}
static void set_XPropertyEvent_type(void *_p, int _v) {((XPropertyEvent *)_p)->type = (int)_v;}
static unsigned long get_XPropertyEvent_serial(void *_p) {return (unsigned long)((XPropertyEvent *)_p)->serial;}
static void set_XPropertyEvent_serial(void *_p, unsigned long _v) {((XPropertyEvent *)_p)->serial = (unsigned long)_v;}
static int get_XPropertyEvent_send_event(void *_p) {return (int)((XPropertyEvent *)_p)->send_event;}
static void set_XPropertyEvent_send_event(void *_p, int _v) {((XPropertyEvent *)_p)->send_event = (int)_v;}
static void *get_XPropertyEvent_display(void *_p) {return (void *)((XPropertyEvent *)_p)->display;}
static void set_XPropertyEvent_display(void *_p, void *_v) {((XPropertyEvent *)_p)->display = (Display *)_v;}
static unsigned long get_XPropertyEvent_window(void *_p) {return (unsigned long)((XPropertyEvent *)_p)->window;}
static void set_XPropertyEvent_window(void *_p, unsigned long _v) {((XPropertyEvent *)_p)->window = (unsigned long)_v;}
static unsigned long get_XPropertyEvent_atom(void *_p) {return (unsigned long)((XPropertyEvent *)_p)->atom;}
static void set_XPropertyEvent_atom(void *_p, unsigned long _v) {((XPropertyEvent *)_p)->atom = (unsigned long)_v;}
static unsigned long get_XPropertyEvent_time(void *_p) {return (unsigned long)((XPropertyEvent *)_p)->time;}
static void set_XPropertyEvent_time(void *_p, unsigned long _v) {((XPropertyEvent *)_p)->time = (unsigned long)_v;}
static int get_XPropertyEvent_state(void *_p) {return (int)((XPropertyEvent *)_p)->state;}
static void set_XPropertyEvent_state(void *_p, int _v) {((XPropertyEvent *)_p)->state = (int)_v;}
static void *alloc_XSelectionClearEvent(void) {XSelectionClearEvent *_p = (XSelectionClearEvent *)malloc(sizeof(XSelectionClearEvent)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XSelectionClearEvent(void *_p) {if (_p==NULL) abort(); free((XSelectionClearEvent *)_p);}
static int get_XSelectionClearEvent_type(void *_p) {return (int)((XSelectionClearEvent *)_p)->type;}
static void set_XSelectionClearEvent_type(void *_p, int _v) {((XSelectionClearEvent *)_p)->type = (int)_v;}
static unsigned long get_XSelectionClearEvent_serial(void *_p) {return (unsigned long)((XSelectionClearEvent *)_p)->serial;}
static void set_XSelectionClearEvent_serial(void *_p, unsigned long _v) {((XSelectionClearEvent *)_p)->serial = (unsigned long)_v;}
static int get_XSelectionClearEvent_send_event(void *_p) {return (int)((XSelectionClearEvent *)_p)->send_event;}
static void set_XSelectionClearEvent_send_event(void *_p, int _v) {((XSelectionClearEvent *)_p)->send_event = (int)_v;}
static void *get_XSelectionClearEvent_display(void *_p) {return (void *)((XSelectionClearEvent *)_p)->display;}
static void set_XSelectionClearEvent_display(void *_p, void *_v) {((XSelectionClearEvent *)_p)->display = (Display *)_v;}
static unsigned long get_XSelectionClearEvent_window(void *_p) {return (unsigned long)((XSelectionClearEvent *)_p)->window;}
static void set_XSelectionClearEvent_window(void *_p, unsigned long _v) {((XSelectionClearEvent *)_p)->window = (unsigned long)_v;}
static unsigned long get_XSelectionClearEvent_selection(void *_p) {return (unsigned long)((XSelectionClearEvent *)_p)->selection;}
static void set_XSelectionClearEvent_selection(void *_p, unsigned long _v) {((XSelectionClearEvent *)_p)->selection = (unsigned long)_v;}
static unsigned long get_XSelectionClearEvent_time(void *_p) {return (unsigned long)((XSelectionClearEvent *)_p)->time;}
static void set_XSelectionClearEvent_time(void *_p, unsigned long _v) {((XSelectionClearEvent *)_p)->time = (unsigned long)_v;}
static void *alloc_XSelectionRequestEvent(void) {XSelectionRequestEvent *_p = (XSelectionRequestEvent *)malloc(sizeof(XSelectionRequestEvent)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XSelectionRequestEvent(void *_p) {if (_p==NULL) abort(); free((XSelectionRequestEvent *)_p);}
static int get_XSelectionRequestEvent_type(void *_p) {return (int)((XSelectionRequestEvent *)_p)->type;}
static void set_XSelectionRequestEvent_type(void *_p, int _v) {((XSelectionRequestEvent *)_p)->type = (int)_v;}
static unsigned long get_XSelectionRequestEvent_serial(void *_p) {return (unsigned long)((XSelectionRequestEvent *)_p)->serial;}
static void set_XSelectionRequestEvent_serial(void *_p, unsigned long _v) {((XSelectionRequestEvent *)_p)->serial = (unsigned long)_v;}
static int get_XSelectionRequestEvent_send_event(void *_p) {return (int)((XSelectionRequestEvent *)_p)->send_event;}
static void set_XSelectionRequestEvent_send_event(void *_p, int _v) {((XSelectionRequestEvent *)_p)->send_event = (int)_v;}
static void *get_XSelectionRequestEvent_display(void *_p) {return (void *)((XSelectionRequestEvent *)_p)->display;}
static void set_XSelectionRequestEvent_display(void *_p, void *_v) {((XSelectionRequestEvent *)_p)->display = (Display *)_v;}
static unsigned long get_XSelectionRequestEvent_owner(void *_p) {return (unsigned long)((XSelectionRequestEvent *)_p)->owner;}
static void set_XSelectionRequestEvent_owner(void *_p, unsigned long _v) {((XSelectionRequestEvent *)_p)->owner = (unsigned long)_v;}
static unsigned long get_XSelectionRequestEvent_requestor(void *_p) {return (unsigned long)((XSelectionRequestEvent *)_p)->requestor;}
static void set_XSelectionRequestEvent_requestor(void *_p, unsigned long _v) {((XSelectionRequestEvent *)_p)->requestor = (unsigned long)_v;}
static unsigned long get_XSelectionRequestEvent_selection(void *_p) {return (unsigned long)((XSelectionRequestEvent *)_p)->selection;}
static void set_XSelectionRequestEvent_selection(void *_p, unsigned long _v) {((XSelectionRequestEvent *)_p)->selection = (unsigned long)_v;}
static unsigned long get_XSelectionRequestEvent_target(void *_p) {return (unsigned long)((XSelectionRequestEvent *)_p)->target;}
static void set_XSelectionRequestEvent_target(void *_p, unsigned long _v) {((XSelectionRequestEvent *)_p)->target = (unsigned long)_v;}
static unsigned long get_XSelectionRequestEvent_property(void *_p) {return (unsigned long)((XSelectionRequestEvent *)_p)->property;}
static void set_XSelectionRequestEvent_property(void *_p, unsigned long _v) {((XSelectionRequestEvent *)_p)->property = (unsigned long)_v;}
static unsigned long get_XSelectionRequestEvent_time(void *_p) {return (unsigned long)((XSelectionRequestEvent *)_p)->time;}
static void set_XSelectionRequestEvent_time(void *_p, unsigned long _v) {((XSelectionRequestEvent *)_p)->time = (unsigned long)_v;}
static void *alloc_XSelectionEvent(void) {XSelectionEvent *_p = (XSelectionEvent *)malloc(sizeof(XSelectionEvent)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XSelectionEvent(void *_p) {if (_p==NULL) abort(); free((XSelectionEvent *)_p);}
static int get_XSelectionEvent_type(void *_p) {return (int)((XSelectionEvent *)_p)->type;}
static void set_XSelectionEvent_type(void *_p, int _v) {((XSelectionEvent *)_p)->type = (int)_v;}
static unsigned long get_XSelectionEvent_serial(void *_p) {return (unsigned long)((XSelectionEvent *)_p)->serial;}
static void set_XSelectionEvent_serial(void *_p, unsigned long _v) {((XSelectionEvent *)_p)->serial = (unsigned long)_v;}
static int get_XSelectionEvent_send_event(void *_p) {return (int)((XSelectionEvent *)_p)->send_event;}
static void set_XSelectionEvent_send_event(void *_p, int _v) {((XSelectionEvent *)_p)->send_event = (int)_v;}
static void *get_XSelectionEvent_display(void *_p) {return (void *)((XSelectionEvent *)_p)->display;}
static void set_XSelectionEvent_display(void *_p, void *_v) {((XSelectionEvent *)_p)->display = (Display *)_v;}
static unsigned long get_XSelectionEvent_requestor(void *_p) {return (unsigned long)((XSelectionEvent *)_p)->requestor;}
static void set_XSelectionEvent_requestor(void *_p, unsigned long _v) {((XSelectionEvent *)_p)->requestor = (unsigned long)_v;}
static unsigned long get_XSelectionEvent_selection(void *_p) {return (unsigned long)((XSelectionEvent *)_p)->selection;}
static void set_XSelectionEvent_selection(void *_p, unsigned long _v) {((XSelectionEvent *)_p)->selection = (unsigned long)_v;}
static unsigned long get_XSelectionEvent_target(void *_p) {return (unsigned long)((XSelectionEvent *)_p)->target;}
static void set_XSelectionEvent_target(void *_p, unsigned long _v) {((XSelectionEvent *)_p)->target = (unsigned long)_v;}
static unsigned long get_XSelectionEvent_property(void *_p) {return (unsigned long)((XSelectionEvent *)_p)->property;}
static void set_XSelectionEvent_property(void *_p, unsigned long _v) {((XSelectionEvent *)_p)->property = (unsigned long)_v;}
static unsigned long get_XSelectionEvent_time(void *_p) {return (unsigned long)((XSelectionEvent *)_p)->time;}
static void set_XSelectionEvent_time(void *_p, unsigned long _v) {((XSelectionEvent *)_p)->time = (unsigned long)_v;}
static void *alloc_XColormapEvent(void) {XColormapEvent *_p = (XColormapEvent *)malloc(sizeof(XColormapEvent)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XColormapEvent(void *_p) {if (_p==NULL) abort(); free((XColormapEvent *)_p);}
static int get_XColormapEvent_type(void *_p) {return (int)((XColormapEvent *)_p)->type;}
static void set_XColormapEvent_type(void *_p, int _v) {((XColormapEvent *)_p)->type = (int)_v;}
static unsigned long get_XColormapEvent_serial(void *_p) {return (unsigned long)((XColormapEvent *)_p)->serial;}
static void set_XColormapEvent_serial(void *_p, unsigned long _v) {((XColormapEvent *)_p)->serial = (unsigned long)_v;}
static int get_XColormapEvent_send_event(void *_p) {return (int)((XColormapEvent *)_p)->send_event;}
static void set_XColormapEvent_send_event(void *_p, int _v) {((XColormapEvent *)_p)->send_event = (int)_v;}
static void *get_XColormapEvent_display(void *_p) {return (void *)((XColormapEvent *)_p)->display;}
static void set_XColormapEvent_display(void *_p, void *_v) {((XColormapEvent *)_p)->display = (Display *)_v;}
static unsigned long get_XColormapEvent_window(void *_p) {return (unsigned long)((XColormapEvent *)_p)->window;}
static void set_XColormapEvent_window(void *_p, unsigned long _v) {((XColormapEvent *)_p)->window = (unsigned long)_v;}
static unsigned long get_XColormapEvent_colormap(void *_p) {return (unsigned long)((XColormapEvent *)_p)->colormap;}
static void set_XColormapEvent_colormap(void *_p, unsigned long _v) {((XColormapEvent *)_p)->colormap = (unsigned long)_v;}
static int get_XColormapEvent_new(void *_p) {return (int)((XColormapEvent *)_p)->new;}
static void set_XColormapEvent_new(void *_p, int _v) {((XColormapEvent *)_p)->new = (int)_v;}
static int get_XColormapEvent_state(void *_p) {return (int)((XColormapEvent *)_p)->state;}
static void set_XColormapEvent_state(void *_p, int _v) {((XColormapEvent *)_p)->state = (int)_v;}
static void *alloc_XClientMessageEvent(void) {XClientMessageEvent *_p = (XClientMessageEvent *)malloc(sizeof(XClientMessageEvent)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XClientMessageEvent(void *_p) {if (_p==NULL) abort(); free((XClientMessageEvent *)_p);}
static int get_XClientMessageEvent_type(void *_p) {return (int)((XClientMessageEvent *)_p)->type;}
static void set_XClientMessageEvent_type(void *_p, int _v) {((XClientMessageEvent *)_p)->type = (int)_v;}
static unsigned long get_XClientMessageEvent_serial(void *_p) {return (unsigned long)((XClientMessageEvent *)_p)->serial;}
static void set_XClientMessageEvent_serial(void *_p, unsigned long _v) {((XClientMessageEvent *)_p)->serial = (unsigned long)_v;}
static int get_XClientMessageEvent_send_event(void *_p) {return (int)((XClientMessageEvent *)_p)->send_event;}
static void set_XClientMessageEvent_send_event(void *_p, int _v) {((XClientMessageEvent *)_p)->send_event = (int)_v;}
static void *get_XClientMessageEvent_display(void *_p) {return (void *)((XClientMessageEvent *)_p)->display;}
static void set_XClientMessageEvent_display(void *_p, void *_v) {((XClientMessageEvent *)_p)->display = (Display *)_v;}
static unsigned long get_XClientMessageEvent_window(void *_p) {return (unsigned long)((XClientMessageEvent *)_p)->window;}
static void set_XClientMessageEvent_window(void *_p, unsigned long _v) {((XClientMessageEvent *)_p)->window = (unsigned long)_v;}
static unsigned long get_XClientMessageEvent_message_type(void *_p) {return (unsigned long)((XClientMessageEvent *)_p)->message_type;}
static void set_XClientMessageEvent_message_type(void *_p, unsigned long _v) {((XClientMessageEvent *)_p)->message_type = (unsigned long)_v;}
static int get_XClientMessageEvent_format(void *_p) {return (int)((XClientMessageEvent *)_p)->format;}
static void set_XClientMessageEvent_format(void *_p, int _v) {((XClientMessageEvent *)_p)->format = (int)_v;}
static void *get_XClientMessageEvent_data_b(void *_p) {return (void *)(((XClientMessageEvent *)_p)->data.b);}
static void *get_XClientMessageEvent_data_s(void *_p) {return (void *)(((XClientMessageEvent *)_p)->data.s);}
static void *get_XClientMessageEvent_data_l(void *_p) {return (void *)(((XClientMessageEvent *)_p)->data.l);}
static void *alloc_XMappingEvent(void) {XMappingEvent *_p = (XMappingEvent *)malloc(sizeof(XMappingEvent)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XMappingEvent(void *_p) {if (_p==NULL) abort(); free((XMappingEvent *)_p);}
static int get_XMappingEvent_type(void *_p) {return (int)((XMappingEvent *)_p)->type;}
static void set_XMappingEvent_type(void *_p, int _v) {((XMappingEvent *)_p)->type = (int)_v;}
static unsigned long get_XMappingEvent_serial(void *_p) {return (unsigned long)((XMappingEvent *)_p)->serial;}
static void set_XMappingEvent_serial(void *_p, unsigned long _v) {((XMappingEvent *)_p)->serial = (unsigned long)_v;}
static int get_XMappingEvent_send_event(void *_p) {return (int)((XMappingEvent *)_p)->send_event;}
static void set_XMappingEvent_send_event(void *_p, int _v) {((XMappingEvent *)_p)->send_event = (int)_v;}
static void *get_XMappingEvent_display(void *_p) {return (void *)((XMappingEvent *)_p)->display;}
static void set_XMappingEvent_display(void *_p, void *_v) {((XMappingEvent *)_p)->display = (Display *)_v;}
static unsigned long get_XMappingEvent_window(void *_p) {return (unsigned long)((XMappingEvent *)_p)->window;}
static void set_XMappingEvent_window(void *_p, unsigned long _v) {((XMappingEvent *)_p)->window = (unsigned long)_v;}
static int get_XMappingEvent_request(void *_p) {return (int)((XMappingEvent *)_p)->request;}
static void set_XMappingEvent_request(void *_p, int _v) {((XMappingEvent *)_p)->request = (int)_v;}
static int get_XMappingEvent_first_keycode(void *_p) {return (int)((XMappingEvent *)_p)->first_keycode;}
static void set_XMappingEvent_first_keycode(void *_p, int _v) {((XMappingEvent *)_p)->first_keycode = (int)_v;}
static int get_XMappingEvent_count(void *_p) {return (int)((XMappingEvent *)_p)->count;}
static void set_XMappingEvent_count(void *_p, int _v) {((XMappingEvent *)_p)->count = (int)_v;}
static void *alloc_XErrorEvent(void) {XErrorEvent *_p = (XErrorEvent *)malloc(sizeof(XErrorEvent)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XErrorEvent(void *_p) {if (_p==NULL) abort(); free((XErrorEvent *)_p);}
static int get_XErrorEvent_type(void *_p) {return (int)((XErrorEvent *)_p)->type;}
static void set_XErrorEvent_type(void *_p, int _v) {((XErrorEvent *)_p)->type = (int)_v;}
static void *get_XErrorEvent_display(void *_p) {return (void *)((XErrorEvent *)_p)->display;}
static void set_XErrorEvent_display(void *_p, void *_v) {((XErrorEvent *)_p)->display = (Display *)_v;}
static unsigned long get_XErrorEvent_resourceid(void *_p) {return (unsigned long)((XErrorEvent *)_p)->resourceid;}
static void set_XErrorEvent_resourceid(void *_p, unsigned long _v) {((XErrorEvent *)_p)->resourceid = (unsigned long)_v;}
static unsigned long get_XErrorEvent_serial(void *_p) {return (unsigned long)((XErrorEvent *)_p)->serial;}
static void set_XErrorEvent_serial(void *_p, unsigned long _v) {((XErrorEvent *)_p)->serial = (unsigned long)_v;}
static unsigned char get_XErrorEvent_error_code(void *_p) {return (unsigned char)((XErrorEvent *)_p)->error_code;}
static void set_XErrorEvent_error_code(void *_p, unsigned char _v) {((XErrorEvent *)_p)->error_code = (unsigned char)_v;}
static unsigned char get_XErrorEvent_request_code(void *_p) {return (unsigned char)((XErrorEvent *)_p)->request_code;}
static void set_XErrorEvent_request_code(void *_p, unsigned char _v) {((XErrorEvent *)_p)->request_code = (unsigned char)_v;}
static unsigned char get_XErrorEvent_minor_code(void *_p) {return (unsigned char)((XErrorEvent *)_p)->minor_code;}
static void set_XErrorEvent_minor_code(void *_p, unsigned char _v) {((XErrorEvent *)_p)->minor_code = (unsigned char)_v;}
static void *alloc_XAnyEvent(void) {XAnyEvent *_p = (XAnyEvent *)malloc(sizeof(XAnyEvent)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XAnyEvent(void *_p) {if (_p==NULL) abort(); free((XAnyEvent *)_p);}
static int get_XAnyEvent_type(void *_p) {return (int)((XAnyEvent *)_p)->type;}
static void set_XAnyEvent_type(void *_p, int _v) {((XAnyEvent *)_p)->type = (int)_v;}
static unsigned long get_XAnyEvent_serial(void *_p) {return (unsigned long)((XAnyEvent *)_p)->serial;}
static void set_XAnyEvent_serial(void *_p, unsigned long _v) {((XAnyEvent *)_p)->serial = (unsigned long)_v;}
static int get_XAnyEvent_send_event(void *_p) {return (int)((XAnyEvent *)_p)->send_event;}
static void set_XAnyEvent_send_event(void *_p, int _v) {((XAnyEvent *)_p)->send_event = (int)_v;}
static void *get_XAnyEvent_display(void *_p) {return (void *)((XAnyEvent *)_p)->display;}
static void set_XAnyEvent_display(void *_p, void *_v) {((XAnyEvent *)_p)->display = (Display *)_v;}
static unsigned long get_XAnyEvent_window(void *_p) {return (unsigned long)((XAnyEvent *)_p)->window;}
static void set_XAnyEvent_window(void *_p, unsigned long _v) {((XAnyEvent *)_p)->window = (unsigned long)_v;}
static void *alloc_XCharStruct(void) {XCharStruct *_p = (XCharStruct *)malloc(sizeof(XCharStruct)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XCharStruct(void *_p) {if (_p==NULL) abort(); free((XCharStruct *)_p);}
static short get_XCharStruct_lbearing(void *_p) {return (short)((XCharStruct *)_p)->lbearing;}
static void set_XCharStruct_lbearing(void *_p, short _v) {((XCharStruct *)_p)->lbearing = (short)_v;}
static short get_XCharStruct_rbearing(void *_p) {return (short)((XCharStruct *)_p)->rbearing;}
static void set_XCharStruct_rbearing(void *_p, short _v) {((XCharStruct *)_p)->rbearing = (short)_v;}
static short get_XCharStruct_width(void *_p) {return (short)((XCharStruct *)_p)->width;}
static void set_XCharStruct_width(void *_p, short _v) {((XCharStruct *)_p)->width = (short)_v;}
static short get_XCharStruct_ascent(void *_p) {return (short)((XCharStruct *)_p)->ascent;}
static void set_XCharStruct_ascent(void *_p, short _v) {((XCharStruct *)_p)->ascent = (short)_v;}
static short get_XCharStruct_descent(void *_p) {return (short)((XCharStruct *)_p)->descent;}
static void set_XCharStruct_descent(void *_p, short _v) {((XCharStruct *)_p)->descent = (short)_v;}
static unsigned short get_XCharStruct_attributes(void *_p) {return (unsigned short)((XCharStruct *)_p)->attributes;}
static void set_XCharStruct_attributes(void *_p, unsigned short _v) {((XCharStruct *)_p)->attributes = (unsigned short)_v;}
static void *alloc_XFontProp(void) {XFontProp *_p = (XFontProp *)malloc(sizeof(XFontProp)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XFontProp(void *_p) {if (_p==NULL) abort(); free((XFontProp *)_p);}
static unsigned long get_XFontProp_name(void *_p) {return (unsigned long)((XFontProp *)_p)->name;}
static void set_XFontProp_name(void *_p, unsigned long _v) {((XFontProp *)_p)->name = (unsigned long)_v;}
static unsigned long get_XFontProp_card32(void *_p) {return (unsigned long)((XFontProp *)_p)->card32;}
static void set_XFontProp_card32(void *_p, unsigned long _v) {((XFontProp *)_p)->card32 = (unsigned long)_v;}
static void *alloc_XFontStruct(void) {XFontStruct *_p = (XFontStruct *)malloc(sizeof(XFontStruct)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XFontStruct(void *_p) {if (_p==NULL) abort(); free((XFontStruct *)_p);}
static void *get_XFontStruct_ext_data(void *_p) {return (void *)((XFontStruct *)_p)->ext_data;}
static void set_XFontStruct_ext_data(void *_p, void *_v) {((XFontStruct *)_p)->ext_data = (XExtData *)_v;}
static unsigned long get_XFontStruct_fid(void *_p) {return (unsigned long)((XFontStruct *)_p)->fid;}
static void set_XFontStruct_fid(void *_p, unsigned long _v) {((XFontStruct *)_p)->fid = (unsigned long)_v;}
static unsigned get_XFontStruct_direction(void *_p) {return (unsigned)((XFontStruct *)_p)->direction;}
static void set_XFontStruct_direction(void *_p, unsigned _v) {((XFontStruct *)_p)->direction = (unsigned)_v;}
static unsigned get_XFontStruct_min_char_or_byte2(void *_p) {return (unsigned)((XFontStruct *)_p)->min_char_or_byte2;}
static void set_XFontStruct_min_char_or_byte2(void *_p, unsigned _v) {((XFontStruct *)_p)->min_char_or_byte2 = (unsigned)_v;}
static unsigned get_XFontStruct_max_char_or_byte2(void *_p) {return (unsigned)((XFontStruct *)_p)->max_char_or_byte2;}
static void set_XFontStruct_max_char_or_byte2(void *_p, unsigned _v) {((XFontStruct *)_p)->max_char_or_byte2 = (unsigned)_v;}
static unsigned get_XFontStruct_min_byte1(void *_p) {return (unsigned)((XFontStruct *)_p)->min_byte1;}
static void set_XFontStruct_min_byte1(void *_p, unsigned _v) {((XFontStruct *)_p)->min_byte1 = (unsigned)_v;}
static unsigned get_XFontStruct_max_byte1(void *_p) {return (unsigned)((XFontStruct *)_p)->max_byte1;}
static void set_XFontStruct_max_byte1(void *_p, unsigned _v) {((XFontStruct *)_p)->max_byte1 = (unsigned)_v;}
static int get_XFontStruct_all_chars_exist(void *_p) {return (int)((XFontStruct *)_p)->all_chars_exist;}
static void set_XFontStruct_all_chars_exist(void *_p, int _v) {((XFontStruct *)_p)->all_chars_exist = (int)_v;}
static unsigned get_XFontStruct_default_char(void *_p) {return (unsigned)((XFontStruct *)_p)->default_char;}
static void set_XFontStruct_default_char(void *_p, unsigned _v) {((XFontStruct *)_p)->default_char = (unsigned)_v;}
static int get_XFontStruct_n_properties(void *_p) {return (int)((XFontStruct *)_p)->n_properties;}
static void set_XFontStruct_n_properties(void *_p, int _v) {((XFontStruct *)_p)->n_properties = (int)_v;}
static void *get_XFontStruct_properties(void *_p) {return (void *)((XFontStruct *)_p)->properties;}
static void set_XFontStruct_properties(void *_p, void *_v) {((XFontStruct *)_p)->properties = (XFontProp *)_v;}
static short get_XFontStruct_min_bounds_lbearing(void *_p) {return (short)((XFontStruct *)_p)->min_bounds.lbearing;}
static void set_XFontStruct_min_bounds_lbearing(void *_p, short _v) {((XFontStruct *)_p)->min_bounds.lbearing = (short)_v;}
static short get_XFontStruct_min_bounds_rbearing(void *_p) {return (short)((XFontStruct *)_p)->min_bounds.rbearing;}
static void set_XFontStruct_min_bounds_rbearing(void *_p, short _v) {((XFontStruct *)_p)->min_bounds.rbearing = (short)_v;}
static short get_XFontStruct_min_bounds_width(void *_p) {return (short)((XFontStruct *)_p)->min_bounds.width;}
static void set_XFontStruct_min_bounds_width(void *_p, short _v) {((XFontStruct *)_p)->min_bounds.width = (short)_v;}
static short get_XFontStruct_min_bounds_ascent(void *_p) {return (short)((XFontStruct *)_p)->min_bounds.ascent;}
static void set_XFontStruct_min_bounds_ascent(void *_p, short _v) {((XFontStruct *)_p)->min_bounds.ascent = (short)_v;}
static short get_XFontStruct_min_bounds_descent(void *_p) {return (short)((XFontStruct *)_p)->min_bounds.descent;}
static void set_XFontStruct_min_bounds_descent(void *_p, short _v) {((XFontStruct *)_p)->min_bounds.descent = (short)_v;}
static unsigned short get_XFontStruct_min_bounds_attributes(void *_p) {return (unsigned short)((XFontStruct *)_p)->min_bounds.attributes;}
static void set_XFontStruct_min_bounds_attributes(void *_p, unsigned short _v) {((XFontStruct *)_p)->min_bounds.attributes = (unsigned short)_v;}
static short get_XFontStruct_max_bounds_lbearing(void *_p) {return (short)((XFontStruct *)_p)->max_bounds.lbearing;}
static void set_XFontStruct_max_bounds_lbearing(void *_p, short _v) {((XFontStruct *)_p)->max_bounds.lbearing = (short)_v;}
static short get_XFontStruct_max_bounds_rbearing(void *_p) {return (short)((XFontStruct *)_p)->max_bounds.rbearing;}
static void set_XFontStruct_max_bounds_rbearing(void *_p, short _v) {((XFontStruct *)_p)->max_bounds.rbearing = (short)_v;}
static short get_XFontStruct_max_bounds_width(void *_p) {return (short)((XFontStruct *)_p)->max_bounds.width;}
static void set_XFontStruct_max_bounds_width(void *_p, short _v) {((XFontStruct *)_p)->max_bounds.width = (short)_v;}
static short get_XFontStruct_max_bounds_ascent(void *_p) {return (short)((XFontStruct *)_p)->max_bounds.ascent;}
static void set_XFontStruct_max_bounds_ascent(void *_p, short _v) {((XFontStruct *)_p)->max_bounds.ascent = (short)_v;}
static short get_XFontStruct_max_bounds_descent(void *_p) {return (short)((XFontStruct *)_p)->max_bounds.descent;}
static void set_XFontStruct_max_bounds_descent(void *_p, short _v) {((XFontStruct *)_p)->max_bounds.descent = (short)_v;}
static unsigned short get_XFontStruct_max_bounds_attributes(void *_p) {return (unsigned short)((XFontStruct *)_p)->max_bounds.attributes;}
static void set_XFontStruct_max_bounds_attributes(void *_p, unsigned short _v) {((XFontStruct *)_p)->max_bounds.attributes = (unsigned short)_v;}
static void *get_XFontStruct_per_char(void *_p) {return (void *)((XFontStruct *)_p)->per_char;}
static void set_XFontStruct_per_char(void *_p, void *_v) {((XFontStruct *)_p)->per_char = (XCharStruct *)_v;}
static int get_XFontStruct_ascent(void *_p) {return (int)((XFontStruct *)_p)->ascent;}
static void set_XFontStruct_ascent(void *_p, int _v) {((XFontStruct *)_p)->ascent = (int)_v;}
static int get_XFontStruct_descent(void *_p) {return (int)((XFontStruct *)_p)->descent;}
static void set_XFontStruct_descent(void *_p, int _v) {((XFontStruct *)_p)->descent = (int)_v;}
static void *alloc_XTextItem(void) {XTextItem *_p = (XTextItem *)malloc(sizeof(XTextItem)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XTextItem(void *_p) {if (_p==NULL) abort(); free((XTextItem *)_p);}
static void *get_XTextItem_chars(void *_p) {return (void *)((XTextItem *)_p)->chars;}
static void set_XTextItem_chars(void *_p, void *_v) {((XTextItem *)_p)->chars = (char *)_v;}
static int get_XTextItem_nchars(void *_p) {return (int)((XTextItem *)_p)->nchars;}
static void set_XTextItem_nchars(void *_p, int _v) {((XTextItem *)_p)->nchars = (int)_v;}
static int get_XTextItem_delta(void *_p) {return (int)((XTextItem *)_p)->delta;}
static void set_XTextItem_delta(void *_p, int _v) {((XTextItem *)_p)->delta = (int)_v;}
static unsigned long get_XTextItem_font(void *_p) {return (unsigned long)((XTextItem *)_p)->font;}
static void set_XTextItem_font(void *_p, unsigned long _v) {((XTextItem *)_p)->font = (unsigned long)_v;}
static void *alloc_XChar2b(void) {XChar2b *_p = (XChar2b *)malloc(sizeof(XChar2b)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XChar2b(void *_p) {if (_p==NULL) abort(); free((XChar2b *)_p);}
static unsigned char get_XChar2b_byte1(void *_p) {return (unsigned char)((XChar2b *)_p)->byte1;}
static void set_XChar2b_byte1(void *_p, unsigned char _v) {((XChar2b *)_p)->byte1 = (unsigned char)_v;}
static unsigned char get_XChar2b_byte2(void *_p) {return (unsigned char)((XChar2b *)_p)->byte2;}
static void set_XChar2b_byte2(void *_p, unsigned char _v) {((XChar2b *)_p)->byte2 = (unsigned char)_v;}
static void *alloc_XTextItem16(void) {XTextItem16 *_p = (XTextItem16 *)malloc(sizeof(XTextItem16)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XTextItem16(void *_p) {if (_p==NULL) abort(); free((XTextItem16 *)_p);}
static void *get_XTextItem16_chars(void *_p) {return (void *)((XTextItem16 *)_p)->chars;}
static void set_XTextItem16_chars(void *_p, void *_v) {((XTextItem16 *)_p)->chars = (XChar2b *)_v;}
static int get_XTextItem16_nchars(void *_p) {return (int)((XTextItem16 *)_p)->nchars;}
static void set_XTextItem16_nchars(void *_p, int _v) {((XTextItem16 *)_p)->nchars = (int)_v;}
static int get_XTextItem16_delta(void *_p) {return (int)((XTextItem16 *)_p)->delta;}
static void set_XTextItem16_delta(void *_p, int _v) {((XTextItem16 *)_p)->delta = (int)_v;}
static unsigned long get_XTextItem16_font(void *_p) {return (unsigned long)((XTextItem16 *)_p)->font;}
static void set_XTextItem16_font(void *_p, unsigned long _v) {((XTextItem16 *)_p)->font = (unsigned long)_v;}
static void *alloc_XFontSetExtents(void) {XFontSetExtents *_p = (XFontSetExtents *)malloc(sizeof(XFontSetExtents)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XFontSetExtents(void *_p) {if (_p==NULL) abort(); free((XFontSetExtents *)_p);}
static short get_XFontSetExtents_max_ink_extent_x(void *_p) {return (short)((XFontSetExtents *)_p)->max_ink_extent.x;}
static void set_XFontSetExtents_max_ink_extent_x(void *_p, short _v) {((XFontSetExtents *)_p)->max_ink_extent.x = (short)_v;}
static short get_XFontSetExtents_max_ink_extent_y(void *_p) {return (short)((XFontSetExtents *)_p)->max_ink_extent.y;}
static void set_XFontSetExtents_max_ink_extent_y(void *_p, short _v) {((XFontSetExtents *)_p)->max_ink_extent.y = (short)_v;}
static unsigned short get_XFontSetExtents_max_ink_extent_width(void *_p) {return (unsigned short)((XFontSetExtents *)_p)->max_ink_extent.width;}
static void set_XFontSetExtents_max_ink_extent_width(void *_p, unsigned short _v) {((XFontSetExtents *)_p)->max_ink_extent.width = (unsigned short)_v;}
static unsigned short get_XFontSetExtents_max_ink_extent_height(void *_p) {return (unsigned short)((XFontSetExtents *)_p)->max_ink_extent.height;}
static void set_XFontSetExtents_max_ink_extent_height(void *_p, unsigned short _v) {((XFontSetExtents *)_p)->max_ink_extent.height = (unsigned short)_v;}
static short get_XFontSetExtents_max_logical_extent_x(void *_p) {return (short)((XFontSetExtents *)_p)->max_logical_extent.x;}
static void set_XFontSetExtents_max_logical_extent_x(void *_p, short _v) {((XFontSetExtents *)_p)->max_logical_extent.x = (short)_v;}
static short get_XFontSetExtents_max_logical_extent_y(void *_p) {return (short)((XFontSetExtents *)_p)->max_logical_extent.y;}
static void set_XFontSetExtents_max_logical_extent_y(void *_p, short _v) {((XFontSetExtents *)_p)->max_logical_extent.y = (short)_v;}
static unsigned short get_XFontSetExtents_max_logical_extent_width(void *_p) {return (unsigned short)((XFontSetExtents *)_p)->max_logical_extent.width;}
static void set_XFontSetExtents_max_logical_extent_width(void *_p, unsigned short _v) {((XFontSetExtents *)_p)->max_logical_extent.width = (unsigned short)_v;}
static unsigned short get_XFontSetExtents_max_logical_extent_height(void *_p) {return (unsigned short)((XFontSetExtents *)_p)->max_logical_extent.height;}
static void set_XFontSetExtents_max_logical_extent_height(void *_p, unsigned short _v) {((XFontSetExtents *)_p)->max_logical_extent.height = (unsigned short)_v;}
static void *alloc_XmbTextItem(void) {XmbTextItem *_p = (XmbTextItem *)malloc(sizeof(XmbTextItem)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XmbTextItem(void *_p) {if (_p==NULL) abort(); free((XmbTextItem *)_p);}
static void *get_XmbTextItem_chars(void *_p) {return (void *)((XmbTextItem *)_p)->chars;}
static void set_XmbTextItem_chars(void *_p, void *_v) {((XmbTextItem *)_p)->chars = (char *)_v;}
static int get_XmbTextItem_nchars(void *_p) {return (int)((XmbTextItem *)_p)->nchars;}
static void set_XmbTextItem_nchars(void *_p, int _v) {((XmbTextItem *)_p)->nchars = (int)_v;}
static int get_XmbTextItem_delta(void *_p) {return (int)((XmbTextItem *)_p)->delta;}
static void set_XmbTextItem_delta(void *_p, int _v) {((XmbTextItem *)_p)->delta = (int)_v;}
static void *get_XmbTextItem_font_set(void *_p) {return (void *)((XmbTextItem *)_p)->font_set;}
static void set_XmbTextItem_font_set(void *_p, void *_v) {((XmbTextItem *)_p)->font_set = (void *)_v;}
static void *alloc_XwcTextItem(void) {XwcTextItem *_p = (XwcTextItem *)malloc(sizeof(XwcTextItem)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XwcTextItem(void *_p) {if (_p==NULL) abort(); free((XwcTextItem *)_p);}
static void *get_XwcTextItem_chars(void *_p) {return (void *)((XwcTextItem *)_p)->chars;}
static void set_XwcTextItem_chars(void *_p, void *_v) {((XwcTextItem *)_p)->chars = (wchar_t *)_v;}
static int get_XwcTextItem_nchars(void *_p) {return (int)((XwcTextItem *)_p)->nchars;}
static void set_XwcTextItem_nchars(void *_p, int _v) {((XwcTextItem *)_p)->nchars = (int)_v;}
static int get_XwcTextItem_delta(void *_p) {return (int)((XwcTextItem *)_p)->delta;}
static void set_XwcTextItem_delta(void *_p, int _v) {((XwcTextItem *)_p)->delta = (int)_v;}
static void *get_XwcTextItem_font_set(void *_p) {return (void *)((XwcTextItem *)_p)->font_set;}
static void set_XwcTextItem_font_set(void *_p, void *_v) {((XwcTextItem *)_p)->font_set = (void *)_v;}
static void *alloc_XIMStyles(void) {XIMStyles *_p = (XIMStyles *)malloc(sizeof(XIMStyles)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XIMStyles(void *_p) {if (_p==NULL) abort(); free((XIMStyles *)_p);}
static unsigned short get_XIMStyles_count_styles(void *_p) {return (unsigned short)((XIMStyles *)_p)->count_styles;}
static void set_XIMStyles_count_styles(void *_p, unsigned short _v) {((XIMStyles *)_p)->count_styles = (unsigned short)_v;}
static void *get_XIMStyles_supported_styles(void *_p) {return (void *)((XIMStyles *)_p)->supported_styles;}
static void set_XIMStyles_supported_styles(void *_p, void *_v) {((XIMStyles *)_p)->supported_styles = (unsigned long *)_v;}
static void *alloc_XIMCallback(void) {XIMCallback *_p = (XIMCallback *)malloc(sizeof(XIMCallback)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XIMCallback(void *_p) {if (_p==NULL) abort(); free((XIMCallback *)_p);}
static void *get_XIMCallback_client_data(void *_p) {return (void *)((XIMCallback *)_p)->client_data;}
static void set_XIMCallback_client_data(void *_p, void *_v) {((XIMCallback *)_p)->client_data = (char *)_v;}
static void *get_XIMCallback_callback(void *_p) {return (void *)((XIMCallback *)_p)->callback;}
static void set_XIMCallback_callback(void *_p, void *_v) {((XIMCallback *)_p)->callback = (void( *)())_v;}
static void *alloc_XIMText(void) {XIMText *_p = (XIMText *)malloc(sizeof(XIMText)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XIMText(void *_p) {if (_p==NULL) abort(); free((XIMText *)_p);}
static unsigned short get_XIMText_length(void *_p) {return (unsigned short)((XIMText *)_p)->length;}
static void set_XIMText_length(void *_p, unsigned short _v) {((XIMText *)_p)->length = (unsigned short)_v;}
static void *get_XIMText_feedback(void *_p) {return (void *)((XIMText *)_p)->feedback;}
static void set_XIMText_feedback(void *_p, void *_v) {((XIMText *)_p)->feedback = (unsigned long *)_v;}
static int get_XIMText_encoding_is_wchar(void *_p) {return (int)((XIMText *)_p)->encoding_is_wchar;}
static void set_XIMText_encoding_is_wchar(void *_p, int _v) {((XIMText *)_p)->encoding_is_wchar = (int)_v;}
static void *get_XIMText_string_multi_byte(void *_p) {return (void *)((XIMText *)_p)->string.multi_byte;}
static void set_XIMText_string_multi_byte(void *_p, void *_v) {((XIMText *)_p)->string.multi_byte = (char *)_v;}
static void *get_XIMText_string_wide_char(void *_p) {return (void *)((XIMText *)_p)->string.wide_char;}
static void set_XIMText_string_wide_char(void *_p, void *_v) {((XIMText *)_p)->string.wide_char = (wchar_t *)_v;}
static void *alloc_XIMPreeditDrawCallbackStruct(void) {XIMPreeditDrawCallbackStruct *_p = (XIMPreeditDrawCallbackStruct *)malloc(sizeof(XIMPreeditDrawCallbackStruct)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XIMPreeditDrawCallbackStruct(void *_p) {if (_p==NULL) abort(); free((XIMPreeditDrawCallbackStruct *)_p);}
static int get_XIMPreeditDrawCallbackStruct_caret(void *_p) {return (int)((XIMPreeditDrawCallbackStruct *)_p)->caret;}
static void set_XIMPreeditDrawCallbackStruct_caret(void *_p, int _v) {((XIMPreeditDrawCallbackStruct *)_p)->caret = (int)_v;}
static int get_XIMPreeditDrawCallbackStruct_chg_first(void *_p) {return (int)((XIMPreeditDrawCallbackStruct *)_p)->chg_first;}
static void set_XIMPreeditDrawCallbackStruct_chg_first(void *_p, int _v) {((XIMPreeditDrawCallbackStruct *)_p)->chg_first = (int)_v;}
static int get_XIMPreeditDrawCallbackStruct_chg_length(void *_p) {return (int)((XIMPreeditDrawCallbackStruct *)_p)->chg_length;}
static void set_XIMPreeditDrawCallbackStruct_chg_length(void *_p, int _v) {((XIMPreeditDrawCallbackStruct *)_p)->chg_length = (int)_v;}
static void *get_XIMPreeditDrawCallbackStruct_text(void *_p) {return (void *)((XIMPreeditDrawCallbackStruct *)_p)->text;}
static void set_XIMPreeditDrawCallbackStruct_text(void *_p, void *_v) {((XIMPreeditDrawCallbackStruct *)_p)->text = (XIMText *)_v;}
static void *alloc_XIMPreeditCaretCallbackStruct(void) {XIMPreeditCaretCallbackStruct *_p = (XIMPreeditCaretCallbackStruct *)malloc(sizeof(XIMPreeditCaretCallbackStruct)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XIMPreeditCaretCallbackStruct(void *_p) {if (_p==NULL) abort(); free((XIMPreeditCaretCallbackStruct *)_p);}
static int get_XIMPreeditCaretCallbackStruct_position(void *_p) {return (int)((XIMPreeditCaretCallbackStruct *)_p)->position;}
static void set_XIMPreeditCaretCallbackStruct_position(void *_p, int _v) {((XIMPreeditCaretCallbackStruct *)_p)->position = (int)_v;}
static int get_XIMPreeditCaretCallbackStruct_direction(void *_p) {return (int)((XIMPreeditCaretCallbackStruct *)_p)->direction;}
static void set_XIMPreeditCaretCallbackStruct_direction(void *_p, int _v) {((XIMPreeditCaretCallbackStruct *)_p)->direction = (int)_v;}
static int get_XIMPreeditCaretCallbackStruct_style(void *_p) {return (int)((XIMPreeditCaretCallbackStruct *)_p)->style;}
static void set_XIMPreeditCaretCallbackStruct_style(void *_p, int _v) {((XIMPreeditCaretCallbackStruct *)_p)->style = (int)_v;}
static void *alloc_XIMStatusDrawCallbackStruct(void) {XIMStatusDrawCallbackStruct *_p = (XIMStatusDrawCallbackStruct *)malloc(sizeof(XIMStatusDrawCallbackStruct)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XIMStatusDrawCallbackStruct(void *_p) {if (_p==NULL) abort(); free((XIMStatusDrawCallbackStruct *)_p);}
static int get_XIMStatusDrawCallbackStruct_type(void *_p) {return (int)((XIMStatusDrawCallbackStruct *)_p)->type;}
static void set_XIMStatusDrawCallbackStruct_type(void *_p, int _v) {((XIMStatusDrawCallbackStruct *)_p)->type = (int)_v;}
static void *get_XIMStatusDrawCallbackStruct_data_text(void *_p) {return (void *)((XIMStatusDrawCallbackStruct *)_p)->data.text;}
static void set_XIMStatusDrawCallbackStruct_data_text(void *_p, void *_v) {((XIMStatusDrawCallbackStruct *)_p)->data.text = (XIMText *)_v;}
static unsigned long get_XIMStatusDrawCallbackStruct_data_bitmap(void *_p) {return (unsigned long)((XIMStatusDrawCallbackStruct *)_p)->data.bitmap;}
static void set_XIMStatusDrawCallbackStruct_data_bitmap(void *_p, unsigned long _v) {((XIMStatusDrawCallbackStruct *)_p)->data.bitmap = (unsigned long)_v;}
static void *alloc_XSizeHints(void) {XSizeHints *_p = (XSizeHints *)malloc(sizeof(XSizeHints)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XSizeHints(void *_p) {if (_p==NULL) abort(); free((XSizeHints *)_p);}
static long get_XSizeHints_flags(void *_p) {return (long)((XSizeHints *)_p)->flags;}
static void set_XSizeHints_flags(void *_p, long _v) {((XSizeHints *)_p)->flags = (long)_v;}
static int get_XSizeHints_x(void *_p) {return (int)((XSizeHints *)_p)->x;}
static void set_XSizeHints_x(void *_p, int _v) {((XSizeHints *)_p)->x = (int)_v;}
static int get_XSizeHints_y(void *_p) {return (int)((XSizeHints *)_p)->y;}
static void set_XSizeHints_y(void *_p, int _v) {((XSizeHints *)_p)->y = (int)_v;}
static int get_XSizeHints_width(void *_p) {return (int)((XSizeHints *)_p)->width;}
static void set_XSizeHints_width(void *_p, int _v) {((XSizeHints *)_p)->width = (int)_v;}
static int get_XSizeHints_height(void *_p) {return (int)((XSizeHints *)_p)->height;}
static void set_XSizeHints_height(void *_p, int _v) {((XSizeHints *)_p)->height = (int)_v;}
static int get_XSizeHints_min_width(void *_p) {return (int)((XSizeHints *)_p)->min_width;}
static void set_XSizeHints_min_width(void *_p, int _v) {((XSizeHints *)_p)->min_width = (int)_v;}
static int get_XSizeHints_min_height(void *_p) {return (int)((XSizeHints *)_p)->min_height;}
static void set_XSizeHints_min_height(void *_p, int _v) {((XSizeHints *)_p)->min_height = (int)_v;}
static int get_XSizeHints_max_width(void *_p) {return (int)((XSizeHints *)_p)->max_width;}
static void set_XSizeHints_max_width(void *_p, int _v) {((XSizeHints *)_p)->max_width = (int)_v;}
static int get_XSizeHints_max_height(void *_p) {return (int)((XSizeHints *)_p)->max_height;}
static void set_XSizeHints_max_height(void *_p, int _v) {((XSizeHints *)_p)->max_height = (int)_v;}
static int get_XSizeHints_width_inc(void *_p) {return (int)((XSizeHints *)_p)->width_inc;}
static void set_XSizeHints_width_inc(void *_p, int _v) {((XSizeHints *)_p)->width_inc = (int)_v;}
static int get_XSizeHints_height_inc(void *_p) {return (int)((XSizeHints *)_p)->height_inc;}
static void set_XSizeHints_height_inc(void *_p, int _v) {((XSizeHints *)_p)->height_inc = (int)_v;}
static int get_XSizeHints_min_aspect_x(void *_p) {return (int)((XSizeHints *)_p)->min_aspect.x;}
static void set_XSizeHints_min_aspect_x(void *_p, int _v) {((XSizeHints *)_p)->min_aspect.x = (int)_v;}
static int get_XSizeHints_min_aspect_y(void *_p) {return (int)((XSizeHints *)_p)->min_aspect.y;}
static void set_XSizeHints_min_aspect_y(void *_p, int _v) {((XSizeHints *)_p)->min_aspect.y = (int)_v;}
static int get_XSizeHints_max_aspect_x(void *_p) {return (int)((XSizeHints *)_p)->max_aspect.x;}
static void set_XSizeHints_max_aspect_x(void *_p, int _v) {((XSizeHints *)_p)->max_aspect.x = (int)_v;}
static int get_XSizeHints_max_aspect_y(void *_p) {return (int)((XSizeHints *)_p)->max_aspect.y;}
static void set_XSizeHints_max_aspect_y(void *_p, int _v) {((XSizeHints *)_p)->max_aspect.y = (int)_v;}
static int get_XSizeHints_base_width(void *_p) {return (int)((XSizeHints *)_p)->base_width;}
static void set_XSizeHints_base_width(void *_p, int _v) {((XSizeHints *)_p)->base_width = (int)_v;}
static int get_XSizeHints_base_height(void *_p) {return (int)((XSizeHints *)_p)->base_height;}
static void set_XSizeHints_base_height(void *_p, int _v) {((XSizeHints *)_p)->base_height = (int)_v;}
static int get_XSizeHints_win_gravity(void *_p) {return (int)((XSizeHints *)_p)->win_gravity;}
static void set_XSizeHints_win_gravity(void *_p, int _v) {((XSizeHints *)_p)->win_gravity = (int)_v;}
static void *alloc_XWMHints(void) {XWMHints *_p = (XWMHints *)malloc(sizeof(XWMHints)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XWMHints(void *_p) {if (_p==NULL) abort(); free((XWMHints *)_p);}
static long get_XWMHints_flags(void *_p) {return (long)((XWMHints *)_p)->flags;}
static void set_XWMHints_flags(void *_p, long _v) {((XWMHints *)_p)->flags = (long)_v;}
static int get_XWMHints_input(void *_p) {return (int)((XWMHints *)_p)->input;}
static void set_XWMHints_input(void *_p, int _v) {((XWMHints *)_p)->input = (int)_v;}
static int get_XWMHints_initial_state(void *_p) {return (int)((XWMHints *)_p)->initial_state;}
static void set_XWMHints_initial_state(void *_p, int _v) {((XWMHints *)_p)->initial_state = (int)_v;}
static unsigned long get_XWMHints_icon_pixmap(void *_p) {return (unsigned long)((XWMHints *)_p)->icon_pixmap;}
static void set_XWMHints_icon_pixmap(void *_p, unsigned long _v) {((XWMHints *)_p)->icon_pixmap = (unsigned long)_v;}
static unsigned long get_XWMHints_icon_window(void *_p) {return (unsigned long)((XWMHints *)_p)->icon_window;}
static void set_XWMHints_icon_window(void *_p, unsigned long _v) {((XWMHints *)_p)->icon_window = (unsigned long)_v;}
static int get_XWMHints_icon_x(void *_p) {return (int)((XWMHints *)_p)->icon_x;}
static void set_XWMHints_icon_x(void *_p, int _v) {((XWMHints *)_p)->icon_x = (int)_v;}
static int get_XWMHints_icon_y(void *_p) {return (int)((XWMHints *)_p)->icon_y;}
static void set_XWMHints_icon_y(void *_p, int _v) {((XWMHints *)_p)->icon_y = (int)_v;}
static unsigned long get_XWMHints_icon_mask(void *_p) {return (unsigned long)((XWMHints *)_p)->icon_mask;}
static void set_XWMHints_icon_mask(void *_p, unsigned long _v) {((XWMHints *)_p)->icon_mask = (unsigned long)_v;}
static unsigned long get_XWMHints_window_group(void *_p) {return (unsigned long)((XWMHints *)_p)->window_group;}
static void set_XWMHints_window_group(void *_p, unsigned long _v) {((XWMHints *)_p)->window_group = (unsigned long)_v;}
static void *alloc_XTextProperty(void) {XTextProperty *_p = (XTextProperty *)malloc(sizeof(XTextProperty)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XTextProperty(void *_p) {if (_p==NULL) abort(); free((XTextProperty *)_p);}
static void *get_XTextProperty_value(void *_p) {return (void *)((XTextProperty *)_p)->value;}
static void set_XTextProperty_value(void *_p, void *_v) {((XTextProperty *)_p)->value = (unsigned char *)_v;}
static unsigned long get_XTextProperty_encoding(void *_p) {return (unsigned long)((XTextProperty *)_p)->encoding;}
static void set_XTextProperty_encoding(void *_p, unsigned long _v) {((XTextProperty *)_p)->encoding = (unsigned long)_v;}
static int get_XTextProperty_format(void *_p) {return (int)((XTextProperty *)_p)->format;}
static void set_XTextProperty_format(void *_p, int _v) {((XTextProperty *)_p)->format = (int)_v;}
static unsigned long get_XTextProperty_nitems(void *_p) {return (unsigned long)((XTextProperty *)_p)->nitems;}
static void set_XTextProperty_nitems(void *_p, unsigned long _v) {((XTextProperty *)_p)->nitems = (unsigned long)_v;}
static void *alloc_XIconSize(void) {XIconSize *_p = (XIconSize *)malloc(sizeof(XIconSize)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XIconSize(void *_p) {if (_p==NULL) abort(); free((XIconSize *)_p);}
static int get_XIconSize_min_width(void *_p) {return (int)((XIconSize *)_p)->min_width;}
static void set_XIconSize_min_width(void *_p, int _v) {((XIconSize *)_p)->min_width = (int)_v;}
static int get_XIconSize_min_height(void *_p) {return (int)((XIconSize *)_p)->min_height;}
static void set_XIconSize_min_height(void *_p, int _v) {((XIconSize *)_p)->min_height = (int)_v;}
static int get_XIconSize_max_width(void *_p) {return (int)((XIconSize *)_p)->max_width;}
static void set_XIconSize_max_width(void *_p, int _v) {((XIconSize *)_p)->max_width = (int)_v;}
static int get_XIconSize_max_height(void *_p) {return (int)((XIconSize *)_p)->max_height;}
static void set_XIconSize_max_height(void *_p, int _v) {((XIconSize *)_p)->max_height = (int)_v;}
static int get_XIconSize_width_inc(void *_p) {return (int)((XIconSize *)_p)->width_inc;}
static void set_XIconSize_width_inc(void *_p, int _v) {((XIconSize *)_p)->width_inc = (int)_v;}
static int get_XIconSize_height_inc(void *_p) {return (int)((XIconSize *)_p)->height_inc;}
static void set_XIconSize_height_inc(void *_p, int _v) {((XIconSize *)_p)->height_inc = (int)_v;}
static void *alloc_XClassHint(void) {XClassHint *_p = (XClassHint *)malloc(sizeof(XClassHint)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XClassHint(void *_p) {if (_p==NULL) abort(); free((XClassHint *)_p);}
static void *get_XClassHint_res_name(void *_p) {return (void *)((XClassHint *)_p)->res_name;}
static void set_XClassHint_res_name(void *_p, void *_v) {((XClassHint *)_p)->res_name = (char *)_v;}
static void *get_XClassHint_res_class(void *_p) {return (void *)((XClassHint *)_p)->res_class;}
static void set_XClassHint_res_class(void *_p, void *_v) {((XClassHint *)_p)->res_class = (char *)_v;}
static void *alloc_XComposeStatus(void) {XComposeStatus *_p = (XComposeStatus *)malloc(sizeof(XComposeStatus)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XComposeStatus(void *_p) {if (_p==NULL) abort(); free((XComposeStatus *)_p);}
static void *get_XComposeStatus_compose_ptr(void *_p) {return (void *)((XComposeStatus *)_p)->compose_ptr;}
static void set_XComposeStatus_compose_ptr(void *_p, void *_v) {((XComposeStatus *)_p)->compose_ptr = (char *)_v;}
static int get_XComposeStatus_chars_matched(void *_p) {return (int)((XComposeStatus *)_p)->chars_matched;}
static void set_XComposeStatus_chars_matched(void *_p, int _v) {((XComposeStatus *)_p)->chars_matched = (int)_v;}
static void *alloc_XVisualInfo(void) {XVisualInfo *_p = (XVisualInfo *)malloc(sizeof(XVisualInfo)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XVisualInfo(void *_p) {if (_p==NULL) abort(); free((XVisualInfo *)_p);}
static void *get_XVisualInfo_visual(void *_p) {return (void *)((XVisualInfo *)_p)->visual;}
static void set_XVisualInfo_visual(void *_p, void *_v) {((XVisualInfo *)_p)->visual = (Visual *)_v;}
static unsigned long get_XVisualInfo_visualid(void *_p) {return (unsigned long)((XVisualInfo *)_p)->visualid;}
static void set_XVisualInfo_visualid(void *_p, unsigned long _v) {((XVisualInfo *)_p)->visualid = (unsigned long)_v;}
static int get_XVisualInfo_screen(void *_p) {return (int)((XVisualInfo *)_p)->screen;}
static void set_XVisualInfo_screen(void *_p, int _v) {((XVisualInfo *)_p)->screen = (int)_v;}
static int get_XVisualInfo_depth(void *_p) {return (int)((XVisualInfo *)_p)->depth;}
static void set_XVisualInfo_depth(void *_p, int _v) {((XVisualInfo *)_p)->depth = (int)_v;}
static int get_XVisualInfo_class(void *_p) {return (int)((XVisualInfo *)_p)->class;}
static void set_XVisualInfo_class(void *_p, int _v) {((XVisualInfo *)_p)->class = (int)_v;}
static unsigned long get_XVisualInfo_red_mask(void *_p) {return (unsigned long)((XVisualInfo *)_p)->red_mask;}
static void set_XVisualInfo_red_mask(void *_p, unsigned long _v) {((XVisualInfo *)_p)->red_mask = (unsigned long)_v;}
static unsigned long get_XVisualInfo_green_mask(void *_p) {return (unsigned long)((XVisualInfo *)_p)->green_mask;}
static void set_XVisualInfo_green_mask(void *_p, unsigned long _v) {((XVisualInfo *)_p)->green_mask = (unsigned long)_v;}
static unsigned long get_XVisualInfo_blue_mask(void *_p) {return (unsigned long)((XVisualInfo *)_p)->blue_mask;}
static void set_XVisualInfo_blue_mask(void *_p, unsigned long _v) {((XVisualInfo *)_p)->blue_mask = (unsigned long)_v;}
static int get_XVisualInfo_colormap_size(void *_p) {return (int)((XVisualInfo *)_p)->colormap_size;}
static void set_XVisualInfo_colormap_size(void *_p, int _v) {((XVisualInfo *)_p)->colormap_size = (int)_v;}
static int get_XVisualInfo_bits_per_rgb(void *_p) {return (int)((XVisualInfo *)_p)->bits_per_rgb;}
static void set_XVisualInfo_bits_per_rgb(void *_p, int _v) {((XVisualInfo *)_p)->bits_per_rgb = (int)_v;}
static void *alloc_XStandardColormap(void) {XStandardColormap *_p = (XStandardColormap *)malloc(sizeof(XStandardColormap)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XStandardColormap(void *_p) {if (_p==NULL) abort(); free((XStandardColormap *)_p);}
static unsigned long get_XStandardColormap_colormap(void *_p) {return (unsigned long)((XStandardColormap *)_p)->colormap;}
static void set_XStandardColormap_colormap(void *_p, unsigned long _v) {((XStandardColormap *)_p)->colormap = (unsigned long)_v;}
static unsigned long get_XStandardColormap_red_max(void *_p) {return (unsigned long)((XStandardColormap *)_p)->red_max;}
static void set_XStandardColormap_red_max(void *_p, unsigned long _v) {((XStandardColormap *)_p)->red_max = (unsigned long)_v;}
static unsigned long get_XStandardColormap_red_mult(void *_p) {return (unsigned long)((XStandardColormap *)_p)->red_mult;}
static void set_XStandardColormap_red_mult(void *_p, unsigned long _v) {((XStandardColormap *)_p)->red_mult = (unsigned long)_v;}
static unsigned long get_XStandardColormap_green_max(void *_p) {return (unsigned long)((XStandardColormap *)_p)->green_max;}
static void set_XStandardColormap_green_max(void *_p, unsigned long _v) {((XStandardColormap *)_p)->green_max = (unsigned long)_v;}
static unsigned long get_XStandardColormap_green_mult(void *_p) {return (unsigned long)((XStandardColormap *)_p)->green_mult;}
static void set_XStandardColormap_green_mult(void *_p, unsigned long _v) {((XStandardColormap *)_p)->green_mult = (unsigned long)_v;}
static unsigned long get_XStandardColormap_blue_max(void *_p) {return (unsigned long)((XStandardColormap *)_p)->blue_max;}
static void set_XStandardColormap_blue_max(void *_p, unsigned long _v) {((XStandardColormap *)_p)->blue_max = (unsigned long)_v;}
static unsigned long get_XStandardColormap_blue_mult(void *_p) {return (unsigned long)((XStandardColormap *)_p)->blue_mult;}
static void set_XStandardColormap_blue_mult(void *_p, unsigned long _v) {((XStandardColormap *)_p)->blue_mult = (unsigned long)_v;}
static unsigned long get_XStandardColormap_base_pixel(void *_p) {return (unsigned long)((XStandardColormap *)_p)->base_pixel;}
static void set_XStandardColormap_base_pixel(void *_p, unsigned long _v) {((XStandardColormap *)_p)->base_pixel = (unsigned long)_v;}
static unsigned long get_XStandardColormap_visualid(void *_p) {return (unsigned long)((XStandardColormap *)_p)->visualid;}
static void set_XStandardColormap_visualid(void *_p, unsigned long _v) {((XStandardColormap *)_p)->visualid = (unsigned long)_v;}
static unsigned long get_XStandardColormap_killid(void *_p) {return (unsigned long)((XStandardColormap *)_p)->killid;}
static void set_XStandardColormap_killid(void *_p, unsigned long _v) {((XStandardColormap *)_p)->killid = (unsigned long)_v;}
static void *alloc_XEvent(void) {XEvent *_p = (XEvent *)malloc(sizeof(XEvent)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XEvent(void *_p) {if (_p==NULL) abort(); free((XEvent *)_p);}
static int get_XEvent_type(void *_p) {return (int)((XEvent *)_p)->type;}
static void set_XEvent_type(void *_p, int _v) {((XEvent *)_p)->type = (int)_v;}
static int get_XEvent_xany_type(void *_p) {return (int)((XEvent *)_p)->xany.type;}
static void set_XEvent_xany_type(void *_p, int _v) {((XEvent *)_p)->xany.type = (int)_v;}
static unsigned long get_XEvent_xany_serial(void *_p) {return (unsigned long)((XEvent *)_p)->xany.serial;}
static void set_XEvent_xany_serial(void *_p, unsigned long _v) {((XEvent *)_p)->xany.serial = (unsigned long)_v;}
static int get_XEvent_xany_send_event(void *_p) {return (int)((XEvent *)_p)->xany.send_event;}
static void set_XEvent_xany_send_event(void *_p, int _v) {((XEvent *)_p)->xany.send_event = (int)_v;}
static void *get_XEvent_xany_display(void *_p) {return (void *)((XEvent *)_p)->xany.display;}
static void set_XEvent_xany_display(void *_p, void *_v) {((XEvent *)_p)->xany.display = (Display *)_v;}
static unsigned long get_XEvent_xany_window(void *_p) {return (unsigned long)((XEvent *)_p)->xany.window;}
static void set_XEvent_xany_window(void *_p, unsigned long _v) {((XEvent *)_p)->xany.window = (unsigned long)_v;}
static int get_XEvent_xkey_type(void *_p) {return (int)((XEvent *)_p)->xkey.type;}
static void set_XEvent_xkey_type(void *_p, int _v) {((XEvent *)_p)->xkey.type = (int)_v;}
static unsigned long get_XEvent_xkey_serial(void *_p) {return (unsigned long)((XEvent *)_p)->xkey.serial;}
static void set_XEvent_xkey_serial(void *_p, unsigned long _v) {((XEvent *)_p)->xkey.serial = (unsigned long)_v;}
static int get_XEvent_xkey_send_event(void *_p) {return (int)((XEvent *)_p)->xkey.send_event;}
static void set_XEvent_xkey_send_event(void *_p, int _v) {((XEvent *)_p)->xkey.send_event = (int)_v;}
static void *get_XEvent_xkey_display(void *_p) {return (void *)((XEvent *)_p)->xkey.display;}
static void set_XEvent_xkey_display(void *_p, void *_v) {((XEvent *)_p)->xkey.display = (Display *)_v;}
static unsigned long get_XEvent_xkey_window(void *_p) {return (unsigned long)((XEvent *)_p)->xkey.window;}
static void set_XEvent_xkey_window(void *_p, unsigned long _v) {((XEvent *)_p)->xkey.window = (unsigned long)_v;}
static unsigned long get_XEvent_xkey_root(void *_p) {return (unsigned long)((XEvent *)_p)->xkey.root;}
static void set_XEvent_xkey_root(void *_p, unsigned long _v) {((XEvent *)_p)->xkey.root = (unsigned long)_v;}
static unsigned long get_XEvent_xkey_subwindow(void *_p) {return (unsigned long)((XEvent *)_p)->xkey.subwindow;}
static void set_XEvent_xkey_subwindow(void *_p, unsigned long _v) {((XEvent *)_p)->xkey.subwindow = (unsigned long)_v;}
static unsigned long get_XEvent_xkey_time(void *_p) {return (unsigned long)((XEvent *)_p)->xkey.time;}
static void set_XEvent_xkey_time(void *_p, unsigned long _v) {((XEvent *)_p)->xkey.time = (unsigned long)_v;}
static int get_XEvent_xkey_x(void *_p) {return (int)((XEvent *)_p)->xkey.x;}
static void set_XEvent_xkey_x(void *_p, int _v) {((XEvent *)_p)->xkey.x = (int)_v;}
static int get_XEvent_xkey_y(void *_p) {return (int)((XEvent *)_p)->xkey.y;}
static void set_XEvent_xkey_y(void *_p, int _v) {((XEvent *)_p)->xkey.y = (int)_v;}
static int get_XEvent_xkey_x_root(void *_p) {return (int)((XEvent *)_p)->xkey.x_root;}
static void set_XEvent_xkey_x_root(void *_p, int _v) {((XEvent *)_p)->xkey.x_root = (int)_v;}
static int get_XEvent_xkey_y_root(void *_p) {return (int)((XEvent *)_p)->xkey.y_root;}
static void set_XEvent_xkey_y_root(void *_p, int _v) {((XEvent *)_p)->xkey.y_root = (int)_v;}
static unsigned get_XEvent_xkey_state(void *_p) {return (unsigned)((XEvent *)_p)->xkey.state;}
static void set_XEvent_xkey_state(void *_p, unsigned _v) {((XEvent *)_p)->xkey.state = (unsigned)_v;}
static unsigned get_XEvent_xkey_keycode(void *_p) {return (unsigned)((XEvent *)_p)->xkey.keycode;}
static void set_XEvent_xkey_keycode(void *_p, unsigned _v) {((XEvent *)_p)->xkey.keycode = (unsigned)_v;}
static int get_XEvent_xkey_same_screen(void *_p) {return (int)((XEvent *)_p)->xkey.same_screen;}
static void set_XEvent_xkey_same_screen(void *_p, int _v) {((XEvent *)_p)->xkey.same_screen = (int)_v;}
static int get_XEvent_xbutton_type(void *_p) {return (int)((XEvent *)_p)->xbutton.type;}
static void set_XEvent_xbutton_type(void *_p, int _v) {((XEvent *)_p)->xbutton.type = (int)_v;}
static unsigned long get_XEvent_xbutton_serial(void *_p) {return (unsigned long)((XEvent *)_p)->xbutton.serial;}
static void set_XEvent_xbutton_serial(void *_p, unsigned long _v) {((XEvent *)_p)->xbutton.serial = (unsigned long)_v;}
static int get_XEvent_xbutton_send_event(void *_p) {return (int)((XEvent *)_p)->xbutton.send_event;}
static void set_XEvent_xbutton_send_event(void *_p, int _v) {((XEvent *)_p)->xbutton.send_event = (int)_v;}
static void *get_XEvent_xbutton_display(void *_p) {return (void *)((XEvent *)_p)->xbutton.display;}
static void set_XEvent_xbutton_display(void *_p, void *_v) {((XEvent *)_p)->xbutton.display = (Display *)_v;}
static unsigned long get_XEvent_xbutton_window(void *_p) {return (unsigned long)((XEvent *)_p)->xbutton.window;}
static void set_XEvent_xbutton_window(void *_p, unsigned long _v) {((XEvent *)_p)->xbutton.window = (unsigned long)_v;}
static unsigned long get_XEvent_xbutton_root(void *_p) {return (unsigned long)((XEvent *)_p)->xbutton.root;}
static void set_XEvent_xbutton_root(void *_p, unsigned long _v) {((XEvent *)_p)->xbutton.root = (unsigned long)_v;}
static unsigned long get_XEvent_xbutton_subwindow(void *_p) {return (unsigned long)((XEvent *)_p)->xbutton.subwindow;}
static void set_XEvent_xbutton_subwindow(void *_p, unsigned long _v) {((XEvent *)_p)->xbutton.subwindow = (unsigned long)_v;}
static unsigned long get_XEvent_xbutton_time(void *_p) {return (unsigned long)((XEvent *)_p)->xbutton.time;}
static void set_XEvent_xbutton_time(void *_p, unsigned long _v) {((XEvent *)_p)->xbutton.time = (unsigned long)_v;}
static int get_XEvent_xbutton_x(void *_p) {return (int)((XEvent *)_p)->xbutton.x;}
static void set_XEvent_xbutton_x(void *_p, int _v) {((XEvent *)_p)->xbutton.x = (int)_v;}
static int get_XEvent_xbutton_y(void *_p) {return (int)((XEvent *)_p)->xbutton.y;}
static void set_XEvent_xbutton_y(void *_p, int _v) {((XEvent *)_p)->xbutton.y = (int)_v;}
static int get_XEvent_xbutton_x_root(void *_p) {return (int)((XEvent *)_p)->xbutton.x_root;}
static void set_XEvent_xbutton_x_root(void *_p, int _v) {((XEvent *)_p)->xbutton.x_root = (int)_v;}
static int get_XEvent_xbutton_y_root(void *_p) {return (int)((XEvent *)_p)->xbutton.y_root;}
static void set_XEvent_xbutton_y_root(void *_p, int _v) {((XEvent *)_p)->xbutton.y_root = (int)_v;}
static unsigned get_XEvent_xbutton_state(void *_p) {return (unsigned)((XEvent *)_p)->xbutton.state;}
static void set_XEvent_xbutton_state(void *_p, unsigned _v) {((XEvent *)_p)->xbutton.state = (unsigned)_v;}
static unsigned get_XEvent_xbutton_button(void *_p) {return (unsigned)((XEvent *)_p)->xbutton.button;}
static void set_XEvent_xbutton_button(void *_p, unsigned _v) {((XEvent *)_p)->xbutton.button = (unsigned)_v;}
static int get_XEvent_xbutton_same_screen(void *_p) {return (int)((XEvent *)_p)->xbutton.same_screen;}
static void set_XEvent_xbutton_same_screen(void *_p, int _v) {((XEvent *)_p)->xbutton.same_screen = (int)_v;}
static int get_XEvent_xmotion_type(void *_p) {return (int)((XEvent *)_p)->xmotion.type;}
static void set_XEvent_xmotion_type(void *_p, int _v) {((XEvent *)_p)->xmotion.type = (int)_v;}
static unsigned long get_XEvent_xmotion_serial(void *_p) {return (unsigned long)((XEvent *)_p)->xmotion.serial;}
static void set_XEvent_xmotion_serial(void *_p, unsigned long _v) {((XEvent *)_p)->xmotion.serial = (unsigned long)_v;}
static int get_XEvent_xmotion_send_event(void *_p) {return (int)((XEvent *)_p)->xmotion.send_event;}
static void set_XEvent_xmotion_send_event(void *_p, int _v) {((XEvent *)_p)->xmotion.send_event = (int)_v;}
static void *get_XEvent_xmotion_display(void *_p) {return (void *)((XEvent *)_p)->xmotion.display;}
static void set_XEvent_xmotion_display(void *_p, void *_v) {((XEvent *)_p)->xmotion.display = (Display *)_v;}
static unsigned long get_XEvent_xmotion_window(void *_p) {return (unsigned long)((XEvent *)_p)->xmotion.window;}
static void set_XEvent_xmotion_window(void *_p, unsigned long _v) {((XEvent *)_p)->xmotion.window = (unsigned long)_v;}
static unsigned long get_XEvent_xmotion_root(void *_p) {return (unsigned long)((XEvent *)_p)->xmotion.root;}
static void set_XEvent_xmotion_root(void *_p, unsigned long _v) {((XEvent *)_p)->xmotion.root = (unsigned long)_v;}
static unsigned long get_XEvent_xmotion_subwindow(void *_p) {return (unsigned long)((XEvent *)_p)->xmotion.subwindow;}
static void set_XEvent_xmotion_subwindow(void *_p, unsigned long _v) {((XEvent *)_p)->xmotion.subwindow = (unsigned long)_v;}
static unsigned long get_XEvent_xmotion_time(void *_p) {return (unsigned long)((XEvent *)_p)->xmotion.time;}
static void set_XEvent_xmotion_time(void *_p, unsigned long _v) {((XEvent *)_p)->xmotion.time = (unsigned long)_v;}
static int get_XEvent_xmotion_x(void *_p) {return (int)((XEvent *)_p)->xmotion.x;}
static void set_XEvent_xmotion_x(void *_p, int _v) {((XEvent *)_p)->xmotion.x = (int)_v;}
static int get_XEvent_xmotion_y(void *_p) {return (int)((XEvent *)_p)->xmotion.y;}
static void set_XEvent_xmotion_y(void *_p, int _v) {((XEvent *)_p)->xmotion.y = (int)_v;}
static int get_XEvent_xmotion_x_root(void *_p) {return (int)((XEvent *)_p)->xmotion.x_root;}
static void set_XEvent_xmotion_x_root(void *_p, int _v) {((XEvent *)_p)->xmotion.x_root = (int)_v;}
static int get_XEvent_xmotion_y_root(void *_p) {return (int)((XEvent *)_p)->xmotion.y_root;}
static void set_XEvent_xmotion_y_root(void *_p, int _v) {((XEvent *)_p)->xmotion.y_root = (int)_v;}
static unsigned get_XEvent_xmotion_state(void *_p) {return (unsigned)((XEvent *)_p)->xmotion.state;}
static void set_XEvent_xmotion_state(void *_p, unsigned _v) {((XEvent *)_p)->xmotion.state = (unsigned)_v;}
static char get_XEvent_xmotion_is_hint(void *_p) {return (char)((XEvent *)_p)->xmotion.is_hint;}
static void set_XEvent_xmotion_is_hint(void *_p, char _v) {((XEvent *)_p)->xmotion.is_hint = (char)_v;}
static int get_XEvent_xmotion_same_screen(void *_p) {return (int)((XEvent *)_p)->xmotion.same_screen;}
static void set_XEvent_xmotion_same_screen(void *_p, int _v) {((XEvent *)_p)->xmotion.same_screen = (int)_v;}
static int get_XEvent_xcrossing_type(void *_p) {return (int)((XEvent *)_p)->xcrossing.type;}
static void set_XEvent_xcrossing_type(void *_p, int _v) {((XEvent *)_p)->xcrossing.type = (int)_v;}
static unsigned long get_XEvent_xcrossing_serial(void *_p) {return (unsigned long)((XEvent *)_p)->xcrossing.serial;}
static void set_XEvent_xcrossing_serial(void *_p, unsigned long _v) {((XEvent *)_p)->xcrossing.serial = (unsigned long)_v;}
static int get_XEvent_xcrossing_send_event(void *_p) {return (int)((XEvent *)_p)->xcrossing.send_event;}
static void set_XEvent_xcrossing_send_event(void *_p, int _v) {((XEvent *)_p)->xcrossing.send_event = (int)_v;}
static void *get_XEvent_xcrossing_display(void *_p) {return (void *)((XEvent *)_p)->xcrossing.display;}
static void set_XEvent_xcrossing_display(void *_p, void *_v) {((XEvent *)_p)->xcrossing.display = (Display *)_v;}
static unsigned long get_XEvent_xcrossing_window(void *_p) {return (unsigned long)((XEvent *)_p)->xcrossing.window;}
static void set_XEvent_xcrossing_window(void *_p, unsigned long _v) {((XEvent *)_p)->xcrossing.window = (unsigned long)_v;}
static unsigned long get_XEvent_xcrossing_root(void *_p) {return (unsigned long)((XEvent *)_p)->xcrossing.root;}
static void set_XEvent_xcrossing_root(void *_p, unsigned long _v) {((XEvent *)_p)->xcrossing.root = (unsigned long)_v;}
static unsigned long get_XEvent_xcrossing_subwindow(void *_p) {return (unsigned long)((XEvent *)_p)->xcrossing.subwindow;}
static void set_XEvent_xcrossing_subwindow(void *_p, unsigned long _v) {((XEvent *)_p)->xcrossing.subwindow = (unsigned long)_v;}
static unsigned long get_XEvent_xcrossing_time(void *_p) {return (unsigned long)((XEvent *)_p)->xcrossing.time;}
static void set_XEvent_xcrossing_time(void *_p, unsigned long _v) {((XEvent *)_p)->xcrossing.time = (unsigned long)_v;}
static int get_XEvent_xcrossing_x(void *_p) {return (int)((XEvent *)_p)->xcrossing.x;}
static void set_XEvent_xcrossing_x(void *_p, int _v) {((XEvent *)_p)->xcrossing.x = (int)_v;}
static int get_XEvent_xcrossing_y(void *_p) {return (int)((XEvent *)_p)->xcrossing.y;}
static void set_XEvent_xcrossing_y(void *_p, int _v) {((XEvent *)_p)->xcrossing.y = (int)_v;}
static int get_XEvent_xcrossing_x_root(void *_p) {return (int)((XEvent *)_p)->xcrossing.x_root;}
static void set_XEvent_xcrossing_x_root(void *_p, int _v) {((XEvent *)_p)->xcrossing.x_root = (int)_v;}
static int get_XEvent_xcrossing_y_root(void *_p) {return (int)((XEvent *)_p)->xcrossing.y_root;}
static void set_XEvent_xcrossing_y_root(void *_p, int _v) {((XEvent *)_p)->xcrossing.y_root = (int)_v;}
static int get_XEvent_xcrossing_mode(void *_p) {return (int)((XEvent *)_p)->xcrossing.mode;}
static void set_XEvent_xcrossing_mode(void *_p, int _v) {((XEvent *)_p)->xcrossing.mode = (int)_v;}
static int get_XEvent_xcrossing_detail(void *_p) {return (int)((XEvent *)_p)->xcrossing.detail;}
static void set_XEvent_xcrossing_detail(void *_p, int _v) {((XEvent *)_p)->xcrossing.detail = (int)_v;}
static int get_XEvent_xcrossing_same_screen(void *_p) {return (int)((XEvent *)_p)->xcrossing.same_screen;}
static void set_XEvent_xcrossing_same_screen(void *_p, int _v) {((XEvent *)_p)->xcrossing.same_screen = (int)_v;}
static int get_XEvent_xcrossing_focus(void *_p) {return (int)((XEvent *)_p)->xcrossing.focus;}
static void set_XEvent_xcrossing_focus(void *_p, int _v) {((XEvent *)_p)->xcrossing.focus = (int)_v;}
static unsigned get_XEvent_xcrossing_state(void *_p) {return (unsigned)((XEvent *)_p)->xcrossing.state;}
static void set_XEvent_xcrossing_state(void *_p, unsigned _v) {((XEvent *)_p)->xcrossing.state = (unsigned)_v;}
static int get_XEvent_xfocus_type(void *_p) {return (int)((XEvent *)_p)->xfocus.type;}
static void set_XEvent_xfocus_type(void *_p, int _v) {((XEvent *)_p)->xfocus.type = (int)_v;}
static unsigned long get_XEvent_xfocus_serial(void *_p) {return (unsigned long)((XEvent *)_p)->xfocus.serial;}
static void set_XEvent_xfocus_serial(void *_p, unsigned long _v) {((XEvent *)_p)->xfocus.serial = (unsigned long)_v;}
static int get_XEvent_xfocus_send_event(void *_p) {return (int)((XEvent *)_p)->xfocus.send_event;}
static void set_XEvent_xfocus_send_event(void *_p, int _v) {((XEvent *)_p)->xfocus.send_event = (int)_v;}
static void *get_XEvent_xfocus_display(void *_p) {return (void *)((XEvent *)_p)->xfocus.display;}
static void set_XEvent_xfocus_display(void *_p, void *_v) {((XEvent *)_p)->xfocus.display = (Display *)_v;}
static unsigned long get_XEvent_xfocus_window(void *_p) {return (unsigned long)((XEvent *)_p)->xfocus.window;}
static void set_XEvent_xfocus_window(void *_p, unsigned long _v) {((XEvent *)_p)->xfocus.window = (unsigned long)_v;}
static int get_XEvent_xfocus_mode(void *_p) {return (int)((XEvent *)_p)->xfocus.mode;}
static void set_XEvent_xfocus_mode(void *_p, int _v) {((XEvent *)_p)->xfocus.mode = (int)_v;}
static int get_XEvent_xfocus_detail(void *_p) {return (int)((XEvent *)_p)->xfocus.detail;}
static void set_XEvent_xfocus_detail(void *_p, int _v) {((XEvent *)_p)->xfocus.detail = (int)_v;}
static int get_XEvent_xexpose_type(void *_p) {return (int)((XEvent *)_p)->xexpose.type;}
static void set_XEvent_xexpose_type(void *_p, int _v) {((XEvent *)_p)->xexpose.type = (int)_v;}
static unsigned long get_XEvent_xexpose_serial(void *_p) {return (unsigned long)((XEvent *)_p)->xexpose.serial;}
static void set_XEvent_xexpose_serial(void *_p, unsigned long _v) {((XEvent *)_p)->xexpose.serial = (unsigned long)_v;}
static int get_XEvent_xexpose_send_event(void *_p) {return (int)((XEvent *)_p)->xexpose.send_event;}
static void set_XEvent_xexpose_send_event(void *_p, int _v) {((XEvent *)_p)->xexpose.send_event = (int)_v;}
static void *get_XEvent_xexpose_display(void *_p) {return (void *)((XEvent *)_p)->xexpose.display;}
static void set_XEvent_xexpose_display(void *_p, void *_v) {((XEvent *)_p)->xexpose.display = (Display *)_v;}
static unsigned long get_XEvent_xexpose_window(void *_p) {return (unsigned long)((XEvent *)_p)->xexpose.window;}
static void set_XEvent_xexpose_window(void *_p, unsigned long _v) {((XEvent *)_p)->xexpose.window = (unsigned long)_v;}
static int get_XEvent_xexpose_x(void *_p) {return (int)((XEvent *)_p)->xexpose.x;}
static void set_XEvent_xexpose_x(void *_p, int _v) {((XEvent *)_p)->xexpose.x = (int)_v;}
static int get_XEvent_xexpose_y(void *_p) {return (int)((XEvent *)_p)->xexpose.y;}
static void set_XEvent_xexpose_y(void *_p, int _v) {((XEvent *)_p)->xexpose.y = (int)_v;}
static int get_XEvent_xexpose_width(void *_p) {return (int)((XEvent *)_p)->xexpose.width;}
static void set_XEvent_xexpose_width(void *_p, int _v) {((XEvent *)_p)->xexpose.width = (int)_v;}
static int get_XEvent_xexpose_height(void *_p) {return (int)((XEvent *)_p)->xexpose.height;}
static void set_XEvent_xexpose_height(void *_p, int _v) {((XEvent *)_p)->xexpose.height = (int)_v;}
static int get_XEvent_xexpose_count(void *_p) {return (int)((XEvent *)_p)->xexpose.count;}
static void set_XEvent_xexpose_count(void *_p, int _v) {((XEvent *)_p)->xexpose.count = (int)_v;}
static int get_XEvent_xgraphicsexpose_type(void *_p) {return (int)((XEvent *)_p)->xgraphicsexpose.type;}
static void set_XEvent_xgraphicsexpose_type(void *_p, int _v) {((XEvent *)_p)->xgraphicsexpose.type = (int)_v;}
static unsigned long get_XEvent_xgraphicsexpose_serial(void *_p) {return (unsigned long)((XEvent *)_p)->xgraphicsexpose.serial;}
static void set_XEvent_xgraphicsexpose_serial(void *_p, unsigned long _v) {((XEvent *)_p)->xgraphicsexpose.serial = (unsigned long)_v;}
static int get_XEvent_xgraphicsexpose_send_event(void *_p) {return (int)((XEvent *)_p)->xgraphicsexpose.send_event;}
static void set_XEvent_xgraphicsexpose_send_event(void *_p, int _v) {((XEvent *)_p)->xgraphicsexpose.send_event = (int)_v;}
static void *get_XEvent_xgraphicsexpose_display(void *_p) {return (void *)((XEvent *)_p)->xgraphicsexpose.display;}
static void set_XEvent_xgraphicsexpose_display(void *_p, void *_v) {((XEvent *)_p)->xgraphicsexpose.display = (Display *)_v;}
static unsigned long get_XEvent_xgraphicsexpose_drawable(void *_p) {return (unsigned long)((XEvent *)_p)->xgraphicsexpose.drawable;}
static void set_XEvent_xgraphicsexpose_drawable(void *_p, unsigned long _v) {((XEvent *)_p)->xgraphicsexpose.drawable = (unsigned long)_v;}
static int get_XEvent_xgraphicsexpose_x(void *_p) {return (int)((XEvent *)_p)->xgraphicsexpose.x;}
static void set_XEvent_xgraphicsexpose_x(void *_p, int _v) {((XEvent *)_p)->xgraphicsexpose.x = (int)_v;}
static int get_XEvent_xgraphicsexpose_y(void *_p) {return (int)((XEvent *)_p)->xgraphicsexpose.y;}
static void set_XEvent_xgraphicsexpose_y(void *_p, int _v) {((XEvent *)_p)->xgraphicsexpose.y = (int)_v;}
static int get_XEvent_xgraphicsexpose_width(void *_p) {return (int)((XEvent *)_p)->xgraphicsexpose.width;}
static void set_XEvent_xgraphicsexpose_width(void *_p, int _v) {((XEvent *)_p)->xgraphicsexpose.width = (int)_v;}
static int get_XEvent_xgraphicsexpose_height(void *_p) {return (int)((XEvent *)_p)->xgraphicsexpose.height;}
static void set_XEvent_xgraphicsexpose_height(void *_p, int _v) {((XEvent *)_p)->xgraphicsexpose.height = (int)_v;}
static int get_XEvent_xgraphicsexpose_count(void *_p) {return (int)((XEvent *)_p)->xgraphicsexpose.count;}
static void set_XEvent_xgraphicsexpose_count(void *_p, int _v) {((XEvent *)_p)->xgraphicsexpose.count = (int)_v;}
static int get_XEvent_xgraphicsexpose_major_code(void *_p) {return (int)((XEvent *)_p)->xgraphicsexpose.major_code;}
static void set_XEvent_xgraphicsexpose_major_code(void *_p, int _v) {((XEvent *)_p)->xgraphicsexpose.major_code = (int)_v;}
static int get_XEvent_xgraphicsexpose_minor_code(void *_p) {return (int)((XEvent *)_p)->xgraphicsexpose.minor_code;}
static void set_XEvent_xgraphicsexpose_minor_code(void *_p, int _v) {((XEvent *)_p)->xgraphicsexpose.minor_code = (int)_v;}
static int get_XEvent_xnoexpose_type(void *_p) {return (int)((XEvent *)_p)->xnoexpose.type;}
static void set_XEvent_xnoexpose_type(void *_p, int _v) {((XEvent *)_p)->xnoexpose.type = (int)_v;}
static unsigned long get_XEvent_xnoexpose_serial(void *_p) {return (unsigned long)((XEvent *)_p)->xnoexpose.serial;}
static void set_XEvent_xnoexpose_serial(void *_p, unsigned long _v) {((XEvent *)_p)->xnoexpose.serial = (unsigned long)_v;}
static int get_XEvent_xnoexpose_send_event(void *_p) {return (int)((XEvent *)_p)->xnoexpose.send_event;}
static void set_XEvent_xnoexpose_send_event(void *_p, int _v) {((XEvent *)_p)->xnoexpose.send_event = (int)_v;}
static void *get_XEvent_xnoexpose_display(void *_p) {return (void *)((XEvent *)_p)->xnoexpose.display;}
static void set_XEvent_xnoexpose_display(void *_p, void *_v) {((XEvent *)_p)->xnoexpose.display = (Display *)_v;}
static unsigned long get_XEvent_xnoexpose_drawable(void *_p) {return (unsigned long)((XEvent *)_p)->xnoexpose.drawable;}
static void set_XEvent_xnoexpose_drawable(void *_p, unsigned long _v) {((XEvent *)_p)->xnoexpose.drawable = (unsigned long)_v;}
static int get_XEvent_xnoexpose_major_code(void *_p) {return (int)((XEvent *)_p)->xnoexpose.major_code;}
static void set_XEvent_xnoexpose_major_code(void *_p, int _v) {((XEvent *)_p)->xnoexpose.major_code = (int)_v;}
static int get_XEvent_xnoexpose_minor_code(void *_p) {return (int)((XEvent *)_p)->xnoexpose.minor_code;}
static void set_XEvent_xnoexpose_minor_code(void *_p, int _v) {((XEvent *)_p)->xnoexpose.minor_code = (int)_v;}
static int get_XEvent_xvisibility_type(void *_p) {return (int)((XEvent *)_p)->xvisibility.type;}
static void set_XEvent_xvisibility_type(void *_p, int _v) {((XEvent *)_p)->xvisibility.type = (int)_v;}
static unsigned long get_XEvent_xvisibility_serial(void *_p) {return (unsigned long)((XEvent *)_p)->xvisibility.serial;}
static void set_XEvent_xvisibility_serial(void *_p, unsigned long _v) {((XEvent *)_p)->xvisibility.serial = (unsigned long)_v;}
static int get_XEvent_xvisibility_send_event(void *_p) {return (int)((XEvent *)_p)->xvisibility.send_event;}
static void set_XEvent_xvisibility_send_event(void *_p, int _v) {((XEvent *)_p)->xvisibility.send_event = (int)_v;}
static void *get_XEvent_xvisibility_display(void *_p) {return (void *)((XEvent *)_p)->xvisibility.display;}
static void set_XEvent_xvisibility_display(void *_p, void *_v) {((XEvent *)_p)->xvisibility.display = (Display *)_v;}
static unsigned long get_XEvent_xvisibility_window(void *_p) {return (unsigned long)((XEvent *)_p)->xvisibility.window;}
static void set_XEvent_xvisibility_window(void *_p, unsigned long _v) {((XEvent *)_p)->xvisibility.window = (unsigned long)_v;}
static int get_XEvent_xvisibility_state(void *_p) {return (int)((XEvent *)_p)->xvisibility.state;}
static void set_XEvent_xvisibility_state(void *_p, int _v) {((XEvent *)_p)->xvisibility.state = (int)_v;}
static int get_XEvent_xcreatewindow_type(void *_p) {return (int)((XEvent *)_p)->xcreatewindow.type;}
static void set_XEvent_xcreatewindow_type(void *_p, int _v) {((XEvent *)_p)->xcreatewindow.type = (int)_v;}
static unsigned long get_XEvent_xcreatewindow_serial(void *_p) {return (unsigned long)((XEvent *)_p)->xcreatewindow.serial;}
static void set_XEvent_xcreatewindow_serial(void *_p, unsigned long _v) {((XEvent *)_p)->xcreatewindow.serial = (unsigned long)_v;}
static int get_XEvent_xcreatewindow_send_event(void *_p) {return (int)((XEvent *)_p)->xcreatewindow.send_event;}
static void set_XEvent_xcreatewindow_send_event(void *_p, int _v) {((XEvent *)_p)->xcreatewindow.send_event = (int)_v;}
static void *get_XEvent_xcreatewindow_display(void *_p) {return (void *)((XEvent *)_p)->xcreatewindow.display;}
static void set_XEvent_xcreatewindow_display(void *_p, void *_v) {((XEvent *)_p)->xcreatewindow.display = (Display *)_v;}
static unsigned long get_XEvent_xcreatewindow_parent(void *_p) {return (unsigned long)((XEvent *)_p)->xcreatewindow.parent;}
static void set_XEvent_xcreatewindow_parent(void *_p, unsigned long _v) {((XEvent *)_p)->xcreatewindow.parent = (unsigned long)_v;}
static unsigned long get_XEvent_xcreatewindow_window(void *_p) {return (unsigned long)((XEvent *)_p)->xcreatewindow.window;}
static void set_XEvent_xcreatewindow_window(void *_p, unsigned long _v) {((XEvent *)_p)->xcreatewindow.window = (unsigned long)_v;}
static int get_XEvent_xcreatewindow_x(void *_p) {return (int)((XEvent *)_p)->xcreatewindow.x;}
static void set_XEvent_xcreatewindow_x(void *_p, int _v) {((XEvent *)_p)->xcreatewindow.x = (int)_v;}
static int get_XEvent_xcreatewindow_y(void *_p) {return (int)((XEvent *)_p)->xcreatewindow.y;}
static void set_XEvent_xcreatewindow_y(void *_p, int _v) {((XEvent *)_p)->xcreatewindow.y = (int)_v;}
static int get_XEvent_xcreatewindow_width(void *_p) {return (int)((XEvent *)_p)->xcreatewindow.width;}
static void set_XEvent_xcreatewindow_width(void *_p, int _v) {((XEvent *)_p)->xcreatewindow.width = (int)_v;}
static int get_XEvent_xcreatewindow_height(void *_p) {return (int)((XEvent *)_p)->xcreatewindow.height;}
static void set_XEvent_xcreatewindow_height(void *_p, int _v) {((XEvent *)_p)->xcreatewindow.height = (int)_v;}
static int get_XEvent_xcreatewindow_border_width(void *_p) {return (int)((XEvent *)_p)->xcreatewindow.border_width;}
static void set_XEvent_xcreatewindow_border_width(void *_p, int _v) {((XEvent *)_p)->xcreatewindow.border_width = (int)_v;}
static int get_XEvent_xcreatewindow_override_redirect(void *_p) {return (int)((XEvent *)_p)->xcreatewindow.override_redirect;}
static void set_XEvent_xcreatewindow_override_redirect(void *_p, int _v) {((XEvent *)_p)->xcreatewindow.override_redirect = (int)_v;}
static int get_XEvent_xdestroywindow_type(void *_p) {return (int)((XEvent *)_p)->xdestroywindow.type;}
static void set_XEvent_xdestroywindow_type(void *_p, int _v) {((XEvent *)_p)->xdestroywindow.type = (int)_v;}
static unsigned long get_XEvent_xdestroywindow_serial(void *_p) {return (unsigned long)((XEvent *)_p)->xdestroywindow.serial;}
static void set_XEvent_xdestroywindow_serial(void *_p, unsigned long _v) {((XEvent *)_p)->xdestroywindow.serial = (unsigned long)_v;}
static int get_XEvent_xdestroywindow_send_event(void *_p) {return (int)((XEvent *)_p)->xdestroywindow.send_event;}
static void set_XEvent_xdestroywindow_send_event(void *_p, int _v) {((XEvent *)_p)->xdestroywindow.send_event = (int)_v;}
static void *get_XEvent_xdestroywindow_display(void *_p) {return (void *)((XEvent *)_p)->xdestroywindow.display;}
static void set_XEvent_xdestroywindow_display(void *_p, void *_v) {((XEvent *)_p)->xdestroywindow.display = (Display *)_v;}
static unsigned long get_XEvent_xdestroywindow_event(void *_p) {return (unsigned long)((XEvent *)_p)->xdestroywindow.event;}
static void set_XEvent_xdestroywindow_event(void *_p, unsigned long _v) {((XEvent *)_p)->xdestroywindow.event = (unsigned long)_v;}
static unsigned long get_XEvent_xdestroywindow_window(void *_p) {return (unsigned long)((XEvent *)_p)->xdestroywindow.window;}
static void set_XEvent_xdestroywindow_window(void *_p, unsigned long _v) {((XEvent *)_p)->xdestroywindow.window = (unsigned long)_v;}
static int get_XEvent_xunmap_type(void *_p) {return (int)((XEvent *)_p)->xunmap.type;}
static void set_XEvent_xunmap_type(void *_p, int _v) {((XEvent *)_p)->xunmap.type = (int)_v;}
static unsigned long get_XEvent_xunmap_serial(void *_p) {return (unsigned long)((XEvent *)_p)->xunmap.serial;}
static void set_XEvent_xunmap_serial(void *_p, unsigned long _v) {((XEvent *)_p)->xunmap.serial = (unsigned long)_v;}
static int get_XEvent_xunmap_send_event(void *_p) {return (int)((XEvent *)_p)->xunmap.send_event;}
static void set_XEvent_xunmap_send_event(void *_p, int _v) {((XEvent *)_p)->xunmap.send_event = (int)_v;}
static void *get_XEvent_xunmap_display(void *_p) {return (void *)((XEvent *)_p)->xunmap.display;}
static void set_XEvent_xunmap_display(void *_p, void *_v) {((XEvent *)_p)->xunmap.display = (Display *)_v;}
static unsigned long get_XEvent_xunmap_event(void *_p) {return (unsigned long)((XEvent *)_p)->xunmap.event;}
static void set_XEvent_xunmap_event(void *_p, unsigned long _v) {((XEvent *)_p)->xunmap.event = (unsigned long)_v;}
static unsigned long get_XEvent_xunmap_window(void *_p) {return (unsigned long)((XEvent *)_p)->xunmap.window;}
static void set_XEvent_xunmap_window(void *_p, unsigned long _v) {((XEvent *)_p)->xunmap.window = (unsigned long)_v;}
static int get_XEvent_xunmap_from_configure(void *_p) {return (int)((XEvent *)_p)->xunmap.from_configure;}
static void set_XEvent_xunmap_from_configure(void *_p, int _v) {((XEvent *)_p)->xunmap.from_configure = (int)_v;}
static int get_XEvent_xmap_type(void *_p) {return (int)((XEvent *)_p)->xmap.type;}
static void set_XEvent_xmap_type(void *_p, int _v) {((XEvent *)_p)->xmap.type = (int)_v;}
static unsigned long get_XEvent_xmap_serial(void *_p) {return (unsigned long)((XEvent *)_p)->xmap.serial;}
static void set_XEvent_xmap_serial(void *_p, unsigned long _v) {((XEvent *)_p)->xmap.serial = (unsigned long)_v;}
static int get_XEvent_xmap_send_event(void *_p) {return (int)((XEvent *)_p)->xmap.send_event;}
static void set_XEvent_xmap_send_event(void *_p, int _v) {((XEvent *)_p)->xmap.send_event = (int)_v;}
static void *get_XEvent_xmap_display(void *_p) {return (void *)((XEvent *)_p)->xmap.display;}
static void set_XEvent_xmap_display(void *_p, void *_v) {((XEvent *)_p)->xmap.display = (Display *)_v;}
static unsigned long get_XEvent_xmap_event(void *_p) {return (unsigned long)((XEvent *)_p)->xmap.event;}
static void set_XEvent_xmap_event(void *_p, unsigned long _v) {((XEvent *)_p)->xmap.event = (unsigned long)_v;}
static unsigned long get_XEvent_xmap_window(void *_p) {return (unsigned long)((XEvent *)_p)->xmap.window;}
static void set_XEvent_xmap_window(void *_p, unsigned long _v) {((XEvent *)_p)->xmap.window = (unsigned long)_v;}
static int get_XEvent_xmap_override_redirect(void *_p) {return (int)((XEvent *)_p)->xmap.override_redirect;}
static void set_XEvent_xmap_override_redirect(void *_p, int _v) {((XEvent *)_p)->xmap.override_redirect = (int)_v;}
static int get_XEvent_xmaprequest_type(void *_p) {return (int)((XEvent *)_p)->xmaprequest.type;}
static void set_XEvent_xmaprequest_type(void *_p, int _v) {((XEvent *)_p)->xmaprequest.type = (int)_v;}
static unsigned long get_XEvent_xmaprequest_serial(void *_p) {return (unsigned long)((XEvent *)_p)->xmaprequest.serial;}
static void set_XEvent_xmaprequest_serial(void *_p, unsigned long _v) {((XEvent *)_p)->xmaprequest.serial = (unsigned long)_v;}
static int get_XEvent_xmaprequest_send_event(void *_p) {return (int)((XEvent *)_p)->xmaprequest.send_event;}
static void set_XEvent_xmaprequest_send_event(void *_p, int _v) {((XEvent *)_p)->xmaprequest.send_event = (int)_v;}
static void *get_XEvent_xmaprequest_display(void *_p) {return (void *)((XEvent *)_p)->xmaprequest.display;}
static void set_XEvent_xmaprequest_display(void *_p, void *_v) {((XEvent *)_p)->xmaprequest.display = (Display *)_v;}
static unsigned long get_XEvent_xmaprequest_parent(void *_p) {return (unsigned long)((XEvent *)_p)->xmaprequest.parent;}
static void set_XEvent_xmaprequest_parent(void *_p, unsigned long _v) {((XEvent *)_p)->xmaprequest.parent = (unsigned long)_v;}
static unsigned long get_XEvent_xmaprequest_window(void *_p) {return (unsigned long)((XEvent *)_p)->xmaprequest.window;}
static void set_XEvent_xmaprequest_window(void *_p, unsigned long _v) {((XEvent *)_p)->xmaprequest.window = (unsigned long)_v;}
static int get_XEvent_xreparent_type(void *_p) {return (int)((XEvent *)_p)->xreparent.type;}
static void set_XEvent_xreparent_type(void *_p, int _v) {((XEvent *)_p)->xreparent.type = (int)_v;}
static unsigned long get_XEvent_xreparent_serial(void *_p) {return (unsigned long)((XEvent *)_p)->xreparent.serial;}
static void set_XEvent_xreparent_serial(void *_p, unsigned long _v) {((XEvent *)_p)->xreparent.serial = (unsigned long)_v;}
static int get_XEvent_xreparent_send_event(void *_p) {return (int)((XEvent *)_p)->xreparent.send_event;}
static void set_XEvent_xreparent_send_event(void *_p, int _v) {((XEvent *)_p)->xreparent.send_event = (int)_v;}
static void *get_XEvent_xreparent_display(void *_p) {return (void *)((XEvent *)_p)->xreparent.display;}
static void set_XEvent_xreparent_display(void *_p, void *_v) {((XEvent *)_p)->xreparent.display = (Display *)_v;}
static unsigned long get_XEvent_xreparent_event(void *_p) {return (unsigned long)((XEvent *)_p)->xreparent.event;}
static void set_XEvent_xreparent_event(void *_p, unsigned long _v) {((XEvent *)_p)->xreparent.event = (unsigned long)_v;}
static unsigned long get_XEvent_xreparent_window(void *_p) {return (unsigned long)((XEvent *)_p)->xreparent.window;}
static void set_XEvent_xreparent_window(void *_p, unsigned long _v) {((XEvent *)_p)->xreparent.window = (unsigned long)_v;}
static unsigned long get_XEvent_xreparent_parent(void *_p) {return (unsigned long)((XEvent *)_p)->xreparent.parent;}
static void set_XEvent_xreparent_parent(void *_p, unsigned long _v) {((XEvent *)_p)->xreparent.parent = (unsigned long)_v;}
static int get_XEvent_xreparent_x(void *_p) {return (int)((XEvent *)_p)->xreparent.x;}
static void set_XEvent_xreparent_x(void *_p, int _v) {((XEvent *)_p)->xreparent.x = (int)_v;}
static int get_XEvent_xreparent_y(void *_p) {return (int)((XEvent *)_p)->xreparent.y;}
static void set_XEvent_xreparent_y(void *_p, int _v) {((XEvent *)_p)->xreparent.y = (int)_v;}
static int get_XEvent_xreparent_override_redirect(void *_p) {return (int)((XEvent *)_p)->xreparent.override_redirect;}
static void set_XEvent_xreparent_override_redirect(void *_p, int _v) {((XEvent *)_p)->xreparent.override_redirect = (int)_v;}
static int get_XEvent_xconfigure_type(void *_p) {return (int)((XEvent *)_p)->xconfigure.type;}
static void set_XEvent_xconfigure_type(void *_p, int _v) {((XEvent *)_p)->xconfigure.type = (int)_v;}
static unsigned long get_XEvent_xconfigure_serial(void *_p) {return (unsigned long)((XEvent *)_p)->xconfigure.serial;}
static void set_XEvent_xconfigure_serial(void *_p, unsigned long _v) {((XEvent *)_p)->xconfigure.serial = (unsigned long)_v;}
static int get_XEvent_xconfigure_send_event(void *_p) {return (int)((XEvent *)_p)->xconfigure.send_event;}
static void set_XEvent_xconfigure_send_event(void *_p, int _v) {((XEvent *)_p)->xconfigure.send_event = (int)_v;}
static void *get_XEvent_xconfigure_display(void *_p) {return (void *)((XEvent *)_p)->xconfigure.display;}
static void set_XEvent_xconfigure_display(void *_p, void *_v) {((XEvent *)_p)->xconfigure.display = (Display *)_v;}
static unsigned long get_XEvent_xconfigure_event(void *_p) {return (unsigned long)((XEvent *)_p)->xconfigure.event;}
static void set_XEvent_xconfigure_event(void *_p, unsigned long _v) {((XEvent *)_p)->xconfigure.event = (unsigned long)_v;}
static unsigned long get_XEvent_xconfigure_window(void *_p) {return (unsigned long)((XEvent *)_p)->xconfigure.window;}
static void set_XEvent_xconfigure_window(void *_p, unsigned long _v) {((XEvent *)_p)->xconfigure.window = (unsigned long)_v;}
static int get_XEvent_xconfigure_x(void *_p) {return (int)((XEvent *)_p)->xconfigure.x;}
static void set_XEvent_xconfigure_x(void *_p, int _v) {((XEvent *)_p)->xconfigure.x = (int)_v;}
static int get_XEvent_xconfigure_y(void *_p) {return (int)((XEvent *)_p)->xconfigure.y;}
static void set_XEvent_xconfigure_y(void *_p, int _v) {((XEvent *)_p)->xconfigure.y = (int)_v;}
static int get_XEvent_xconfigure_width(void *_p) {return (int)((XEvent *)_p)->xconfigure.width;}
static void set_XEvent_xconfigure_width(void *_p, int _v) {((XEvent *)_p)->xconfigure.width = (int)_v;}
static int get_XEvent_xconfigure_height(void *_p) {return (int)((XEvent *)_p)->xconfigure.height;}
static void set_XEvent_xconfigure_height(void *_p, int _v) {((XEvent *)_p)->xconfigure.height = (int)_v;}
static int get_XEvent_xconfigure_border_width(void *_p) {return (int)((XEvent *)_p)->xconfigure.border_width;}
static void set_XEvent_xconfigure_border_width(void *_p, int _v) {((XEvent *)_p)->xconfigure.border_width = (int)_v;}
static unsigned long get_XEvent_xconfigure_above(void *_p) {return (unsigned long)((XEvent *)_p)->xconfigure.above;}
static void set_XEvent_xconfigure_above(void *_p, unsigned long _v) {((XEvent *)_p)->xconfigure.above = (unsigned long)_v;}
static int get_XEvent_xconfigure_override_redirect(void *_p) {return (int)((XEvent *)_p)->xconfigure.override_redirect;}
static void set_XEvent_xconfigure_override_redirect(void *_p, int _v) {((XEvent *)_p)->xconfigure.override_redirect = (int)_v;}
static int get_XEvent_xgravity_type(void *_p) {return (int)((XEvent *)_p)->xgravity.type;}
static void set_XEvent_xgravity_type(void *_p, int _v) {((XEvent *)_p)->xgravity.type = (int)_v;}
static unsigned long get_XEvent_xgravity_serial(void *_p) {return (unsigned long)((XEvent *)_p)->xgravity.serial;}
static void set_XEvent_xgravity_serial(void *_p, unsigned long _v) {((XEvent *)_p)->xgravity.serial = (unsigned long)_v;}
static int get_XEvent_xgravity_send_event(void *_p) {return (int)((XEvent *)_p)->xgravity.send_event;}
static void set_XEvent_xgravity_send_event(void *_p, int _v) {((XEvent *)_p)->xgravity.send_event = (int)_v;}
static void *get_XEvent_xgravity_display(void *_p) {return (void *)((XEvent *)_p)->xgravity.display;}
static void set_XEvent_xgravity_display(void *_p, void *_v) {((XEvent *)_p)->xgravity.display = (Display *)_v;}
static unsigned long get_XEvent_xgravity_event(void *_p) {return (unsigned long)((XEvent *)_p)->xgravity.event;}
static void set_XEvent_xgravity_event(void *_p, unsigned long _v) {((XEvent *)_p)->xgravity.event = (unsigned long)_v;}
static unsigned long get_XEvent_xgravity_window(void *_p) {return (unsigned long)((XEvent *)_p)->xgravity.window;}
static void set_XEvent_xgravity_window(void *_p, unsigned long _v) {((XEvent *)_p)->xgravity.window = (unsigned long)_v;}
static int get_XEvent_xgravity_x(void *_p) {return (int)((XEvent *)_p)->xgravity.x;}
static void set_XEvent_xgravity_x(void *_p, int _v) {((XEvent *)_p)->xgravity.x = (int)_v;}
static int get_XEvent_xgravity_y(void *_p) {return (int)((XEvent *)_p)->xgravity.y;}
static void set_XEvent_xgravity_y(void *_p, int _v) {((XEvent *)_p)->xgravity.y = (int)_v;}
static int get_XEvent_xresizerequest_type(void *_p) {return (int)((XEvent *)_p)->xresizerequest.type;}
static void set_XEvent_xresizerequest_type(void *_p, int _v) {((XEvent *)_p)->xresizerequest.type = (int)_v;}
static unsigned long get_XEvent_xresizerequest_serial(void *_p) {return (unsigned long)((XEvent *)_p)->xresizerequest.serial;}
static void set_XEvent_xresizerequest_serial(void *_p, unsigned long _v) {((XEvent *)_p)->xresizerequest.serial = (unsigned long)_v;}
static int get_XEvent_xresizerequest_send_event(void *_p) {return (int)((XEvent *)_p)->xresizerequest.send_event;}
static void set_XEvent_xresizerequest_send_event(void *_p, int _v) {((XEvent *)_p)->xresizerequest.send_event = (int)_v;}
static void *get_XEvent_xresizerequest_display(void *_p) {return (void *)((XEvent *)_p)->xresizerequest.display;}
static void set_XEvent_xresizerequest_display(void *_p, void *_v) {((XEvent *)_p)->xresizerequest.display = (Display *)_v;}
static unsigned long get_XEvent_xresizerequest_window(void *_p) {return (unsigned long)((XEvent *)_p)->xresizerequest.window;}
static void set_XEvent_xresizerequest_window(void *_p, unsigned long _v) {((XEvent *)_p)->xresizerequest.window = (unsigned long)_v;}
static int get_XEvent_xresizerequest_width(void *_p) {return (int)((XEvent *)_p)->xresizerequest.width;}
static void set_XEvent_xresizerequest_width(void *_p, int _v) {((XEvent *)_p)->xresizerequest.width = (int)_v;}
static int get_XEvent_xresizerequest_height(void *_p) {return (int)((XEvent *)_p)->xresizerequest.height;}
static void set_XEvent_xresizerequest_height(void *_p, int _v) {((XEvent *)_p)->xresizerequest.height = (int)_v;}
static int get_XEvent_xconfigurerequest_type(void *_p) {return (int)((XEvent *)_p)->xconfigurerequest.type;}
static void set_XEvent_xconfigurerequest_type(void *_p, int _v) {((XEvent *)_p)->xconfigurerequest.type = (int)_v;}
static unsigned long get_XEvent_xconfigurerequest_serial(void *_p) {return (unsigned long)((XEvent *)_p)->xconfigurerequest.serial;}
static void set_XEvent_xconfigurerequest_serial(void *_p, unsigned long _v) {((XEvent *)_p)->xconfigurerequest.serial = (unsigned long)_v;}
static int get_XEvent_xconfigurerequest_send_event(void *_p) {return (int)((XEvent *)_p)->xconfigurerequest.send_event;}
static void set_XEvent_xconfigurerequest_send_event(void *_p, int _v) {((XEvent *)_p)->xconfigurerequest.send_event = (int)_v;}
static void *get_XEvent_xconfigurerequest_display(void *_p) {return (void *)((XEvent *)_p)->xconfigurerequest.display;}
static void set_XEvent_xconfigurerequest_display(void *_p, void *_v) {((XEvent *)_p)->xconfigurerequest.display = (Display *)_v;}
static unsigned long get_XEvent_xconfigurerequest_parent(void *_p) {return (unsigned long)((XEvent *)_p)->xconfigurerequest.parent;}
static void set_XEvent_xconfigurerequest_parent(void *_p, unsigned long _v) {((XEvent *)_p)->xconfigurerequest.parent = (unsigned long)_v;}
static unsigned long get_XEvent_xconfigurerequest_window(void *_p) {return (unsigned long)((XEvent *)_p)->xconfigurerequest.window;}
static void set_XEvent_xconfigurerequest_window(void *_p, unsigned long _v) {((XEvent *)_p)->xconfigurerequest.window = (unsigned long)_v;}
static int get_XEvent_xconfigurerequest_x(void *_p) {return (int)((XEvent *)_p)->xconfigurerequest.x;}
static void set_XEvent_xconfigurerequest_x(void *_p, int _v) {((XEvent *)_p)->xconfigurerequest.x = (int)_v;}
static int get_XEvent_xconfigurerequest_y(void *_p) {return (int)((XEvent *)_p)->xconfigurerequest.y;}
static void set_XEvent_xconfigurerequest_y(void *_p, int _v) {((XEvent *)_p)->xconfigurerequest.y = (int)_v;}
static int get_XEvent_xconfigurerequest_width(void *_p) {return (int)((XEvent *)_p)->xconfigurerequest.width;}
static void set_XEvent_xconfigurerequest_width(void *_p, int _v) {((XEvent *)_p)->xconfigurerequest.width = (int)_v;}
static int get_XEvent_xconfigurerequest_height(void *_p) {return (int)((XEvent *)_p)->xconfigurerequest.height;}
static void set_XEvent_xconfigurerequest_height(void *_p, int _v) {((XEvent *)_p)->xconfigurerequest.height = (int)_v;}
static int get_XEvent_xconfigurerequest_border_width(void *_p) {return (int)((XEvent *)_p)->xconfigurerequest.border_width;}
static void set_XEvent_xconfigurerequest_border_width(void *_p, int _v) {((XEvent *)_p)->xconfigurerequest.border_width = (int)_v;}
static unsigned long get_XEvent_xconfigurerequest_above(void *_p) {return (unsigned long)((XEvent *)_p)->xconfigurerequest.above;}
static void set_XEvent_xconfigurerequest_above(void *_p, unsigned long _v) {((XEvent *)_p)->xconfigurerequest.above = (unsigned long)_v;}
static int get_XEvent_xconfigurerequest_detail(void *_p) {return (int)((XEvent *)_p)->xconfigurerequest.detail;}
static void set_XEvent_xconfigurerequest_detail(void *_p, int _v) {((XEvent *)_p)->xconfigurerequest.detail = (int)_v;}
static unsigned long get_XEvent_xconfigurerequest_value_mask(void *_p) {return (unsigned long)((XEvent *)_p)->xconfigurerequest.value_mask;}
static void set_XEvent_xconfigurerequest_value_mask(void *_p, unsigned long _v) {((XEvent *)_p)->xconfigurerequest.value_mask = (unsigned long)_v;}
static int get_XEvent_xcirculate_type(void *_p) {return (int)((XEvent *)_p)->xcirculate.type;}
static void set_XEvent_xcirculate_type(void *_p, int _v) {((XEvent *)_p)->xcirculate.type = (int)_v;}
static unsigned long get_XEvent_xcirculate_serial(void *_p) {return (unsigned long)((XEvent *)_p)->xcirculate.serial;}
static void set_XEvent_xcirculate_serial(void *_p, unsigned long _v) {((XEvent *)_p)->xcirculate.serial = (unsigned long)_v;}
static int get_XEvent_xcirculate_send_event(void *_p) {return (int)((XEvent *)_p)->xcirculate.send_event;}
static void set_XEvent_xcirculate_send_event(void *_p, int _v) {((XEvent *)_p)->xcirculate.send_event = (int)_v;}
static void *get_XEvent_xcirculate_display(void *_p) {return (void *)((XEvent *)_p)->xcirculate.display;}
static void set_XEvent_xcirculate_display(void *_p, void *_v) {((XEvent *)_p)->xcirculate.display = (Display *)_v;}
static unsigned long get_XEvent_xcirculate_event(void *_p) {return (unsigned long)((XEvent *)_p)->xcirculate.event;}
static void set_XEvent_xcirculate_event(void *_p, unsigned long _v) {((XEvent *)_p)->xcirculate.event = (unsigned long)_v;}
static unsigned long get_XEvent_xcirculate_window(void *_p) {return (unsigned long)((XEvent *)_p)->xcirculate.window;}
static void set_XEvent_xcirculate_window(void *_p, unsigned long _v) {((XEvent *)_p)->xcirculate.window = (unsigned long)_v;}
static int get_XEvent_xcirculate_place(void *_p) {return (int)((XEvent *)_p)->xcirculate.place;}
static void set_XEvent_xcirculate_place(void *_p, int _v) {((XEvent *)_p)->xcirculate.place = (int)_v;}
static int get_XEvent_xcirculaterequest_type(void *_p) {return (int)((XEvent *)_p)->xcirculaterequest.type;}
static void set_XEvent_xcirculaterequest_type(void *_p, int _v) {((XEvent *)_p)->xcirculaterequest.type = (int)_v;}
static unsigned long get_XEvent_xcirculaterequest_serial(void *_p) {return (unsigned long)((XEvent *)_p)->xcirculaterequest.serial;}
static void set_XEvent_xcirculaterequest_serial(void *_p, unsigned long _v) {((XEvent *)_p)->xcirculaterequest.serial = (unsigned long)_v;}
static int get_XEvent_xcirculaterequest_send_event(void *_p) {return (int)((XEvent *)_p)->xcirculaterequest.send_event;}
static void set_XEvent_xcirculaterequest_send_event(void *_p, int _v) {((XEvent *)_p)->xcirculaterequest.send_event = (int)_v;}
static void *get_XEvent_xcirculaterequest_display(void *_p) {return (void *)((XEvent *)_p)->xcirculaterequest.display;}
static void set_XEvent_xcirculaterequest_display(void *_p, void *_v) {((XEvent *)_p)->xcirculaterequest.display = (Display *)_v;}
static unsigned long get_XEvent_xcirculaterequest_parent(void *_p) {return (unsigned long)((XEvent *)_p)->xcirculaterequest.parent;}
static void set_XEvent_xcirculaterequest_parent(void *_p, unsigned long _v) {((XEvent *)_p)->xcirculaterequest.parent = (unsigned long)_v;}
static unsigned long get_XEvent_xcirculaterequest_window(void *_p) {return (unsigned long)((XEvent *)_p)->xcirculaterequest.window;}
static void set_XEvent_xcirculaterequest_window(void *_p, unsigned long _v) {((XEvent *)_p)->xcirculaterequest.window = (unsigned long)_v;}
static int get_XEvent_xcirculaterequest_place(void *_p) {return (int)((XEvent *)_p)->xcirculaterequest.place;}
static void set_XEvent_xcirculaterequest_place(void *_p, int _v) {((XEvent *)_p)->xcirculaterequest.place = (int)_v;}
static int get_XEvent_xproperty_type(void *_p) {return (int)((XEvent *)_p)->xproperty.type;}
static void set_XEvent_xproperty_type(void *_p, int _v) {((XEvent *)_p)->xproperty.type = (int)_v;}
static unsigned long get_XEvent_xproperty_serial(void *_p) {return (unsigned long)((XEvent *)_p)->xproperty.serial;}
static void set_XEvent_xproperty_serial(void *_p, unsigned long _v) {((XEvent *)_p)->xproperty.serial = (unsigned long)_v;}
static int get_XEvent_xproperty_send_event(void *_p) {return (int)((XEvent *)_p)->xproperty.send_event;}
static void set_XEvent_xproperty_send_event(void *_p, int _v) {((XEvent *)_p)->xproperty.send_event = (int)_v;}
static void *get_XEvent_xproperty_display(void *_p) {return (void *)((XEvent *)_p)->xproperty.display;}
static void set_XEvent_xproperty_display(void *_p, void *_v) {((XEvent *)_p)->xproperty.display = (Display *)_v;}
static unsigned long get_XEvent_xproperty_window(void *_p) {return (unsigned long)((XEvent *)_p)->xproperty.window;}
static void set_XEvent_xproperty_window(void *_p, unsigned long _v) {((XEvent *)_p)->xproperty.window = (unsigned long)_v;}
static unsigned long get_XEvent_xproperty_atom(void *_p) {return (unsigned long)((XEvent *)_p)->xproperty.atom;}
static void set_XEvent_xproperty_atom(void *_p, unsigned long _v) {((XEvent *)_p)->xproperty.atom = (unsigned long)_v;}
static unsigned long get_XEvent_xproperty_time(void *_p) {return (unsigned long)((XEvent *)_p)->xproperty.time;}
static void set_XEvent_xproperty_time(void *_p, unsigned long _v) {((XEvent *)_p)->xproperty.time = (unsigned long)_v;}
static int get_XEvent_xproperty_state(void *_p) {return (int)((XEvent *)_p)->xproperty.state;}
static void set_XEvent_xproperty_state(void *_p, int _v) {((XEvent *)_p)->xproperty.state = (int)_v;}
static int get_XEvent_xselectionclear_type(void *_p) {return (int)((XEvent *)_p)->xselectionclear.type;}
static void set_XEvent_xselectionclear_type(void *_p, int _v) {((XEvent *)_p)->xselectionclear.type = (int)_v;}
static unsigned long get_XEvent_xselectionclear_serial(void *_p) {return (unsigned long)((XEvent *)_p)->xselectionclear.serial;}
static void set_XEvent_xselectionclear_serial(void *_p, unsigned long _v) {((XEvent *)_p)->xselectionclear.serial = (unsigned long)_v;}
static int get_XEvent_xselectionclear_send_event(void *_p) {return (int)((XEvent *)_p)->xselectionclear.send_event;}
static void set_XEvent_xselectionclear_send_event(void *_p, int _v) {((XEvent *)_p)->xselectionclear.send_event = (int)_v;}
static void *get_XEvent_xselectionclear_display(void *_p) {return (void *)((XEvent *)_p)->xselectionclear.display;}
static void set_XEvent_xselectionclear_display(void *_p, void *_v) {((XEvent *)_p)->xselectionclear.display = (Display *)_v;}
static unsigned long get_XEvent_xselectionclear_window(void *_p) {return (unsigned long)((XEvent *)_p)->xselectionclear.window;}
static void set_XEvent_xselectionclear_window(void *_p, unsigned long _v) {((XEvent *)_p)->xselectionclear.window = (unsigned long)_v;}
static unsigned long get_XEvent_xselectionclear_selection(void *_p) {return (unsigned long)((XEvent *)_p)->xselectionclear.selection;}
static void set_XEvent_xselectionclear_selection(void *_p, unsigned long _v) {((XEvent *)_p)->xselectionclear.selection = (unsigned long)_v;}
static unsigned long get_XEvent_xselectionclear_time(void *_p) {return (unsigned long)((XEvent *)_p)->xselectionclear.time;}
static void set_XEvent_xselectionclear_time(void *_p, unsigned long _v) {((XEvent *)_p)->xselectionclear.time = (unsigned long)_v;}
static int get_XEvent_xselectionrequest_type(void *_p) {return (int)((XEvent *)_p)->xselectionrequest.type;}
static void set_XEvent_xselectionrequest_type(void *_p, int _v) {((XEvent *)_p)->xselectionrequest.type = (int)_v;}
static unsigned long get_XEvent_xselectionrequest_serial(void *_p) {return (unsigned long)((XEvent *)_p)->xselectionrequest.serial;}
static void set_XEvent_xselectionrequest_serial(void *_p, unsigned long _v) {((XEvent *)_p)->xselectionrequest.serial = (unsigned long)_v;}
static int get_XEvent_xselectionrequest_send_event(void *_p) {return (int)((XEvent *)_p)->xselectionrequest.send_event;}
static void set_XEvent_xselectionrequest_send_event(void *_p, int _v) {((XEvent *)_p)->xselectionrequest.send_event = (int)_v;}
static void *get_XEvent_xselectionrequest_display(void *_p) {return (void *)((XEvent *)_p)->xselectionrequest.display;}
static void set_XEvent_xselectionrequest_display(void *_p, void *_v) {((XEvent *)_p)->xselectionrequest.display = (Display *)_v;}
static unsigned long get_XEvent_xselectionrequest_owner(void *_p) {return (unsigned long)((XEvent *)_p)->xselectionrequest.owner;}
static void set_XEvent_xselectionrequest_owner(void *_p, unsigned long _v) {((XEvent *)_p)->xselectionrequest.owner = (unsigned long)_v;}
static unsigned long get_XEvent_xselectionrequest_requestor(void *_p) {return (unsigned long)((XEvent *)_p)->xselectionrequest.requestor;}
static void set_XEvent_xselectionrequest_requestor(void *_p, unsigned long _v) {((XEvent *)_p)->xselectionrequest.requestor = (unsigned long)_v;}
static unsigned long get_XEvent_xselectionrequest_selection(void *_p) {return (unsigned long)((XEvent *)_p)->xselectionrequest.selection;}
static void set_XEvent_xselectionrequest_selection(void *_p, unsigned long _v) {((XEvent *)_p)->xselectionrequest.selection = (unsigned long)_v;}
static unsigned long get_XEvent_xselectionrequest_target(void *_p) {return (unsigned long)((XEvent *)_p)->xselectionrequest.target;}
static void set_XEvent_xselectionrequest_target(void *_p, unsigned long _v) {((XEvent *)_p)->xselectionrequest.target = (unsigned long)_v;}
static unsigned long get_XEvent_xselectionrequest_property(void *_p) {return (unsigned long)((XEvent *)_p)->xselectionrequest.property;}
static void set_XEvent_xselectionrequest_property(void *_p, unsigned long _v) {((XEvent *)_p)->xselectionrequest.property = (unsigned long)_v;}
static unsigned long get_XEvent_xselectionrequest_time(void *_p) {return (unsigned long)((XEvent *)_p)->xselectionrequest.time;}
static void set_XEvent_xselectionrequest_time(void *_p, unsigned long _v) {((XEvent *)_p)->xselectionrequest.time = (unsigned long)_v;}
static int get_XEvent_xselection_type(void *_p) {return (int)((XEvent *)_p)->xselection.type;}
static void set_XEvent_xselection_type(void *_p, int _v) {((XEvent *)_p)->xselection.type = (int)_v;}
static unsigned long get_XEvent_xselection_serial(void *_p) {return (unsigned long)((XEvent *)_p)->xselection.serial;}
static void set_XEvent_xselection_serial(void *_p, unsigned long _v) {((XEvent *)_p)->xselection.serial = (unsigned long)_v;}
static int get_XEvent_xselection_send_event(void *_p) {return (int)((XEvent *)_p)->xselection.send_event;}
static void set_XEvent_xselection_send_event(void *_p, int _v) {((XEvent *)_p)->xselection.send_event = (int)_v;}
static void *get_XEvent_xselection_display(void *_p) {return (void *)((XEvent *)_p)->xselection.display;}
static void set_XEvent_xselection_display(void *_p, void *_v) {((XEvent *)_p)->xselection.display = (Display *)_v;}
static unsigned long get_XEvent_xselection_requestor(void *_p) {return (unsigned long)((XEvent *)_p)->xselection.requestor;}
static void set_XEvent_xselection_requestor(void *_p, unsigned long _v) {((XEvent *)_p)->xselection.requestor = (unsigned long)_v;}
static unsigned long get_XEvent_xselection_selection(void *_p) {return (unsigned long)((XEvent *)_p)->xselection.selection;}
static void set_XEvent_xselection_selection(void *_p, unsigned long _v) {((XEvent *)_p)->xselection.selection = (unsigned long)_v;}
static unsigned long get_XEvent_xselection_target(void *_p) {return (unsigned long)((XEvent *)_p)->xselection.target;}
static void set_XEvent_xselection_target(void *_p, unsigned long _v) {((XEvent *)_p)->xselection.target = (unsigned long)_v;}
static unsigned long get_XEvent_xselection_property(void *_p) {return (unsigned long)((XEvent *)_p)->xselection.property;}
static void set_XEvent_xselection_property(void *_p, unsigned long _v) {((XEvent *)_p)->xselection.property = (unsigned long)_v;}
static unsigned long get_XEvent_xselection_time(void *_p) {return (unsigned long)((XEvent *)_p)->xselection.time;}
static void set_XEvent_xselection_time(void *_p, unsigned long _v) {((XEvent *)_p)->xselection.time = (unsigned long)_v;}
static int get_XEvent_xcolormap_type(void *_p) {return (int)((XEvent *)_p)->xcolormap.type;}
static void set_XEvent_xcolormap_type(void *_p, int _v) {((XEvent *)_p)->xcolormap.type = (int)_v;}
static unsigned long get_XEvent_xcolormap_serial(void *_p) {return (unsigned long)((XEvent *)_p)->xcolormap.serial;}
static void set_XEvent_xcolormap_serial(void *_p, unsigned long _v) {((XEvent *)_p)->xcolormap.serial = (unsigned long)_v;}
static int get_XEvent_xcolormap_send_event(void *_p) {return (int)((XEvent *)_p)->xcolormap.send_event;}
static void set_XEvent_xcolormap_send_event(void *_p, int _v) {((XEvent *)_p)->xcolormap.send_event = (int)_v;}
static void *get_XEvent_xcolormap_display(void *_p) {return (void *)((XEvent *)_p)->xcolormap.display;}
static void set_XEvent_xcolormap_display(void *_p, void *_v) {((XEvent *)_p)->xcolormap.display = (Display *)_v;}
static unsigned long get_XEvent_xcolormap_window(void *_p) {return (unsigned long)((XEvent *)_p)->xcolormap.window;}
static void set_XEvent_xcolormap_window(void *_p, unsigned long _v) {((XEvent *)_p)->xcolormap.window = (unsigned long)_v;}
static unsigned long get_XEvent_xcolormap_colormap(void *_p) {return (unsigned long)((XEvent *)_p)->xcolormap.colormap;}
static void set_XEvent_xcolormap_colormap(void *_p, unsigned long _v) {((XEvent *)_p)->xcolormap.colormap = (unsigned long)_v;}
static int get_XEvent_xcolormap_new(void *_p) {return (int)((XEvent *)_p)->xcolormap.new;}
static void set_XEvent_xcolormap_new(void *_p, int _v) {((XEvent *)_p)->xcolormap.new = (int)_v;}
static int get_XEvent_xcolormap_state(void *_p) {return (int)((XEvent *)_p)->xcolormap.state;}
static void set_XEvent_xcolormap_state(void *_p, int _v) {((XEvent *)_p)->xcolormap.state = (int)_v;}
static int get_XEvent_xclient_type(void *_p) {return (int)((XEvent *)_p)->xclient.type;}
static void set_XEvent_xclient_type(void *_p, int _v) {((XEvent *)_p)->xclient.type = (int)_v;}
static unsigned long get_XEvent_xclient_serial(void *_p) {return (unsigned long)((XEvent *)_p)->xclient.serial;}
static void set_XEvent_xclient_serial(void *_p, unsigned long _v) {((XEvent *)_p)->xclient.serial = (unsigned long)_v;}
static int get_XEvent_xclient_send_event(void *_p) {return (int)((XEvent *)_p)->xclient.send_event;}
static void set_XEvent_xclient_send_event(void *_p, int _v) {((XEvent *)_p)->xclient.send_event = (int)_v;}
static void *get_XEvent_xclient_display(void *_p) {return (void *)((XEvent *)_p)->xclient.display;}
static void set_XEvent_xclient_display(void *_p, void *_v) {((XEvent *)_p)->xclient.display = (Display *)_v;}
static unsigned long get_XEvent_xclient_window(void *_p) {return (unsigned long)((XEvent *)_p)->xclient.window;}
static void set_XEvent_xclient_window(void *_p, unsigned long _v) {((XEvent *)_p)->xclient.window = (unsigned long)_v;}
static unsigned long get_XEvent_xclient_message_type(void *_p) {return (unsigned long)((XEvent *)_p)->xclient.message_type;}
static void set_XEvent_xclient_message_type(void *_p, unsigned long _v) {((XEvent *)_p)->xclient.message_type = (unsigned long)_v;}
static int get_XEvent_xclient_format(void *_p) {return (int)((XEvent *)_p)->xclient.format;}
static void set_XEvent_xclient_format(void *_p, int _v) {((XEvent *)_p)->xclient.format = (int)_v;}
static void *get_XEvent_xclient_data_b(void *_p) {return (void *)(((XEvent *)_p)->xclient.data.b);}
static void *get_XEvent_xclient_data_s(void *_p) {return (void *)(((XEvent *)_p)->xclient.data.s);}
static void *get_XEvent_xclient_data_l(void *_p) {return (void *)(((XEvent *)_p)->xclient.data.l);}
static int get_XEvent_xmapping_type(void *_p) {return (int)((XEvent *)_p)->xmapping.type;}
static void set_XEvent_xmapping_type(void *_p, int _v) {((XEvent *)_p)->xmapping.type = (int)_v;}
static unsigned long get_XEvent_xmapping_serial(void *_p) {return (unsigned long)((XEvent *)_p)->xmapping.serial;}
static void set_XEvent_xmapping_serial(void *_p, unsigned long _v) {((XEvent *)_p)->xmapping.serial = (unsigned long)_v;}
static int get_XEvent_xmapping_send_event(void *_p) {return (int)((XEvent *)_p)->xmapping.send_event;}
static void set_XEvent_xmapping_send_event(void *_p, int _v) {((XEvent *)_p)->xmapping.send_event = (int)_v;}
static void *get_XEvent_xmapping_display(void *_p) {return (void *)((XEvent *)_p)->xmapping.display;}
static void set_XEvent_xmapping_display(void *_p, void *_v) {((XEvent *)_p)->xmapping.display = (Display *)_v;}
static unsigned long get_XEvent_xmapping_window(void *_p) {return (unsigned long)((XEvent *)_p)->xmapping.window;}
static void set_XEvent_xmapping_window(void *_p, unsigned long _v) {((XEvent *)_p)->xmapping.window = (unsigned long)_v;}
static int get_XEvent_xmapping_request(void *_p) {return (int)((XEvent *)_p)->xmapping.request;}
static void set_XEvent_xmapping_request(void *_p, int _v) {((XEvent *)_p)->xmapping.request = (int)_v;}
static int get_XEvent_xmapping_first_keycode(void *_p) {return (int)((XEvent *)_p)->xmapping.first_keycode;}
static void set_XEvent_xmapping_first_keycode(void *_p, int _v) {((XEvent *)_p)->xmapping.first_keycode = (int)_v;}
static int get_XEvent_xmapping_count(void *_p) {return (int)((XEvent *)_p)->xmapping.count;}
static void set_XEvent_xmapping_count(void *_p, int _v) {((XEvent *)_p)->xmapping.count = (int)_v;}
static int get_XEvent_xerror_type(void *_p) {return (int)((XEvent *)_p)->xerror.type;}
static void set_XEvent_xerror_type(void *_p, int _v) {((XEvent *)_p)->xerror.type = (int)_v;}
static void *get_XEvent_xerror_display(void *_p) {return (void *)((XEvent *)_p)->xerror.display;}
static void set_XEvent_xerror_display(void *_p, void *_v) {((XEvent *)_p)->xerror.display = (Display *)_v;}
static unsigned long get_XEvent_xerror_resourceid(void *_p) {return (unsigned long)((XEvent *)_p)->xerror.resourceid;}
static void set_XEvent_xerror_resourceid(void *_p, unsigned long _v) {((XEvent *)_p)->xerror.resourceid = (unsigned long)_v;}
static unsigned long get_XEvent_xerror_serial(void *_p) {return (unsigned long)((XEvent *)_p)->xerror.serial;}
static void set_XEvent_xerror_serial(void *_p, unsigned long _v) {((XEvent *)_p)->xerror.serial = (unsigned long)_v;}
static unsigned char get_XEvent_xerror_error_code(void *_p) {return (unsigned char)((XEvent *)_p)->xerror.error_code;}
static void set_XEvent_xerror_error_code(void *_p, unsigned char _v) {((XEvent *)_p)->xerror.error_code = (unsigned char)_v;}
static unsigned char get_XEvent_xerror_request_code(void *_p) {return (unsigned char)((XEvent *)_p)->xerror.request_code;}
static void set_XEvent_xerror_request_code(void *_p, unsigned char _v) {((XEvent *)_p)->xerror.request_code = (unsigned char)_v;}
static unsigned char get_XEvent_xerror_minor_code(void *_p) {return (unsigned char)((XEvent *)_p)->xerror.minor_code;}
static void set_XEvent_xerror_minor_code(void *_p, unsigned char _v) {((XEvent *)_p)->xerror.minor_code = (unsigned char)_v;}
static int get_XEvent_xkeymap_type(void *_p) {return (int)((XEvent *)_p)->xkeymap.type;}
static void set_XEvent_xkeymap_type(void *_p, int _v) {((XEvent *)_p)->xkeymap.type = (int)_v;}
static unsigned long get_XEvent_xkeymap_serial(void *_p) {return (unsigned long)((XEvent *)_p)->xkeymap.serial;}
static void set_XEvent_xkeymap_serial(void *_p, unsigned long _v) {((XEvent *)_p)->xkeymap.serial = (unsigned long)_v;}
static int get_XEvent_xkeymap_send_event(void *_p) {return (int)((XEvent *)_p)->xkeymap.send_event;}
static void set_XEvent_xkeymap_send_event(void *_p, int _v) {((XEvent *)_p)->xkeymap.send_event = (int)_v;}
static void *get_XEvent_xkeymap_display(void *_p) {return (void *)((XEvent *)_p)->xkeymap.display;}
static void set_XEvent_xkeymap_display(void *_p, void *_v) {((XEvent *)_p)->xkeymap.display = (Display *)_v;}
static unsigned long get_XEvent_xkeymap_window(void *_p) {return (unsigned long)((XEvent *)_p)->xkeymap.window;}
static void set_XEvent_xkeymap_window(void *_p, unsigned long _v) {((XEvent *)_p)->xkeymap.window = (unsigned long)_v;}
static void *get_XEvent_xkeymap_key_vector(void *_p) {return (void *)(((XEvent *)_p)->xkeymap.key_vector);}
static void *get_XEvent_pad(void *_p) {return (void *)(((XEvent *)_p)->pad);}
static void *alloc_XEDataObject(void) {XEDataObject *_p = (XEDataObject *)malloc(sizeof(XEDataObject)); if (_p==NULL) abort(); return (void *)_p;}
static void free_XEDataObject(void *_p) {if (_p==NULL) abort(); free((XEDataObject *)_p);}
static void *get_XEDataObject_display(void *_p) {return (void *)((XEDataObject *)_p)->display;}
static void set_XEDataObject_display(void *_p, void *_v) {((XEDataObject *)_p)->display = (Display *)_v;}
static void *get_XEDataObject_gc(void *_p) {return (void *)((XEDataObject *)_p)->gc;}
static void set_XEDataObject_gc(void *_p, void *_v) {((XEDataObject *)_p)->gc = (void *)_v;}
static void *get_XEDataObject_visual(void *_p) {return (void *)((XEDataObject *)_p)->visual;}
static void set_XEDataObject_visual(void *_p, void *_v) {((XEDataObject *)_p)->visual = (Visual *)_v;}
static void *get_XEDataObject_screen(void *_p) {return (void *)((XEDataObject *)_p)->screen;}
static void set_XEDataObject_screen(void *_p, void *_v) {((XEDataObject *)_p)->screen = (Screen *)_v;}
static void *get_XEDataObject_pixmap_format(void *_p) {return (void *)((XEDataObject *)_p)->pixmap_format;}
static void set_XEDataObject_pixmap_format(void *_p, void *_v) {((XEDataObject *)_p)->pixmap_format = (ScreenFormat *)_v;}
static void *get_XEDataObject_font(void *_p) {return (void *)((XEDataObject *)_p)->font;}
static void set_XEDataObject_font(void *_p, void *_v) {((XEDataObject *)_p)->font = (XFontStruct *)_v;}

static void *alloc_int(void) {int *_p = (int *)malloc(sizeof(int)); if (_p==NULL) abort(); return (void *)_p;}
static void free_int(void *_p) {if (_p==NULL) abort(); free((int *)_p);}
static int get_int(void *_p) {return *((int *)_p);}
static void set_int(void *_p, int _v) {*((int *)_p) = _v;}
