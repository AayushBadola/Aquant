#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <errno.h>

#include "aquant.h"

// Local helper function prototype if needed (none needed for this basic version)

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
                return NULL; // Allocation error
            }
            buffer = temp;
            capacity = new_capacity;
        }
        buffer[size++] = (char) c;
    }

    // Handle case where only EOF was read or input stream error
    if (size == 0 && c == EOF)
    {
        return NULL;
    }

    // Null-terminate the string
    if (size + 1 > capacity)
    {
        char *temp = realloc(buffer, size + 1);
        if (temp == NULL)
        {
            free(buffer);
            return NULL; // Allocation error
        }
        buffer = temp;
        capacity = size + 1;
    }
    buffer[size] = '\0';

    // Trim buffer to actual size (optional, good practice)
    char *final_buffer = realloc(buffer, size + 1);
    if (final_buffer == NULL)
    {
        // If trimming fails, return the slightly larger buffer
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
             // Handle EOF or allocation error in get_string
             // CS50 library might loop, exit, or return a specific value.
             // Looping seems most consistent with re-prompting behavior.
             // If you need a specific EOF indicator, return CHAR_MAX or similar.
             // For simplicity here, we treat it like invalid input (retry)
             // but print an indicator for clarity during debugging.
             // printf("EOF or error encountered in get_string.\n"); // TEMP/DEBUG
             // If you must return on EOF, use something like: return CHAR_MAX;
             continue; // Retry prompt
        }

        if (line[0] != '\0' && line[1] == '\0')
        {
            char c = line[0];
            free(line);
            return c;
        }

        free(line);
        // Re-prompt handled by loop
        if (prompt == NULL)
        {
             // Avoid printing the same default reprompt message if no custom prompt was given.
             prompt = "Retry: "; // Provide a default retry prompt if none exists
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
             // Handle EOF or allocation error similar to get_char
             // printf("EOF or error encountered in get_string.\n"); // TEMP/DEBUG
             // If you must return on EOF, use something like: return INT_MAX;
             continue; // Retry prompt
        }

        if (line[0] == '\0') // Handle empty input line
        {
            free(line);
            if (prompt == NULL) prompt = "Retry: ";
            continue;
        }

        char *endptr;
        errno = 0; // Reset errno before call
        long n = strtol(line, &endptr, 10);

        // Check for conversion errors
        if (errno == ERANGE) // Out of range for long
        {
            free(line);
            if (prompt == NULL) prompt = "Retry: ";
            continue;
        }

        // Check if the entire string was consumed (allowing trailing whitespace)
        char *check_ptr = endptr;
        while (isspace((unsigned char)*check_ptr))
        {
            check_ptr++;
        }

        if (*line != '\0' && *check_ptr == '\0') // Valid conversion, nothing left but whitespace
        {
             // Check if the long value fits in an int
             if (n >= INT_MIN && n <= INT_MAX)
             {
                 free(line);
                 return (int) n;
             }
        }

        // If not valid integer input or out of int range
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
             // Handle EOF or allocation error similar to get_char
             // printf("EOF or error encountered in get_string.\n"); // TEMP/DEBUG
             // If you must return on EOF, use something like: return LONG_MAX;
             continue; // Retry prompt
        }

        if (line[0] == '\0') // Handle empty input line
        {
            free(line);
            if (prompt == NULL) prompt = "Retry: ";
            continue;
        }


        char *endptr;
        errno = 0; // Reset errno
        long n = strtol(line, &endptr, 10);

        // Check for conversion errors
        if (errno == ERANGE) // Out of range for long
        {
            free(line);
            if (prompt == NULL) prompt = "Retry: ";
            continue;
        }

        // Check if the entire string was consumed (allowing trailing whitespace)
        char *check_ptr = endptr;
        while (isspace((unsigned char)*check_ptr))
        {
            check_ptr++;
        }

        if (*line != '\0' && *check_ptr == '\0') // Valid conversion
        {
            free(line);
            return n;
        }

        // If not valid long input
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
             // Handle EOF or allocation error similar to get_char
             // printf("EOF or error encountered in get_string.\n"); // TEMP/DEBUG
             // If you must return on EOF, use something like: return FLT_MAX;
             continue; // Retry prompt
        }

        if (line[0] == '\0') // Handle empty input line
        {
            free(line);
            if (prompt == NULL) prompt = "Retry: ";
            continue;
        }

        char *endptr;
        errno = 0; // Reset errno
        float f = strtof(line, &endptr);

        // Check for conversion errors (range errors for float are less common to check strictly like int/long)
        // strtof returns HUGE_VALF on overflow, 0 on underflow. We can check errno.
         if (errno == ERANGE)
         {
             free(line);
             if (prompt == NULL) prompt = "Retry: ";
             continue;
         }

        // Check if the entire string was consumed (allowing trailing whitespace)
        char *check_ptr = endptr;
        while (isspace((unsigned char)*check_ptr))
        {
            check_ptr++;
        }

        if (*line != '\0' && *check_ptr == '\0') // Valid conversion
        {
            free(line);
            return f;
        }

        // If not valid float input
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
             // Handle EOF or allocation error similar to get_char
             // printf("EOF or error encountered in get_string.\n"); // TEMP/DEBUG
             // If you must return on EOF, use something like: return DBL_MAX;
             continue; // Retry prompt
        }

        if (line[0] == '\0') // Handle empty input line
        {
            free(line);
            if (prompt == NULL) prompt = "Retry: ";
            continue;
        }


        char *endptr;
        errno = 0; // Reset errno
        double d = strtod(line, &endptr);

        // Check for conversion errors (range errors for double)
        // strtod returns HUGE_VAL on overflow, 0 on underflow. We can check errno.
         if (errno == ERANGE)
         {
             free(line);
             if (prompt == NULL) prompt = "Retry: ";
             continue;
         }


        // Check if the entire string was consumed (allowing trailing whitespace)
        char *check_ptr = endptr;
        while (isspace((unsigned char)*check_ptr))
        {
            check_ptr++;
        }

        if (*line != '\0' && *check_ptr == '\0') // Valid conversion
        {
            free(line);
            return d;
        }

        // If not valid double input
        free(line);
        if (prompt == NULL) prompt = "Retry: ";
    }
}
