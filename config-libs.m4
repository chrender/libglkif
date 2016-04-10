
libglkif_nonpkg_cflags=""

AC_CHECK_HEADER([glk.h],
  [],
  [for dir in $with_glk_includedir $with_glktermw_includedir /usr/include /usr/local/include ; do
     AC_MSG_CHECKING(for $dir/glk.h)
     if [ test -e $dir/glk.h ]; then
       AC_MSG_RESULT(yes)
       glk_h_dir=$dir
       break
     else
       AC_MSG_RESULT(no)
     fi
   done
   if [ test "x$glk_h_dir" == "x"] ; then
     echo "Could not find glk.h."
     echo "Try setting the location using --with-glk-includedir."
     AS_EXIT
   fi
   libglkif_nonpkg_cflags+="-I$glk_h_dir"])

