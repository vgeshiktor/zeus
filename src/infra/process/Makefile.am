# what flags you want to pass to the C compiler & linker
AM_CXXFLAGS = --pedantic -Wall -Wextra -std=c++11 -g3 -O0
AM_CFLAGS = --pedantic -Wall -Wextra -std=c++11 -g3 -O0
AM_CPPFLAGS = -I../../ -I../msgqueue

# this lists the binaries to produce, the (non-PHONY, binary) targets in
# the previous manual Makefile
noinst_LIBRARIES = libprocess.a
libprocess_a_SOURCES = workerbase.cpp managerbase.cpp 
