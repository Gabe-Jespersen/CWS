CC = g++
CFLAGS =  -std=c++11 -g -Wall -lcurses -fpermissive -O2


all: CWS

CWS: main.o turn.o clearscreen.o endcheck.o parse.o
	$(CC) $(CFLAGS) main.o turn.o clearscreen.o endcheck.o parse.o -o CWS

main.o: main.cpp clearscreen.h turn.h endcheck.h parse.h
	$(CC) $(CFLAGS) -c main.cpp

turn.o: turn.cpp turn.h
	$(CC) $(CFLAGS) -c turn.cpp

clearscreen.o: clearscreen.cpp clearscreen.h
	$(CC) $(CFLAGS) -c clearscreen.cpp

endcheck.o: endcheck.cpp endcheck.h
	$(CC) $(CFLAGS) -c endcheck.cpp

parse.o: parse.cpp
	$(CC) $(CFLAGS) -c parse.cpp


clean:
	rm -rf *.o CWS
