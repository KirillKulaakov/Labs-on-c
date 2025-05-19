CC=g++
CPPFLAGS=-Wall -Werror -Wextra -c

ifeq ($(OS),Windows_NT)
    RM = del /Q /F
else
		RM = rm -f
endif

all: build


build: 268.exe 378.exe 


268.exe: 268.o 268_1.o
		${CC} 268_1.o 268.o -o 268
		$(RM) *.o

268_1.o: 268_1.cpp
		$(CC) ${CPPFLAGS} 268_1.cpp

268.o: 268.cpp
		${CC} ${CPPFLAGS} 268.cpp


378.exe: 378_1.o 378.o
		${CC} 378_1.o 378.o -o 378
		$(RM) *.o

378_1.o: 378_1.cpp
		$(CC) ${CPPFLAGS} 378_1.cpp

378.o: 378.cpp
		${CC} ${CPPFLAGS} 378.cpp


clean:
		$(RM) *.o
		$(RM) *.exe
