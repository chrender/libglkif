
CC = gcc
AR = ar
override CFLAGS += -Wall -Wextra

prefix = /usr/local
destprefix = $(DESTDIR)$(prefix)
bindir = $(destprefix)/bin
datarootdir = $(destprefix)/share
mandir = $(datarootdir)/man
localedir = $(datarootdir)/fizmo/locales


# -----
# General settings:
ENABLE_OPTIMIZATION = 1
#ENABLE_TRACING = 1
#ENABLE_GDB_SYMBOLS = 1
# -----



# -----
# Settings for libglkif:
LIBGLK_NONPKG_CFLAGS = -I$(HOME)/opt/glktermw
LIBGLK_NONPKG_LIBS = -L$(HOME)/opt/glktermw
# -----

