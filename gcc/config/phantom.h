/* Configuration common to all targets running PhantomOS. 
   Copyright (C) 2000-2021 Free Software Foundation, Inc.

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published
   by the Free Software Foundation; either version 3, or (at your
   option) any later version.

   GCC is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   Under Section 7 of GPL version 3, you are granted additional
   permissions described in the GCC Runtime Library Exception, version
   3.1, as published by the Free Software Foundation.

   You should have received a copy of the GNU General Public License and
   a copy of the GCC Runtime Library Exception along with this program;
   see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
   <http://www.gnu.org/licenses/>.  */

#ifndef PHANTOMOS_STARTFILE_SPEC
#define PHANTOMOS_STARTFILE_SPEC "crti%O%s crtbegin%O%s"
#endif

#ifndef PHANTOMOS_ENDFILE_SPEC
#define PHANTOMOS_ENDFILE_SPEC "crtend%O%s crtn%O%s"
#endif

/*
 * The crt0.o is a dummy start file to let the linker work as needed by
 * autoconf scripts using this compiler.
 */
#undef STARTFILE_SPEC
#define STARTFILE_SPEC \
"%{!nostdlib:%{!nostartfiles:" PHANTOMOS_STARTFILE_SPEC "}}"

#undef ENDFILE_SPEC
#define ENDFILE_SPEC \
"%{!nostdlib:%{!nostartfiles:" PHANTOMOS_ENDFILE_SPEC "}}"


#undef LIB_SPEC
#define LIB_SPEC \
"%{!nostdlib:%{!nodefaultlibs:--start-group -lc -lgcc --end-group}}"

#undef STDINT_LONG32
#define STDINT_LONG32 (INT_TYPE_SIZE != 32 && LONG_TYPE_SIZE == 32)

#undef GNU_USER_DYNAMIC_LINKER
#define GNU_USER_DYNAMIC_LINKER "/lib/ld-phantom.so"

