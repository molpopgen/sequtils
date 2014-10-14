AC_PREREQ(2.59)

AC_INIT(sequtils, [0.2.9], [https://github.com/molpopgen/sequtils])
AC_CONFIG_SRCDIR([src/revcom.cc])
AM_INIT_AUTOMAKE
AC_CONFIG_HEADERS([config-h.in])

AC_CONFIG_MACRO_DIR([m4])

AC_PROG_CC
AC_C_CONST
AC_PROG_CXX
AX_CXX_COMPILE_STDCXX_11([noext],[mandatory])

AM_MAINTAINER_MODE([enable])

AC_LANG(C++)
AC_CONFIG_FILES([Makefile src/Makefile])

AC_ARG_ENABLE(debug,
[  --enable-debug    Turn on debugging],
[case "${enableval}" in
  yes) debug=true ;;
  no)  debug=false ;;
  *) AC_MSG_ERROR(bad value ${enableval} for --enable-debug) ;;
esac],[debug=false])
AM_CONDITIONAL(DEBUG, test x$debug = xtrue)

AC_ARG_ENABLE(profiling,
[  --enable-profiling    Turn on profiling],
[case "${enableval}" in
  yes) profiling=true ;;
  no)  profiling=false ;;
  *) AC_MSG_ERROR(bad value ${enableval} for --enable-profiling) ;;
esac],[profiling=false])
AM_CONDITIONAL(PROFILING, test x$profiling = xtrue)


dnl check for zlib
ZLIB_HEADERS_FOUND="false"
AC_CHECK_HEADER(zlib.h,ZLIB_HEADERS_FOUND="true")
AM_CONDITIONAL(HAVE_ZLIB_HEADERS,test x$ZLIB_HEADERS_FOUND = xtrue)

AC_LANG_SAVE
          AC_LANG_CPLUSPLUS
          AC_REQUIRE_CPP
	  AC_CHECK_LIB(sequence, main,,[echo "libsequence runtime library does not seem to be here";exit 1])	
AC_LANG_RESTORE
dnl AM_CONFIG_HEADER(config.h)

AC_OUTPUT
