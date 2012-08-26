
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

AC_CONFIG_AUX_DIR([.])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_PROG_CC
AC_PROG_RANLIB
AM_PROG_AR

AM_CONDITIONAL([FIZMO_BUILD_PREFIX_EMPTY], [test "$fizmo_build_prefix" = ""])

PKG_CHECK_MODULES([libfizmo], [libfizmo >= 0.7.4])

AC_CHECK_HEADER([glk.h],
  [],
  [AC_MSG_ERROR([You need to specify glk.h location using "--with-glktermw-includedir=<path>".])])

AC_CHECK_LIB([glktermw],
  [main],
  [],
  [AC_MSG_ERROR([You need to specify libglktermw.a location using "--with-glktermw-libdir=<path>".])])

AM_CONDITIONAL([ENABLE_TRACING],
                [test "$enable_tracing" = "yes"])

# AC_SUBST([GLKTERMW_INCLUDE_DIR], $with_glktermw_includedir)
# AC_SUBST([GLKTERMW_LIB_DIR], $with_glktermw_libdir)

AC_CONFIG_FILES([Makefile src/glk_interface/Makefile])
AC_OUTPUT

