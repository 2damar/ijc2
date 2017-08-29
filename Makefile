CC=gcc
CPP=g++
CFLAGS=-std=c99 -O2 -Wall -Wextra -pedantic
CPPFLAGS=-std=c++11 -O2 -Wall -Wextra -pedantic

all: tail tail2 wordcount wordcount-dynamic 

tail: tail.o
	$(CC) $(CFLAGS) $< -o $@

tail2: tail2.o
	$(CPP) $(CPPFLAGS) $< -o $@

tail.o: tail.c
	$(CC) $(CFLAGS) -c $< -o $@

tail2.o: tail2.cc
	$(CPP) $(CPPFLAGS) -c $< -o $@

wordcount: wordcount.o io.o libhtab.a
	$(CC) $(CFLAGS) $^ -o $@

wordcount-dynamic: wordcount.o io.o libhtab.so
	$(CC) $(CFLAGS) -L/home/mil/src/C/ijc/2 $^ -o $@ -lhtab

wordcount.o: wordcount.c htab.h io.h
	$(CC) $(CFLAGS) -c $< -o $@

io.o: io.c io.h
	$(CC) $(CFLAGS) -c $< -o $@

libhtab.a: hash_function.o htab_bucket_count.o htab_clear.o \
			  htab_find.o htab_foreach.o htab_free.o htab_init.o \
			  htab_lookup_add.o htab_move.o htab_remove.o htab_size.o
	ar rcs $@ $^

libhtab.so: hash_function.o htab_bucket_count.o htab_clear.o \
			  htab_find.o htab_foreach.o htab_free.o htab_init.o \
			  htab_lookup_add.o htab_move.o htab_remove.o htab_size.o
	$(CC) -shared $^ -o $@


hash_function.o: hash_function.c
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

htab_bucket_count.o: htab_bucket_count.c htab.h
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

htab_clear.o: htab_clear.c htab.h
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

htab_find.o: htab_find.c htab.h
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

htab_foreach.o: htab_foreach.c htab.h
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

htab_free.o: htab_free.c htab.h
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

htab_init.o: htab_init.c htab.h
	$(CC) $(CFLAGS) -fPIC -c $< -o $@
	
htab_lookup_add.o: htab_lookup_add.c htab.h
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

htab_move.o: htab_move.c htab.h
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

htab_remove.o: htab_remove.c htab.h
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

htab_size.o: htab_size.c htab.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean: 
	rm -f *.o
