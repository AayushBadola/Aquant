#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <errno.h>
#include <stdbool.h>
#include <math.h>

#include "aquant.h"

string get_string(const char *prompt)
{
    if (prompt != NULL)
    {
        printf("%s", prompt);
        fflush(stdout);
    }

    char *buffer = NULL;
    size_t capacity = 0;
    size_t size = 0;
    int c;

    while ((c = fgetc(stdin)) != '\n' && c != EOF)
    {
        if (size + 1 > capacity)
        {
            size_t new_capacity = (capacity == 0) ? 16 : capacity + (capacity / 2);
            if (new_capacity < size + 1) new_capacity = size + 1;

            char *temp = realloc(buffer, new_capacity);
            if (temp == NULL)
            {
                free(buffer);
                return NULL;
            }
            buffer = temp;
            capacity = new_capacity;
        }
        buffer[size++] = (char) c;
    }

    if (size == 0 && c == EOF)
    {
        free(buffer);
        return NULL;
    }

    char *final_buffer = realloc(buffer, size + 1);
    if (final_buffer == NULL && size > 0) {
         buffer[size] = '\0';
         return buffer;
    } else if (final_buffer == NULL && size == 0) {
        free(buffer);
        return NULL;
    }

    final_buffer[size] = '\0';
    return final_buffer;
}


char get_char(const char *prompt)
{
    while (1)
    {
        string line = get_string(prompt);
        if (line == NULL)
        {
             if (prompt == NULL) prompt = "Retry: ";
             fprintf(stderr, "\nInput error or EOF. Please try again.\n");
             continue;
        }

        if (line[0] != '\0' && line[1] == '\0')
        {
            char c = line[0];
            free(line);
            return c;
        }

        free(line);
        if (prompt == NULL)
        {
            prompt = "Retry: ";
        }
         printf("Invalid input. Please enter exactly one character.\n");
    }
}


int get_int(const char *prompt)
{
    while (1)
    {
        string line = get_string(prompt);
        if (line == NULL) {
             if (prompt == NULL) prompt = "Retry: ";
             fprintf(stderr, "\nInput error or EOF. Please try again.\n");
             continue;
        }

        if (line[0] == '\0')
        {
            free(line);
            if (prompt == NULL) prompt = "Retry: ";
            printf("Invalid input. Please enter an integer.\n");
            continue;
        }

        char *endptr;
        errno = 0;
        long n = strtol(line, &endptr, 10);

        if (errno == ERANGE)
        {
            free(line);
            if (prompt == NULL) prompt = "Retry: ";
            printf("Input out of range. Please enter a valid integer.\n");
            continue;
        }
         if (endptr == line)
        {
            free(line);
            if (prompt == NULL) prompt = "Retry: ";
             printf("Invalid input. Please enter an integer.\n");
             continue;
        }

        char *check_ptr = endptr;
        while (isspace((unsigned char)*check_ptr))
        {
            check_ptr++;
        }

        if (*check_ptr != '\0')
        {
            free(line);
            if (prompt == NULL) prompt = "Retry: ";
            printf("Invalid input. Please enter only an integer.\n");
            continue;
        }

        if (n < INT_MIN || n > INT_MAX)
        {
             free(line);
             if (prompt == NULL) prompt = "Retry: ";
             printf("Input out of range for standard integer. Please enter a smaller value.\n");
             continue;
        }

        free(line);
        return (int) n;
    }
}


long get_long(const char *prompt)
{
    while (1)
    {
        string line = get_string(prompt);
         if (line == NULL) {
             if (prompt == NULL) prompt = "Retry: ";
             fprintf(stderr, "\nInput error or EOF. Please try again.\n");
             continue;
        }

        if (line[0] == '\0') {
            free(line);
            if (prompt == NULL) prompt = "Retry: ";
            printf("Invalid input. Please enter a long integer.\n");
            continue;
        }

        char *endptr;
        errno = 0;
        long n = strtol(line, &endptr, 10);

        if (errno == ERANGE) {
            free(line);
            if (prompt == NULL) prompt = "Retry: ";
            printf("Input out of range. Please enter a valid long integer.\n");
            continue;
        }
        if (endptr == line) {
            free(line);
            if (prompt == NULL) prompt = "Retry: ";
             printf("Invalid input. Please enter a long integer.\n");
             continue;
        }


        char *check_ptr = endptr;
        while (isspace((unsigned char)*check_ptr)) {
            check_ptr++;
        }

        if (*check_ptr != '\0') {
             free(line);
             if (prompt == NULL) prompt = "Retry: ";
             printf("Invalid input. Please enter only a long integer.\n");
             continue;
        }

        free(line);
        return n;
    }
}


