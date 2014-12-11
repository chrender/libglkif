
# This is included from fizmo-dist and not required by libfizmo's own
# configuration. It nevertheless needs to be maintained so fizmo-dist
# will still work.
#
# The $build_prefix, $build_prefix_cflags and $build_prefix_libs are
# pre-defined by fizmo-dist.

AC_SUBST([LIBGLKIF_NONPKG_CFLAGS], "$libglkif_nonpkg_cflags")
AC_SUBST([LIBGLKIF_NONPKG_LIBS], "$libglkif_nonpkg_libs")
AC_SUBST([libglkif_CFLAGS], "-I$build_prefix_cflags $libglkif_nonpkg_cflags")
AC_SUBST([libglkif_LIBS], "-L$build_prefix_libs -lglkif $libglkif_nonpkg_libs")

