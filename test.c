#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "aquant.h"


void print_test_array(const char* name, const int *arr, size_t size) {
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


void print_separator(const char *title) {
    printf("\n--- Testing %s ---\n", title);
}

void print_string_array(const char* name, const char *arr[], size_t size) {
     printf("%s: [", name);
    if (arr == NULL) {
        printf("NULL");
    } else if (size == 0) {
        printf("empty");
    } else {
        for (size_t i = 0; i < size; ++i) {
            printf("\"%s\"%s", arr[i] ? arr[i] : "(null)", (i == size - 1) ? "" : ", ");
        }
    }
    printf("] (size %zu)\n", size);
}


int main(void)
{
    printf("------------------------------------ Starting Aquant Library Test Suite (v1.1.0 + New Features) ------------------------------------\n\n");


    printf("=== Section 1: Testing Input Functions (Requires User Input) ===\n");
    printf("Instructions: Enter valid and invalid input when prompted.\n");
    printf("              Try empty input (just Enter), text for numbers, etc.\n");
    printf("              Press Ctrl+D (Unix/macOS) or Ctrl+Z then Enter (Windows) to simulate EOF.\n\n");

    printf("--- Testing get_string ---\n");
    string s = get_string("Enter any string (e.g., 'hello world', empty, long): ");
    if (s != NULL) {
        printf("get_string returned: \"%s\"\n", s);
        free(s);
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
    int i_null = get_int(NULL);
    printf("get_int(NULL) returned: %i\n", i_null);
    printf("---\n\n");



    printf("=== Section 2: Testing Basic Array Functions ===\n\n");

    int arr1[] = {5, -2, 10, 0, 8, 5, -3, 15};
    size_t size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {100};
    size_t size2 = sizeof(arr2) / sizeof(arr2[0]);

    int arr3[] = {-10, -5, -20, -15};
    size_t size3 = sizeof(arr3) / sizeof(arr3[0]);

    int arr4[] = {6, 6, 6};
    size_t size4 = sizeof(arr4) / sizeof(arr4[0]);

    int arr5[] = {INT_MAX, 1, -5, INT_MIN, 2};
    size_t size5 = sizeof(arr5) / sizeof(arr5[0]);

    int arr_empty[] = {};
    size_t size_empty = 0;

    int* arr_null = NULL;

    print_test_array("arr1 (General)", arr1, size1);
    print_test_array("arr2 (Single)", arr2, size2);
    print_test_array("arr3 (Negative)", arr3, size3);
    print_test_array("arr4 (Duplicates)", arr4, size4);
    print_test_array("arr5 (Edges)", arr5, size5);
    print_test_array("arr_empty", arr_empty, size_empty);
    print_test_array("arr_null", arr_null, size1);
    printf("\n");


    printf("--- Testing array_max ---\n");
    int max_val;
    if (array_max(arr1, size1, &max_val)) printf("  arr1: Max = %d (Expected: 15)\n", max_val); else printf("  arr1: Max FAILED\n");
    if (array_max(arr2, size2, &max_val)) printf("  arr2: Max = %d (Expected: 100)\n", max_val); else printf("  arr2: Max FAILED\n");
    if (array_max(arr3, size3, &max_val)) printf("  arr3: Max = %d (Expected: -5)\n", max_val); else printf("  arr3: Max FAILED\n");
    if (array_max(arr5, size5, &max_val)) printf("  arr5: Max = %d (Expected: %d)\n", max_val, INT_MAX); else printf("  arr5: Max FAILED\n");
    if (array_max(arr_empty, size_empty, &max_val)) printf("  arr_empty: Max FAILED (Should Fail)\n"); else printf("  arr_empty: Max returned false (Expected)\n");
    if (array_max(arr_null, size1, &max_val)) printf("  arr_null: Max FAILED (Should Fail)\n"); else printf("  arr_null: Max returned false (Expected)\n");
    if (array_max(arr1, size1, NULL)) printf("  arr1 (NULL out): Max FAILED (Should Fail)\n"); else printf("  arr1 (NULL out): Max returned false (Expected)\n");
    printf("---\n\n");


    printf("--- Testing array_min ---\n");
    int min_val;
    if (array_min(arr1, size1, &min_val)) printf("  arr1: Min = %d (Expected: -3)\n", min_val); else printf("  arr1: Min FAILED\n");
    if (array_min(arr2, size2, &min_val)) printf("  arr2: Min = %d (Expected: 100)\n", min_val); else printf("  arr2: Min FAILED\n");
    if (array_min(arr3, size3, &min_val)) printf("  arr3: Min = %d (Expected: -20)\n", min_val); else printf("  arr3: Min FAILED\n");
    if (array_min(arr5, size5, &min_val)) printf("  arr5: Min = %d (Expected: %d)\n", min_val, INT_MIN); else printf("  arr5: Min FAILED\n");
    if (array_min(arr_empty, size_empty, &min_val)) printf("  arr_empty: Min FAILED (Should Fail)\n"); else printf("  arr_empty: Min returned false (Expected)\n");
    if (array_min(arr_null, size1, &min_val)) printf("  arr_null: Min FAILED (Should Fail)\n"); else printf("  arr_null: Min returned false (Expected)\n");
    if (array_min(arr1, size1, NULL)) printf("  arr1 (NULL out): Min FAILED (Should Fail)\n"); else printf("  arr1 (NULL out): Min returned false (Expected)\n");
    printf("---\n\n");


    printf("--- Testing array_sum ---\n");
    long long sum_val;
    if (array_sum(arr1, size1, &sum_val)) printf("  arr1: Sum = %lld (Expected: 38)\n", sum_val); else printf("  arr1: Sum FAILED\n");
    if (array_sum(arr3, size3, &sum_val)) printf("  arr3: Sum = %lld (Expected: -50)\n", sum_val); else printf("  arr3: Sum FAILED\n");
    if (array_sum(arr5, size5, &sum_val)) printf("  arr5: Sum = %lld (Expected: -2)\n", sum_val); else printf("  arr5: Sum FAILED\n");
    if (array_sum(arr_empty, size_empty, &sum_val)) printf("  arr_empty: Sum = %lld (Expected: 0)\n", sum_val); else printf("  arr_empty: Sum FAILED (Should succeed!)\n");
    if (array_sum(arr_null, size1, &sum_val)) printf("  arr_null: Sum FAILED (Should Fail)\n"); else printf("  arr_null: Sum returned false (Expected)\n");
    if (array_sum(arr1, size1, NULL)) printf("  arr1 (NULL out): Sum FAILED (Should Fail)\n"); else printf("  arr1 (NULL out): Sum returned false (Expected)\n");
    printf("---\n\n");


    printf("--- Testing array_has_pair_sum ---\n");
    printf("  arr1: Has pair sum 8? (10 + -2): %s (Expected: true)\n", array_has_pair_sum(arr1, size1, 8) ? "true" : "false");
    printf("  arr1: Has pair sum 10? (5 + 5): %s (Expected: true)\n", array_has_pair_sum(arr1, size1, 10) ? "true" : "false");
    printf("  arr1: Has pair sum -5? (-2 + -3): %s (Expected: true)\n", array_has_pair_sum(arr1, size1, -5) ? "true" : "false");
    printf("  arr1: Has pair sum 100? (No): %s (Expected: false)\n", array_has_pair_sum(arr1, size1, 100) ? "true" : "false");
    printf("  arr4: Has pair sum 12? (6 + 6): %s (Expected: true)\n", array_has_pair_sum(arr4, size4, 12) ? "true" : "false");
    printf("  arr4: Has pair sum 10? (No): %s (Expected: false)\n", array_has_pair_sum(arr4, size4, 10) ? "true" : "false");
    printf("  arr5: Has pair sum %d? (INT_MAX + -5): %s (Expected: true)\n", INT_MAX - 5 , array_has_pair_sum(arr5, size5, INT_MAX - 5) ? "true" : "false");
    printf("  arr5: Has pair sum %d? (INT_MIN + 2): %s (Expected: true)\n", INT_MIN + 2 , array_has_pair_sum(arr5, size5, INT_MIN + 2) ? "true" : "false");
    printf("  arr5: Has pair sum 0? (No simple pair): %s (Expected: false)\n", array_has_pair_sum(arr5, size5, 0) ? "true" : "false");
    printf("  arr2: Has pair sum 200? (size<2, single element doesn't form a pair): %s (Expected: false)\n", array_has_pair_sum(arr2, size2, 200) ? "true" : "false");
    printf("  arr_empty: Has pair sum 5? (empty): %s (Expected: false)\n", array_has_pair_sum(arr_empty, size_empty, 5) ? "true" : "false");
    printf("  arr_null: Has pair sum 5? (null): %s (Expected: false)\n", array_has_pair_sum(arr_null, size1, 5) ? "true" : "false");
    printf("---\n\n");


    printf("--- Testing array_has_pair_product ---\n");
    printf("  arr1: Has pair product 0? (0 * x): %s (Expected: true)\n", array_has_pair_product(arr1, size1, 0) ? "true" : "false");
    printf("  arr1: Has pair product -20? (10 * -2): %s (Expected: true)\n", array_has_pair_product(arr1, size1, -20) ? "true" : "false");
    printf("  arr1: Has pair product 25? (5 * 5): %s (Expected: true)\n", array_has_pair_product(arr1, size1, 25) ? "true" : "false");
    printf("  arr1: Has pair product -15? (5 * -3): %s (Expected: true)\n", array_has_pair_product(arr1, size1, -15) ? "true" : "false");
    printf("  arr1: Has pair product 1000? (No): %s (Expected: false)\n", array_has_pair_product(arr1, size1, 1000) ? "true" : "false");
    printf("  arr3: Has pair product 50? (-10 * -5): %s (Expected: true)\n", array_has_pair_product(arr3, size3, 50) ? "true" : "false");
    printf("  arr4: Has pair product 36? (6 * 6): %s (Expected: true)\n", array_has_pair_product(arr4, size4, 36) ? "true" : "false");
    printf("  arr4: Has pair product 12? (No): %s (Expected: false)\n", array_has_pair_product(arr4, size4, 12) ? "true" : "false");
    int arr_zero1[] = {0, 5, 10};
    int arr_zero2[] = {0, 0, 5};
    printf("  {0, 5, 10}: Has pair product 0?: %s (Expected: true)\n", array_has_pair_product(arr_zero1, 3, 0) ? "true" : "false");
    printf("  {0, 0, 5}: Has pair product 0?: %s (Expected: true)\n", array_has_pair_product(arr_zero2, 3, 0) ? "true" : "false");
    printf("  arr2: Has pair product 10000? (size<2): %s (Expected: false)\n", array_has_pair_product(arr2, size2, 10000) ? "true" : "false");
    printf("  arr2: Has pair product 100? (single element does not form a pair): %s (Expected: false)\n", array_has_pair_product(arr2, size2, 100) ? "true" : "false");
    printf("  arr_empty: Has pair product 5? (empty): %s (Expected: false)\n", array_has_pair_product(arr_empty, size_empty, 5) ? "true" : "false");
    printf("  arr_null: Has pair product 5? (null): %s (Expected: false)\n", array_has_pair_product(arr_null, size1, 5) ? "true" : "false");
    printf("---\n\n");


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
    printf("  arr5: Has pair diff %d? (INT_MAX - INT_MIN): %s (Expected: true)\n", INT_MAX - INT_MIN, array_has_pair_difference(arr5, size5, INT_MAX - INT_MIN) ? "true" : "false");
    printf("  arr2: Has pair diff 0? (Yes, 100-100): %s (Expected: true)\n", array_has_pair_difference(arr2, size2, 0) ? "true" : "false");
    printf("  arr2: Has pair diff 1? (No): %s (Expected: false)\n", array_has_pair_difference(arr2, size2, 1) ? "true" : "false");
    printf("  arr_empty: Has pair diff 0? (empty): %s (Expected: false)\n", array_has_pair_difference(arr_empty, size_empty, 0) ? "true" : "false");
    printf("  arr_null: Has pair diff 0? (null): %s (Expected: false)\n", array_has_pair_difference(arr_null, size1, 0) ? "true" : "false");
    printf("---\n\n");


    printf("=== Section 3: Testing Added Array/String Utilities ===\n\n");

    int sort_test1[] = {5, 2, 8, 2, 1, 9, 4, 0};
    size_t sort_size1 = sizeof(sort_test1) / sizeof(sort_test1[0]);
    int expected_sort1[] = {0, 1, 2, 2, 4, 5, 8, 9};

    int sort_test_empty[] = {};
    size_t sort_size_empty = 0;

    int sort_test_single[] = {42};
    size_t sort_size_single = 1;

    int sort_test_mixed[] = {3, -1, 5, 0, -10};
    size_t sort_size_mixed = sizeof(sort_test_mixed) / sizeof(sort_test_mixed[0]);
    int expected_sort_mixed[] = {-10, -1, 0, 3, 5};

    const char *names[] = {"Alice", "Bob", "Charlie", "David", "Bob", NULL, "Eve"};
    size_t names_size = sizeof(names) / sizeof(names[0]);

    const char *names_empty[] = {};
    size_t names_empty_size = 0;

    const char **names_null = NULL;


    print_separator("print_array (Library Function)");
    printf("Printing sort_test1: ");
    print_array(sort_test1, sort_size1);

    printf("Printing empty array: ");
    print_array(sort_test_empty, sort_size_empty);

    printf("Printing single element array: ");
    print_array(sort_test_single, sort_size_single);

    printf("Printing NULL array: ");
    print_array(arr_null, 5);
    printf("---\n\n");


    print_separator("sort_array");

    printf("Original sort_test1: ");
    int sort_test1_copy[] = {5, 2, 8, 2, 1, 9, 4, 0};
    print_test_array("sort_test1", sort_test1_copy, sort_size1);
    sort_array(sort_test1_copy, sort_size1);
    printf("Sorted sort_test1:   ");
    print_test_array("sort_test1", sort_test1_copy, sort_size1);
    bool sorted_ok = true;
    for(size_t k=0; k < sort_size1; ++k) {
        if(sort_test1_copy[k] != expected_sort1[k]) sorted_ok = false;
    }
    printf("Verification: %s\n", sorted_ok ? "Passed" : "FAILED");

    printf("\nOriginal sort_test_mixed: ");
    int sort_test_mixed_copy[] = {3, -1, 5, 0, -10};
    print_test_array("sort_test_mixed", sort_test_mixed_copy, sort_size_mixed);
    sort_array(sort_test_mixed_copy, sort_size_mixed);
    printf("Sorted sort_test_mixed:   ");
    print_test_array("sort_test_mixed", sort_test_mixed_copy, sort_size_mixed);
    sorted_ok = true;
    for(size_t k=0; k < sort_size_mixed; ++k) {
        if(sort_test_mixed_copy[k] != expected_sort_mixed[k]) sorted_ok = false;
    }
    printf("Verification: %s\n", sorted_ok ? "Passed" : "FAILED");


    printf("\nSorting empty array:\n");
    print_test_array("Original", sort_test_empty, sort_size_empty);
    sort_array(sort_test_empty, sort_size_empty);
    printf("Sorted:  ");
    print_test_array("Result", sort_test_empty, sort_size_empty);

    printf("\nSorting single element array:\n");
    print_test_array("Original", sort_test_single, sort_size_single);
    sort_array(sort_test_single, sort_size_single);
    printf("Sorted:  ");
    print_test_array("Result", sort_test_single, sort_size_single);

    printf("\nAttempting to sort NULL array:\n");
    sort_array(arr_null, 5);
    printf("Call completed (check for crashes)\n");

    printf("---\n\n");


    print_separator("find_string");
    print_string_array("Names", names, names_size);

    const char *target1 = "Bob";
    int index1 = find_string(names, names_size, target1);
    printf("  Finding \"%s\": index = %d (Expected: 1)\n", target1, index1);

    const char *target2 = "David";
    int index2 = find_string(names, names_size, target2);
    printf("  Finding \"%s\": index = %d (Expected: 3)\n", target2, index2);

    const char *target3 = "Eve";
    int index3 = find_string(names, names_size, target3);
    printf("  Finding \"%s\": index = %d (Expected: 6)\n", target3, index3);

    const char *target4 = "Zoe";
    int index4 = find_string(names, names_size, target4);
    printf("  Finding \"%s\": index = %d (Expected: -1)\n", target4, index4);

    printf("\nFinding in empty array:\n");
    const char *target5 = "Alice";
    int index5 = find_string(names_empty, names_empty_size, target5);
    printf("  Finding \"%s\" in empty array: index = %d (Expected: -1)\n", target5, index5);

    printf("\nFinding NULL target:\n");
    const char *target_null_explicit = NULL;
    int index_find_null = find_string(names, names_size, target_null_explicit);
    printf("  Finding NULL target in names: index = %d (Expected: 5 if NULL in array is findable, else -1)\n", index_find_null);

    printf("\nFinding in NULL array:\n");
    int index7 = find_string(names_null, 5, target1);
    printf("  Finding \"%s\" in NULL array: index = %d (Expected: -1)\n", target1, index7);

    printf("---\n\n");


    printf("--- Aquant Library Test Suite Complete ---\n");
    return 0;
}