float get_float(const char *prompt)
{
    while (1)
    {
        string line = get_string(prompt);
        if (line == NULL) {
             if (prompt == NULL) prompt = "Retry: ";
             fprintf(stderr, "\nInput error or EOF. Please try again.\n");
             continue;
        }

        if (line[0] == '\0') {
            free(line);
            if (prompt == NULL) prompt = "Retry: ";
             printf("Invalid input. Please enter a floating-point number.\n");
            continue;
        }

        char *endptr;
        errno = 0;
        float f = strtof(line, &endptr);

        if (errno == ERANGE) {
            free(line);
            if (prompt == NULL) prompt = "Retry: ";
            printf("Input out of range. Please enter a valid floating-point number.\n");
            continue;
        }
         if (endptr == line) {
            free(line);
            if (prompt == NULL) prompt = "Retry: ";
             printf("Invalid input. Please enter a floating-point number.\n");
             continue;
        }

        char *check_ptr = endptr;
        while (isspace((unsigned char)*check_ptr)) {
            check_ptr++;
        }

        if (*check_ptr != '\0') {
             free(line);
             if (prompt == NULL) prompt = "Retry: ";
             printf("Invalid input. Please enter only a floating-point number.\n");
             continue;
        }

        free(line);
        return f;
    }
}


double get_double(const char *prompt)
{
     while (1)
    {
        string line = get_string(prompt);
        if (line == NULL) {
             if (prompt == NULL) prompt = "Retry: ";
             fprintf(stderr, "\nInput error or EOF. Please try again.\n");
             continue;
        }

        if (line[0] == '\0') {
            free(line);
            if (prompt == NULL) prompt = "Retry: ";
            printf("Invalid input. Please enter a double-precision number.\n");
            continue;
        }

        char *endptr;
        errno = 0;
        double d = strtod(line, &endptr);

        if (errno == ERANGE) {
            free(line);
            if (prompt == NULL) prompt = "Retry: ";
            printf("Input out of range. Please enter a valid double-precision number.\n");
            continue;
        }
         if (endptr == line) {
            free(line);
            if (prompt == NULL) prompt = "Retry: ";
            printf("Invalid input. Please enter a double-precision number.\n");
             continue;
        }

        char *check_ptr = endptr;
        while (isspace((unsigned char)*check_ptr)) {
            check_ptr++;
        }

         if (*check_ptr != '\0') {
             free(line);
             if (prompt == NULL) prompt = "Retry: ";
             printf("Invalid input. Please enter only a double-precision number.\n");
             continue;
        }

        free(line);
        return d;
    }
}


bool array_max(const int *arr, size_t size, int *max_val) {
    if (arr == NULL || size == 0 || max_val == NULL) {
        return false;
    }

    *max_val = arr[0];
    for (size_t i = 1; i < size; ++i) {
        if (arr[i] > *max_val) {
            *max_val = arr[i];
        }
    }
    return true;
}


bool array_min(const int *arr, size_t size, int *min_val) {
    if (arr == NULL || size == 0 || min_val == NULL) {
        return false;
    }

    *min_val = arr[0];
    for (size_t i = 1; i < size; ++i) {
        if (arr[i] < *min_val) {
            *min_val = arr[i];
        }
    }
    return true;
}


bool array_sum(const int *arr, size_t size, long long *sum) {
    if (sum == NULL) {
        return false;
    }
    if (arr == NULL && size > 0) {
        *sum = 0;
        return false;
    }

    *sum = 0;
    for (size_t i = 0; i < size; ++i) {
        *sum += arr[i];
    }
    return true;
}


typedef struct HashNode {
    int key;
    int count;
    struct HashNode *next;
} HashNode;

typedef struct HashTable {
    HashNode **buckets;
    size_t table_size;
} HashTable;


static size_t hash_func(int key, size_t table_size) {
    return (size_t)llabs((long long)key) % table_size;
}


static HashTable* ht_create(size_t initial_size) {
    if (initial_size == 0) initial_size = 1;

    HashTable *ht = malloc(sizeof(HashTable));
    if (!ht) return NULL;

    ht->buckets = calloc(initial_size, sizeof(HashNode*));
    if (!ht->buckets) {
        free(ht);
        return NULL;
    }
    ht->table_size = initial_size;
    return ht;
}


