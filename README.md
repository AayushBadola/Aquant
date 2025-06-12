


<div align="center">

# Aquant

### A Robust C Library for User Input, Array Utilities, and String Manipulation

<br>

<img src="https://img.shields.io/badge/Author-Aayush%20Badola-blue?style=for-the-badge&logo=github" alt="Author Badge"/>

<br>

<kbd><b><span style="color:#27ae60">Current Version 1.3.0</span></b></kbd>
<br>
<kbd><b><span style="color:#FF474C">previous Version 1.2.0</span></b></kbd>
<br>

![Language](https://img.shields.io/badge/language-C-green.svg)
![Platform](https://img.shields.io/badge/platform-Cross--Platform-lightgrey.svg)
![License](https://img.shields.io/badge/license-MIT-orange.svg)
![Status](https://img.shields.io/badge/status-Active-brightgreen.svg)

<br>

<div align="center">
  <a href="https://github.com/AayushBadola">
    <img src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white" alt="GitHub"/>
  </a>
  <a href="https://www.linkedin.com/in/aayush-badola-0a7b2b343">
    <img src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white" alt="LinkedIn"/>
  </a>
  <a href="https://mail.google.com/mail/?view=cm&fs=1&to=aayush.badola2@gmail.com" target="_blank">
    <img src="https://img.shields.io/badge/Email-D14836?style=for-the-badge&logo=gmail&logoColor=white" alt="Email"/>
  </a>
</div>

</div>

---

<div align="center">

### "Simplify C- Language"

</div>

## 📖 Overview

Aquant is a lightweight yet powerful C library designed to simplify and standardize common programming tasks. It began by focusing on robust user input in console applications but has expanded significantly to include a comprehensive suite of utility functions for manipulating arrays (integer, float, double, string) and performing common string operations.

Developed with a focus on robustness, ease of use, and safe memory handling, Aquant abstracts away the complexity and potential pitfalls of traditional C methods, offering intuitive functions that promote reliable interaction and data processing.

### Note - Aquant has been updated significantly. Please ensure you are using the latest `aquant.h` and `aquant.c` files.
<br>
<div align="center">

```
📋 Ideal for educational environments, command-line tools, data processing utilities,
and any C application requiring secure input, array operations, or string handling.
```
### Note - While compiling if you get some errors related to array please ignore it its done so the finding speed for sort and other functions are fast just start coding dont panic 


</div>

## ✨ Features

<table>
  <tr>
    <td>✅ <b>Memory-Safe String Handling</b></td>
    <td>Dynamic allocation for input and string creation to prevent buffer overflows</td>
  </tr>
  <tr>
    <td>✅ <b>Comprehensive Input Validation</b></td>
    <td>Automatic type checking, range checking, and error handling for input</td>
  </tr>
  <tr>
    <td>✅ <b>Type-Specific Input Functions</b></td>
    <td>Specialized functions for strings, characters, integers, floats, doubles</td>
  </tr>
    <tr>
    <td>✅ <b>Intelligent Retry Mechanism</b></td>
    <td>Automatic prompting for retries on invalid input</td>
  </tr>
  <tr>
    <td>✅ <b>Extensive Array Utilities</b></td>
    <td>Functions for searching, sorting, aggregation (min, max, sum, avg), copying, reversing, shuffling, concatenating, finding unique elements for int, float, double, and string arrays</td>
  </tr>
  <tr>
    <td>✅ <b>Rich String Manipulation</b></td>
    <td>Functions for copying, comparing, trimming, splitting, joining, case conversion, searching, replacing, substring extraction, type checking, and conversion</td>
  </tr>
   <tr>
    <td>✅ <b>Helper Functions</b></td>
    <td>Memory management for strings/arrays allocated by Aquant, random number generation, basic timing</td>
  </tr>
  <tr>
    <td>✅ <b>Clean API Design</b></td>
    <td>Consistent function signatures and behavior across the library</td>
  </tr>
  <tr>
    <td>✅ <b>Minimal Dependencies</b></td>
    <td>Uses only standard C libraries for maximum compatibility</td>
  </tr>
  <tr>
    <td>✅ <b>Cross-Platform Compatibility</b></td>
    <td>Works on any system with a standard C compiler</td>
  </tr>
</table>

## 🚀 Installation


The simplest way to use Aquant in your project is to include the source files directly:

1.  Download both `aquant.c` and `aquant.h` from this repository.
2.  Place them in your project directory.
3.  Include the header in your source files:

```bash
git clone https://github.com/AayushBadola/Aquant.git
```

```bash
cd Aquant
```

```c
#include "aquant.h"
```

4.  Compile your program linking both your code and `aquant.c`:

```bash
gcc your_program.c aquant.c -o your_program -lm
```

5.  Run your program:

```bash
./your_program
```

### **Bonus**

For running the provided `test.c` file compile both `test.c` and  `aquant.c` like this:

```bash
gcc test.c aquant.c -o test -lm
```

For running the `test.c`

```bash
./test
```

<div align="center">

## 💡 Usage Examples (General)

</div>

*(See the API Reference section below for examples specific to each function.)*

### Basic Input

```c
#include <stdio.h>
#include "aquant.h"
#include <stdlib.h> // For free()

int main(void) {
    // Safe string input (remember to free)
    string name = get_string("Enter your name: ");
    if (name) {
        printf("Hello, %s!\n", name);
        free_string(name); // Use aquant's free helper
    }

    // Validated integer input
    int age = get_int("Enter your age: ");
    printf("You are %d years old.\n", age);

    // Integer within a range
    int score = get_int_range("Enter score (0-100): ", 0, 100);
    printf("Score: %d\n", score);

    // Character input
    char confirm = get_char("Proceed? (y/n): ");
    if (confirm == 'y' || confirm == 'Y') {
        printf("Proceeding...\n");
    } else {
        printf("Cancelled.\n");
    }

    // Float input
    float price = get_float("Enter price: ");
    printf("Price: %.2f\n", price);

    return 0;
}
```

### Integer Array Operations

```c
#include <stdio.h>
#include "aquant.h"
#include <stdlib.h> // For free

int main(void) {
    int numbers[] = {5, -2, 8, 1, 5, 9, 0};
    size_t size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Original Array: ");
    print_array(numbers, size); // Output: [5, -2, 8, 1, 5, 9, 0]

    sort_array(numbers, size);
    printf("Sorted Array: ");
    print_array(numbers, size); // Output: [-2, 0, 1, 5, 5, 8, 9]

    int max_val;
    if (array_max(numbers, size, &max_val)) {
        printf("Max value: %d\n", max_val); // Output: 9
    }

    long long sum;
    if (array_sum(numbers, size, &sum)) {
        printf("Sum: %lld\n", sum); // Output: 26
    }

    printf("Average: %f\n", array_average(numbers, size)); // Output: 3.714...

    if (array_contains_int(numbers, size, 8)) {
        printf("Array contains 8.\n"); // Output: Array contains 8.
    }

    printf("Index of 1: %d\n", array_index_of_int(numbers, size, 1)); // Output: 2

    printf("Occurrences of 5: %zu\n", array_count_occurrence(numbers, size, 5)); // Output: 2

    array_reverse_int(numbers, size);
    printf("Reversed Sorted Array: ");
    print_array(numbers, size); // Output: [9, 8, 5, 5, 1, 0, -2]

    // Shuffling needs random seed (call once at start)
    initialize_random();
    array_shuffle_int(numbers, size);
    printf("Shuffled Array: ");
    print_array(numbers, size); // Output: (random order)

    size_t unique_size;
    int* unique_arr = array_unique_int(numbers, size, &unique_size);
    if (unique_arr) {
        printf("Unique Elements: ");
        print_array(unique_arr, unique_size); // Output: (unique elements in some order)
        free(unique_arr); // IMPORTANT: Free the result
    }

    return 0;
}
```

### String Manipulation

```c
#include <stdio.h>
#include "aquant.h"
#include <stdlib.h> // For free

int main(void) {
    string greeting = string_copy("   Hello, World!   "); // Remember to free
    string trimmed = string_trim(greeting); // Remember to free
    printf("Original: '%s'\n", greeting);
    printf("Trimmed: '%s'\n", trimmed); // Output: 'Hello, World!'

    if (string_starts_with(trimmed, "Hello")) {
        printf("Starts with Hello.\n");
    }
    if (string_ends_with(trimmed, "World!")) {
        printf("Ends with World!.\n");
    }

    string upper = string_to_upper(trimmed); // Remember to free
    printf("Upper: %s\n", upper); // Output: HELLO, WORLD!

    string lower = string_to_lower(upper); // Remember to free
    printf("Lower: %s\n", lower); // Output: hello, world!

    size_t num_parts;
    string* parts = string_split(trimmed, ',', &num_parts); // Remember to free array/strings
    if (parts) {
        printf("Split parts (%zu):\n", num_parts);
        print_string_array(parts, num_parts); // Output: ["Hello", " World!"]
        free_string_array(parts, num_parts); // Use aquant's helper
    }

    string joined = string_join((const string[]){"Aquant", "is", "cool"}, 3, " "); // Remember to free
    printf("Joined: %s\n", joined); // Output: Aquant is cool

    free_string(greeting);
    free_string(trimmed);
    free_string(upper);
    free_string(lower);
    free_string(joined);

    return 0;
}
```

<div align="center">

## 📚 API Reference

</div>

### Type Definitions

```c
// Type definition for dynamically allocated strings
typedef char *string;

// Epsilon values for float/double comparisons (used internally)
#define FLOAT_EPSILON 1e-6f
#define DOUBLE_EPSILON 1e-9
```

### Input Functions

---

#### `string get_string(const char *prompt)`

Reads a line of text from standard input with dynamic memory allocation.

-   **Parameters**:
    -   `prompt`: `const char*` - Text to display before reading input (can be `NULL`).
-   **Returns**:
    -   `string` (dynamically allocated `char*`) containing the input line (excluding newline). **Caller must `free()` or `free_string()` the result.**
    -   An empty string `""` if the user just presses Enter.
    -   `NULL` if memory allocation fails or EOF is encountered immediately. May return partially read string if `realloc` fails mid-read.
-   **Behavior**:
    -   Handles input of arbitrary length.
    -   Dynamically resizes internal buffer as needed.
    -   Trims buffer to exact size.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"
    #include <stdlib.h> // For free_string

    int main(void) {
        string name = get_string("Enter name: ");
        if (name) {
            printf("Hello, %s!\n", name);
            free_string(name);
        } else {
            printf("Input failed.\n");
        }
        return 0;
    }
    ```

---

#### `char get_char(const char *prompt)`

Reads a single character from standard input, ensuring only one character is entered.

-   **Parameters**:
    -   `prompt`: `const char*` - Text to display before reading input (can be `NULL`).
-   **Returns**:
    -   `char` - The single character entered by the user.
-   **Behavior**:
    -   Uses `get_string` internally.
    -   Reprompts the user with "Retry: " if input is empty or contains more than one character.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        char choice = get_char("Choose (A/B/C): ");
        printf("You chose: %c\n", choice);
        return 0;
    }
    ```

---

#### `int get_int(const char *prompt)`

Reads an integer from standard input with validation.

-   **Parameters**:
    -   `prompt`: `const char*` - Text to display before reading input (can be `NULL`).
-   **Returns**:
    -   `int` - The valid integer entered by the user.
-   **Behavior**:
    -   Uses `get_string` internally.
    -   Uses `strtol` for robust parsing.
    -   Checks for valid integer format, overflow/underflow (`INT_MIN`/`INT_MAX`), and trailing non-whitespace characters.
    -   Reprompts on invalid input.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        int age = get_int("Enter your age: ");
        printf("Your age: %d\n", age);
        return 0;
    }
    ```

---

#### `long get_long(const char *prompt)`

Reads a long integer from standard input with validation.

-   **Parameters**:
    -   `prompt`: `const char*` - Text to display before reading input (can be `NULL`).
-   **Returns**:
    -   `long` - The valid long integer entered by the user.
-   **Behavior**:
    -   Similar to `get_int` but uses `strtol` and checks against `LONG_MIN`/`LONG_MAX`.
    -   Reprompts on invalid input.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        long population = get_long("Enter city population: ");
        printf("Population: %ld\n", population);
        return 0;
    }
    ```

---

#### `float get_float(const char *prompt)`

Reads a floating-point number from standard input with validation.

-   **Parameters**:
    -   `prompt`: `const char*` - Text to display before reading input (can be `NULL`).
-   **Returns**:
    -   `float` - The valid float entered by the user.
-   **Behavior**:
    -   Uses `get_string` internally.
    -   Uses `strtof` for robust parsing.
    -   Checks for valid float format, overflow/underflow, and trailing non-whitespace characters.
    -   Reprompts on invalid input.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        float price = get_float("Enter item price: $");
        printf("Price: $%.2f\n", price);
        return 0;
    }
    ```

---

#### `double get_double(const char *prompt)`

Reads a double-precision floating-point number from standard input with validation.

-   **Parameters**:
    -   `prompt`: `const char*` - Text to display before reading input (can be `NULL`).
-   **Returns**:
    -   `double` - The valid double entered by the user.
-   **Behavior**:
    -   Similar to `get_float` but uses `strtod`.
    -   Reprompts on invalid input.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        double measurement = get_double("Enter measurement (cm): ");
        printf("Measurement: %.4f cm\n", measurement);
        return 0;
    }
    ```

---

#### `int get_int_range(const char *prompt, int min, int max)`

Reads an integer from standard input, ensuring it falls within a specified range (inclusive).

-   **Parameters**:
    -   `prompt`: `const char*` - Text to display before reading input.
    -   `min`: `int` - The minimum allowed value.
    -   `max`: `int` - The maximum allowed value.
-   **Returns**:
    -   `int` - A valid integer within the range `[min, max]`.
-   **Behavior**:
    -   Uses `get_int` internally.
    -   Reprompts if the entered integer is outside the specified range.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        int rating = get_int_range("Rate service (1-5): ", 1, 5);
        printf("Your rating: %d\n", rating); // Will be between 1 and 5
        return 0;
    }
    ```

---

#### `string get_string_non_empty(const char *prompt)`

Reads a line of text, ensuring it is not empty.

-   **Parameters**:
    -   `prompt`: `const char*` - Text to display before reading input.
-   **Returns**:
    -   `string` - A dynamically allocated, non-empty string. **Caller must `free()` or `free_string()`**.
    -   `NULL` on memory allocation failure or immediate EOF.
-   **Behavior**:
    -   Uses `get_string` internally.
    -   Reprompts if the user enters an empty line.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"
    #include <stdlib.h> // For free_string

    int main(void) {
        string filename = get_string_non_empty("Enter required filename: ");
        if (filename) {
            printf("Using filename: %s\n", filename);
            // ... process filename ...
            free_string(filename);
        } else {
            printf("Input failed.\n");
        }
        return 0;
    }
    ```

---

### Integer Array Functions

---

#### `bool array_max(const int *arr, size_t size, int *max_val)`

Finds the maximum value in an integer array.

-   **Parameters**:
    -   `arr`: `const int*` - Pointer to the array.
    -   `size`: `size_t` - Number of elements.
    -   `max_val`: `int*` - Pointer to store the result.
-   **Returns**:
    -   `true` if successful (array not `NULL`, `size > 0`, `max_val` not `NULL`).
    -   `false` otherwise.
-   **Behavior**: Stores the maximum value in `*max_val`.
-   **Complexity**: O(n) time, O(1) space.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        int data[] = {3, 1, 4, 1, 5, 9, 2, 6};
        size_t n = sizeof(data)/sizeof(data[0]);
        int max_v;
        if (array_max(data, n, &max_v)) {
            printf("Maximum value: %d\n", max_v); // Output: 9
        } else {
            printf("Could not find maximum.\n");
        }
        return 0;
    }
    ```

---

#### `bool array_min(const int *arr, size_t size, int *min_val)`

Finds the minimum value in an integer array.

-   **Parameters**:
    -   `arr`: `const int*` - Pointer to the array.
    -   `size`: `size_t` - Number of elements.
    -   `min_val`: `int*` - Pointer to store the result.
-   **Returns**:
    -   `true` if successful.
    -   `false` otherwise.
-   **Behavior**: Stores the minimum value in `*min_val`.
-   **Complexity**: O(n) time, O(1) space.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        int data[] = {3, 1, 4, -5, 9, 2, 6};
        size_t n = sizeof(data)/sizeof(data[0]);
        int min_v;
        if (array_min(data, n, &min_v)) {
            printf("Minimum value: %d\n", min_v); // Output: -5
        } else {
            printf("Could not find minimum.\n");
        }
        return 0;
    }
    ```

