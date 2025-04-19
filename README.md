<div align="center">
  
# Aquant

### A Robust C Library for Handling User Input

<br>

<img src="https://img.shields.io/badge/Author-Aayush%20Badola-blue?style=for-the-badge&logo=github" alt="Author Badge"/>

<br>

<kbd><b><span style="color:#27ae60">Current Version 1.2.0</span></b></kbd>
<br>
<kbd><b><span style="color:#FF474C">previous Version 1.1.0</span></b></kbd>
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

Aquant is a lightweight yet powerful C library designed to simplify and standardize the process of obtaining user input in console applications. Developed with a focus on robustness and ease of use, Aquant handles common input scenarios while providing comprehensive error checking and validation.

The library abstracts away the complexity and potential pitfalls of traditional input methods in C, offering a collection of intuitive functions that promote safe memory handling and reliable user interaction.

### Note - Aquant has been updated to 1.1.0 please remove the original 1.0.0 File and clone the updated file to use new arrary functions
<br>
<div align="center">
  
```
📋 Perfect for educational environments, command-line tools, and any C application
requiring secure and validated user input.
```

</div>

## ✨ Features

<table>
  <tr>
    <td>✅ <b>Memory-Safe String Handling</b></td>
    <td>Dynamic allocation that prevents buffer overflows and memory leaks</td>
  </tr>
  <tr>
    <td>✅ <b>Comprehensive Input Validation</b></td>
    <td>Automatic type checking and error handling for all input functions</td>
  </tr>
  <tr>
    <td>✅ <b>Type-Specific Input Functions</b></td>
    <td>Specialized functions for strings, characters, integers, and floating-point numbers</td>
  </tr>
  <tr>
    <td>✅ <b>Intelligent Retry Mechanism</b></td>
    <td>Automatic prompting for retries when invalid input is provided</td>
  </tr>
  <tr>
    <td>✅ <b>Multiple Numeric Type Support</b></td>
    <td>Functions for int, long, float, and double with proper range validation</td>
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

1. Download both `aquant.c` and `aquant.h` from this repository
2. Place them in your project directory
3. Include the header in your source files:

```bash
git clone https://github.com/AayushBadola/Aquant.git
```

```bash
cd Aquant
```

```c
#include "aquant.h"
```

4. Compile your program with both files:

```bash
gcc your_program.c aquant.c -o your_program -lm
```

5. Run your program:

```bash
./your_program
```
This will start your program and you will be able to run the C file you created.

<div align="center">
  
## 💡 Usage Examples

</div>

### Basic String Input

The `get_string` function provides a safe way to read text input of any length:

```c
#include <stdio.h>
#include "aquant.h"

int main(void) {
    string name = get_string("Enter your name: ");
    if (name != NULL) {
        printf("Hello, %s!\n", name);
        free(name);  // Remember to free the allocated memory
    }
    return 0;
}
```

### Reading and Validating Numbers

Aquant handles the parsing and validation of numeric input automatically:

```c
#include <stdio.h>
#include "aquant.h"

int main(void) {
    // Get an integer with automatic validation
    int age = get_int("Enter your age: ");
    printf("You are %d years old.\n", age);
    
    // Get a floating-point number for currency
    float price = get_float("Enter the price: $");
    printf("The price is $%.2f\n", price);
    
    // Get a long integer for larger values
    long population = get_long("Enter world population: ");
    printf("World population is %ld\n", population);
    
    // Get a precise double value
    double pi_value = get_double("Enter the value of pi: ");
    printf("Pi is approximately %.10f\n", pi_value);
    
    return 0;
}
```

### User Confirmation

Getting a single character input for confirmation prompts:

```c
#include <stdio.h>
#include "aquant.h"

int main(void) {
    printf("This will delete all files. Are you sure?\n");
    char answer = get_char("Continue? (y/n): ");
    
    if (answer == 'y' || answer == 'Y') {
        printf("Proceeding with deletion...\n");
        // deletion code would go here
    } else {
        printf("Operation cancelled.\n");
    }
    
    return 0;
}
```

### Building a Complete Form

Combining multiple input functions to create a data entry form:

```c
#include <stdio.h>
#include <stdlib.h>
#include "aquant.h"

typedef struct {
    string name;
    int age;
    float height;  // in meters
    char gender;   // 'M', 'F', or 'O' for other
} Person;

int main(void) {
    Person person;
    
    // Get all fields with proper validation
    person.name = get_string("Enter name: ");
    person.age = get_int("Enter age: ");
    person.height = get_float("Enter height (m): ");
    person.gender = get_char("Enter gender (M/F/O): ");
    
    // Display the information
    printf("\nPerson Information:\n");
    printf("------------------\n");
    printf("Name: %s\n", person.name);
    printf("Age: %d\n", person.age);
    printf("Height: %.2f m\n", person.height);
    printf("Gender: %c\n", person.gender);
    
    // Free the dynamically allocated string
    free(person.name);
    
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
```

### String Handling

#### `string get_string(const char *prompt)`

Reads a line of text from standard input with dynamic memory allocation.

- **Parameters**:
  - `prompt`: Text to display before reading input (can be NULL)
- **Returns**: 
  - Dynamically allocated string containing the input (remember to `free()` it)
  - `NULL` if memory allocation fails or EOF is encountered
- **Behavior**:
  - Automatically allocates memory as needed for input of any length
  - Dynamically resizes buffer while reading to accommodate arbitrary-length input
  - Trims the buffer to exact size before returning
  - Handles memory allocation errors gracefully
  - Returns NULL if memory allocation fails or if EOF is encountered with no input
- **Implementation Details**:
  - Uses a doubling strategy for efficient buffer growth
  - Reads character by character to avoid buffer overflow
  - Performs proper NULL-termination of the string
  - Shrinks the final allocation to the exact size needed
- **Example**:
  ```c
  string name = get_string("Enter your name: ");
  if (name != NULL) {
      printf("Hello, %s!\n", name);
      free(name);  // Don't forget to free when done
  } else {
      printf("Error reading input or EOF encountered.\n");
  }
  ```

### Character Input

#### `char get_char(const char *prompt)`

Reads a single character from standard input.

- **Parameters**:
  - `prompt`: Text to display before reading input (can be NULL)
- **Returns**: 
  - A single character
- **Behavior**:
  - Ensures only one character is read (not counting newline)
  - Prompts for retry if more than one character is entered
  - Uses "Retry: " as the default prompt for retries if original prompt is NULL
- **Implementation Details**:
  - Uses get_string internally to read input
  - Validates that exactly one character was entered
  - Automatically prompts for retry until valid input is received
- **Example**:
  ```c
  char direction = get_char("Move (N/E/S/W): ");
  switch (direction) {
      case 'N': case 'n': printf("Moving north\n"); break;
      case 'E': case 'e': printf("Moving east\n"); break;
      case 'S': case 's': printf("Moving south\n"); break;
      case 'W': case 'w': printf("Moving west\n"); break;
      default: printf("Invalid direction\n");
  }
  ```

### Integer Input

#### `int get_int(const char *prompt)`

Reads an integer from standard input with validation.

- **Parameters**:
  - `prompt`: Text to display before reading input (can be NULL)
- **Returns**:
  - A valid integer within the range of `int`
- **Behavior**:
  - Validates that input is a valid integer
  - Automatically prompts for retry if invalid input is provided
  - Checks for integer overflow/underflow
  - Ignores whitespace after the number
- **Implementation Details**:
  - Uses get_string internally to read input
  - Uses strtol for robust parsing with error detection
  - Checks errno for ERANGE to detect overflow/underflow
  - Verifies that the entire string was consumed (no trailing characters)
- **Example**:
  ```c
  int quantity = get_int("How many items? ");
  printf("You ordered %d items\n", quantity);
  ```

#### `long get_long(const char *prompt)`

Reads a long integer from standard input with validation.

- **Parameters**:
  - `prompt`: Text to display before reading input (can be NULL)
- **Returns**:
  - A valid long integer
- **Behavior**:
  - Validates that input is a valid long integer
  - Automatically prompts for retry if invalid input is provided
  - Checks for overflow/underflow
  - Ignores whitespace after the number
- **Implementation Details**:
  - Uses get_string internally to read input
  - Uses strtol for robust parsing with error detection
  - Checks errno for ERANGE to detect overflow/underflow
  - Verifies that the entire string was consumed (no trailing characters)
