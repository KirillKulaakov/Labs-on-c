CC=g++
CPPFLAGS=-Wall -Werror -Wextra -c

ifeq ($(OS),Windows_NT)
    RM = del /Q /F
else
		RM = rm -f
endif

all: build


build: lab6_bits.exe lab6_float.exe 


lab6_bits.exe: lab6_bits_1.o lab6_bits.o
		${CC} lab6_bits_1.o lab6_bits.o -o lab6_bits
		$(RM) *.o

lab6_bits_1.o: lab6_bits_1.cpp
		$(CC) ${CPPFLAGS} lab6_bits_1.cpp

lab6_bits.o: lab6_bits.cpp
		${CC} ${CPPFLAGS} lab6_bits.cpp


lab6_float.exe: lab6_float.o
		${CC} lab6_float.o -o lab6_float
		$(RM) *.o

lab6_float.o: lab6_float.cpp
		${CC} ${CPPFLAGS} lab6_float.cpp


clean:
		$(RM) *.o
		$(RM) *.exe