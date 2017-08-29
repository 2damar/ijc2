#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LINE_LEN 1024

int read_line(FILE* f, int n, char* buffer) {
	static bool longline = false;
	int c = fgetc(f);
	if(c == EOF) 
		return c;
	int i;
	for(i = 0; (i < n-1) && c!= EOF && c != '\n'; i++) {
		buffer[i] = c;
		c = fgetc(f);
	}
	buffer[i] = '\0';
	if(c != '\n' && c != EOF) {
		if(longline) 
			fprintf(stderr, "Line has more than %d chars", n);
		longline = true;
		while((c = fgetc(f)) != EOF && c != '\n'); //skip rest of the line
   }
	return c;
}
	

int tail(FILE *f, int nlines) {
	if(f == NULL) 
		return -1;

	char** lines = (char**)malloc(nlines * sizeof(char*));
	if(lines == NULL) 
		return -1;
	

	for(int i = 0; i < nlines; i++) {
		lines[i] = (char*) malloc(LINE_LEN*sizeof(char));
		if(lines[i] == NULL) {
			while(--i >= 0) 
				free(lines[i]);
			free(lines);
			return -1;
		}
	}

	int li = 0;
	int rewind = 0;
	int c;
	while((c = read_line(f, LINE_LEN, lines[li])) != EOF) {
		li++;
		if(li == nlines) {
			rewind = 1;
			li = 0;
		}
	}
			
	if(rewind) {
		for(int i = li; i < nlines; i++) 
			printf("%s\n", lines[i]);
		for(int i = 0; i < li; i++)
			printf("%s\n", lines[i]);
	} else {
		for (int i = 0; i < li; i++)
			printf("%s\n", lines[i]);
	}

	for(int i = 0; i < li; i++) 
		free(lines[i]);

	free(lines);

	return li;
}

void usage() {
	fprintf(stderr, "Usage: ./tail [-n lines] [file]");
	exit(1);
}

int main(int argc, char* argv[]) {

	int nlines = 10;
	FILE* f = stdin;

	if(argc == 2) {
		f = fopen(argv[1], "r");
		if(f == NULL)
			return -1;
	} else if(argc == 3) {
		if(strcmp(argv[1], "-n") != 0)	
			usage();
		nlines = atoi(argv[2]);
	} else if(argc == 4) {
		if(strcmp(argv[1], "-n") != 0)
			usage();
		nlines = atoi(argv[2]);
		f = fopen(argv[3], "r");
		if(f == NULL)
			return -1;
	} else if(argc != 1) {
		usage();
	}

	tail(f, nlines);

	return 0;
}
