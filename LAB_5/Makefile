CC=g++
CPPFLAGS=-Wall -Werror -Wextra -c

ifeq ($(OS),Windows_NT)
    RM = del /Q /F
else
		RM = rm -f
endif

all: build


build: 258.exe 398.exe 


258.exe: 258_1.o 258.o
		${CC} 258_1.o 258.o -o 258
		$(RM) *.o

258_1.o: 258_1.cpp
		$(CC) ${CPPFLAGS} 258_1.cpp

258.o: 258.cpp
		${CC} ${CPPFLAGS} 258.cpp


398.exe: 398_1.o 398.o
		${CC} 398_1.o 398.o -o 398
		$(RM) *.o

398_1.o: 398_1.cpp
		$(CC) ${CPPFLAGS} 398_1.cpp

398.o: 398.cpp
		${CC} ${CPPFLAGS} 398.cpp


clean:
		$(RM) *.o
		$(RM) *.exe