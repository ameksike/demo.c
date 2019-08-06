/* snaccconfig.h
 *
 * This is an automatically generated file - please modify 'configure.in'.
 */

#ifndef _SNACCCONFIG_H
#define _SNACCCONFIG_H

/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated from configure.ac by autoheader.  */
/*
 * file: acconfig.h
 *
 * $Header: /usr/app/odstb/CVS/snacc/acconfig.h,v 1.7 1997/03/03 11:58:26 wan Exp $
 * $Log: acconfig.h,v $
 * Revision 1.7  1997/03/03 11:58:26  wan
 * Final pre-delivery stuff (I hope).
 *
 * Revision 1.6  1997/02/28 13:39:34  wan
 * Modifications collected for new version 1.3: Bug fixes, tk4.2.
 *
 * Revision 1.5  1997/02/15 20:01:37  rj
 * check whether the compiler supports volatile functions (and whether abort() is volatile).
 *
 * Revision 1.4  1995/02/20  11:16:57  rj
 * cpp switch HAVE_VARIABLE_SIZED_AUTOMATIC_ARRAYS added.
 *
 * Revision 1.3  1995/02/13  14:46:49  rj
 * settings for IEEE_REAL_FMT/IEEE_REAL_LIB moved from {c_lib,c++_lib}/inc/asn_config.h to acconfig.h.
 *
 * Revision 1.2  1994/10/08  04:38:56  rj
 * slot for autoconf Tcl detection added.
 *
 * Revision 1.1  1994/09/01  00:51:19  rj
 * first check-in (new file).
 *
 */

/*
 * define IEEE_REAL_FMT if your system/compiler uses the native ieee double
 * this should improve the performance of encoding reals.
 * If your system has the IEEE library routines (iszero, isinf etc)
 * then define IEEE_REAL_LIB.  If neither are defined then
 * frexp is used.  Performance is probaby best for IEEE_REAL_FMT.
 *
 *  #define IEEE_REAL_FMT
 *  #define IEEE_REAL_LIB
 */
/* use ANSI or K&R style C? */
#define __USE_ANSI_C__ 1

/* does the C++ compiler have the bool type built-in? */
#define BOOL_BUILTIN 1

/* does the C++ compiler allow variable sized automatic arryas? */
#define HAVE_VARIABLE_SIZED_AUTOMATIC_ARRAYS 1

/* do we have all the libs we need for the Tcl interface? */
/* #undef HAVE_TCL */

/* does the compiler support volatile functions (and is abort() volatile?) */
#define COMPILER_WITHOUT_VOLATILE_FUNCTIONS 1

/* Define to 1 if you have the <dirent.h> header file, and it defines `DIR'.
   */
#define HAVE_DIRENT_H 1

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define to 1 if you don't have `vprintf' but do have `_doprnt.' */
/* #undef HAVE_DOPRNT */

/* Define to 1 if you have the <fcntl.h> header file. */
#define HAVE_FCNTL_H 1

/* Define to 1 if you have the `finite' function. */
#define HAVE_FINITE 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the `isinf' function. */
#define HAVE_ISINF 1

/* Define to 1 if you have the `m' library (-lm). */
#define HAVE_LIBM 1

/* Define to 1 if you have the <malloc.h> header file. */
#define HAVE_MALLOC_H 1

/* Define to 1 if you have the `memcmp' function. */
#define HAVE_MEMCMP 1

/* Define to 1 if you have the `memcpy' function. */
#define HAVE_MEMCPY 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the `memset' function. */
#define HAVE_MEMSET 1

/* Define to 1 if you have the <ndir.h> header file, and it defines `DIR'. */
/* #undef HAVE_NDIR_H */

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/dir.h> header file, and it defines `DIR'.
   */
/* #undef HAVE_SYS_DIR_H */

/* Define to 1 if you have the <sys/ndir.h> header file, and it defines `DIR'.
   */
/* #undef HAVE_SYS_NDIR_H */

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to 1 if you have the `vprintf' function. */
#define HAVE_VPRINTF 1

/* Name of package */

/* Define to the address where bug reports for this package should be sent. */

/* Define to the full name of this package. */

/* Define to the full name and version of this package. */

/* Define to the one symbol short name of this package. */

/* Define to the version of this package. */

/* The size of `double', as computed by sizeof. */
#define SIZEOF_DOUBLE 8

/* The size of `int', as computed by sizeof. */
#define SIZEOF_INT 4

/* The size of `long', as computed by sizeof. */
#define SIZEOF_LONG 4

/* The size of `short', as computed by sizeof. */
#define SIZEOF_SHORT 2

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Define to 1 if you can safely include both <sys/time.h> and <time.h>. */
#define TIME_WITH_SYS_TIME 1

/* Version number of package */

/* Define to 1 if your processor stores words with the most significant byte
   first (like Motorola and SPARC, unlike Intel and VAX). */
/* #undef WORDS_BIGENDIAN */

/* Define to 1 if the X Window System is missing or not being used. */
/* #undef X_DISPLAY_MISSING */

/* Define to 1 if `lex' declares `yytext' as a `char *' by default, not a
   `char[]'. */
#define YYTEXT_POINTER 1

/* Define to empty if `const' does not conform to ANSI C. */
/* #undef const */

/* Define to `int' if <sys/types.h> doesn't define. */
/* #undef gid_t */

/* Define to `unsigned int' if <sys/types.h> does not define. */
/* #undef size_t */

/* Define to `int' if <sys/types.h> doesn't define. */
/* #undef uid_t */
#define SNACC_DEEP_COPY 1
#endif /* !_SNACCCONFIG_H */
