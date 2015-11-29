# what flags you want to pass to the C compiler & linker
AM_CXXFLAGS = --pedantic -Wall -std=c++11 -g3 -O0
AM_CFLAGS = --pedantic -Wall -std=c++11 -g3 -O0
AM_CPPFLAGS = -I../infra/process

# this lists the binaries to produce, the (non-PHONY, binary) targets in
# the previous manual Makefile
bin_PROGRAMS = cerberus
cerberus_SOURCES = cerberus.cpp manager.cpp manager.h
cerberus_LDADD = -L../infra/process -lprocess
