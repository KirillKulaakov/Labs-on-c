CC=g++
CPPFLAGS=-Wall -Werror -Wextra -c


ifeq ($(OS),Windows_NT)
    RM = del /Q /F
else
		RM = rm -f
endif


all: build


build: lab7.exe 


lab7.exe: General_func.o Functions.o Main.o
		${CC} General_func.o Functions.o Main.o -o lab8
		$(RM) *.o

General_func.o: General_func.cpp
		$(CC) ${CPPFLAGS} General_func.cpp

Functions.o: Functions.cpp
		$(CC) ${CPPFLAGS} Functions.cpp

Main.o: Main.cpp
		${CC} ${CPPFLAGS} Main.cpp


clean:
		$(RM) *.o
		$(RM) *.exe