
AC_ARG_ENABLE([tracing],
 [AS_HELP_STRING([--enable-tracing],
                 [enable tracelog for debugging])],
 [],
 [enable_tracing=no])

AC_ARG_WITH([glktermw-includedir],
  [AS_HELP_STRING([--with-glktermw-includedir],
          [Specify include directory to use for glktermw])],
  [],
  [with_glktermw_includedir=])

AC_ARG_WITH([glktermw-libdir],
  [AS_HELP_STRING([--with-glktermw-libdir],
          [Specify library directory for glktermw])],
  [],
  [with_glktermw_libdir=])

AC_INIT([libglkif], [0.1.4])

libglkif_reqs="libfizmo >= 0.7.4"
libglkif_nonpkg_cflags=""
libglkif_nonpkg_libs=""

AC_CONFIG_AUX_DIR([.])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_PROG_CC
AC_PROG_RANLIB
AM_PROG_AR

PKG_CHECK_MODULES(
 [ncursesw],
 [ncursesw],
 [AS_IF([test "x$libglkif_reqs" != "x"], [
    libglkif_reqs+=", "
  ])
  libglkif_reqs+="ncursesw"],
 [AC_MSG_ERROR([Could not find ncursesw.])
  AS_EXIT])

AM_CONDITIONAL([FIZMO_BUILD_PREFIX_EMPTY], [test "$fizmo_build_prefix" = ""])

PKG_CHECK_MODULES([libfizmo], [libfizmo >= 0.7.4])

AC_CHECK_HEADER([glkterm.h],
  [],
  [for dir in $with_glktermw_includedir /usr/include /usr/local/include ; do
     AC_MSG_CHECKING(for $dir/glkterm.h)
     if [ test -e $dir/glkterm.h ]; then
       AC_MSG_RESULT(yes)
       glk_h_dir=$dir
       break
     else
       AC_MSG_RESULT(no)
     fi
   done
   if [ test "x$glk_h_dir" == "x"] ; then
     echo "Could not find glk.h."
     echo "Try setting the location using --with-glktermw-includedir."
     AS_EXIT
   fi
   libglkif_nonpkg_cflags+="-I$glk_h_dir"])

AC_CHECK_LIB([glktermw],
  [main],
  [],
  [LIBS_OLD=$LIBS
   LIBS="-lglktermw $ncursesw_LIBS"
   for dir in $with_glktermw_libdir /usr/lib /usr/local/lib ; do
     AC_MSG_CHECKING(for libglktermw in $dir)
     LDFLAGS="-L$dir"
     AC_LINK_IFELSE(
       [AC_LANG_SOURCE(
        [[
          #include <stdio.h>
          #include <curses.h>
          #include "$glk_h_dir/glk.h"
          #include "$glk_h_dir/glkstart.h"
          glkunix_argumentlist_t glkunix_arguments[] = { };
          int glkunix_startup_code(glkunix_startup_t *data) { }
          void glk_main(void) { glk_exit(); } ]])],
       [AC_MSG_RESULT(yes)
        glk_l_dir=$dir
        break],
       [AC_MSG_RESULT(no)])
   done
   if [ test "x$glk_l_dir" == "x"] ; then
     echo "Could not find libglktermw."
     echo "Try setting the location using --with-glktermw-libdir."
     AC_MSG_ERROR([Could not find libglktermw.])
     AC_MSG_ERROR([You need to specify libglktermw.a location using "--with-glktermw-libdir=<path>".])
     AS_EXIT
   fi
   LIBS=$LIBS_OLD
   libglkif_nonpkg_libs="-L$glk_l_dir -lglktermw"
])

AM_CONDITIONAL([ENABLE_TRACING],
                [test "$enable_tracing" = "yes"])

AC_SUBST([LIBGLKIF_NONPKG_CFLAGS], $libglkif_nonpkg_cflags)
AC_SUBST([LIBGLKIF_NONPKG_LIBS], $libglkif_nonpkg_libs)

AC_CONFIG_FILES([Makefile src/glk_interface/Makefile])
AC_OUTPUT

