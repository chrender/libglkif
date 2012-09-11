
AUTOMAKE_OPTIONS = -Wno-override

localedir = $(datarootdir)/fizmo/locales

fizmo_build_prefix=$(DEV_BUILD_PREFIX)

PKG_DIR = $(fizmo_build_prefix)/lib/pkgconfig
PKGFILE = $(PKG_DIR)/libglkif.pc

SUBDIRS = src/glk_interface .
noinst_LIBRARIES = libglkif.a

libglkif.a::
	cd src/glk_interface ; make
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
	echo 'Requires: $(LIBGLKIF_REQS) ' >>$(PKGFILE)
	echo 'Requires.private:' >>$(PKGFILE)
	echo 'Cflags: -I$(fizmo_build_prefix)/include/fizmo $(LIBGLKIF_NONPKG_CFLAGS)' >>$(PKGFILE)
	echo 'Libs: -L$(fizmo_build_prefix)/lib/fizmo -lglkif $(LIBGLKIF_NONPKG_LIBS)' >>$(PKGFILE)
	echo >>$(PKGFILE)

install-locales::
	mkdir -p $(DESTDIR)$(localedir)
	for l in `cd src/locales ; ls -d ??_??`; \
	do \
	  mkdir -p $(DESTDIR)$(localedir)/$$l; \
	  cp src/locales/$$l/*.txt $(DESTDIR)$(localedir)/$$l; \
	done