---

#### `bool array_sum(const int *arr, size_t size, long long *sum)`

Calculates the sum of elements in an integer array.

-   **Parameters**:
    -   `arr`: `const int*` - Pointer to the array.
    -   `size`: `size_t` - Number of elements.
    -   `sum`: `long long*` - Pointer to store the result (uses `long long` to prevent overflow).
-   **Returns**:
    -   `true` if successful (`sum` not `NULL`). Sum is 0 for `size == 0`.
    -   `false` otherwise.
-   **Behavior**: Stores the sum in `*sum`.
-   **Complexity**: O(n) time, O(1) space.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        int data[] = {3, 1, 4, 1, 5, 9, 2, 6};
        size_t n = sizeof(data)/sizeof(data[0]);
        long long total;
        if (array_sum(data, n, &total)) {
            printf("Sum: %lld\n", total); // Output: 31
        } else {
             printf("Could not calculate sum.\n");
        }
        return 0;
    }
    ```

---

#### `bool array_contains_int(const int *arr, size_t size, int value)`

Checks if an integer array contains a specific value.

-   **Parameters**:
    -   `arr`: `const int*` - Pointer to the array.
    -   `size`: `size_t` - Number of elements.
    -   `value`: `int` - The value to search for.
-   **Returns**:
    -   `true` if `value` is found in the array.
    -   `false` otherwise (or if `arr` is `NULL` or `size` is 0).
-   **Complexity**: O(n) time, O(1) space.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        int data[] = {3, 1, 4, 1, 5, 9, 2, 6};
        size_t n = sizeof(data)/sizeof(data[0]);
        int search_val = 5;
        if (array_contains_int(data, n, search_val)) {
            printf("Array contains %d.\n", search_val); // Output: Array contains 5.
        } else {
            printf("Array does not contain %d.\n", search_val);
        }
        search_val = 7;
        if (!array_contains_int(data, n, search_val)) {
             printf("Array does not contain %d.\n", search_val); // Output: Array does not contain 7.
        }
        return 0;
    }
    ```

---

#### `int array_index_of_int(const int *arr, size_t size, int value)`

Finds the index of the *first* occurrence of a value in an integer array.

-   **Parameters**:
    -   `arr`: `const int*` - Pointer to the array.
    -   `size`: `size_t` - Number of elements.
    -   `value`: `int` - The value to search for.
-   **Returns**:
    -   `int` - The index of the first occurrence of `value`.
    -   `-1` if `value` is not found, `arr` is `NULL`, `size` is 0, or the index exceeds `INT_MAX`.
-   **Complexity**: O(n) time, O(1) space.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        int data[] = {3, 1, 4, 1, 5, 9, 2, 6};
        size_t n = sizeof(data)/sizeof(data[0]);
        int idx = array_index_of_int(data, n, 1);
        printf("First index of 1: %d\n", idx); // Output: 1

        idx = array_index_of_int(data, n, 9);
        printf("First index of 9: %d\n", idx); // Output: 5

        idx = array_index_of_int(data, n, 7);
        printf("First index of 7: %d\n", idx); // Output: -1
        return 0;
    }
    ```

---

#### `double array_average(const int *arr, size_t size)`

Calculates the average (mean) of the elements in an integer array.

-   **Parameters**:
    -   `arr`: `const int*` - Pointer to the array.
    -   `size`: `size_t` - Number of elements.
-   **Returns**:
    -   `double` - The average value.
    -   `NAN` (Not a Number) if `arr` is `NULL`, `size` is 0, or internal sum calculation fails.
-   **Behavior**: Uses `array_sum` internally.
-   **Complexity**: O(n) time, O(1) space.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"
    #include <math.h> // For NAN checking

    int main(void) {
        int data[] = {1, 2, 3, 4, 5};
        size_t n = sizeof(data)/sizeof(data[0]);
        double avg = array_average(data, n);
        if (!isnan(avg)) {
            printf("Average: %f\n", avg); // Output: 3.000000
        } else {
            printf("Could not calculate average.\n");
        }
        return 0;
    }
    ```

---

#### `size_t array_count_occurrence(const int *arr, size_t size, int value)`

Counts how many times a specific value appears in an integer array.

-   **Parameters**:
    -   `arr`: `const int*` - Pointer to the array.
    -   `size`: `size_t` - Number of elements.
    -   `value`: `int` - The value to count.
-   **Returns**:
    -   `size_t` - The number of occurrences of `value`.
    -   `0` if `arr` is `NULL` or `size` is 0.
