CC=g++
CPPFLAGS=-Wall -Werror -Wextra -c

ifeq ($(OS),Windows_NT)
    RM = del /Q /F
else
		RM = rm -f
endif

all: build


build: lab7.exe 


lab7.exe: Functions.o Main.o
		${CC} Functions.o Main.o -o lab7
		$(RM) *.o

Functions.o: Functions.cpp
		$(CC) ${CPPFLAGS} Functions.cpp

Main.o: Main.cpp
		${CC} ${CPPFLAGS} Main.cpp


clean:
		$(RM) *.o
		$(RM) *.exe