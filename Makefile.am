
# Makefile.am
#
# This file is part of fizmo.
#
# Copyright (c) 2009-2014 Christoph Ender.
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
# 3. The name of the author may not be used to endorse or promote products
#    derived from this software without specific prior written permission.
# 
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
# IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
# OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
# IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
# NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
# THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


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
	echo 'Version: 0.1.7' >>$(PKGFILE)
	echo 'Requires: $(LIBGLKIF_REQS) ' >>$(PKGFILE)
	echo 'Requires.private:' >>$(PKGFILE)
	echo 'Cflags: -I$(fizmo_build_prefix)/include/fizmo $(LIBGLKIF_NONPKG_CFLAGS)' >>$(PKGFILE)
	echo 'Libs: -L$(fizmo_build_prefix)/lib/fizmo -lglkif $(LIBGLKIF_NONPKG_LIBS)' >>$(PKGFILE)
	echo >>$(PKGFILE)

install-data-local::
	mkdir -p $(DESTDIR)$(localedir)
	for l in `cd src/locales ; ls -d ??_??`; \
	do \
	  mkdir -p $(DESTDIR)$(localedir)/$$l; \
	  cp src/locales/$$l/*.txt $(DESTDIR)$(localedir)/$$l; \
	done

# About "-rmdir": make ignores errors of commands which are prefixed with
# a - sign. rmdir may fail in clean-dev in case other libs have installed
# development files, or in case clean-dev has been run before.
clean-dev::
	-rm "$(fizmo_build_prefix)/lib/fizmo/libglkif.a"
	-rmdir "$(fizmo_build_prefix)/lib/fizmo"
	rm -rf "$(fizmo_build_prefix)/include/fizmo/glk_interface"
	-rmdir "$(fizmo_build_prefix)/include/fizmo"
	-rmdir "$(fizmo_build_prefix)/include"
	-rm "$(PKGFILE)"
	-rmdir "$(PKG_DIR)"
	-rmdir "$(fizmo_build_prefix)/lib"

