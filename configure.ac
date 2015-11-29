#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([zeus], [1.0], [vgeshiktor@gmail.com])
AC_CONFIG_SRCDIR([src/hermes/manager.cpp])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

# Checks for programs.

# Set empty default flags
if test -z $CXXFLAGS; then
	    CXXFLAGS=''
fi

AC_PROG_CXX

# Set empty default flags
if test -z $CFLAGS; then
	    CFLAGS=''
fi

AC_PROG_CC

# Checks for libraries.
AC_PROG_RANLIB
AM_PROG_AR

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL

# Checks for library functions.

AC_OUTPUT(Makefile src/Makefile doc/Makefile examples/Makefile man/Makefile
		  scripts/Makefile src/hermes/Makefile src/apollo/Makefile
		  src/cerberus/Makefile src/infra/Makefile src/infra/process/Makefile
		  src/infra/msgqueue/Makefile)