static void ht_destroy(HashTable *ht) {
    if (!ht) return;
    for (size_t i = 0; i < ht->table_size; ++i) {
        HashNode *current = ht->buckets[i];
        while (current) {
            HashNode *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(ht->buckets);
    free(ht);
}


static HashNode* ht_search(HashTable *ht, int key) {
    if (!ht) return NULL;
    size_t index = hash_func(key, ht->table_size);
    HashNode *current = ht->buckets[index];
    while (current) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}


static bool ht_insert(HashTable *ht, int key) {
     if (!ht) return false;
    size_t index = hash_func(key, ht->table_size);
    HashNode *current = ht->buckets[index];

    while (current) {
        if (current->key == key) {
            current->count++;
            return true;
        }
        current = current->next;
    }

    HashNode *new_node = malloc(sizeof(HashNode));
    if (!new_node) return false;

    new_node->key = key;
    new_node->count = 1;
    new_node->next = ht->buckets[index];
    ht->buckets[index] = new_node;
    return true;
}



bool array_has_pair_sum(const int *arr, size_t size, int target) {
    if (arr == NULL || size < 2) {
        return false;
    }

    HashTable *ht = ht_create(size);
    if (!ht) {
        return false;
    }

    bool found = false;
    for (size_t i = 0; i < size; ++i) {
        long long complement_ll = (long long)target - arr[i];
        if (complement_ll < INT_MIN || complement_ll > INT_MAX) {
             continue;
        }
        int complement = (int)complement_ll;

        HashNode* existing = ht_search(ht, complement);
        if (existing) {
            if (complement == arr[i]) {
                 if (existing->count >= 1) {
                    found = true;
                    break;
                 }
            } else {
                 found = true;
                 break;
            }
        }
        if (!ht_insert(ht, arr[i])) {
             found = false;
             break;
        }
    }

    ht_destroy(ht);
    return found;
}


bool array_has_pair_product(const int *arr, size_t size, int target) {
    if (arr == NULL || size < 2) {
        return false;
    }

    HashTable *ht = ht_create(size);
    if (!ht) return false;

    bool found = false;
    size_t zero_count = 0;

    for (size_t i = 0; i < size; ++i) {
        if (arr[i] == 0) {
            zero_count++;
        } else {
            if (!ht_insert(ht, arr[i])) {
                ht_destroy(ht);
                return false;
            }
        }
    }

    if (target == 0) {
        size_t non_zero_elements = 0;
        for(size_t i = 0; i < ht->table_size; ++i) {
            if (ht->buckets[i] != NULL) {
                non_zero_elements++;
                break; // Found at least one non-zero
            }
        }
        if (zero_count > 0 && non_zero_elements > 0) {
             found = true;
        } else if (zero_count > 1) {
             found = true;
        }
    } else {
        for (size_t i = 0; i < size; ++i) {
             int current_val = arr[i];
             if (current_val == 0) continue;

             if (target % current_val == 0) {
                 int needed = target / current_val;
                 HashNode *existing = ht_search(ht, needed);

                 if (existing) {
                     if (needed == current_val) {
                         if (existing->count > 1) {
                             found = true;
                             break;
                         }
                     } else {
                         found = true;
                         break;
                     }
                 }
             }
        }
    }

    ht_destroy(ht);
    return found;
}


bool array_has_pair_difference(const int *arr, size_t size, int target) {
     if (arr == NULL) {
         return false;
     }

    HashTable *ht = ht_create(size);
    if (!ht) return false;

    bool found = false;
    for (size_t i = 0; i < size; ++i) {

        long long needed1_ll = (long long)arr[i] - target;
        long long needed2_ll = (long long)arr[i] + target;

        bool check1 = (needed1_ll >= INT_MIN && needed1_ll <= INT_MAX);
        bool check2 = (needed2_ll >= INT_MIN && needed2_ll <= INT_MAX);

        if (check1) {
             HashNode* node1 = ht_search(ht, (int)needed1_ll);
             if (node1) {
                  // Special case: if target is 0, arr[i] - target = arr[i].
                  // We need > 1 count *if* we are looking for arr[i] itself.
                  if (target == 0) {
                      if (node1->count >= 1) { // >=1 because ht_insert hasn't happened yet for arr[i]
                           found = true;
                           break;
                      }
                  } else {
                      found = true; // Found arr[i] - target
                      break;
                  }
             }
        }

        if (target != 0 && check2) {
             if (ht_search(ht, (int)needed2_ll)) {
                 found = true; // Found arr[i] + target (which means (arr[i]+target) - arr[i] = target)
                 break;
             }
        }


         if (!ht_insert(ht, arr[i])) {
              found = false;
              break;
         }
    }

    ht_destroy(ht);
    return found;
}