-   **Complexity**: O(n) time, O(1) space.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        int data[] = {3, 1, 4, 1, 5, 9, 1, 6};
        size_t n = sizeof(data)/sizeof(data[0]);
        size_t count = array_count_occurrence(data, n, 1);
        printf("Count of 1: %zu\n", count); // Output: 3

        count = array_count_occurrence(data, n, 7);
        printf("Count of 7: %zu\n", count); // Output: 0
        return 0;
    }
    ```

---

#### `int* array_copy_int(const int *arr, size_t size)`

Creates a dynamically allocated copy of an integer array.

-   **Parameters**:
    -   `arr`: `const int*` - Pointer to the source array.
    -   `size`: `size_t` - Number of elements to copy.
-   **Returns**:
    -   `int*` - A pointer to the newly allocated copy. **Caller must `free()` the result.**
    -   `NULL` if `arr` is `NULL`, `size` is 0, or memory allocation fails.
-   **Behavior**: Performs a shallow copy of the integer values.
-   **Complexity**: O(n) time, O(n) space.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"
    #include <stdlib.h> // For free

    int main(void) {
        int original[] = {10, 20, 30};
        size_t n = sizeof(original)/sizeof(original[0]);
        int* copy = array_copy_int(original, n);
        if (copy) {
            printf("Original: "); print_array(original, n);
            printf("Copy:     "); print_array(copy, n);
            // Modify copy - original is unaffected
            copy[0] = 99;
            printf("Modified Copy: "); print_array(copy, n);      // Output: [99, 20, 30]
            printf("Original Still: "); print_array(original, n); // Output: [10, 20, 30]
            free(copy); // Don't forget to free
        } else {
            printf("Failed to copy array.\n");
        }
        return 0;
    }
    ```

---

#### `bool array_has_pair_sum(const int *arr, size_t size, int target)`

Checks if any *distinct* pair of elements in the array sums to a target value.

-   **Parameters**:
    -   `arr`: `const int*` - Pointer to the array.
    -   `size`: `size_t` - Number of elements.
    -   `target`: `int` - The target sum.
-   **Returns**:
    -   `true` if a pair `(arr[i], arr[j])` with `i != j` exists such that `arr[i] + arr[j] == target`.
    -   `false` otherwise (or if `arr` is `NULL`, `size < 2`, or internal allocation fails).
-   **Implementation**: Uses an internal hash table.
-   **Complexity**: O(n) average time, O(n) space.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        int data[] = {2, 7, 11, 15, 6};
        size_t n = sizeof(data)/sizeof(data[0]);
        int target_sum = 9;
        if (array_has_pair_sum(data, n, target_sum)) {
             printf("Found pair summing to %d.\n", target_sum); // Output: Found pair summing to 9.
        } else {
             printf("No pair summing to %d.\n", target_sum);
        }
        target_sum = 10;
        if (!array_has_pair_sum(data, n, target_sum)) {
             printf("No pair summing to %d.\n", target_sum); // Output: No pair summing to 10.
        }
        return 0;
    }
    ```

---

#### `bool array_has_pair_product(const int *arr, size_t size, int target)`

Checks if any *distinct* pair of elements multiplies to a target value.

-   **Parameters**:
    -   `arr`: `const int*` - Pointer to the array.
    -   `size`: `size_t` - Number of elements.
    -   `target`: `int` - The target product.
-   **Returns**:
    -   `true` if a pair `(arr[i], arr[j])` with `i != j` exists such that `arr[i] * arr[j] == target`.
    -   `false` otherwise (or if `arr` is `NULL`, `size < 2` [unless target is 0 and size >= 1 with a 0], or internal allocation fails).
-   **Implementation**: Uses an internal hash table, handles zero carefully.
-   **Complexity**: O(n) average time, O(n) space.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        int data[] = {3, 5, 4, 6, 2};
        size_t n = sizeof(data)/sizeof(data[0]);
        int target_prod = 20;
        if (array_has_pair_product(data, n, target_prod)) {
            printf("Found pair with product %d.\n", target_prod); // Output: Found pair with product 20.
        } else {
            printf("No pair with product %d.\n", target_prod);
        }
         target_prod = 11;
        if (!array_has_pair_product(data, n, target_prod)) {
            printf("No pair with product %d.\n", target_prod); // Output: No pair with product 11.
        }
        return 0;
    }
    ```

---

#### `bool array_has_pair_difference(const int *arr, size_t size, int target)`

Checks if any pair of elements has a specific difference (`a - b == target`).

-   **Parameters**:
    -   `arr`: `const int*` - Pointer to the array.
    -   `size`: `size_t` - Number of elements.
    -   `target`: `int` - The target difference.
-   **Returns**:
    -   `true` if a pair `(arr[i], arr[j])` exists such that `arr[i] - arr[j] == target`. Note: `i` can equal `j` if `target == 0` and duplicates exist.
    -   `false` otherwise (or if `arr` is `NULL`, `size < 1`, or internal allocation fails).
-   **Implementation**: Uses an internal hash table.
-   **Complexity**: O(n) average time, O(n) space.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        int data[] = {10, 7, 1, 5, 12};
        size_t n = sizeof(data)/sizeof(data[0]);
        int target_diff = 3; // 10 - 7 = 3
        if (array_has_pair_difference(data, n, target_diff)) {
            printf("Found pair with difference %d.\n", target_diff); // Output: Found pair with difference 3.
        } else {
             printf("No pair with difference %d.\n", target_diff);
        }
        target_diff = 6; // 7 - 1 = 6, 1 - 7 = -6
        if (array_has_pair_difference(data, n, target_diff)) {
            printf("Found pair with difference %d.\n", target_diff); // Output: Found pair with difference 6.
        } else {
             printf("No pair with difference %d.\n", target_diff);
        }
        target_diff = -5; // 7 - 12 = -5
        if (array_has_pair_difference(data, n, target_diff)) {
            printf("Found pair with difference %d.\n", target_diff); // Output: Found pair with difference -5.
        } else {
             printf("No pair with difference %d.\n", target_diff);
        }
        return 0;
    }
    ```

---

#### `void sort_array(int arr[], size_t size)`

Sorts an integer array in ascending order (in-place).

-   **Parameters**:
    -   `arr`: `int[]` - The array to sort.
    -   `size`: `size_t` - Number of elements.
-   **Returns**: `void`.
-   **Behavior**: Modifies the input array `arr`. Does nothing if `arr` is `NULL` or `size < 2`.
-   **Implementation**: Uses `qsort` from `stdlib.h`.
-   **Complexity**: O(n log n) average time, O(log n) or O(n) space depending on `qsort` implementation.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        int data[] = {3, 1, 4, 1, 5, 9, 2, 6};
        size_t n = sizeof(data)/sizeof(data[0]);
        printf("Before sort: "); print_array(data, n);
        sort_array(data, n);
        printf("After sort:  "); print_array(data, n); // Output: [1, 1, 2, 3, 4, 5, 6, 9]
        return 0;
    }
    ```

---

#### `void print_array(const int arr[], size_t size)`

Prints the elements of an integer array to standard output.

-   **Parameters**:
    -   `arr`: `const int[]` - The array to print.
    -   `size`: `size_t` - Number of elements.
-   **Returns**: `void`.
-   **Behavior**: Prints in the format `[elem1, elem2, ..., elemN]\n`. Prints `[]\n` for `NULL` array or `size == 0`.
-   **Complexity**: O(n) time, O(1) space.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        int values[] = {10, -20, 30, 0};
        print_array(values, 4); // Output: [10, -20, 30, 0]

        int empty_arr[] = {};
        print_array(empty_arr, 0); // Output: []

        print_array(NULL, 5); // Output: []
        return 0;
    }
    ```

---

#### `void array_reverse_int(int arr[], size_t size)`

Reverses the order of elements in an integer array (in-place).

-   **Parameters**:
    -   `arr`: `int[]` - The array to reverse.
    -   `size`: `size_t` - Number of elements.
-   **Returns**: `void`.
-   **Behavior**: Modifies the input array `arr`. Does nothing if `arr` is `NULL` or `size < 2`.
-   **Complexity**: O(n) time, O(1) space.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        int data[] = {1, 2, 3, 4, 5};
        size_t n = sizeof(data)/sizeof(data[0]);
        printf("Before reverse: "); print_array(data, n);
        array_reverse_int(data, n);
        printf("After reverse:  "); print_array(data, n); // Output: [5, 4, 3, 2, 1]
        return 0;
    }
    ```

---

#### `void array_shuffle_int(int arr[], size_t size)`

Randomly shuffles the elements of an integer array (in-place) using the Fisher-Yates algorithm.

-   **Parameters**:
    -   `arr`: `int[]` - The array to shuffle.
    -   `size`: `size_t` - Number of elements.
-   **Returns**: `void`.
-   **Behavior**:
    -   Modifies the input array `arr`. Does nothing if `arr` is `NULL` or `size < 2`.
    -   Requires `initialize_random()` to be called once beforehand to seed the random number generator (`rand`).
-   **Complexity**: O(n) time, O(1) space.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"
    #include <stdlib.h> // Needed for srand/rand via initialize_random
    #include <time.h>   // Needed for time() via initialize_random

    int main(void) {
        int data[] = {1, 2, 3, 4, 5, 6, 7, 8};
        size_t n = sizeof(data)/sizeof(data[0]);
        initialize_random(); // Call once at program start

        printf("Before shuffle: "); print_array(data, n);
        array_shuffle_int(data, n);
        printf("After shuffle:  "); print_array(data, n); // Output: elements in random order
        return 0;
    }
    ```

---

#### `int* array_unique_int(const int *arr, size_t size, size_t *new_size)`

Creates a new array containing only the unique elements from the input array.

-   **Parameters**:
    -   `arr`: `const int*` - Pointer to the source array.
    -   `size`: `size_t` - Number of elements in the source array.
    -   `new_size`: `size_t*` - Pointer to store the number of unique elements found.
-   **Returns**:
    -   `int*` - A pointer to a newly allocated array containing unique elements. **Caller must `free()` the result.** Order is not guaranteed.
    -   `NULL` if `arr` is `NULL`, `size` is 0, `new_size` is `NULL`, or memory allocation fails. `*new_size` is set to 0 on failure.
-   **Implementation**: Uses an internal hash table.
-   **Complexity**: O(n) average time, O(n) space.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"
    #include <stdlib.h> // For free

    int main(void) {
        int data[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
        size_t n = sizeof(data)/sizeof(data[0]);
        printf("Original: "); print_array(data, n);

        size_t unique_count;
        int* unique_items = array_unique_int(data, n, &unique_count);

        if (unique_items) {
            printf("Unique (%zu items): ", unique_count);
            // Sort the unique items for predictable output (optional)
            sort_array(unique_items, unique_count);
            print_array(unique_items, unique_count); // Output: [1, 2, 3, 4, 5, 6, 9] (after sorting)
            free(unique_items);
        } else {
            printf("Failed to get unique items.\n");
        }
        return 0;
    }
    ```

---

#### `int* array_concat_int(const int *arr1, size_t size1, const int *arr2, size_t size2, size_t *new_size)`

Creates a new array by concatenating two integer arrays.

-   **Parameters**:
    -   `arr1`: `const int*` - Pointer to the first array (can be `NULL` if `size1` is 0).
    -   `size1`: `size_t` - Number of elements in the first array.
    -   `arr2`: `const int*` - Pointer to the second array (can be `NULL` if `size2` is 0).
    -   `size2`: `size_t` - Number of elements in the second array.
    -   `new_size`: `size_t*` - Pointer to store the total size of the new array (`size1 + size2`).
-   **Returns**:
    -   `int*` - Pointer to the newly allocated concatenated array. **Caller must `free()` the result.**
    -   `NULL` if `new_size` is `NULL`, total size is 0, or memory allocation fails. `*new_size` is set to 0 on failure.
