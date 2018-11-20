CXX = g++
CXXFLAGS = -Wall -g

HEADERS = TicTacToe.h clientserverhelper.h
CLIENTSOURCES = TicTacToe.cpp clientserverhelper.cpp client.cpp
CLIENTOBJECTS = client.o TicTacToe.o clientserverhelper.o
SERVEROBJECTS = server.o TicTacToe.o clientserverhelper.o

BINARIES = client server

all: $(BINARIES)

clean:
	-rm -f $(BINARIES) $(CLIENTOBJECTS) core

client: $(CLIENTOBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

server: $(SERVEROBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: $(HEADERS)

