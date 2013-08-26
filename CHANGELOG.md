


   **Version 0.1.7**

 - Adapted to automake v1.14 “subdir-objects” option.

---


   **Version 0.1.6 —  5, 2013**

 - Fixed verification of libglktermw location in “config-libs.m4”.
 - Renamed “install-locales” to “install-data” build target.
 - Adapted to new readchar function names in file system interface.

---


   **Version 0.1.5 —  30, 2012**

 - Fixed include statement in “configure.ac”.

---


   **Version 0.1.4 —  17, 2012**

 - Adapted to new autoconf/automake build system.

---


   **Version 0.1.3 —  1, 2012**

 - Merged with Andrew Plotkin's iOS-fizmo implementation: replaced old “fizmo_register_ask_user_for_file_function” with “prompt_for_file” implementation in “glk_screen_if.c”, added quote box support.

---


   **Version 0.1.2 —  9, 2012**

 - Merged zarf's GLK changes into “glk_screen_if.c”. The new version 0.1.2 fixes screen size detection, timed input and adds lowering of the input line.
 - Fixed missing $(DESTDIR) variable – should already have been present since version 0.1.1.

---


   **Version 0.1.1 —  6, 2011**

 - Fixed missing “override” statments for CFLAGS in Makefiles.
 - Fixed $(DESTDIR) evaluation in config.[default|macports].mk.
 - Adapted Makefiles and configuration to use standard GNU Makefile variables instead of INSTALL_PATH and FIZMO_BIN_DIR.

---


   **Version 0.1.0 —  18, 2011**

 - libglkif was built from code in Andrew Plotkin's github repository. It represents an interface translating fizmo's Z-machine output operations into GLK-invocations. The current code should be seen as a first experimental release. Please note that bug reports should be sent to [mailto:fizmo@spellbreaker.org](mailto:fizmo@spellbreaker.org) instead of sending them to Andrew Plotkin.
 - The “fizmo-glktermw” frontend relies on libglkif for it's GLK output.