- **Example**:
  ```c
  long file_size = get_long("Enter file size in bytes: ");
  printf("File size: %ld bytes\n", file_size);
  ```

### Floating Point Input

#### `float get_float(const char *prompt)`

Reads a floating-point number from standard input with validation.

- **Parameters**:
  - `prompt`: Text to display before reading input (can be NULL)
- **Returns**:
  - A valid float
- **Behavior**:
  - Validates that input is a valid floating-point number
  - Automatically prompts for retry if invalid input is provided
  - Checks for overflow/underflow
  - Ignores whitespace after the number
- **Implementation Details**:
  - Uses get_string internally to read input
  - Uses strtof for robust parsing with error detection
  - Checks errno for ERANGE to detect overflow/underflow
  - Verifies that the entire string was consumed (no trailing characters)
- **Example**:
  ```c
  float temperature = get_float("Enter temperature in Celsius: ");
  printf("%.1f°C is %.1f°F\n", temperature, (temperature * 9/5) + 32);
  ```

#### `double get_double(const char *prompt)`

Reads a double-precision floating-point number from standard input with validation.

- **Parameters**:
  - `prompt`: Text to display before reading input (can be NULL)
- **Returns**:
  - A valid double
- **Behavior**:
  - Validates that input is a valid double-precision floating-point number
  - Automatically prompts for retry if invalid input is provided
  - Checks for overflow/underflow
  - Ignores whitespace after the number
- **Implementation Details**:
  - Uses get_string internally to read input
  - Uses strtod for robust parsing with error detection
  - Checks errno for ERANGE to detect overflow/underflow
  - Verifies that the entire string was consumed (no trailing characters)
- **Example**:
  ```c
  double pi = get_double("Enter the value of pi: ");
  printf("Area of circle with radius 2: %.10f\n", pi * 2 * 2);

  ```

  ### Array Utility Functions (v1.1.0)

These functions operate on integer arrays (`int[]`).

#### `array_max`

Finds the maximum value in an integer array.

-   **Parameters**:
    -   `arr`: `const int*` - Pointer to the integer array.
    -   `size`: `size_t` - Number of elements in the array.
    -   `max_val`: `int*` - Pointer to an `int` variable where the maximum value will be stored if found.
-   **Returns**:
    -   `bool`: `true` if the maximum value was found (array not NULL, size > 0, `max_val` not NULL).
    -   `bool`: `false` otherwise (input invalid).
-   **Behavior**:
    -   Iterates through the array to find the largest element.
    -   If successful, stores the maximum value found in the variable pointed to by `max_val`.
    -   Returns `false` if the array pointer `arr` is NULL, `size` is 0, or the output pointer `max_val` is NULL.
-   **Implementation Details**:
    -   Performs a single pass through the array.
    -   Time Complexity: O(n)
    -   Space Complexity: O(1)
-   **Example**:
    ```c
    int nums[] = {5, -2, 10, 8};
    int max_result;
    if (array_max(nums, 4, &max_result)) {
        printf("Max: %d\n", max_result); // Output: Max: 10
    } else {
        printf("Could not find maximum.\n");
    }
    ```

---

#### `array_min`

Finds the minimum value in an integer array.

-   **Parameters**:
    -   `arr`: `const int*` - Pointer to the integer array.
    -   `size`: `size_t` - Number of elements in the array.
    -   `min_val`: `int*` - Pointer to an `int` variable where the minimum value will be stored if found.
-   **Returns**:
    -   `bool`: `true` if the minimum value was found (array not NULL, size > 0, `min_val` not NULL).
    -   `bool`: `false` otherwise (input invalid).
-   **Behavior**:
    -   Iterates through the array to find the smallest element.
    -   If successful, stores the minimum value found in the variable pointed to by `min_val`.
    -   Returns `false` if the array pointer `arr` is NULL, `size` is 0, or the output pointer `min_val` is NULL.
-   **Implementation Details**:
    -   Performs a single pass through the array.
    -   Time Complexity: O(n)
    -   Space Complexity: O(1)
-   **Example**:
    ```c
    int nums[] = {5, -2, 10, 8};
    int min_result;
    if (array_min(nums, 4, &min_result)) {
        printf("Min: %d\n", min_result); // Output: Min: -2
    } else {
        printf("Could not find minimum.\n");
    }
    ```

