
AC_ARG_WITH([glk-includedir],
  [AS_HELP_STRING([--with-glk-includedir],
          [Specify include directory to use for glk-headers])],
  [AC_SUBST([with_glk_includedir],
   [$( echo $(cd $(dirname "$with_glk_includedir") && pwd -P)/$(basename "$with_glk_includedir") )])],
  [with_glk_includedir=])

