#ifndef AQUANT_H
#define AQUANT_H

#include <stddef.h> // Required for size_t potentially used by underlying functions

// Define string type alias like CS50
typedef char *string;

// Function prototypes
char get_char(const char *prompt);
double get_double(const char *prompt);
float get_float(const char *prompt);
int get_int(const char *prompt);
long get_long(const char *prompt);
string get_string(const char *prompt);

#endif // AQUANT_H
