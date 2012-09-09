
AM_CFLAGS = $(libfizmo_CFLAGS) $(LIBGLKIF_NONPKG_CFLAGS)
AM_CPPFLAGS =
LDADD = $(libfizmo_LIBS) $(LIBGLKIF_NONPKG_LIBS)

localedir = $(datarootdir)/fizmo/locales

noinst_LIBRARIES = libglkif.a
libglkif_a_SOURCES = ../locales/libglkif_locales.c glk_interface.c glk_blorb_if.c glk_filesys_if.c glk_screen_if.c

if ENABLE_TRACING
AM_CFLAGS += -DENABLE_TRACING=
endif

