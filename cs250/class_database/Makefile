class_database: main.o io.o add.o remove.o
	clang -o class_database main.o io.o add.o remove.o

main.o: main.c class_info.h io.h add.h remove.h
	clang -c -Wall -pedantic-errors main.c

io.o: io.c class_info.h
	clang -c -Wall -pedantic-errors io.c

add.o: add.c class_info.h
	clang -c -Wall -pedantic-errors add.c

remove.o: remove.c class_info.h
	clang -c -Wall -pedantic-errors remove.c

all: class_database

clean:
	rm -f main.o io.o add.o remove.o class_database class_database.tar

tarball:
	tar -c -f class_database.tar main.c class_info.h io.c io.h add.c add.h remove.c remove.h Makefile