-   **Complexity**: O(size1 + size2) time, O(size1 + size2) space.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"
    #include <stdlib.h> // For free

    int main(void) {
        int a1[] = {1, 2, 3};
        int a2[] = {4, 5, 6, 7};
        size_t n1 = sizeof(a1)/sizeof(a1[0]);
        size_t n2 = sizeof(a2)/sizeof(a2[0]);

        size_t total_size;
        int* combined = array_concat_int(a1, n1, a2, n2, &total_size);

        if (combined) {
            printf("Array 1: "); print_array(a1, n1);
            printf("Array 2: "); print_array(a2, n2);
            printf("Combined (%zu items): ", total_size);
            print_array(combined, total_size); // Output: [1, 2, 3, 4, 5, 6, 7]
            free(combined);
        } else {
            printf("Failed to concatenate arrays.\n");
        }
        return 0;
    }
    ```

---

### Float Array Functions

*(These functions generally mirror the integer array functions but operate on `float` values. Key differences like using `FLOAT_EPSILON` for comparisons are noted.)*

---

#### `bool array_max_float(const float *arr, size_t size, float *max_val)`

Finds the maximum value in a float array. (O(n) time)

-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        float data[] = {3.1f, 1.4f, 4.1f, -5.9f, 2.6f};
        size_t n = sizeof(data)/sizeof(data[0]);
        float max_v;
        if (array_max_float(data, n, &max_v)) {
            printf("Max float: %.2f\n", max_v); // Output: 4.10
        }
        return 0;
    }
    ```

---

#### `bool array_min_float(const float *arr, size_t size, float *min_val)`

Finds the minimum value in a float array. (O(n) time)

-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        float data[] = {3.1f, 1.4f, 4.1f, -5.9f, 2.6f};
        size_t n = sizeof(data)/sizeof(data[0]);
        float min_v;
        if (array_min_float(data, n, &min_v)) {
            printf("Min float: %.2f\n", min_v); // Output: -5.90
        }
        return 0;
    }
    ```

---

#### `bool array_sum_float(const float *arr, size_t size, double *sum)`

Calculates the sum of elements in a float array (uses `double` for sum to maintain precision). (O(n) time)

-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        float data[] = {1.1f, 2.2f, 3.3f};
        size_t n = sizeof(data)/sizeof(data[0]);
        double total;
        if (array_sum_float(data, n, &total)) {
            printf("Float sum: %f\n", total); // Output: 6.600000 (approx)
        }
        return 0;
    }
    ```

---

#### `double array_average_float(const float *arr, size_t size)`

Calculates the average of elements in a float array. Returns `NAN` on error/empty. (O(n) time)

-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"
    #include <math.h> // For isnan

    int main(void) {
        float data[] = {1.0f, 2.5f, 3.0f, 4.5f};
        size_t n = sizeof(data)/sizeof(data[0]);
        double avg = array_average_float(data, n);
         if (!isnan(avg)) {
            printf("Float average: %f\n", avg); // Output: 2.750000
        }
        return 0;
    }
    ```

---

#### `void sort_array_float(float arr[], size_t size)`

Sorts a float array in ascending order (in-place) using `qsort`. (O(n log n) time)

-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        float data[] = {3.1f, 1.4f, 4.1f, -5.9f, 2.6f};
        size_t n = sizeof(data)/sizeof(data[0]);
        printf("Before sort: "); print_float_array(data, n);
        sort_array_float(data, n);
        printf("After sort:  "); print_float_array(data, n); // Output: [-5.90..., 1.40..., 2.60..., 3.10..., 4.10...]
        return 0;
    }
    ```

---

#### `bool array_contains_float(const float *arr, size_t size, float value)`

Checks if a float array contains a value (uses `FLOAT_EPSILON` for comparison). (O(n) time)

-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        float data[] = {3.14159f, 2.71828f, 1.61803f};
        size_t n = sizeof(data)/sizeof(data[0]);
        if (array_contains_float(data, n, 2.71828f)) {
            printf("Array contains e (approx).\n");
        }
        // Comparison with slightly different value due to precision
         if (array_contains_float(data, n, 3.141592f)) {
            printf("Array contains pi (approx).\n"); // May or may not print depending on epsilon
        }
        return 0;
    }
    ```

---

#### `int array_index_of_float(const float *arr, size_t size, float value)`

Finds the index of the first occurrence of a float value (uses `FLOAT_EPSILON`). Returns `-1` if not found or index > `INT_MAX`. (O(n) time)

-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        float data[] = {3.1f, 1.4f, 4.1f, 1.4f, 2.6f};
        size_t n = sizeof(data)/sizeof(data[0]);
        int idx = array_index_of_float(data, n, 1.4f);
        printf("Index of 1.4: %d\n", idx); // Output: 1
        return 0;
    }
    ```

---

#### `size_t array_count_occurrence_float(const float *arr, size_t size, float value)`

Counts occurrences of a float value (uses `FLOAT_EPSILON`). (O(n) time)

-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        float data[] = {3.1f, 1.4f, 4.1f, 1.400001f, 1.399999f, 2.6f};
        size_t n = sizeof(data)/sizeof(data[0]);
        // Counts values close to 1.4 within FLOAT_EPSILON
        size_t count = array_count_occurrence_float(data, n, 1.4f);
        printf("Count of ~1.4: %zu\n", count); // Output: 3 (depending on EPSILON)
        return 0;
    }
    ```

---

#### `float* array_copy_float(const float *arr, size_t size)`

Creates a dynamically allocated copy of a float array. **Caller must `free()`**. Returns `NULL` on failure. (O(n) time, O(n) space)

-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"
    #include <stdlib.h> // For free

    int main(void) {
        float original[] = {1.1f, 2.2f, 3.3f};
        size_t n = sizeof(original)/sizeof(original[0]);
        float* copy = array_copy_float(original, n);
        if (copy) {
            printf("Original: "); print_float_array(original, n);
            printf("Copy:     "); print_float_array(copy, n);
            free(copy);
        }
        return 0;
    }
    ```

---

#### `void print_float_array(const float arr[], size_t size)`

Prints the elements of a float array (format `[%.6f, ...]\n`). (O(n) time)

-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        float data[] = {3.14f, 2.71f, 1.61f};
        size_t n = sizeof(data)/sizeof(data[0]);
        print_float_array(data, n); // Output: [3.140000, 2.710000, 1.610000]
        return 0;
    }
    ```

---

#### `void array_reverse_float(float arr[], size_t size)`

Reverses a float array in-place. (O(n) time)

-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        float data[] = {1.1f, 2.2f, 3.3f, 4.4f};
        size_t n = sizeof(data)/sizeof(data[0]);
        printf("Before: "); print_float_array(data, n);
        array_reverse_float(data, n);
        printf("After:  "); print_float_array(data, n); // Output: [4.4..., 3.3..., 2.2..., 1.1...]
        return 0;
    }
    ```

---

#### `void array_shuffle_float(float arr[], size_t size)`

Randomly shuffles a float array in-place (requires `initialize_random()`). (O(n) time)

-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"
    #include <stdlib.h>
    #include <time.h>

    int main(void) {
        float data[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
        size_t n = sizeof(data)/sizeof(data[0]);
        initialize_random();
        printf("Before: "); print_float_array(data, n);
        array_shuffle_float(data, n);
        printf("After:  "); print_float_array(data, n); // Output: random order
        return 0;
    }
    ```

---

#### `float* array_concat_float(const float *arr1, size_t size1, const float *arr2, size_t size2, size_t *new_size)`

Creates a new array by concatenating two float arrays. **Caller must `free()`**. Returns `NULL` on failure. (O(size1 + size2) time, O(size1 + size2) space)

-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"
    #include <stdlib.h> // For free

    int main(void) {
        float a1[] = {1.1f, 2.2f};
        float a2[] = {3.3f, 4.4f, 5.5f};
        size_t n1 = sizeof(a1)/sizeof(a1[0]);
        size_t n2 = sizeof(a2)/sizeof(a2[0]);
        size_t total_size;
        float* combined = array_concat_float(a1, n1, a2, n2, &total_size);
        if (combined) {
             printf("Combined (%zu): ", total_size);
             print_float_array(combined, total_size); // Output: [1.1..., 2.2..., 3.3..., 4.4..., 5.5...]
             free(combined);
        }
        return 0;
    }
    ```

---

### Double Array Functions

*(These functions mirror the float array functions but operate on `double` values and use `DOUBLE_EPSILON` for comparisons.)*

---

#### `bool array_max_double(const double *arr, size_t size, double *max_val)`

Finds the maximum value in a double array. (O(n) time)

-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        double data[] = {3.14, 2.71, 1.61, -0.57};
        size_t n = sizeof(data)/sizeof(data[0]);
        double max_v;
        if(array_max_double(data, n, &max_v)) {
            printf("Max double: %.3f\n", max_v); // Output: 3.140
        }
        return 0;
    }
    ```

---

#### `bool array_min_double(const double *arr, size_t size, double *min_val)`

Finds the minimum value in a double array. (O(n) time)

-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        double data[] = {3.14, 2.71, 1.61, -0.57};
        size_t n = sizeof(data)/sizeof(data[0]);
        double min_v;
        if(array_min_double(data, n, &min_v)) {
            printf("Min double: %.3f\n", min_v); // Output: -0.570
        }
        return 0;
    }
    ```
---

#### `bool array_sum_double(const double *arr, size_t size, double *sum)`

Calculates the sum of elements in a double array. (O(n) time)

-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        double data[] = {1.11, 2.22, 3.33};
        size_t n = sizeof(data)/sizeof(data[0]);
        double total;
        if (array_sum_double(data, n, &total)) {
            printf("Double sum: %.10f\n", total); // Output: 6.6600000000
        }
        return 0;
    }
    ```

---

#### `double array_average_double(const double *arr, size_t size)`

Calculates the average of elements in a double array. Returns `NAN` on error/empty. (O(n) time)

-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"
    #include <math.h>

    int main(void) {
        double data[] = {10.0, 20.0, 30.0, 40.0};
        size_t n = sizeof(data)/sizeof(data[0]);
        double avg = array_average_double(data, n);
        if(!isnan(avg)) {
             printf("Double average: %.2f\n", avg); // Output: 25.00
        }
        return 0;
    }
    ```

---

#### `void sort_array_double(double arr[], size_t size)`

Sorts a double array in ascending order (in-place) using `qsort`. (O(n log n) time)

