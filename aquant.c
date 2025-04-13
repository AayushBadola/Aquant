#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <errno.h>

#include "aquant.h"

string get_string(const char *prompt)
{
    if (prompt != NULL)
    {
        printf("%s", prompt);
    }

    char *buffer = NULL;
    size_t capacity = 0;
    size_t size = 0;
    int c;

    while ((c = fgetc(stdin)) != '\n' && c != EOF)
    {
        if (size + 1 > capacity)
        {
            size_t new_capacity = (capacity == 0) ? 16 : capacity * 2;
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
        return NULL;
    }

    if (size + 1 > capacity)
    {
        char *temp = realloc(buffer, size + 1);
        if (temp == NULL)
        {
            free(buffer);
            return NULL;
        }
        buffer = temp;
        capacity = size + 1;
    }
    buffer[size] = '\0';

    char *final_buffer = realloc(buffer, size + 1);
    if (final_buffer == NULL)
    {
        return buffer;
    }

    return final_buffer;
}

char get_char(const char *prompt)
{
    while (1)
    {
        string line = get_string(prompt);
        if (line == NULL)
        {
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
    }
}

int get_int(const char *prompt)
{
    while (1)
    {
        string line = get_string(prompt);
        if (line == NULL)
        {
            continue;
        }

        if (line[0] == '\0')
        {
            free(line);
            if (prompt == NULL) prompt = "Retry: ";
            continue;
        }

        char *endptr;
        errno = 0;
        long n = strtol(line, &endptr, 10);

        if (errno == ERANGE)
        {
            free(line);
            if (prompt == NULL) prompt = "Retry: ";
            continue;
        }

        char *check_ptr = endptr;
        while (isspace((unsigned char)*check_ptr))
        {
            check_ptr++;
        }

        if (*line != '\0' && *check_ptr == '\0')
        {
            if (n >= INT_MIN && n <= INT_MAX)
            {
                free(line);
                return (int) n;
            }
        }

        free(line);
        if (prompt == NULL) prompt = "Retry: ";
    }
}

long get_long(const char *prompt)
{
    while (1)
    {
        string line = get_string(prompt);
        if (line == NULL)
        {
            continue;
        }

        if (line[0] == '\0')
        {
            free(line);
            if (prompt == NULL) prompt = "Retry: ";
            continue;
        }

        char *endptr;
        errno = 0;
        long n = strtol(line, &endptr, 10);

        if (errno == ERANGE)
        {
            free(line);
            if (prompt == NULL) prompt = "Retry: ";
            continue;
        }

        char *check_ptr = endptr;
        while (isspace((unsigned char)*check_ptr))
        {
            check_ptr++;
        }

        if (*line != '\0' && *check_ptr == '\0')
        {
            free(line);
            return n;
        }

        free(line);
        if (prompt == NULL) prompt = "Retry: ";
    }
}

float get_float(const char *prompt)
{
    while (1)
    {
        string line = get_string(prompt);
        if (line == NULL)
        {
            continue;
        }

        if (line[0] == '\0')
        {
            free(line);
            if (prompt == NULL) prompt = "Retry: ";
            continue;
        }

        char *endptr;
        errno = 0;
        float f = strtof(line, &endptr);

        if (errno == ERANGE)
        {
            free(line);
            if (prompt == NULL) prompt = "Retry: ";
            continue;
        }

        char *check_ptr = endptr;
        while (isspace((unsigned char)*check_ptr))
        {
            check_ptr++;
        }

        if (*line != '\0' && *check_ptr == '\0')
        {
            free(line);
            return f;
        }

        free(line);
        if (prompt == NULL) prompt = "Retry: ";
    }
}

double get_double(const char *prompt)
{
    while (1)
    {
        string line = get_string(prompt);
        if (line == NULL)
        {
            continue;
        }

        if (line[0] == '\0')
        {
            free(line);
            if (prompt == NULL) prompt = "Retry: ";
            continue;
        }

        char *endptr;
        errno = 0;
        double d = strtod(line, &endptr);

        if (errno == ERANGE)
        {
            free(line);
            if (prompt == NULL) prompt = "Retry: ";
            continue;
        }

        char *check_ptr = endptr;
        while (isspace((unsigned char)*check_ptr))
        {
            check_ptr++;
        }

        if (*line != '\0' && *check_ptr == '\0')
        {
            free(line);
            return d;
        }

        free(line);
        if (prompt == NULL) prompt = "Retry: ";
    }
}
