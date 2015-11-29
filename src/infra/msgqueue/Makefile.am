# what flags you want to pass to the C compiler & linker
AM_CXXFLAGS = --pedantic -Wall -std=c++11 -g3 -O0
AM_CFLAGS = --pedantic -Wall -std=c++11 -g3 -O0
AM_CPPFLAGS = -I../../

# this lists the binaries to produce, the (non-PHONY, binary) targets in
# the previous manual Makefile
noinst_LIBRARIES = libmsgqueue.a
libmsgqueue_a_SOURCES = msgqueue.cpp 
