
AUTOMAKE_OPTIONS = -Wno-override

localedir = $(datarootdir)/fizmo/locales

if FIZMO_BUILD_PREFIX_EMPTY
  fizmo_build_prefix=$(DESTDIR)$(prefix)
endif

PKG_DIR = $(fizmo_build_prefix)/lib/pkgconfig
PKGFILE = $(PKG_DIR)/libcellif.pc

SUBDIRS = src/glk_interface .
noinst_LIBRARIES = libglkif.a

libglkif.a:
	mv src/glk_interface/libglkif.a .

install-dev:: libglkif.a
	mkdir -p $(fizmo_build_prefix)/lib/fizmo
	mkdir -p $(fizmo_build_prefix)/include/fizmo/glk_interface
	cp src/glk_interface/*.h \
	  $(fizmo_build_prefix)/include/fizmo/glk_interface
	cp libglkif.a $(fizmo_build_prefix)/lib/fizmo
	mkdir -p $(PKG_DIR)
	echo 'prefix=$(fizmo_build_prefix)' >$(PKGFILE)
	echo 'exec_prefix=$${prefix}' >>$(PKGFILE)
	echo 'libdir=$${exec_prefix}/lib/fizmo' >>$(PKGFILE)
	echo 'includedir=$${prefix}/include/fizmo' >>$(PKGFILE)
	echo >>$(PKGFILE)
	echo 'Name: libglkif' >>$(PKGFILE)
	echo 'Description: libglkif' >>$(PKGFILE)
	echo 'Version: 0.1.4' >>$(PKGFILE)
	echo 'Requires: libfizmo >= 0.7.4 ' >>$(PKGFILE)
	echo 'Requires.private:' >>$(PKGFILE)
	echo 'Cflags: -I$(fizmo_build_prefix)/include/fizmo $(GLKTERMW_CFLAGS)' >>$(PKGFILE)
	echo 'Libs: -L$(fizmo_build_prefix)/lib/fizmo -lfizmo $(GLKTERMW_LIBS)' >>$(PKGFILE)
	echo >>$(PKGFILE)

install-locales::
	mkdir -p $(DESTDIR)$(localedir)
	for l in `cd src/locales ; ls -d ??_??`; \
	do \
	  mkdir -p $(DESTDIR)$(localedir)/$$l; \
	  cp src/locales/$$l/*.txt $(DESTDIR)$(localedir)/$$l; \
	done