---

#### `array_sum`

Calculates the sum of all elements in an integer array.

-   **Parameters**:
    -   `arr`: `const int*` - Pointer to the integer array.
    -   `size`: `size_t` - Number of elements in the array.
    -   `sum`: `long long*` - Pointer to a `long long` variable where the sum will be stored.
-   **Returns**:
    -   `bool`: `true` if the sum was calculated (includes sum = 0 for empty arrays).
    -   `bool`: `false` if `sum` is NULL, or if `arr` is NULL *and* `size` > 0 (indicates invalid state).
-   **Behavior**:
    -   Iterates through the array, adding each element to an accumulator.
    -   If successful, stores the final sum in the variable pointed to by `sum`.
    -   Uses `long long` for the sum to reduce the risk of integer overflow.
    -   Treats the sum of an empty array (size = 0) as 0 and returns `true`.
-   **Implementation Details**:
    -   Performs a single pass through the array.
    -   Time Complexity: O(n)
    -   Space Complexity: O(1) (excluding the space for the `long long` sum variable passed in).
-   **Example**:
    ```c
    int nums[] = {5, -2, 10, 8};
    long long sum_result;
    if (array_sum(nums, 4, &sum_result)) {
        printf("Sum: %lld\n", sum_result); // Output: Sum: 21
    } else {
        printf("Could not calculate sum.\n");
    }
    ```

---

#### `array_has_pair_sum`

Checks if any *distinct* pair of elements in the array sums up to the target value.

-   **Parameters**:
    -   `arr`: `const int*` - Pointer to the integer array.
    -   `size`: `size_t` - Number of elements in the array.
    -   `target`: `int` - The target sum value.
-   **Returns**:
    -   `bool`: `true` if a pair `(arr[i], arr[j])` exists where `i != j` and `arr[i] + arr[j] == target`.
    -   `bool`: `false` otherwise, or if `size < 2`, or if internal memory allocation fails.
-   **Behavior**:
    -   Determines if two different elements in the array add up to the `target`.
    -   Handles duplicate numbers within the array correctly (e.g., `[5, 5]` sums to `10`).
-   **Implementation Details**:
    -   Uses an internal hash table for efficient lookups.
    -   Iterates through the array once. For each element `x`, it checks if the complement (`target - x`) exists in the hash table. If not, `x` is added to the table.
    -   Handles potential integer overflow when calculating the complement.
    -   Time Complexity: O(n) average (due to hash table lookups/insertions). O(n) worst case if hash collisions are pathologically bad, but highly unlikely with a reasonable hash function.
    -   Space Complexity: O(n) for the internal hash table.
-   **Example**:
    ```c
    int nums[] = {2, 7, 11, 15, 7};
    bool found_9 = array_has_pair_sum(nums, 5, 9);  // Checks for 2 + 7
    bool found_14 = array_has_pair_sum(nums, 5, 14); // Checks for 7 + 7
    printf("Pair summing to 9 found: %s\n", found_9 ? "true" : "false");   // Output: true
    printf("Pair summing to 14 found: %s\n", found_14 ? "true" : "false"); // Output: true
    ```

---

#### `array_has_pair_product`

Checks if any *distinct* pair of elements in the array multiplies to the target value.

-   **Parameters**:
    -   `arr`: `const int*` - Pointer to the integer array.
    -   `size`: `size_t` - Number of elements in the array.
    -   `target`: `int` - The target product value.
-   **Returns**:
    -   `bool`: `true` if a pair `(arr[i], arr[j])` exists where `i != j` and `arr[i] * arr[j] == target`.
    -   `bool`: `false` otherwise, or if `size < 2`, or if internal memory allocation fails.
-   **Behavior**:
    -   Determines if two different elements in the array multiply to the `target`.
    -   Handles zero correctly: returns `true` for target 0 if the array contains at least one zero and one non-zero, or at least two zeros.
    -   Handles duplicate numbers correctly (e.g., `[6, 6]` has product `36`).
-   **Implementation Details**:
    -   Uses an internal hash table for efficient lookups.
    -   Handles zero elements separately first. Then populates the hash table with non-zero elements.
    -   Iterates through the non-zero elements `x`, checking if `target / x` (provided `target` is divisible by `x`) exists in the hash table.
    -   Performs internal multiplication checks using `long long` to reduce intermediate overflow risk.
    -   Time Complexity: O(n) average.
    -   Space Complexity: O(n) for the internal hash table.
