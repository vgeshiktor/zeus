# what flags you want to pass to the C compiler & linker
AM_CXXFLAGS = --pedantic -Wall -Wextra -std=c++11 -g3 -O0
AM_CFLAGS = --pedantic -Wall -Wextra -std=c++11 -g3 -O0
AM_CPPFLAGS = -I../infra/msgqueue -I../infra/process

# this lists the binaries to produce, the (non-PHONY, binary) targets in
# the previous manual Makefile
bin_PROGRAMS = apollo
apollo_SOURCES = apollo.cpp manager.cpp manager.h worker.cpp worker.h
apollo_LDADD = -L../infra/msgqueue -lmsgqueue -L../infra/process -lprocess