-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        double data[] = {3.14, 2.71, 1.61, -0.57};
        size_t n = sizeof(data)/sizeof(data[0]);
        printf("Before: "); print_double_array(data, n);
        sort_array_double(data, n);
        printf("After:  "); print_double_array(data, n); // Output: [-0.57..., 1.61..., 2.71..., 3.14...]
        return 0;
    }
    ```

---

#### `bool array_contains_double(const double *arr, size_t size, double value)`

Checks if a double array contains a value (uses `DOUBLE_EPSILON`). (O(n) time)

-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        double pi = 3.1415926535;
        double e = 2.7182818284;
        double data[] = {pi, e};
        size_t n = sizeof(data)/sizeof(data[0]);
        if (array_contains_double(data, n, 3.1415926535)) {
            printf("Contains pi.\n");
        }
        // Check approximate value
        if (array_contains_double(data, n, 2.71828)) {
             printf("Contains e (approx).\n"); // Should print due to epsilon
        }
        return 0;
    }
    ```

---

#### `int array_index_of_double(const double *arr, size_t size, double value)`

Finds the index of the first occurrence of a double value (uses `DOUBLE_EPSILON`). Returns `-1` if not found or index > `INT_MAX`. (O(n) time)

-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        double data[] = {10.1, 20.2, 30.3, 20.2};
        size_t n = sizeof(data)/sizeof(data[0]);
        int idx = array_index_of_double(data, n, 20.2);
        printf("Index of 20.2: %d\n", idx); // Output: 1
        return 0;
    }
    ```
---

#### `size_t array_count_occurrence_double(const double *arr, size_t size, double value)`

Counts occurrences of a double value (uses `DOUBLE_EPSILON`). (O(n) time)

-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        double data[] = {1.0, 2.0, 1.0000000001, 3.0, 0.9999999999};
        size_t n = sizeof(data)/sizeof(data[0]);
        size_t count = array_count_occurrence_double(data, n, 1.0);
        printf("Count of ~1.0: %zu\n", count); // Output: 3 (depending on DOUBLE_EPSILON)
        return 0;
    }
    ```

---

#### `double* array_copy_double(const double *arr, size_t size)`

Creates a dynamically allocated copy of a double array. **Caller must `free()`**. Returns `NULL` on failure. (O(n) time, O(n) space)

-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"
    #include <stdlib.h>

    int main(void) {
        double original[] = {10.0, 20.0, 30.0};
        size_t n = sizeof(original)/sizeof(original[0]);
        double* copy = array_copy_double(original, n);
        if(copy) {
            printf("Original: "); print_double_array(original, n);
            printf("Copy:     "); print_double_array(copy, n);
            free(copy);
        }
        return 0;
    }
    ```

---

#### `void print_double_array(const double arr[], size_t size)`

Prints the elements of a double array (format `[%.12f, ...]\n`). (O(n) time)

-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        double data[] = {1.23456789, 9.87654321};
        size_t n = sizeof(data)/sizeof(data[0]);
        print_double_array(data, n); // Output: [1.234567890000, 9.876543210000]
        return 0;
    }
    ```

---

#### `void array_reverse_double(double arr[], size_t size)`

Reverses a double array in-place. (O(n) time)

-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        double data[] = {10.1, 20.2, 30.3};
        size_t n = sizeof(data)/sizeof(data[0]);
        printf("Before: "); print_double_array(data, n);
        array_reverse_double(data, n);
        printf("After:  "); print_double_array(data, n); // Output: [30.3..., 20.2..., 10.1...]
        return 0;
    }
    ```

---

#### `void array_shuffle_double(double arr[], size_t size)`

Randomly shuffles a double array in-place (requires `initialize_random()`). (O(n) time)

-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"
    #include <stdlib.h>
    #include <time.h>

    int main(void) {
        double data[] = {1.1, 2.2, 3.3, 4.4, 5.5};
        size_t n = sizeof(data)/sizeof(data[0]);
        initialize_random();
        printf("Before: "); print_double_array(data, n);
        array_shuffle_double(data, n);
        printf("After:  "); print_double_array(data, n); // Output: random order
        return 0;
    }
    ```
---

#### `double* array_concat_double(const double *arr1, size_t size1, const double *arr2, size_t size2, size_t *new_size)`

Creates a new array by concatenating two double arrays. **Caller must `free()`**. Returns `NULL` on failure. (O(size1 + size2) time, O(size1 + size2) space)

-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"
    #include <stdlib.h>

    int main(void) {
        double a1[] = {1.1, 2.2};
        double a2[] = {3.3, 4.4, 5.5};
        size_t n1 = sizeof(a1)/sizeof(a1[0]);
        size_t n2 = sizeof(a2)/sizeof(a2[0]);
        size_t total_size;
        double* combined = array_concat_double(a1, n1, a2, n2, &total_size);
        if(combined) {
            printf("Combined (%zu): ", total_size);
            print_double_array(combined, total_size); // Output: [1.1..., 2.2..., 3.3..., 4.4..., 5.5...]
            free(combined);
        }
        return 0;
    }
    ```

---

### String Array Functions

*(These operate on arrays of `string` (which is `char*`). String comparisons use `strcmp`. Copying often involves deep copies.)*

---

#### `bool array_max_string(const string *arr, size_t size, string *max_val)`

Finds the lexicographically largest non-NULL string in an array.

-   **Parameters**: `arr`, `size`, `max_val` (pointer to a `string` to store the result).
-   **Returns**: `true` if successful (even if all strings are `NULL`, in which case `*max_val` is `NULL`). Returns pointer *within* the input array.
-   **Complexity**: O(n * L) time (L = average string length).
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        string data[] = {"apple", "banana", "zebra", "grape"};
        size_t n = sizeof(data)/sizeof(data[0]);
        string max_s = NULL; // Initialize
        if (array_max_string(data, n, &max_s)) {
            printf("Max string: %s\n", max_s ? max_s : "NULL"); // Output: zebra
        }
        return 0;
    }
    ```

---

#### `bool array_min_string(const string *arr, size_t size, string *min_val)`

Finds the lexicographically smallest string (NULL is considered smallest).

-   **Parameters**: `arr`, `size`, `min_val`.
-   **Returns**: `true` if successful. Returns pointer *within* the input array. `*min_val` will be `NULL` if the array contains `NULL`.
-   **Complexity**: O(n * L) time.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        string data[] = {"apple", "banana", NULL, "zebra", "grape"};
        size_t n = sizeof(data)/sizeof(data[0]);
        string min_s = (string)""; // Initialize to non-NULL
        if (array_min_string(data, n, &min_s)) {
            printf("Min string: %s\n", min_s ? min_s : "NULL"); // Output: NULL
        }

        string data2[] = {"fig", "elderberry", "date"};
        size_t n2 = sizeof(data2)/sizeof(data2[0]);
        string min_s2 = NULL;
        if (array_min_string(data2, n2, &min_s2)) {
            printf("Min string 2: %s\n", min_s2 ? min_s2 : "NULL"); // Output: date
        }
        return 0;
    }
    ```

---

#### `void sort_array_string(string arr[], size_t size)`

Sorts an array of strings lexicographically (in-place) using `qsort` and `strcmp`. `NULL` strings are sorted first.

-   **Parameters**: `arr`, `size`.
-   **Complexity**: O(n log n * L) time.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        string data[] = {"banana", "apple", NULL, "grape", "cherry"};
        size_t n = sizeof(data)/sizeof(data[0]);
        printf("Before: "); print_string_array(data, n);
        sort_array_string(data, n);
        printf("After:  "); print_string_array(data, n); // Output: [null, "apple", "banana", "cherry", "grape"]
        return 0;
    }
    ```

---

#### `bool array_contains_string(const string *arr, size_t size, const string value)`

Checks if a string array contains a specific string (uses `string_equals`, handles `NULL`).

-   **Parameters**: `arr`, `size`, `value` (the string to search for).
-   **Complexity**: O(n * L) time.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        string data[] = {"hello", "world", NULL, "test"};
        size_t n = sizeof(data)/sizeof(data[0]);
        if (array_contains_string(data, n, "world")) {
            printf("Contains 'world'.\n");
        }
        if (array_contains_string(data, n, NULL)) {
            printf("Contains NULL.\n");
        }
        if (!array_contains_string(data, n, "goodbye")) {
            printf("Does not contain 'goodbye'.\n");
        }
        return 0;
    }
    ```

---

#### `int find_string(const string names[], size_t size, const string target_name)`

Alias for `array_index_of_string`. Finds the index of the *first* occurrence of a target string.

-   **Parameters**: `names` (the array), `size`, `target_name`.
-   **Returns**: Index (int) or `-1` if not found, inputs are `NULL`, or index > `INT_MAX`.
-   **Complexity**: O(n * L) time.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        const char *items[] = {"Apple", "Banana", "Cherry", "Apple"};
        size_t n = sizeof(items) / sizeof(items[0]);
        int index = find_string(items, n, "Apple");
        printf("First 'Apple' found at index: %d\n", index); // Output: 0

        index = find_string(items, n, "Durian");
        printf("'Durian' found at index: %d\n", index); // Output: -1
        return 0;
    }
    ```

---

#### `size_t array_count_occurrence_string(const string *arr, size_t size, const string value)`

Counts occurrences of a specific string (uses `string_equals`, handles `NULL`).

-   **Parameters**: `arr`, `size`, `value`.
-   **Complexity**: O(n * L) time.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        string data[] = {"a", "b", "a", NULL, "c", "a", NULL};
        size_t n = sizeof(data)/sizeof(data[0]);
        printf("Count of 'a': %zu\n", array_count_occurrence_string(data, n, "a")); // Output: 3
        printf("Count of NULL: %zu\n", array_count_occurrence_string(data, n, NULL)); // Output: 2
        printf("Count of 'd': %zu\n", array_count_occurrence_string(data, n, "d")); // Output: 0
        return 0;
    }
    ```

---

#### `string* array_copy_string_array(const string *arr, size_t size)`

Creates a dynamically allocated **deep copy** of a string array (copies the array structure and each string within it).

-   **Parameters**: `arr`, `size`.
-   **Returns**:
    -   `string*` - Pointer to the new array of copied strings. **Caller must free using `free_string_array()`**.
    -   `NULL` on failure (input `NULL`, `size 0`, or memory allocation failure).
-   **Complexity**: O(n * L) time, O(n * L) space.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"
    #include <stdlib.h> // For free_string_array

    int main(void) {
        string original[] = {"one", "two", NULL, "four"};
        size_t n = sizeof(original)/sizeof(original[0]);
        string* copy = array_copy_string_array(original, n);
        if (copy) {
            printf("Original: "); print_string_array(original, n);
            printf("Copy:     "); print_string_array(copy, n);
            // Modify copy - original is unaffected
            free_string(copy[0]); // Need to free old string before replacing
            copy[0] = string_copy("uno");
            printf("Modified Copy: "); print_string_array(copy, n); // Output: ["uno", "two", null, "four"]
            printf("Original Still:"); print_string_array(original, n); // Output: ["one", "two", null, "four"]
            free_string_array(copy, n); // Use helper to free deep copy
        }
        return 0;
    }
    ```

---

#### `void print_string_array(const string arr[], size_t size)`

Prints the elements of a string array (format `["str1", "str2", null, ...]\n`). Handles `NULL` strings.