-   **Example**:
    ```c
    int nums[] = {3, 5, -2, 8, 5};
    bool found_neg_10 = array_has_pair_product(nums, 5, -10); // Checks for 5 * -2
    bool found_25 = array_has_pair_product(nums, 5, 25);     // Checks for 5 * 5
    printf("Pair with product -10 found: %s\n", found_neg_10 ? "true" : "false"); // Output: true
    printf("Pair with product 25 found: %s\n", found_25 ? "true" : "false");     // Output: true
    ```

---

#### `array_has_pair_difference`

Checks if any pair of elements (order matters, `a - b`) has a difference equal to the target value.

-   **Parameters**:
    -   `arr`: `const int*` - Pointer to the integer array.
    -   `size`: `size_t` - Number of elements in the array.
    -   `target`: `int` - The target difference value (`arr[i] - arr[j] == target`).
-   **Returns**:
    -   `bool`: `true` if a pair `(arr[i], arr[j])` exists where `arr[i] - arr[j] == target`. (`i` can be equal to `j` if `target` is 0).
    -   `bool`: `false` otherwise, or if internal memory allocation fails.
-   **Behavior**:
    -   Determines if any element subtracted from another results in the `target`.
    -   `array_has_pair_difference(arr, size, 0)` will return `true` if the array contains duplicate elements, or if the array is non-empty (since `x - x = 0`). *Correction*: The code iterates and adds to the hash table before checking, so `x - x = 0` will only be found if `x` appears at least twice.
-   **Implementation Details**:
    -   Uses an internal hash table for efficient lookups.
    -   Iterates through the array once. For each element `x`, it checks if `x - target` or `x + target` already exists in the hash table built so far. If not, `x` is added to the table.
    -   Handles potential integer overflows when calculating the required complements (`x - target`, `x + target`).
    -   Time Complexity: O(n) average.
    -   Space Complexity: O(n) for the internal hash table.
-   **Example**:
    ```c
    int nums[] = {10, 7, 15, 5, 7};
    bool found_3 = array_has_pair_difference(nums, 5, 3);  // Checks for 10 - 7
    bool found_neg_5 = array_has_pair_difference(nums, 5, -5); // Checks for 10 - 15
    bool found_0 = array_has_pair_difference(nums, 5, 0); // Checks for 7 - 7
    printf("Pair with difference 3 found: %s\n", found_3 ? "true" : "false");     // Output: true
    printf("Pair with difference -5 found: %s\n", found_neg_5 ? "true" : "false"); // Output: true
    printf("Pair with difference 0 found: %s\n", found_0 ? "true" : "false");     // Output: true
    ```
### Array Utility Functions (v1.2.0)
#### `sort_array`
Sorts an integer array in ascending order using Counting Sort (O(n) time complexity). Modifies the array in-place.

- **Parameters**:
  - `arr: int[]` : The integer array to sort.
  - `size: size_t` : Number of elements in the array.

- **Returns**:
  - `void`
- **Behaviour**:
  - Sorts the array `arr` in non-decreasing order.
  - Handles empty arrays or arrays with one element gracefully (returns immediately).
  - Prints an error to `stderr` and returns if memory allocation for internal buffers fails or if the range of values is too large for `size_t` .
- **Implementation Details**:
  - Uses Counting Sort algorithm.
    Requires auxiliary space proportional to the range of values (`max_val - min_val + 1`, simplified to `max_val + 1` for non-negatives) and the size of the array.
  - Time Complexity: O(n + k), where n is the number of elements and k is the range of input values. Since k is often related to n or bounded, it's considered O(n) under typical assumptions for Counting Sort.
  - Space Complexity: O(n + k).
- **Example**:
```c
int data[] = {5, 2, 8, 2, 1, 9, 4, 0};
size_t n = sizeof(data) / sizeof(data[0]);
printf("Before sort: "); print_array(data, n);
sort_array(data, n); // Use the renamed function
printf("After sort:  "); print_array(data, n); // Output: [0, 1, 2, 2, 4, 5, 8, 9]
```
#### `find_string`
Finds the first occurrence of a specific string within an array of strings.
- **Parameters**:
  - `strings: const char*[]` : An array of C strings (pointers to characters).

  - `size: size_t` :  Number of elements (strings) in the strings array.

  - `target_string: const char*` : The string to search for.
