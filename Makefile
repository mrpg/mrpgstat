CXX = g++
LD = ld
CXXFLAGS = -Wall -O3 -s -std=gnu++0x
INSTALL_PROGRAM = install
BINDIR = /usr/bin

all: mrpgstat

clean:
	rm mrpgstat

mrpgstat: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o mrpgstat

install: mrpgstat
	$(INSTALL_PROGRAM) mrpgstat $(BINDIR)/mrpgstat
