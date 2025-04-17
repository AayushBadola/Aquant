#ifndef AQUANT_H
#define AQUANT_H

#include <stddef.h>
#include <stdbool.h>

typedef char *string;

char get_char(const char *prompt);
double get_double(const char *prompt);
float get_float(const char *prompt);
int get_int(const char *prompt);
long get_long(const char *prompt);
string get_string(const char *prompt);

bool array_max(const int *arr, size_t size, int *max_val);
bool array_min(const int *arr, size_t size, int *min_val);
bool array_sum(const int *arr, size_t size, long long *sum);
bool array_has_pair_sum(const int *arr, size_t size, int target);
bool array_has_pair_product(const int *arr, size_t size, int target);
bool array_has_pair_difference(const int *arr, size_t size, int target);


void sort_array_n(int arr[], size_t size);
int find_name(const char *names[], size_t size, const char *target_name);
void print_array(const int arr[], size_t size);

#endif // AQUANT_H