-   **Parameters**: `arr`, `size`.
-   **Complexity**: O(n * L) time.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        string data[] = {"CPU", "GPU", NULL, "RAM"};
        size_t n = sizeof(data)/sizeof(data[0]);
        print_string_array(data, n); // Output: ["CPU", "GPU", null, "RAM"]
        return 0;
    }
    ```

---

#### `void array_reverse_string(string arr[], size_t size)`

Reverses the order of pointers in a string array (in-place, shallow reverse).

-   **Parameters**: `arr`, `size`.
-   **Complexity**: O(n) time.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        string data[] = {"first", "second", "third"};
        size_t n = sizeof(data)/sizeof(data[0]);
        printf("Before: "); print_string_array(data, n);
        array_reverse_string(data, n);
        printf("After:  "); print_string_array(data, n); // Output: ["third", "second", "first"]
        return 0;
    }
    ```

---

#### `void array_shuffle_string(string arr[], size_t size)`

Randomly shuffles the pointers in a string array (in-place, shallow shuffle, requires `initialize_random()`).

-   **Parameters**: `arr`, `size`.
-   **Complexity**: O(n) time.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"
    #include <stdlib.h>
    #include <time.h>

    int main(void) {
        string data[] = {"red", "green", "blue", "yellow", "purple"};
        size_t n = sizeof(data)/sizeof(data[0]);
        initialize_random();
        printf("Before: "); print_string_array(data, n);
        array_shuffle_string(data, n);
        printf("After:  "); print_string_array(data, n); // Output: strings in random order
        return 0;
    }
    ```

---

#### `string* array_concat_string(const string *arr1, size_t size1, const string *arr2, size_t size2, size_t *new_size)`

Creates a new **deep copy** array by concatenating two string arrays.

-   **Parameters**: `arr1`, `size1`, `arr2`, `size2`, `new_size`.
-   **Returns**:
    -   `string*` - Pointer to the new array. **Caller must free using `free_string_array()`**.
    -   `NULL` on failure.
-   **Complexity**: O((size1 + size2) * L) time, O((size1 + size2) * L) space.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"
    #include <stdlib.h>

    int main(void) {
        string a1[] = {"A", "B"};
        string a2[] = {"C", "D", "E"};
        size_t n1 = sizeof(a1)/sizeof(a1[0]);
        size_t n2 = sizeof(a2)/sizeof(a2[0]);
        size_t total_size;
        string* combined = array_concat_string(a1, n1, a2, n2, &total_size);
        if(combined) {
             printf("Combined (%zu): ", total_size);
             print_string_array(combined, total_size); // Output: ["A", "B", "C", "D", "E"]
             free_string_array(combined, total_size);
        }
        return 0;
    }
    ```

---

### String Manipulation Functions

---

#### `string string_copy(const string s)`

Creates a dynamically allocated copy of a string.

-   **Parameters**: `s` (the source string).
-   **Returns**: New allocated string. **Caller must `free()` or `free_string()`**. `NULL` on failure or if `s` is `NULL`.
-   **Complexity**: O(L) time, O(L) space.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"
    #include <stdlib.h>

    int main(void) {
        string original = "Hello";
        string copy = string_copy(original);
        if (copy) {
            printf("Original: %s\n", original);
            printf("Copy:     %s\n", copy);
            // copy and original are independent
            free_string(copy);
        }
        return 0;
    }
    ```

---

#### `bool string_equals(const string s1, const string s2)`

Compares two strings for equality (handles `NULL` pointers safely).

-   **Parameters**: `s1`, `s2`.
-   **Returns**: `true` if equal, `false` otherwise.
-   **Complexity**: O(L) time.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        string str1 = "test";
        string str2 = "test";
        string str3 = "Test";
        string str4 = NULL;

        if (string_equals(str1, str2)) printf("'%s' == '%s'\n", str1, str2); // Prints
        if (!string_equals(str1, str3)) printf("'%s' != '%s'\n", str1, str3); // Prints
        if (!string_equals(str1, str4)) printf("'%s' != NULL\n", str1);     // Prints
        if (string_equals(str4, NULL)) printf("NULL == NULL\n");         // Prints
        return 0;
    }
    ```

---

#### `string string_trim(const string s)`

Creates a new string with leading/trailing whitespace removed.

-   **Parameters**: `s` (the source string).
-   **Returns**: New allocated trimmed string. **Caller must `free()` or `free_string()`**. Returns `""` (empty allocated string) if input is all whitespace. `NULL` on allocation failure or if `s` is `NULL`.
-   **Complexity**: O(L) time, O(L) space.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"
    #include <stdlib.h>

    int main(void) {
        string dirty = "  \t  Whitespace Example\n ";
        string clean = string_trim(dirty);
        if (clean) {
             printf("Original: '%s'\n", dirty);
             printf("Trimmed:  '%s'\n", clean); // Output: 'Whitespace Example'
             free_string(clean);
        }
        return 0;
    }
    ```

---

#### `bool string_is_int(const string s)`

Checks if a string represents a valid integer (uses `strtol` check).

-   **Parameters**: `s`.
-   **Returns**: `true` if `s` can be fully parsed as an integer, `false` otherwise.
-   **Complexity**: O(L) time.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        printf("'123' is int? %s\n", string_is_int("123") ? "yes" : "no");       // yes
        printf("'-45' is int? %s\n", string_is_int("-45") ? "yes" : "no");       // yes
        printf("' 10 ' is int? %s\n", string_is_int(" 10 ") ? "yes" : "no");     // yes (leading/trailing space ignored by check)
        printf("'abc' is int? %s\n", string_is_int("abc") ? "yes" : "no");       // no
        printf("'12a' is int? %s\n", string_is_int("12a") ? "yes" : "no");       // no
        printf("'' is int? %s\n", string_is_int("") ? "yes" : "no");           // no
        printf("NULL is int? %s\n", string_is_int(NULL) ? "yes" : "no");        // no
        return 0;
    }
    ```

---

#### `bool string_is_alpha(const string s)`

Checks if a string contains only alphabetic characters. False for empty/NULL string.

-   **Parameters**: `s`.
-   **Complexity**: O(L) time.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        printf("'Hello' is alpha? %s\n", string_is_alpha("Hello") ? "yes" : "no");   // yes
        printf("'Hello ' is alpha? %s\n", string_is_alpha("Hello ") ? "yes" : "no"); // no (space)
        printf("'Hello5' is alpha? %s\n", string_is_alpha("Hello5") ? "yes" : "no"); // no (digit)
        printf("'' is alpha? %s\n", string_is_alpha("") ? "yes" : "no");           // no
        return 0;
    }
    ```

---

#### `bool string_is_digit(const string s)`

Checks if a string contains only digit characters. False for empty/NULL string.

-   **Parameters**: `s`.
-   **Complexity**: O(L) time.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        printf("'12345' is digit? %s\n", string_is_digit("12345") ? "yes" : "no");   // yes
        printf("'123 45' is digit? %s\n", string_is_digit("123 45") ? "yes" : "no"); // no (space)
        printf("'12.3' is digit? %s\n", string_is_digit("12.3") ? "yes" : "no");     // no (period)
        printf("'-123' is digit? %s\n", string_is_digit("-123") ? "yes" : "no");     // no (minus sign)
        printf("'' is digit? %s\n", string_is_digit("") ? "yes" : "no");             // no
        return 0;
    }
    ```

---

#### `bool string_is_alnum(const string s)`

Checks if a string contains only alphanumeric characters. False for empty/NULL string.

-   **Parameters**: `s`.
-   **Complexity**: O(L) time.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        printf("'Alpha123' is alnum? %s\n", string_is_alnum("Alpha123") ? "yes" : "no"); // yes
        printf("'Alpha 123' is alnum? %s\n", string_is_alnum("Alpha 123") ? "yes" : "no");// no (space)
        printf("'Alpha-123' is alnum? %s\n", string_is_alnum("Alpha-123") ? "yes" : "no");// no (hyphen)
        printf("'' is alnum? %s\n", string_is_alnum("") ? "yes" : "no");               // no
        return 0;
    }
    ```

---

#### `bool string_is_space(const string s)`

Checks if a string contains only whitespace characters. False for empty/NULL string.

-   **Parameters**: `s`.
-   **Complexity**: O(L) time.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        printf("'   \\t\\n' is space? %s\n", string_is_space("   \t\n") ? "yes" : "no"); // yes
        printf("'  x ' is space? %s\n", string_is_space("  x ") ? "yes" : "no");       // no
        printf("'' is space? %s\n", string_is_space("") ? "yes" : "no");               // no
        return 0;
    }
    ```

---

#### `bool string_is_empty(const string s)`

Checks if a string is `NULL` or the empty string `""`.

-   **Parameters**: `s`.
-   **Complexity**: O(1) time.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        printf("NULL is empty? %s\n", string_is_empty(NULL) ? "yes" : "no"); // yes
        printf("'' is empty? %s\n", string_is_empty("") ? "yes" : "no");     // yes
        printf("' ' is empty? %s\n", string_is_empty(" ") ? "yes" : "no");   // no
        printf("'a' is empty? %s\n", string_is_empty("a") ? "yes" : "no");   // no
        return 0;
    }
    ```

---

#### `string string_concat(const string s1, const string s2)`

Creates a new string by concatenating two strings.

-   **Parameters**: `s1`, `s2`. Handles `NULL` inputs.
-   **Returns**: New allocated concatenated string. **Caller must `free()` or `free_string()`**. `NULL` on failure.
-   **Complexity**: O(L1 + L2) time, O(L1 + L2) space.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"
    #include <stdlib.h>

    int main(void) {
        string part1 = "Hello, ";
        string part2 = "world!";
        string combined = string_concat(part1, part2);
        if (combined) {
            printf("%s\n", combined); // Output: Hello, world!
            free_string(combined);
        }

        string combined_null = string_concat(part1, NULL);
        if (combined_null) {
             printf("%s\n", combined_null); // Output: Hello,
             free_string(combined_null);
        }
        return 0;
    }
    ```

---

#### `string string_substring(const string s, size_t start, size_t length)`

Creates a new string containing a substring of the original.

-   **Parameters**: `s`, `start` index, `length`. Handles bounds checks gracefully.
-   **Returns**: New allocated substring. **Caller must `free()` or `free_string()`**. Returns `""` if length is 0. `NULL` on failure or if `s` is `NULL`.
-   **Complexity**: O(length) time, O(length) space.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"
    #include <stdlib.h>

    int main(void) {
        string text = "Programming";
        string sub = string_substring(text, 3, 7); // Start at index 3, length 7
        if (sub) {
             printf("Substring: '%s'\n", sub); // Output: 'grammin'
             free_string(sub);
        }
        // Example with out-of-bounds length
        string sub_end = string_substring(text, 8, 10); // Tries to go past end
        if (sub_end) {
             printf("Substring end: '%s'\n", sub_end); // Output: 'ing' (truncated length)
             free_string(sub_end);
        }
        return 0;
    }
    ```

---

#### `int string_find_char(const string s, char c)`

Finds the index of the first occurrence of a character in a string.

-   **Parameters**: `s`, `c`.
-   **Returns**: Index (int) or `-1` if not found, `s` is `NULL`, or index > `INT_MAX`.
-   **Complexity**: O(L) time.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        string text = "abracadabra";
        int index = string_find_char(text, 'a');
        printf("First 'a' at: %d\n", index); // Output: 0

        index = string_find_char(text, 'd');
        printf("First 'd' at: %d\n", index); // Output: 6

        index = string_find_char(text, 'z');
        printf("First 'z' at: %d\n", index); // Output: -1
        return 0;
    }
    ```

