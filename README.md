<div align="center">
  
# Aquant

### A Robust C Library for Handling User Input

<br>

<img src="https://img.shields.io/badge/Author-Aayush%20Badola-blue?style=for-the-badge&logo=github" alt="Author Badge"/>

<br>

<kbd><b><span style="color:#27ae60">Version 1.0.0</span></b></kbd>

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
  <a href="https://www.linkedin.com/in/aayushbadola">
    <img src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white" alt="LinkedIn"/>
  </a>
  <a href="https://mail.google.com/mail/?view=cm&fs=1&to=aayush.badola2@gmail.com" target="_blank">
    <img src="https://img.shields.io/badge/Email-D14836?style=for-the-badge&logo=gmail&logoColor=white" alt="Email"/>
  </a>
</div>

</div>

---

<div align="center">
  
### "Simplify user input handling in C with confidence"

</div>

## 📖 Overview

Aquant is a lightweight yet powerful C library designed to simplify and standardize the process of obtaining user input in console applications. Developed with a focus on robustness and ease of use, Aquant handles common input scenarios while providing comprehensive error checking and validation.

The library abstracts away the complexity and potential pitfalls of traditional input methods in C, offering a collection of intuitive functions that promote safe memory handling and reliable user interaction.

### Note - Its just an extention of C for using string functions you have to import <string.h>, <stdlib.h> etc "aquant" is only there to make "C - language" less complex 	   for beginners For more info check out Harvard's CS50. Its has the same use cases.
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

### Option 1: Direct Inclusion

The simplest way to use Aquant in your project is to include the source files directly:

1. Download both `aquant.c` and `aquant.h` from this repository
2. Place them in your project directory
3. Include the header in your source files:

```c
#include "aquant.h"
```

4. Compile your program with both files:

```bash
gcc your_program.c aquant.c -o your_program
```

### Option 2: Static Library

For larger projects, you might prefer building Aquant as a static library:

```bash
# Compile the library object file
gcc -c aquant.c -o aquant.o

# Create the static library archive
ar rcs libaquant.a aquant.o

# Compile your program with the library
gcc your_program.c -L. -laquant -o your_program
```

### Option 3: Using Make

If you have a Makefile for your project, add the following:

```makefile
CC = gcc
CFLAGS = -Wall -Wextra

your_program: your_program.c libaquant.a
	$(CC) $(CFLAGS) your_program.c -L. -laquant -o your_program

libaquant.a: aquant.o
	ar rcs libaquant.a aquant.o

aquant.o: aquant.c aquant.h
	$(CC) $(CFLAGS) -c aquant.c -o aquant.o

clean:
	rm -f *.o *.a your_program
```

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

## 🔧 Internal Implementation

The library uses a layered approach where more complex functions build upon simpler ones:

1. `get_string` forms the foundation, providing dynamic memory allocation for input
2. All other functions use `get_string` internally to read the input as text
3. Each numeric function performs appropriate parsing and validation:
   - `get_char` validates that exactly one character was entered
   - `get_int` and `get_long` use `strtol` with appropriate range checking
   - `get_float` and `get_double` use `strtof` and `strtod` respectively

This design ensures consistent behavior across functions and minimizes code duplication.

## 📋 Best Practices

When using the Aquant library, keep the following best practices in mind:

1. **Always check for NULL** when using `get_string`:
   ```c
   string input = get_string("Enter text: ");
   if (input == NULL) {
       // Handle error or EOF
       return 1;
   }
   ```

2. **Free string memory** when you're done with it:
   ```c
   string name = get_string("Name: ");
   // Use name...
   free(name);  // Prevent memory leaks
   ```

3. **Consider range limitations** of the various numeric types:
   - `int`: Typically -2,147,483,648 to 2,147,483,647
   - `long`: Potentially larger range depending on the platform
   - `float`: ~7 decimal digits of precision
   - `double`: ~15 decimal digits of precision

4. **Use appropriate prompts** to guide users:
   ```c
   // Good prompt with context and format
   float height = get_float("Enter height in meters (e.g., 1.75): ");
   
   // Not as helpful
   float height = get_float("Height: ");
   ```

## 🔍 Error Handling

Aquant handles most input errors internally by prompting for retry. However, you should still handle these cases:

1. **Memory allocation failure** in `get_string` (returns NULL)
2. **EOF encountered** in `get_string` (also returns NULL)
3. **Extremely large inputs** that could cause memory allocation issues

## 📦 Dependencies

Aquant relies only on standard C libraries:
- `<stdio.h>`: For input/output operations
- `<stdlib.h>`: For memory allocation and numeric conversion
- `<string.h>`: For string operations
- `<ctype.h>`: For character classification
- `<limits.h>`: For integer limits
- `<float.h>`: For floating-point limits
- `<errno.h>`: For error reporting

## 🔄 Version History

### Version 1.0.0 (Current)
- Initial release
- Complete implementation of all core input functions
- Comprehensive error handling and validation

## 📝 License

This project is licensed under the MIT License - see the LICENSE file for details.

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
  <a href="https://linkedin.com/in/yourlinkedin">
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
