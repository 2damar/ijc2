/**
 * Collection of functions for I/O
 */
#ifndef IO_H
#define IO_H

/**
 * Reads word from stream f to buffer s
 *
 * If word is longer than max than it prints warrning message to stderr
 * and skips rest of the word. Buffer has to has enough space free for 
 * max * char. Puts '\0' at the end. Returns number of characters read or EOF
 * @param buffer for the word
 * @param max maximum lenght of the word read - 1
 * @return number of chars read into s
 */
int get_word(char* s, int max, FILE* f);

#endif
