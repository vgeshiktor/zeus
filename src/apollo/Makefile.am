# what flags you want to pass to the C compiler & linker
AM_CXXFLAGS = --pedantic -Wall -Wextra -std=c++11 -g3 -O0
AM_CFLAGS = --pedantic -Wall -Wextra -std=c++11 -g3 -O0
AM_CPPFLAGS = -I../infra/msgqueue -I../infra/process

# this lists the binaries to produce, the (non-PHONY, binary) targets in
# the previous manual Makefile
bin_PROGRAMS = apollo client
apollo_SOURCES = apollo.cpp manager.cpp worker.cpp 
apollo_LDADD = -L../infra/process -lprocess -L../infra/msgqueue -lmsgqueue -lrt
client_SOURCES = client.cpp
client_LDADD = -L../infra/msgqueue -lmsgqueue -lrt