- **Returns**:
  -  `int` : The index of the first matching string if found.
  - `int : -1` :  if the string is not found, or if strings or `target_string` is `NULL`.
- **Behaviour**:
  - Performs a linear search through the `strings` array.
  - Compares each string in the array with `target_string` using `strcmp`.
  - Safely handles `NULL` pointers within the `strings` array (they are skipped).
- **Implementation Details**:
  - Uses `strcmp` for string comparison.
  - Requires `<string.h>` to be included (which aquant.c does).
  - Time Complexity: `O(n * m)`, where n is the number of strings in the array and m is the average length of the strings (due to strcmp within the loop). Often simplified to `O(n)` if string length is considered bounded or small relative to n.
  - Space Complexity: `O(1)`.
- **Example**:
```c
const char *items[] = {"Apple", "Banana", "Cherry", "Apple"};
int index = find_string(items, 4, "Apple"); // Use the renamed function
printf("First 'Apple' found at index: %d\n", index); // Output: 0

index = find_string(items, 4, "Durian");
printf("'Durian' found at index: %d\n", index); // Output: -1
```
#### `print_array`
Prints the elements of an integer array to standard output in a formatted way.
- **Parameters**:
  - `arr: const int[]` : The integer array to print.
  - `size: size_t` : Number of elements in the array.
- **Return**:
  - `void`
- **Behaviour**:
  - Prints the array elements enclosed in square brackets `[]`.
  - Elements are separated by a comma and a space `,` .
  - Handles `NULL` arrays by printing `[]` .
  - Handles empty arrays (size = 0) by printing  `[]` .
  - Prints a newline character `\n` after the closing bracket.

- **Implementation Details**:
  - Uses printf for output.
  - Iterates through the array.
  - Time Complexity: O(n)
  - Space Complexity: O(1)

- **Example**:
```c
int values[] = {10, 20, 30};
print_array(values, 3); // Output: [10, 20, 30]

int empty_arr[] = {};
print_array(empty_arr, 0); // Output: []

print_array(NULL, 5); // Output: []
```



## 🔧 Internal Implementation

The library uses a layered approach for input and optimized algorithms for array operations:

1.  **Input Foundation:** `get_string` forms the base, providing robust dynamic memory allocation for reading lines from standard input.
2.  **Input Validation:** All other `get_*` functions utilize `get_string` internally, followed by specific parsing and validation logic:
    *   `get_char` validates that exactly one character was entered.
    *   `get_int` and `get_long` use `strtol` with appropriate range checking and ensure no trailing non-whitespace characters.
    *   `get_float` and `get_double` use `strtof` and `strtod` respectively, also checking ranges and for trailing characters.
3.  **Array Operations:**
    *   `array_max`, `array_min`, `array_sum`, `find_string`, `print_array` perform simple O(n) traversals(though `find_string` involves string comparisons).
    *   `array_has_pair_sum`, `array_has_pair_product`, `array_has_pair_difference` use an **internal hash table** to achieve O(n) average time complexity for checking pair conditions, requiring O(n) auxiliary space.
    * `sort_array` uses Counting Sort for O(n+k) time complexity (often considered O(n)) for sorting non-negative integers, requiring O(n+k) auxiliary space.




## 📋 Best Practices

When using the Aquant library, keep the following best practices in mind:

1.  **Always check for NULL** when using `get_string`:
    ```c
    string input = get_string("Enter text: ");
    if (input == NULL) {
        // Handle memory allocation error or EOF
        fprintf(stderr, "Error reading input or EOF.\n");
        return 1;
    }
    // ... use input ...
    ```

2.  **Free string memory** obtained from `get_string` when you're done:
    ```c
    string name = get_string("Name: ");
    if (name != NULL) {
        // Use name...
        printf("Processing %s\n", name);
        free(name); // Prevent memory leaks
    }
    ```

