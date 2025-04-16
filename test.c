#include <stdio.h>
#include <stdlib.h>
#include <limits.h>  // For INT_MAX/MIN example values
#include "aquant.h"  // Include your library header

// Helper function to print an array for clarity
void print_array(const char* name, const int *arr, size_t size) {
    printf("%s: [", name);
    if (arr == NULL) {
        printf("NULL");
    } else if (size == 0) {
        printf("empty");
    } else {
        for (size_t i = 0; i < size; ++i) {
            printf("%d%s", arr[i], (i == size - 1) ? "" : ", ");
        }
    }
    printf("] (size %zu)\n", size);
}


int main(void)
{
    printf("--- Starting Aquant Library Test Suite (v1.1.0 features) ---\n\n");

    //-------------------------------------------------------------------------
    // Section 1: Testing Input Functions (Interactive)
    //-------------------------------------------------------------------------
    printf("=== Section 1: Testing Input Functions (Requires User Input) ===\n");
    printf("Instructions: Enter valid and invalid input when prompted.\n");
    printf("              Try empty input (just Enter), text for numbers, etc.\n");
    printf("              Press Ctrl+D (Unix/macOS) or Ctrl+Z then Enter (Windows) to simulate EOF.\n\n");

    printf("--- Testing get_string ---\n");
    string s = get_string("Enter any string (e.g., 'hello world', empty, long): ");
    if (s != NULL) {
        printf("get_string returned: \"%s\"\n", s);
        free(s); // IMPORTANT: Free the returned string
    } else {
        printf("get_string returned NULL (EOF or memory error)\n");
    }
    printf("---\n\n");

    printf("--- Testing get_char ---\n");
    printf("Try entering: single char ('a'), multiple ('abc'), empty (Enter)\n");
    char c = get_char("Enter exactly one character: ");
    printf("get_char returned: '%c' (ASCII: %d)\n", c, c);
    printf("---\n\n");

    printf("--- Testing get_int ---\n");
    printf("Try entering: valid int ('123', '-5'), invalid ('abc', '1.5', '10x'), out of range ('9999999999'), empty\n");
    int i = get_int("Enter an integer: ");
    printf("get_int returned: %d\n", i);
    printf("---\n\n");

    printf("--- Testing get_long ---\n");
    printf("Try entering: valid long ('-1234567890'), huge number, invalid ('xyz')\n");
    long l = get_long("Enter a long integer: ");
    printf("get_long returned: %ld\n", l);
    printf("---\n\n");

    printf("--- Testing get_float ---\n");
    printf("Try entering: valid float ('3.14', '-1e-5'), invalid ('pi')\n");
    float f = get_float("Enter a float: ");
    printf("get_float returned: %f\n", f);
    printf("---\n\n");

    printf("--- Testing get_double ---\n");
    printf("Try entering: valid double ('-9.87654321e+10'), invalid ('--1.0')\n");
    double d = get_double("Enter a double: ");
    printf("get_double returned: %lf\n", d);
    printf("---\n\n");

    printf("--- Testing NULL prompt fallback ---\n");
    printf("(Will show 'Retry: ' if you enter invalid input first)\n");
    int i_null = get_int(NULL); // Prompt should be NULL initially
    printf("get_int(NULL) returned: %i\n", i_null);
    printf("---\n\n");


    //-------------------------------------------------------------------------
    // Section 2: Testing Array Utility Functions (Automated)
    //-------------------------------------------------------------------------
    printf("=== Section 2: Testing Array Functions ===\n\n");

    // Define various test arrays
    int arr1[] = {5, -2, 10, 0, 8, 5, -3, 15}; // General mix
    size_t size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {100}; // Single element
    size_t size2 = sizeof(arr2) / sizeof(arr2[0]);

    int arr3[] = {-10, -5, -20, -15}; // All negative
    size_t size3 = sizeof(arr3) / sizeof(arr3[0]);

    int arr4[] = {6, 6, 6}; // Duplicates only
    size_t size4 = sizeof(arr4) / sizeof(arr4[0]);

    int arr5[] = {INT_MAX, 1, -5, INT_MIN, 2}; // Edge integer values
    size_t size5 = sizeof(arr5) / sizeof(arr5[0]);

    int arr_empty[] = {}; // Empty array
    size_t size_empty = 0;

    int* arr_null = NULL; // Null pointer array

    // Print arrays being used
    print_array("arr1 (General)", arr1, size1);
    print_array("arr2 (Single)", arr2, size2);
    print_array("arr3 (Negative)", arr3, size3);
    print_array("arr4 (Duplicates)", arr4, size4);
    print_array("arr5 (Edges)", arr5, size5);
    print_array("arr_empty", arr_empty, size_empty);
    print_array("arr_null", arr_null, size1); // Use size1 to test invalid combo
    printf("\n");


    // --- Test array_max ---
    printf("--- Testing array_max ---\n");
    int max_val;
    if (array_max(arr1, size1, &max_val)) printf("  arr1: Max = %d (Expected: 15)\n", max_val); else printf("  arr1: Max FAILED\n");
    if (array_max(arr2, size2, &max_val)) printf("  arr2: Max = %d (Expected: 100)\n", max_val); else printf("  arr2: Max FAILED\n");
    if (array_max(arr3, size3, &max_val)) printf("  arr3: Max = %d (Expected: -5)\n", max_val); else printf("  arr3: Max FAILED\n");
    if (array_max(arr5, size5, &max_val)) printf("  arr5: Max = %d (Expected: %d)\n", max_val, INT_MAX); else printf("  arr5: Max FAILED\n");
    // Edge cases
    if (array_max(arr_empty, size_empty, &max_val)) printf("  arr_empty: Max FAILED (Should Fail)\n"); else printf("  arr_empty: Max returned false (Expected)\n");
    if (array_max(arr_null, size1, &max_val)) printf("  arr_null: Max FAILED (Should Fail)\n"); else printf("  arr_null: Max returned false (Expected)\n");
    if (array_max(arr1, size1, NULL)) printf("  arr1 (NULL out): Max FAILED (Should Fail)\n"); else printf("  arr1 (NULL out): Max returned false (Expected)\n");
    printf("---\n\n");


    // --- Test array_min ---
    printf("--- Testing array_min ---\n");
    int min_val;
    if (array_min(arr1, size1, &min_val)) printf("  arr1: Min = %d (Expected: -3)\n", min_val); else printf("  arr1: Min FAILED\n");
    if (array_min(arr2, size2, &min_val)) printf("  arr2: Min = %d (Expected: 100)\n", min_val); else printf("  arr2: Min FAILED\n");
    if (array_min(arr3, size3, &min_val)) printf("  arr3: Min = %d (Expected: -20)\n", min_val); else printf("  arr3: Min FAILED\n");
    if (array_min(arr5, size5, &min_val)) printf("  arr5: Min = %d (Expected: %d)\n", min_val, INT_MIN); else printf("  arr5: Min FAILED\n");
    // Edge cases
    if (array_min(arr_empty, size_empty, &min_val)) printf("  arr_empty: Min FAILED (Should Fail)\n"); else printf("  arr_empty: Min returned false (Expected)\n");
    if (array_min(arr_null, size1, &min_val)) printf("  arr_null: Min FAILED (Should Fail)\n"); else printf("  arr_null: Min returned false (Expected)\n");
    if (array_min(arr1, size1, NULL)) printf("  arr1 (NULL out): Min FAILED (Should Fail)\n"); else printf("  arr1 (NULL out): Min returned false (Expected)\n");
    printf("---\n\n");


    // --- Test array_sum ---
    printf("--- Testing array_sum ---\n");
    long long sum_val;
    // Expected arr1 sum: 5 - 2 + 10 + 0 + 8 + 5 - 3 + 15 = 38
    if (array_sum(arr1, size1, &sum_val)) printf("  arr1: Sum = %lld (Expected: 38)\n", sum_val); else printf("  arr1: Sum FAILED\n");
    // Expected arr3 sum: -10 - 5 - 20 - 15 = -50
    if (array_sum(arr3, size3, &sum_val)) printf("  arr3: Sum = %lld (Expected: -50)\n", sum_val); else printf("  arr3: Sum FAILED\n");
    // Expected arr5 sum: INT_MAX + 1 - 5 + INT_MIN + 2 = -2 (might wrap without long long)
    if (array_sum(arr5, size5, &sum_val)) printf("  arr5: Sum = %lld (Expected: -2)\n", sum_val); else printf("  arr5: Sum FAILED\n");
    // Edge cases
    if (array_sum(arr_empty, size_empty, &sum_val)) printf("  arr_empty: Sum = %lld (Expected: 0)\n", sum_val); else printf("  arr_empty: Sum FAILED (Should succeed!)\n");
    if (array_sum(arr_null, size1, &sum_val)) printf("  arr_null: Sum FAILED (Should Fail)\n"); else printf("  arr_null: Sum returned false (Expected)\n");
    if (array_sum(arr1, size1, NULL)) printf("  arr1 (NULL out): Sum FAILED (Should Fail)\n"); else printf("  arr1 (NULL out): Sum returned false (Expected)\n");
    printf("---\n\n");


    // --- Test array_has_pair_sum (O(n) version) ---
    printf("--- Testing array_has_pair_sum ---\n");
    printf("  arr1: Has pair sum 8? (10 + -2): %s (Expected: true)\n", array_has_pair_sum(arr1, size1, 8) ? "true" : "false");
    printf("  arr1: Has pair sum 10? (5 + 5): %s (Expected: true)\n", array_has_pair_sum(arr1, size1, 10) ? "true" : "false");
    printf("  arr1: Has pair sum -5? (-2 + -3): %s (Expected: true)\n", array_has_pair_sum(arr1, size1, -5) ? "true" : "false");
    printf("  arr1: Has pair sum 100? (No): %s (Expected: false)\n", array_has_pair_sum(arr1, size1, 100) ? "true" : "false");
    printf("  arr4: Has pair sum 12? (6 + 6): %s (Expected: true)\n", array_has_pair_sum(arr4, size4, 12) ? "true" : "false");
    printf("  arr4: Has pair sum 10? (No): %s (Expected: false)\n", array_has_pair_sum(arr4, size4, 10) ? "true" : "false");
    printf("  arr5: Has pair sum %d? (INT_MAX + -5): %s (Expected: true)\n", INT_MAX - 5 , array_has_pair_sum(arr5, size5, INT_MAX - 5) ? "true" : "false");
    printf("  arr5: Has pair sum 0? (No distinct pair): %s (Expected: false)\n", array_has_pair_sum(arr5, size5, 0) ? "true" : "false");
    
    // Edge cases
    printf("  arr2: Has pair sum 200? (size<2): %s (Expected: false)\n", array_has_pair_sum(arr2, size2, 200) ? "true" : "false");
    printf("  arr_empty: Has pair sum 5? (empty): %s (Expected: false)\n", array_has_pair_sum(arr_empty, size_empty, 5) ? "true" : "false");
    printf("  arr_null: Has pair sum 5? (null): %s (Expected: false)\n", array_has_pair_sum(arr_null, size1, 5) ? "true" : "false");
    printf("---\n\n");


    // --- Test array_has_pair_product (O(n) version) ---
    printf("--- Testing array_has_pair_product ---\n");
    printf("  arr1: Has pair product 0? (0 * x): %s (Expected: true)\n", array_has_pair_product(arr1, size1, 0) ? "true" : "false");
    printf("  arr1: Has pair product -20? (10 * -2): %s (Expected: true)\n", array_has_pair_product(arr1, size1, -20) ? "true" : "false");
    printf("  arr1: Has pair product 25? (5 * 5): %s (Expected: true)\n", array_has_pair_product(arr1, size1, 25) ? "true" : "false");
    printf("  arr1: Has pair product -15? (5 * -3): %s (Expected: true)\n", array_has_pair_product(arr1, size1, -15) ? "true" : "false");
    printf("  arr1: Has pair product 1000? (No): %s (Expected: false)\n", array_has_pair_product(arr1, size1, 1000) ? "true" : "false");
    printf("  arr3: Has pair product 50? (-10 * -5): %s (Expected: true)\n", array_has_pair_product(arr3, size3, 50) ? "true" : "false");
    printf("  arr4: Has pair product 36? (6 * 6): %s (Expected: true)\n", array_has_pair_product(arr4, size4, 36) ? "true" : "false");
    printf("  arr4: Has pair product 12? (No): %s (Expected: false)\n", array_has_pair_product(arr4, size4, 12) ? "true" : "false");
    // Edge cases
    int arr_zero1[] = {0, 5, 10};
    int arr_zero2[] = {0, 0, 5};
    printf("  {0, 5, 10}: Has pair product 0?: %s (Expected: true)\n", array_has_pair_product(arr_zero1, 3, 0) ? "true" : "false");
    printf("  {0, 0, 5}: Has pair product 0?: %s (Expected: true)\n", array_has_pair_product(arr_zero2, 3, 0) ? "true" : "false");
    printf("  arr2: Has pair product 10000? (size<2): %s (Expected: false)\n", array_has_pair_product(arr2, size2, 10000) ? "true" : "false");
    printf("  arr_empty: Has pair product 5? (empty): %s (Expected: false)\n", array_has_pair_product(arr_empty, size_empty, 5) ? "true" : "false");
    printf("  arr_null: Has pair product 5? (null): %s (Expected: false)\n", array_has_pair_product(arr_null, size1, 5) ? "true" : "false");
    printf("---\n\n");


    // --- Test array_has_pair_difference (O(n) version) ---
    printf("--- Testing array_has_pair_difference ---\n");
    printf("  arr1: Has pair diff 7? (5 - -2): %s (Expected: true)\n", array_has_pair_difference(arr1, size1, 7) ? "true" : "false");
    printf("  arr1: Has pair diff -12? (-2 - 10): %s (Expected: true)\n", array_has_pair_difference(arr1, size1, -12) ? "true" : "false");
    printf("  arr1: Has pair diff 0? (5 - 5): %s (Expected: true)\n", array_has_pair_difference(arr1, size1, 0) ? "true" : "false");
    printf("  arr1: Has pair diff 18? (15 - -3): %s (Expected: true)\n", array_has_pair_difference(arr1, size1, 18) ? "true" : "false");
    printf("  arr1: Has pair diff 100? (No): %s (Expected: false)\n", array_has_pair_difference(arr1, size1, 100) ? "true" : "false");
    printf("  arr3: Has pair diff 5? (-10 - -15): %s (Expected: true)\n", array_has_pair_difference(arr3, size3, 5) ? "true" : "false");
    printf("  arr3: Has pair diff 0? (No Dups): %s (Expected: false)\n", array_has_pair_difference(arr3, size3, 0) ? "true" : "false");
    printf("  arr4: Has pair diff 0? (6 - 6): %s (Expected: true)\n", array_has_pair_difference(arr4, size4, 0) ? "true" : "false");
    printf("  arr4: Has pair diff 1? (No): %s (Expected: false)\n", array_has_pair_difference(arr4, size4, 1) ? "true" : "false");
    printf("  arr5: Has pair diff -6? (-5 - 1): %s (Expected: true)\n", array_has_pair_difference(arr5, size5, -6) ? "true" : "false");
    // Edge cases
    printf("  arr2: Has pair diff 0? (Yes, 100-100): %s (Expected: true)\n", array_has_pair_difference(arr2, size2, 0) ? "true" : "false");
    printf("  arr2: Has pair diff 1? (No): %s (Expected: false)\n", array_has_pair_difference(arr2, size2, 1) ? "true" : "false");
    printf("  arr_empty: Has pair diff 0? (empty): %s (Expected: false)\n", array_has_pair_difference(arr_empty, size_empty, 0) ? "true" : "false");
    printf("  arr_null: Has pair diff 0? (null): %s (Expected: false)\n", array_has_pair_difference(arr_null, size1, 0) ? "true" : "false");
    printf("---\n\n");


    printf("--- Aquant Library Test Suite Complete ---\n");
    return 0;
}