---

#### `int string_find_substring(const string haystack, const string needle)`

Finds the index of the first occurrence of a substring within another string.

-   **Parameters**: `haystack`, `needle`.
-   **Returns**: Index (int) or `-1` if not found or inputs are `NULL`. Returns `0` if `needle` is `""`.
-   **Implementation**: Uses `strstr`.
-   **Complexity**: Typically O(L_haystack * L_needle) worst case, often faster in practice.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        string text = "the quick brown fox jumps over the lazy dog";
        int index = string_find_substring(text, "fox");
        printf("'fox' found at: %d\n", index); // Output: 16

        index = string_find_substring(text, "the");
        printf("First 'the' found at: %d\n", index); // Output: 0

        index = string_find_substring(text, "cat");
        printf("'cat' found at: %d\n", index); // Output: -1

        index = string_find_substring(text, "");
        printf("'' found at: %d\n", index); // Output: 0
        return 0;
    }
    ```

---

#### `string string_replace_char(const string s, char old_char, char new_char)`

Creates a new string with all occurrences of `old_char` replaced by `new_char`.

-   **Parameters**: `s`, `old_char`, `new_char`.
-   **Returns**: New allocated string. **Caller must `free()` or `free_string()`**. `NULL` on failure or if `s` is `NULL`.
-   **Complexity**: O(L) time, O(L) space.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"
    #include <stdlib.h>

    int main(void) {
        string text = "Colorless green ideas sleep furiously.";
        string replaced = string_replace_char(text, 'e', 'X');
        if(replaced) {
            printf("Original: %s\n", text);
            printf("Replaced: %s\n", replaced); // Output: ColorlXss grXXn idXas slXXp furiously.
            free_string(replaced);
        }
        return 0;
    }
    ```

---

#### `string string_to_lower(const string s)`

Creates a new string with all alphabetic characters converted to lowercase.

-   **Parameters**: `s`.
-   **Returns**: New allocated lowercase string. **Caller must `free()` or `free_string()`**. `NULL` on failure or if `s` is `NULL`.
-   **Complexity**: O(L) time, O(L) space.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"
    #include <stdlib.h>

    int main(void) {
        string text = "This Is Mixed CASE 123";
        string lower = string_to_lower(text);
        if (lower) {
             printf("Original: %s\n", text);
             printf("Lower:    %s\n", lower); // Output: this is mixed case 123
             free_string(lower);
        }
        return 0;
    }
    ```

---

#### `string string_to_upper(const string s)`

Creates a new string with all alphabetic characters converted to uppercase.

-   **Parameters**: `s`.
-   **Returns**: New allocated uppercase string. **Caller must `free()` or `free_string()`**. `NULL` on failure or if `s` is `NULL`.
-   **Complexity**: O(L) time, O(L) space.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"
    #include <stdlib.h>

    int main(void) {
        string text = "This Is Mixed CASE 123";
        string upper = string_to_upper(text);
        if (upper) {
             printf("Original: %s\n", text);
             printf("Upper:    %s\n", upper); // Output: THIS IS MIXED CASE 123
             free_string(upper);
        }
        return 0;
    }
    ```

---

#### `string* string_split(const string s, char delimiter, size_t *num_tokens)`

Splits a string into an array of tokens based on a delimiter.

-   **Parameters**: `s`, `delimiter`, `num_tokens` (pointer to store the count).
-   **Returns**:
    -   `string*` - A dynamically allocated array of dynamically allocated strings (tokens). **Caller must free using `free_string_array()`**.
    -   `NULL` if `s` or `num_tokens` is `NULL`, or memory allocation fails. `*num_tokens` is set to 0 on failure.
-   **Behavior**: Creates deep copies of the tokens.
-   **Complexity**: O(L) time, O(L) space.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"
    #include <stdlib.h>

    int main(void) {
        string data = "apple,banana,cherry,,grape";
        size_t count;
        string* parts = string_split(data, ',', &count);

        if (parts) {
            printf("Found %zu parts:\n", count);
            print_string_array(parts, count); // Output: ["apple", "banana", "cherry", "", "grape"]
            free_string_array(parts, count); // Use helper
        } else {
            printf("Split failed.\n");
        }
        return 0;
    }
    ```

---

#### `string string_join(const string *arr, size_t size, const string separator)`

Joins an array of strings into a single new string, separated by a specified separator.

-   **Parameters**: `arr` (array of strings), `size`, `separator` (can be `NULL` or `""` for no separator).
-   **Returns**: New allocated joined string. **Caller must `free()` or `free_string()`**. Returns `""` if `size` is 0. `NULL` on failure. Handles `NULL` strings in the input array gracefully.
-   **Complexity**: O(Total Length + n * Separator Length) time and space.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"
    #include <stdlib.h>

    int main(void) {
        string parts[] = {"path", "to", "your", "file.txt"};
        size_t n = sizeof(parts)/sizeof(parts[0]);
        string joined = string_join(parts, n, "/"); // Join with '/'
        if (joined) {
            printf("Joined: %s\n", joined); // Output: path/to/your/file.txt
            free_string(joined);
        }

        string parts2[] = {"item1", NULL, "item3"};
        size_t n2 = sizeof(parts2)/sizeof(parts2[0]);
        string joined2 = string_join(parts2, n2, ", "); // Join with ', '
         if (joined2) {
            printf("Joined2: %s\n", joined2); // Output: item1, item3
            free_string(joined2);
        }
        return 0;
    }
    ```

---

#### `bool string_starts_with(const string s, const string prefix)`

Checks if a string starts with a given prefix.

-   **Parameters**: `s`, `prefix`.
-   **Returns**: `true` if `s` starts with `prefix`, `false` otherwise. `true` if `prefix` is `""`.
-   **Complexity**: O(Length of prefix) time.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        string filename = "document.txt";
        if (string_starts_with(filename, "doc")) {
             printf("Starts with 'doc'.\n"); // Prints
        }
        if (!string_starts_with(filename, "image")) {
            printf("Does not start with 'image'.\n"); // Prints
        }
        if (string_starts_with(filename, "")) {
            printf("Starts with ''.\n"); // Prints
        }
        return 0;
    }
    ```

---

#### `bool string_ends_with(const string s, const string suffix)`

Checks if a string ends with a given suffix.

-   **Parameters**: `s`, `suffix`.
-   **Returns**: `true` if `s` ends with `suffix`, `false` otherwise. `true` if `suffix` is `""`.
-   **Complexity**: O(Length of suffix) time.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        string filename = "document.txt";
         if (string_ends_with(filename, ".txt")) {
             printf("Ends with '.txt'.\n"); // Prints
        }
        if (!string_ends_with(filename, ".png")) {
            printf("Does not end with '.png'.\n"); // Prints
        }
        if (string_ends_with(filename, "")) {
            printf("Ends with ''.\n"); // Prints
        }
        return 0;
    }
    ```

---

#### `float string_to_float(const string s, bool *success)`

Converts a string to a float, indicating success/failure.

-   **Parameters**: `s`, `success` (pointer to bool, set to `true` if conversion is valid, `false` otherwise).
-   **Returns**: The converted `float` value (0.0f on failure).
-   **Behavior**: Uses `strtof`, checks for full string consumption and range errors.
-   **Complexity**: O(L) time.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        bool ok;
        float val = string_to_float("3.14159", &ok);
        if (ok) printf("Converted float: %f\n", val); // Output: 3.141590
        else printf("Conversion failed.\n");

        val = string_to_float("-1.2e-3", &ok);
        if (ok) printf("Converted float: %g\n", val); // Output: -0.0012
        else printf("Conversion failed.\n");

        val = string_to_float("abc", &ok);
        if (!ok) printf("Conversion correctly failed for 'abc'.\n");

        val = string_to_float("123.45xyz", &ok);
         if (!ok) printf("Conversion correctly failed for '123.45xyz'.\n");

        return 0;
    }
    ```

---

#### `double string_to_double(const string s, bool *success)`

Converts a string to a double, indicating success/failure.

-   **Parameters**: `s`, `success` (pointer to bool).
-   **Returns**: The converted `double` value (0.0 on failure).
-   **Behavior**: Uses `strtod`, checks for full string consumption and range errors.
-   **Complexity**: O(L) time.
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"

    int main(void) {
        bool ok;
        double val = string_to_double("2.718281828459", &ok);
        if (ok) printf("Converted double: %.12f\n", val); // Output: 2.718281828459
        else printf("Conversion failed.\n");

        val = string_to_double(" -9.876E5 ", &ok);
        if (ok) printf("Converted double: %e\n", val); // Output: -9.876000e+05
        else printf("Conversion failed.\n");

        val = string_to_double("invalid", &ok);
        if (!ok) printf("Conversion correctly failed for 'invalid'.\n");

        return 0;
    }
    ```

---

### Memory Management Helpers

---

#### `void free_string(string s)`

Frees memory allocated for a single `string` (e.g., from `get_string`, `string_copy`, `string_trim`, etc.). Equivalent to `free(s)`.

-   **Parameters**: `s` (the string to free).
-   **Complexity**: O(1) (related to system `free`).

---

#### `void free_string_array(string *arr, size_t size)`

Frees memory allocated for an array of strings created by Aquant functions like `string_split`, `array_copy_string_array`, `array_concat_string`.

-   **Parameters**: `arr` (the array of strings), `size` (number of strings in the array).
-   **Behavior**: Frees each individual string in the array, then frees the array pointer itself. Handles `NULL` array pointer safely.
-   **Complexity**: O(n) calls to `free`.

---

### Utility Functions

---

#### `void initialize_random()`

Initializes the pseudo-random number generator using `srand(time(NULL))`. Call this **once** at the beginning of your program if you plan to use any `array_shuffle_*` or `get_random_*` functions.

-   **Complexity**: O(1).

---

#### `int get_random_int(int min, int max)`

Generates a pseudo-random integer within the specified range (inclusive).