3.  **Check boolean return values** for `array_max`, `array_min`, `array_sum` before using the output pointer:
    ```c
    int arr[] = {1, 2, 3};
    int max_val;
    if (array_max(arr, 3, &max_val)) {
        // OK to use max_val
        printf("Max is %d\n", max_val);
    } else {
        // Handle error (e.g., invalid array pointer, size 0, or null output pointer)
        fprintf(stderr, "Failed to find maximum.\n");
    }
    ```

4.  **Consider range limitations** of the various numeric types (`int`, `long`, `float`, `double`) when choosing which `get_*` function to use.

5.  **Use appropriate prompts** to guide users clearly.

## 🔍 Error Handling

Aquant handles most standard input errors internally by prompting the user to retry. However, your calling code should still be prepared for:

1.  **Memory allocation failure** in `get_string` (returns `NULL`).
2.  **EOF encountered** at the start of input in `get_string` (returns `NULL`).
3.  **Internal memory allocation failure** within the array pair-checking functions (`array_has_pair_*`). These functions might return `false` prematurely if `malloc`/`calloc` fails while building their internal hash table. Robust applications might need alternative strategies if this is a critical concern, although it's less common than input errors.
4.  **Invalid function arguments** passed to array functions (e.g., `NULL` array pointer with `size > 0`, `NULL` output pointers for `array_max/min/sum`). These are checked and result in a `false` return value.

## 📦 Dependencies

Aquant relies only on standard C libraries:

-   `<stdio.h>`: For input/output operations (`printf`, `fgetc`, `fflush`).
-   `<stdlib.h>`: For memory allocation (`malloc`, `realloc`, `free`), numeric conversion (`strtol`, `strtof`, `strtod`), and `llabs`.
-   `<string.h>`: For string operations (not directly used in the current functions, but common in C).
-   `<ctype.h>`: For character classification (`isspace`).
-   `<limits.h>`: For integer limits (`INT_MIN`, `INT_MAX`).
-   `<float.h>`: For floating-point limits (not explicitly used for checking but relevant).
-   `<errno.h>`: For error reporting from `strto*` functions (`errno`, `ERANGE`).
-   `<stdbool.h>`: For the `bool`, `true`, `false` types and values.
-   `<math.h>`: For `llabs` (long long absolute value) used in the internal hash function.

## 🔄 Version History
### Version 1.2.0
- **Added Array Sorting :** `sort_array` function implementing Counting Sort for non-negative integers (O(n)).
- **Added String Array Search :** `find_string` function for linear search in `const char*[]` .
- **Added Array Printing :** `print_array` function for formatted output of `int[]` .
- Added <stdint.h> dependency for SIZE_MAX.






### Version 1.1.0
-   **Added Array Utility Functions:** `array_max`, `array_min`, `array_sum`.
-   **Added Array Pair Check Functions:** `array_has_pair_sum`, `array_has_pair_product`, `array_has_pair_difference`.
-   **Optimized Pair Check Functions:** Implemented pair check functions using an internal hash table for O(n) average time complexity.
-   Added `<stdbool.h>` and `<math.h>` dependencies.
-   Improved input function robustness slightly (e.g., `fflush`, more specific error messages).

### Version 1.0.0
-   Initial release.
-   Complete implementation of all core `get_*` input functions (`get_string`, `get_char`, `get_int`, `get_long`, `get_float`, `get_double`).
-   Input validation and retry logic.

## 📝 License
Aquant is licensed under an MIT-based license for personal, non-commercial use only.
Commercial or enterprise usage is strictly prohibited without obtaining a separate commercial license.
- For details, see [LICENSE](./LICENSE.md)
- For commercial licensing terms, see [COMMERCIAL_LICENSE.md](./COMMERCIAL_LICENSE.md)

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add some amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## 📞 Contact

Aayush Badola

<div align="center">
  <a href="https://github.com/AayushBadola">
    <img src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white" alt="GitHub"/>
  </a>&nbsp;&nbsp;
  <a href="https://www.linkedin.com/in/aayush-badola-0a7b2b343">
    <img src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white" alt="LinkedIn"/>
  </a>&nbsp;&nbsp;
  <a href="mailto:youremail@example.com">
    <img src="https://img.shields.io/badge/Email-D14836?style=for-the-badge&logo=gmail&logoColor=white" alt="Email"/>
  </a>
</div>

---

<div align="center">
  
Made with ❤️ by [Aayush Badola](https://github.com/AayushBadola)

</div>

