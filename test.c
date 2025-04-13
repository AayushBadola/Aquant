#include <stdio.h>
#include <stdlib.h> 
#include <limits.h> 
#include <float.h>  

#include "aquant.h" 

int main(void)
{
    printf("--- Starting Aquant Library Tests ---\n");
    printf("Instructions: Enter valid and invalid input when prompted to test.\n");
    printf("Press Ctrl+D (or Ctrl+Z on Windows) to simulate EOF if needed.\n\n");

  
    printf("Testing get_string:\n");
    string s = get_string("Enter a string: ");
    if (s != NULL)
    {
        printf("You entered: \"%s\"\n", s);
        free(s);
    }
    else
    {
        printf("get_string returned NULL\n");
    }
    printf("---\n\n");

   
    printf("Testing get_char:\n");
    char c = get_char("Enter a single character: ");
    printf("You entered: '%c'\n", c);
    printf("---\n\n");


    printf("Testing get_int:\n");
    int i = get_int("Enter an integer: ");
    printf("You entered: %i\n", i);
    printf("---\n\n");

   
    printf("Testing get_int with NULL prompt:\n");
    int i_null = get_int(NULL);
    printf("You entered (NULL prompt): %i\n", i_null);
    printf("---\n\n");

    
    printf("Testing get_long:\n");
    long l = get_long("Enter a long integer: ");
    printf("You entered: %li\n", l);
    printf("---\n\n");

    
    printf("Testing get_float:\n");
    float f = get_float("Enter a float: ");
    printf("You entered: %f\n", f);
    printf("---\n\n");

 
    printf("Testing get_double:\n");
    double d = get_double("Enter a double: ");
    printf("You entered: %lf\n", d);
    printf("---\n\n");

    printf("--- Aquant Library Tests Complete ---\n");
    return 0;
}