-   **Parameters**: `min`, `max`. Handles `min > max`.
-   **Returns**: A random `int` between `min` and `max`.
-   **Requires**: `initialize_random()` must have been called previously.
-   **Complexity**: O(1).
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"
    #include <time.h> // For initialize_random()

    int main(void) {
        initialize_random(); // Seed once
        int dice_roll = get_random_int(1, 6);
        printf("Dice roll: %d\n", dice_roll); // Output: random number 1-6

        int temp = get_random_int(-10, 10);
        printf("Random temp: %d\n", temp); // Output: random number -10 to 10
        return 0;
    }
    ```

---

#### `float get_random_float(float min, float max)`

Generates a pseudo-random float within the specified range.

-   **Parameters**: `min`, `max`. Handles `min > max`.
-   **Returns**: A random `float` between `min` and `max`.
-   **Requires**: `initialize_random()`.
-   **Complexity**: O(1).
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"
    #include <time.h>

    int main(void) {
        initialize_random(); // Seed once
        float rand_val = get_random_float(0.0f, 1.0f);
        printf("Random float [0, 1]: %f\n", rand_val);

        float rand_percent = get_random_float(0.0f, 100.0f);
        printf("Random percentage: %.2f%%\n", rand_percent);
        return 0;
    }
    ```

---

#### `double get_random_double(double min, double max)`

Generates a pseudo-random double within the specified range.

-   **Parameters**: `min`, `max`. Handles `min > max`.
-   **Returns**: A random `double` between `min` and `max`.
-   **Requires**: `initialize_random()`.
-   **Complexity**: O(1).
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"
    #include <time.h>

    int main(void) {
        initialize_random(); // Seed once
        double rand_coord = get_random_double(-100.0, 100.0);
        printf("Random coordinate: %.6f\n", rand_coord);
        return 0;
    }
    ```
---

#### `void start_timer()`

Starts a simple timer using `clock()`.

-   **Complexity**: O(1).

---

#### `double stop_timer()`

Stops the timer started by `start_timer()` and returns the elapsed time.

-   **Returns**: `double` - Elapsed time in seconds.
-   **Complexity**: O(1).
-   **Example**:
    ```c
    #include <stdio.h>
    #include "aquant.h"
    #include <unistd.h> // For sleep() (example delay)

    int main(void) {
        start_timer();
        printf("Timer started...\n");
        // Simulate some work
        sleep(2); // Pause for ~2 seconds
        double elapsed = stop_timer();
        printf("Work finished.\n");
        printf("Elapsed time: %.3f seconds\n", elapsed); // Output: ~2.000 seconds
        return 0;
    }
    ```

---

## 🔧 Internal Implementation

The library uses a layered approach:

1.  **Input Foundation:** `get_string` provides robust dynamic memory allocation.
2.  **Input Validation:** Other `get_*` functions use `get_string` and add parsing (`strtol`, `strtof`, etc.), range checks, and validation logic.
3.  **Array Operations:** Simple traversals for basic functions (`min`, `max`, `sum`, `contains`, `count`, `reverse`, `print`). `qsort` is used for generic sorting. Hash tables (internal implementation) are used for efficient O(n) average time complexity in `array_has_pair_*` and `array_unique_int`. `memcpy` is used for efficient copying and concatenation. Fisher-Yates for shuffling.
4.  **String Operations:** Standard C library functions (`strlen`, `strcmp`, `strcpy`, `strcat`, `strchr`, `strstr`, `ctype.h` functions) are leveraged where appropriate. Memory is managed carefully for functions returning new strings or arrays of strings.

## 📋 Best Practices

1.  **Always `free_string()` or `free()`** strings returned by `get_string`, `get_string_non_empty`, `string_copy`, `string_trim`, `string_concat`, `string_substring`, `string_replace_char`, `string_to_lower`, `string_to_upper`, `string_join`.
2.  **Always `free()`** arrays returned by `array_copy_*`, `array_unique_int`, `array_concat_*` (for int, float, double).
3.  **Always `free_string_array()`** arrays returned by `string_split`, `array_copy_string_array`, `array_concat_string`.
4.  **Check boolean return values** for functions like `array_max`, `array_min`, `array_sum` before using the output pointer. Check the `success` flag for `string_to_float`/`string_to_double`.
5.  **Check for `NULL` return values** from functions that allocate memory.
6.  **Call `initialize_random()` once** at program start if using shuffle or random number functions.
7.  **Use appropriate prompts** for input functions.
8.  **Be mindful of `int` vs `size_t` vs `long long`** for sizes and indices, especially checking return values of `array_index_of_*` and `find_string`. Use epsilon comparisons (`FLOAT_EPSILON`, `DOUBLE_EPSILON`) when working with floats/doubles, especially in `array_contains_*`, `array_index_of_*`, `array_count_occurrence_*`.

## 🔍 Error Handling

-   **Input Functions:** Handle invalid formats, ranges, and empty inputs by reprompting. Return `NULL` or specific error values (like `NAN`) on memory allocation failure or immediate EOF.
-   **Memory Allocation:** Functions allocating memory return `NULL` on failure. Check these return values. Pair-checking and unique functions might return `false`/`NULL` if internal hash table allocation fails.
-   **Invalid Arguments:** Functions generally return `false`, `NULL`, `-1`, or `NAN`, or do nothing if passed invalid arguments (e.g., `NULL` pointers where not expected, zero size for operations requiring elements). String conversion functions (`string_to_float`, `string_to_double`) use the `success` boolean pointer to indicate failure.

## 📦 Dependencies

Aquant relies only on standard C libraries:

-   `<stdio.h>`: Input/output (`printf`, `fgetc`, `fflush`).
-   `<stdlib.h>`: Memory allocation (`malloc`, `realloc`, `free`), numeric conversion (`strtol`, `strtof`, `strtod`), `qsort`, `rand`, `srand`, `llabs`.
-   `<string.h>`: String operations (`strlen`, `strcmp`, `strcpy`, `strcat`, `strchr`, `strstr`, `memcpy`, `strncmp`).
-   `<ctype.h>`: Character classification (`isspace`, `isalpha`, `isdigit`, `isalnum`, `tolower`, `toupper`).
-   `<limits.h>`: Integer limits (`INT_MIN`, `INT_MAX`).
-   `<float.h>`: Floating-point characteristics (used implicitly via `math.h`).
-   `<errno.h>`: Error reporting for `strto*` functions (`errno`, `ERANGE`).
-   `<stdbool.h>`: Boolean type (`bool`, `true`, `false`).
-   `<math.h>`: Math functions (`fabs`, `NAN`, `HUGE_VALF`, `HUGE_VAL`). Required for float/double operations and `NAN`. Link with `-lm`.
-   `<stdint.h>`: Standard integer types (potentially used internally, good practice to include).
-   `<time.h>`: For seeding random number generator (`time`) and timer functions (`clock`).

## 🔄 Version History

###Version 1.3.1 {Testing Ongoing}


### Version 1.3.0
-   **Added Input Functions:**
    -   `get_int_range`: Get an integer within a specified min/max range.
    -   `get_string_non_empty`: Ensures the returned string is not empty.
-   **Expanded Integer Array Functions:**
    -   `array_contains_int`: Check if an integer exists in the array.
    -   `array_index_of_int`: Find the index of an integer in the array.
    -   `array_average`: Calculate the average of array elements.
    -   `array_count_occurrence`: Count how many times a value appears.
    -   `array_copy_int`: Create a duplicate of an integer array.
    -   `array_reverse_int`: Reverse the order of elements in place.
    *   `array_shuffle_int`: Randomly shuffle array elements.
    *   `array_unique_int`: Create a new array with unique elements.
    *   `array_concat_int`: Concatenate two integer arrays.
-   **Added Float Array Functions:** Comprehensive set including `max`, `min`, `sum`, `average`, `sort`, `contains`, `index_of`, `count_occurrence`, `copy`, `print`, `reverse`, `shuffle`, `concat`.
-   **Added Double Array Functions:** Comprehensive set including `max`, `min`, `sum`, `average`, `sort`, `contains`, `index_of`, `count_occurrence`, `copy`, `print`, `reverse`, `shuffle`, `concat`.
-   **Expanded String Array Functions:**
    -   Added `max`, `min`, `sort`, `contains`, `count_occurrence`, `copy` (deep), `print`, `reverse`, `shuffle`, `concat`.
    -   *(Note: `find_string` remains, signature adjusted for `string` type).*
-   **Added String Manipulation Functions:** A large suite including `copy`, `equals`, `trim`, `is_int`, `is_alpha`, `is_digit`, `is_alnum`, `is_space`, `is_empty`, `concat`, `substring`, `find_char`, `find_substring`, `replace_char`, `to_lower`, `to_upper`, `split`, `join`, `starts_with`, `ends_with`, `to_float`, `to_double`.
-   **Added Memory Management Helpers:**
    -   `free_string`: Companion to `get_string` and other string-allocating functions.
    *   `free_string_array`: Companion to functions allocating arrays of strings (like `string_split`).
-   **Added Utility Functions:**
    *   `initialize_random`: Seed the random number generator.
    *   `get_random_int`, `get_random_float`, `get_random_double`: Generate random numbers.
    *   `start_timer`, `stop_timer`: Basic performance timing.
-   **Code Enhancements:**
    -   Added `FLOAT_EPSILON` and `DOUBLE_EPSILON` for floating-point comparisons.
    -   Included necessary headers like `<math.h>`.
    -   Updated API reference with examples for all new functions.

### Version 1.2.0
-   **Added Array Sorting :** `sort_array` function (using `qsort`).
-   **Added String Array Search :** `find_string` function for linear search in `const string[]`.
-   **Added Array Printing :** `print_array` function for formatted output of `int[]`.
-   Added necessary dependencies like `<string.h>`.

### Version 1.1.0
-   **Added Array Utility Functions:** `array_max`, `array_min`, `array_sum`.
-   **Added Array Pair Check Functions:** `array_has_pair_sum`, `array_has_pair_product`, `array_has_pair_difference`.
-   **Optimized Pair Check Functions:** Implemented using an internal hash table for O(n) average time complexity.
-   Added `<stdbool.h>` and `<math.h>` dependencies (implicitly via internal hash needs).
-   Improved input function robustness slightly.

### Version 1.0.0
-   Initial release.
-   Core `get_*` input functions (`get_string`, `get_char`, `get_int`, `get_long`, `get_float`, `get_double`).
-   Input validation and retry logic.

## 📝 License

Aquant is released under the MIT License. See the LICENSE file for details.

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

1.  Fork the repository
2.  Create your feature branch (`git checkout -b feature/amazing-feature`)
3.  Commit your changes (`git commit -m 'Add some amazing feature'`)
4.  Push to the branch (`git push origin feature/amazing-feature`)
5.  Open a Pull Request

## 📞 Contact

Aayush Badola

<div align="center">
  <a href="https://github.com/AayushBadola">
    <img src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white" alt="GitHub"/>
  </a>&nbsp;&nbsp;
  <a href="https://www.linkedin.com/in/aayush-badola-0a7b2b343">
    <img src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white" alt="LinkedIn"/>
  </a>&nbsp;&nbsp;
  <a href="mailto:aayush.badola2@gmail.com">
    <img src="https://img.shields.io/badge/Email-D14836?style=for-the-badge&logo=gmail&logoColor=white" alt="Email"/>
  </a>
</div>

---

<div align="center">

Made with ❤️ by [Aayush Badola](https://github.com/AayushBadola)

</div>
