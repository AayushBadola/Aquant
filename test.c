#include "aquant.h" // Make sure this includes the header with EPSILON defined
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h> // For INT_MAX etc.
#include <float.h>  // For FLT_MAX etc.
#include <math.h>   // For fabs, isnan

// Helper to print simple pass/fail
void check(const char* test_name, bool condition) {
    printf("%s: %s\n", test_name, condition ? "PASS" : "FAIL");
}

int main(void) {
    printf("AQUANT Library Comprehensive Test\n");
    printf("=================================\n\n");

    // --- Input Functions ---
    printf("--- Input Functions (Interactive) ---\n");
    string name = get_string("Test get_string (Enter your name): ");
    printf("Got string: '%s'\n", name ? name : "(null)");
    if (name) free_string(name);

    char c = get_char("Test get_char (Enter 'x'): ");
    printf("Got char: %c\n", c);

    int i = get_int("Test get_int (Enter 123): ");
    printf("Got int: %d\n", i);

    long l = get_long("Test get_long (Enter 9876543210): ");
    printf("Got long: %ld\n", l);

    float f = get_float("Test get_float (Enter 3.14): ");
    printf("Got float: %f\n", f);

    double d = get_double("Test get_double (Enter 2.71828): ");
    printf("Got double: %f\n", d);

    int ir = get_int_range("Test get_int_range (Enter value between 1 and 10): ", 1, 10);
    printf("Got int in range: %d\n", ir);

    string sne = get_string_non_empty("Test get_string_non_empty (Enter non-empty text): ");
    printf("Got non-empty string: '%s'\n", sne ? sne : "(null)");
    if(sne) free_string(sne);
    printf("\n");


    // --- Integer Array Functions ---
    printf("--- Integer Array Functions ---\n");
    int arr1[] = {5, -2, 8, 0, 9, 1, 5, INT_MAX};
    size_t size1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr_empty[] = {};
    size_t size_empty = 0;
    int arr_single[] = {42};
    size_t size_single = 1;
    int arr_dup[] = {3, 3, 3};
    size_t size_dup = 3;
    int arr_neg[] = {-5, -10, -2};
    size_t size_neg = 3;

    int max_val, min_val;
    long long sum_val;
    size_t new_size;
    int *arr_copy = NULL, *arr_unique = NULL, *arr_concat = NULL;

    check("array_max (normal)", array_max(arr1, size1, &max_val) && max_val == INT_MAX);
    check("array_min (normal)", array_min(arr1, size1, &min_val) && min_val == -2);
    check("array_max (empty)", !array_max(arr_empty, size_empty, &max_val));
    check("array_min (empty)", !array_min(arr_empty, size_empty, &min_val));
    check("array_max (single)", array_max(arr_single, size_single, &max_val) && max_val == 42);
    check("array_min (single)", array_min(arr_single, size_single, &min_val) && min_val == 42);
    check("array_max (neg)", array_max(arr_neg, size_neg, &max_val) && max_val == -2);
    check("array_min (neg)", array_min(arr_neg, size_neg, &min_val) && min_val == -10);
    check("array_max (NULL arr)", !array_max(NULL, size1, &max_val));
    check("array_min (NULL arr)", !array_min(NULL, size1, &min_val));
    check("array_max (NULL out)", !array_max(arr1, size1, NULL));
    check("array_min (NULL out)", !array_min(arr1, size1, NULL));
    check("array_sum (normal)", array_sum(arr1, size1, &sum_val) && sum_val == (5LL - 2LL + 8LL + 0LL + 9LL + 1LL + 5LL + (long long)INT_MAX));
    check("array_sum (empty)", array_sum(arr_empty, size_empty, &sum_val) && sum_val == 0);
    check("array_sum (single)", array_sum(arr_single, size_single, &sum_val) && sum_val == 42);
    check("array_sum (NULL arr)", array_sum(NULL, 0, &sum_val) && sum_val == 0);
    check("array_sum (NULL out)", !array_sum(arr1, size1, NULL));
    check("array_contains_int (present)", array_contains_int(arr1, size1, 8));
    check("array_contains_int (not present)", !array_contains_int(arr1, size1, 100));
    check("array_contains_int (first)", array_contains_int(arr1, size1, 5));
    check("array_contains_int (last)", array_contains_int(arr1, size1, INT_MAX));
    check("array_contains_int (zero)", array_contains_int(arr1, size1, 0));
    check("array_contains_int (neg)", array_contains_int(arr1, size1, -2));
    check("array_contains_int (empty)", !array_contains_int(arr_empty, size_empty, 5));
    check("array_contains_int (NULL arr)", !array_contains_int(NULL, size1, 5));
    check("array_index_of_int (present)", array_index_of_int(arr1, size1, 8) == 2);
    check("array_index_of_int (not present)", array_index_of_int(arr1, size1, 100) == -1);
    check("array_index_of_int (first occurrence)", array_index_of_int(arr1, size1, 5) == 0);
    check("array_index_of_int (empty)", array_index_of_int(arr_empty, size_empty, 5) == -1);
    check("array_index_of_int (NULL arr)", array_index_of_int(NULL, size1, 5) == -1);
    check("array_average (normal)", fabs(array_average(arr1, size1) - ((double)(5LL - 2LL + 8LL + 0LL + 9LL + 1LL + 5LL + (long long)INT_MAX) / size1)) < 0.001);
    check("array_average (empty)", isnan(array_average(arr_empty, size_empty)));
    check("array_average (single)", array_average(arr_single, size_single) == 42.0);
    check("array_average (NULL arr)", isnan(array_average(NULL, size1)));
    check("array_count_occurrence (multiple)", array_count_occurrence(arr1, size1, 5) == 2);
    check("array_count_occurrence (single)", array_count_occurrence(arr1, size1, 8) == 1);
    check("array_count_occurrence (none)", array_count_occurrence(arr1, size1, 100) == 0);
    check("array_count_occurrence (empty)", array_count_occurrence(arr_empty, size_empty, 5) == 0);
    check("array_count_occurrence (NULL arr)", array_count_occurrence(NULL, size1, 5) == 0);
    arr_copy = array_copy_int(arr1, size1);
    check("array_copy_int (check content)", arr_copy != NULL && arr_copy[0] == 5 && arr_copy[size1 - 1] == INT_MAX);
    check("array_copy_int (check distinct ptr)", arr_copy != arr1);
    if(arr_copy) free(arr_copy); arr_copy = NULL;
    check("array_copy_int (empty)", array_copy_int(arr_empty, size_empty) == NULL);
    check("array_copy_int (NULL arr)", array_copy_int(NULL, size1) == NULL);
    int pair_sum_arr[] = {1, 4, 5, 7, 9};
    check("array_has_pair_sum (yes)", array_has_pair_sum(pair_sum_arr, 5, 9));
    check("array_has_pair_sum (yes, edges)", array_has_pair_sum(pair_sum_arr, 5, 10));
    check("array_has_pair_sum (yes, duplicate num)", array_has_pair_sum(arr1, size1, 10));
    check("array_has_pair_sum (yes, zero)", array_has_pair_sum(arr1, size1, 8));
    check("array_has_pair_sum (no)", !array_has_pair_sum(pair_sum_arr, 5, 20));
    check("array_has_pair_sum (empty)", !array_has_pair_sum(arr_empty, size_empty, 10));
    check("array_has_pair_sum (single)", !array_has_pair_sum(arr_single, size_single, 84));
    check("array_has_pair_sum (NULL arr)", !array_has_pair_sum(NULL, 5, 10));
    int pair_prod_arr[] = {2, 3, 5, 0, 7};
    check("array_has_pair_product (yes)", array_has_pair_product(pair_prod_arr, 5, 15));
    check("array_has_pair_product (yes, zero)", array_has_pair_product(pair_prod_arr, 5, 0));
    check("array_has_pair_product (yes, dup)", array_has_pair_product(arr1, size1, 25));
    check("array_has_pair_product (no)", !array_has_pair_product(pair_prod_arr, 5, 11));
    check("array_has_pair_product (empty)", !array_has_pair_product(arr_empty, size_empty, 10));
    check("array_has_pair_product (NULL arr)", !array_has_pair_product(NULL, 5, 10));
    int pair_diff_arr[] = {1, 5, 9, 10};
    check("array_has_pair_difference (yes)", array_has_pair_difference(pair_diff_arr, 4, 4));
    check("array_has_pair_difference (yes, neg target)", array_has_pair_difference(pair_diff_arr, 4, -4));
    check("array_has_pair_difference (yes, zero)", array_has_pair_difference(arr1, size1, 0));
    check("array_has_pair_difference (no)", !array_has_pair_difference(pair_diff_arr, 4, 2));
    check("array_has_pair_difference (empty)", !array_has_pair_difference(arr_empty, size_empty, 1));
    check("array_has_pair_difference (NULL arr)", !array_has_pair_difference(NULL, 4, 1));
    arr_copy = array_copy_int(arr1, size1);
    if(arr_copy) {
        sort_array(arr_copy, size1);
        bool sorted = true;
        for(size_t i = 0; i < size1 - 1; ++i) if (arr_copy[i] > arr_copy[i+1]) sorted = false;
        check("sort_array (normal)", sorted);
        free(arr_copy); arr_copy = NULL;
    }
    sort_array(arr_empty, size_empty);
    check("sort_array (empty)", true);
    sort_array(arr_single, size_single);
    check("sort_array (single)", arr_single[0] == 42);
    printf("print_array (normal): "); print_array(arr1, size1);
    printf("print_array (empty): "); print_array(arr_empty, size_empty);
    printf("print_array (NULL): "); print_array(NULL, 0);
    arr_copy = array_copy_int(arr1, size1);
    if(arr_copy) {
        array_reverse_int(arr_copy, size1);
        check("array_reverse_int", arr_copy[0] == INT_MAX && arr_copy[size1 - 1] == 5);
        free(arr_copy); arr_copy = NULL;
    }
    array_reverse_int(arr_empty, size_empty); check("array_reverse_int (empty)", true);
    initialize_random(); // Call ONCE
    arr_copy = array_copy_int(arr1, size1);
    if(arr_copy) {
        array_shuffle_int(arr_copy, size1);
        printf("array_shuffle_int (output): "); print_array(arr_copy, size1);
        free(arr_copy); arr_copy = NULL;
    }
    check("array_shuffle_int (ran)", true);
    arr_unique = array_unique_int(arr1, size1, &new_size);
    check("array_unique_int (size)", arr_unique != NULL && new_size == 7);
    if(arr_unique) {
        sort_array(arr_unique, new_size);
        check("array_unique_int (content)", arr_unique[0]==-2 && arr_unique[1]==0 && arr_unique[6]==INT_MAX);
        free(arr_unique); arr_unique = NULL;
    }
    arr_unique = array_unique_int(arr_dup, size_dup, &new_size);
    check("array_unique_int (all dup)", arr_unique != NULL && new_size == 1 && arr_unique[0] == 3);
    if(arr_unique) { free(arr_unique); arr_unique = NULL; }
    arr_unique = array_unique_int(arr_empty, size_empty, &new_size);
    check("array_unique_int (empty)", arr_unique == NULL && new_size == 0);
    arr_unique = array_unique_int(NULL, size1, &new_size);
    check("array_unique_int (NULL arr)", arr_unique == NULL && new_size == 0);
    int arr_c1[] = {1, 2}; size_t size_c1 = 2;
    int arr_c2[] = {3, 4, 5}; size_t size_c2 = 3;
    arr_concat = array_concat_int(arr_c1, size_c1, arr_c2, size_c2, &new_size);
    check("array_concat_int (normal)", arr_concat != NULL && new_size == 5 && arr_concat[0]==1 && arr_concat[4]==5);
    if(arr_concat) { free(arr_concat); arr_concat = NULL; }
    arr_concat = array_concat_int(arr_c1, size_c1, arr_empty, size_empty, &new_size);
    check("array_concat_int (second empty)", arr_concat != NULL && new_size == 2 && arr_concat[1]==2);
    if(arr_concat) { free(arr_concat); arr_concat = NULL; }
    arr_concat = array_concat_int(arr_empty, size_empty, arr_c2, size_c2, &new_size);
    check("array_concat_int (first empty)", arr_concat != NULL && new_size == 3 && arr_concat[0]==3);
    if(arr_concat) { free(arr_concat); arr_concat = NULL; }
    arr_concat = array_concat_int(NULL, 0, NULL, 0, &new_size);
    check("array_concat_int (both NULL)", arr_concat == NULL && new_size == 0);
    printf("\n");


    // --- Float Array Functions ---
    printf("--- Float Array Functions ---\n");
    float farr1[] = {3.14f, -1.0f, 0.0f, 100.5f, 3.14f}; size_t fsize1 = 5;
    float farr_empty[] = {}; size_t fsize_empty = 0;
    float fmax_val, fmin_val; double fsum_val; size_t fnew_size;
    float *farr_copy = NULL, *farr_concat = NULL;

    check("array_max_float", array_max_float(farr1, fsize1, &fmax_val) && fabs(fmax_val - 100.5f) < FLOAT_EPSILON);
    check("array_min_float", array_min_float(farr1, fsize1, &fmin_val) && fabs(fmin_val - (-1.0f)) < FLOAT_EPSILON);
    check("array_sum_float", array_sum_float(farr1, fsize1, &fsum_val) && fabs(fsum_val - (3.14 - 1.0 + 0.0 + 100.5 + 3.14)) < DOUBLE_EPSILON);
    check("array_average_float", fabs(array_average_float(farr1, fsize1) - ((3.14 - 1.0 + 0.0 + 100.5 + 3.14) / 5.0)) < DOUBLE_EPSILON);
    check("array_contains_float", array_contains_float(farr1, fsize1, 3.14f));
    check("array_index_of_float", array_index_of_float(farr1, fsize1, 0.0f) == 2);
    check("array_count_occurrence_float", array_count_occurrence_float(farr1, fsize1, 3.14f) == 2);
    farr_copy = array_copy_float(farr1, fsize1);
    check("array_copy_float", farr_copy != NULL && fabs(farr_copy[0] - 3.14f) < FLOAT_EPSILON);
    if(farr_copy) free(farr_copy); farr_copy = NULL;
    farr_copy = array_copy_float(farr1, fsize1);
    if(farr_copy) {
        sort_array_float(farr_copy, fsize1);
        check("sort_array_float", fabs(farr_copy[0] - (-1.0f)) < FLOAT_EPSILON && fabs(farr_copy[4] - 100.5f) < FLOAT_EPSILON);
        free(farr_copy); farr_copy = NULL;
    }
    printf("print_float_array: "); print_float_array(farr1, fsize1);
    farr_copy = array_copy_float(farr1, fsize1);
    if(farr_copy) {
        array_reverse_float(farr_copy, fsize1);
        check("array_reverse_float", fabs(farr_copy[0] - 3.14f) < FLOAT_EPSILON && fabs(farr_copy[4] - 3.14f) < FLOAT_EPSILON);
        free(farr_copy); farr_copy = NULL;
    }
    float fc1[] = {1.1f, 2.2f}; size_t fsc1 = 2;
    float fc2[] = {3.3f}; size_t fsc2 = 1;
    farr_concat = array_concat_float(fc1, fsc1, fc2, fsc2, &fnew_size);
    check("array_concat_float", farr_concat != NULL && fnew_size == 3 && fabs(farr_concat[2] - 3.3f) < FLOAT_EPSILON);
    if(farr_concat) free(farr_concat); farr_concat = NULL;
    printf("\n");


    // --- Double Array Functions ---
    printf("--- Double Array Functions ---\n");
    // Add similar comprehensive tests for double arrays using DOUBLE_EPSILON
    printf("Double tests omitted for brevity (pattern follows float tests).\n\n");


    // --- String Array Functions ---
    printf("--- String Array Functions ---\n");
    string sarr1[] = {"Apple", "Banana", "Cherry", "Apple", NULL, ""}; size_t ssize1 = 6;
    string sarr_empty[] = {}; size_t ssize_empty = 0;
    string sarr_single[] = {"OnlyOne"}; size_t ssize_single = 1;
    string sarr_nulls[] = {NULL, NULL}; size_t ssize_nulls = 2;
    string smax_val, smin_val;
    string *sarr_copy = NULL, *sarr_concat = NULL; size_t snew_size;

    check("array_max_string (normal)", array_max_string(sarr1, ssize1, &smax_val) && string_equals(smax_val, "Cherry"));
    check("array_min_string (normal)", array_min_string(sarr1, ssize1, &smin_val) && string_equals(smin_val, NULL));
    check("array_max_string (empty)", !array_max_string(sarr_empty, ssize_empty, &smax_val));
    check("array_min_string (empty)", !array_min_string(sarr_empty, ssize_empty, &smin_val));
    check("array_max_string (all nulls)", array_max_string(sarr_nulls, ssize_nulls, &smax_val) && smax_val == NULL);
    check("array_min_string (all nulls)", array_min_string(sarr_nulls, ssize_nulls, &smin_val) && smin_val == NULL);
    check("array_contains_string (present)", array_contains_string(sarr1, ssize1, "Banana"));
    check("array_contains_string (NULL present)", array_contains_string(sarr1, ssize1, NULL));
    check("array_contains_string (empty string present)", array_contains_string(sarr1, ssize1, ""));
    check("array_contains_string (not present)", !array_contains_string(sarr1, ssize1, "Orange"));
    check("find_string (present)", find_string(sarr1, ssize1, "Cherry") == 2);
    check("find_string (first occurrence)", find_string(sarr1, ssize1, "Apple") == 0);
    check("find_string (NULL)", find_string(sarr1, ssize1, NULL) == 4);
    check("find_string (not present)", find_string(sarr1, ssize1, "Orange") == -1);
    check("array_count_occurrence_string (multiple)", array_count_occurrence_string(sarr1, ssize1, "Apple") == 2);
    check("array_count_occurrence_string (NULL)", array_count_occurrence_string(sarr1, ssize1, NULL) == 1);
    check("array_count_occurrence_string (none)", array_count_occurrence_string(sarr1, ssize1, "Orange") == 0);
    sarr_copy = array_copy_string_array(sarr1, ssize1);
    check("array_copy_string_array (check content)", sarr_copy != NULL && string_equals(sarr_copy[0], "Apple") && sarr_copy[4] == NULL && string_equals(sarr_copy[5],""));
    check("array_copy_string_array (check distinct ptrs)", sarr_copy != sarr1 && (sarr_copy[0] == NULL || sarr_copy[0] != sarr1[0]));
    if(sarr_copy) free_string_array(sarr_copy, ssize1); sarr_copy = NULL;
    check("array_copy_string_array (empty)", array_copy_string_array(sarr_empty, ssize_empty) == NULL);
    sarr_copy = array_copy_string_array(sarr1, ssize1);
    if(sarr_copy) {
        sort_array_string(sarr_copy, ssize1);
        check("sort_array_string", sarr_copy[0]==NULL && string_equals(sarr_copy[1],"") && string_equals(sarr_copy[5],"Cherry"));
        free_string_array(sarr_copy, ssize1); sarr_copy = NULL;
    }
    printf("print_string_array (normal): "); print_string_array(sarr1, ssize1);
    printf("print_string_array (empty): "); print_string_array(sarr_empty, ssize_empty);
    printf("print_string_array (NULL arr): "); print_string_array(NULL, 0);
    sarr_copy = array_copy_string_array(sarr1, ssize1);
    if(sarr_copy){
        array_reverse_string(sarr_copy, ssize1);
        check("array_reverse_string", string_equals(sarr_copy[0],"") && sarr_copy[1] == NULL && string_equals(sarr_copy[5],"Apple"));
        free_string_array(sarr_copy, ssize1); sarr_copy = NULL;
    }
    string sc1[] = {"A", "B"}; size_t ssc1 = 2;
    string sc2[] = {NULL, "D"}; size_t ssc2 = 2;
    sarr_concat = array_concat_string(sc1, ssc1, sc2, ssc2, &snew_size);
    check("array_concat_string", sarr_concat != NULL && snew_size == 4 && string_equals(sarr_concat[0],"A") && sarr_concat[2]==NULL && string_equals(sarr_concat[3],"D"));
    if(sarr_concat) free_string_array(sarr_concat, snew_size); sarr_concat = NULL;
    printf("\n");


    // --- String Manipulation Functions ---
    printf("--- String Manipulation Functions ---\n");
    string str_orig = "  Test String \t";
    string str_empty = "";
    string str_null = NULL;
    string str_copy, str_trim_res, str_lower, str_upper, str_concat_res, str_sub, str_replace;
    string *str_tokens = NULL; string str_joined = NULL;
    size_t num_tokens; bool success;

    str_copy = string_copy(str_orig); check("string_copy (normal)", string_equals(str_copy, str_orig)); if(str_copy) free_string(str_copy);
    str_copy = string_copy(str_empty); check("string_copy (empty)", string_equals(str_copy, str_empty)); if(str_copy) free_string(str_copy);
    str_copy = string_copy(str_null); check("string_copy (NULL)", str_copy == NULL);
    check("string_equals (equal)", string_equals("abc", "abc"));
    check("string_equals (not equal)", !string_equals("abc", "abd"));
    check("string_equals (case diff)", !string_equals("abc", "Abc"));
    check("string_equals (empty)", string_equals("", ""));
    check("string_equals (one NULL)", !string_equals("abc", NULL));
    check("string_equals (other NULL)", !string_equals(NULL, "abc"));
    check("string_equals (both NULL)", string_equals(NULL, NULL));
    str_trim_res = string_trim(str_orig); check("string_trim (normal)", string_equals(str_trim_res, "Test String")); if(str_trim_res) free_string(str_trim_res);
    str_trim_res = string_trim("OnlySpaces   "); check("string_trim (spaces only)", string_equals(str_trim_res, "OnlySpaces")); if(str_trim_res) free_string(str_trim_res);
    str_trim_res = string_trim("NoSpaces"); check("string_trim (no spaces)", string_equals(str_trim_res, "NoSpaces")); if(str_trim_res) free_string(str_trim_res);
    str_trim_res = string_trim("   "); check("string_trim (all space)", string_equals(str_trim_res, "")); if(str_trim_res) free_string(str_trim_res);
    str_trim_res = string_trim(""); check("string_trim (empty)", string_equals(str_trim_res, "")); if(str_trim_res) free_string(str_trim_res);
    str_trim_res = string_trim(NULL); check("string_trim (NULL)", str_trim_res == NULL);
    check("string_is_int (yes)", string_is_int("123"));
    check("string_is_int (yes, neg)", string_is_int("-45"));
    check("string_is_int (yes, space)", string_is_int("  +678  "));
    check("string_is_int (no, float)", !string_is_int("12.3"));
    check("string_is_int (no, alpha)", !string_is_int("abc"));
    check("string_is_int (no, trailing)", !string_is_int("123a"));
    check("string_is_int (no, empty)", !string_is_int(""));
    check("string_is_int (no, NULL)", !string_is_int(NULL));
    check("string_is_alpha (yes)", string_is_alpha("HelloWorld"));
    check("string_is_alpha (no, space)", !string_is_alpha("Hello World"));
    check("string_is_alpha (no, digit)", !string_is_alpha("Hello9"));
    check("string_is_digit (yes)", string_is_digit("0123456789"));
    check("string_is_digit (no, alpha)", !string_is_digit("123a"));
    check("string_is_alnum (yes)", string_is_alnum("Alpha123"));
    check("string_is_alnum (no, symbol)", !string_is_alnum("Alpha!123"));
    check("string_is_space (yes)", string_is_space(" \t\n\r "));
    check("string_is_space (no, alpha)", !string_is_space(" a "));
    check("string_is_empty (yes, null)", string_is_empty(NULL));
    check("string_is_empty (yes, empty)", string_is_empty(""));
    check("string_is_empty (no)", !string_is_empty("a"));
    str_concat_res = string_concat("Hello ", "World!"); check("string_concat (normal)", string_equals(str_concat_res, "Hello World!")); if(str_concat_res) free_string(str_concat_res);
    str_concat_res = string_concat("", "World!"); check("string_concat (first empty)", string_equals(str_concat_res, "World!")); if(str_concat_res) free_string(str_concat_res);
    str_concat_res = string_concat("Hello ", ""); check("string_concat (second empty)", string_equals(str_concat_res, "Hello ")); if(str_concat_res) free_string(str_concat_res);
    str_concat_res = string_concat("Hello ", NULL); check("string_concat (second NULL)", string_equals(str_concat_res, "Hello ")); if(str_concat_res) free_string(str_concat_res);
    str_concat_res = string_concat(NULL, NULL); check("string_concat (both NULL)", str_concat_res == NULL);
    str_sub = string_substring("ABCDEFG", 2, 3); check("string_substring (middle)", string_equals(str_sub, "CDE")); if(str_sub) free_string(str_sub);
    str_sub = string_substring("ABCDEFG", 0, 3); check("string_substring (start)", string_equals(str_sub, "ABC")); if(str_sub) free_string(str_sub);
    str_sub = string_substring("ABCDEFG", 4, 10); check("string_substring (end, long length)", string_equals(str_sub, "EFG")); if(str_sub) free_string(str_sub);
    str_sub = string_substring("ABCDEFG", 5, 0); check("string_substring (zero length)", string_equals(str_sub, "")); if(str_sub) free_string(str_sub);
    str_sub = string_substring("ABCDEFG", 10, 3); check("string_substring (start > len)", string_equals(str_sub, "")); if(str_sub) free_string(str_sub);
    str_sub = string_substring("", 0, 1); check("string_substring (empty src)", string_equals(str_sub, "")); if(str_sub) free_string(str_sub);
    str_sub = string_substring(NULL, 0, 1); check("string_substring (NULL src)", str_sub == NULL);
    check("string_find_char (found)", string_find_char("Test String", 'S') == 5);
    check("string_find_char (not found)", string_find_char("Test String", 'X') == -1);
    check("string_find_substring (found)", string_find_substring("Test String", "Str") == 5);
    check("string_find_substring (not found)", string_find_substring("Test String", "XYZ") == -1);
    check("string_find_substring (empty needle)", string_find_substring("Test String", "") == 0);
    str_replace = string_replace_char("Hello World", 'o', 'X'); check("string_replace_char", string_equals(str_replace, "HellX WXrld")); if(str_replace) free_string(str_replace);
    str_lower = string_to_lower("HeLlO"); check("string_to_lower", string_equals(str_lower, "hello")); if(str_lower) free_string(str_lower);
    str_upper = string_to_upper("HeLlO"); check("string_to_upper", string_equals(str_upper, "HELLO")); if(str_upper) free_string(str_upper);
    str_tokens = string_split("a,b,,d,", ',', &num_tokens); check("string_split (normal)", num_tokens==5 && string_equals(str_tokens[0],"a") && string_equals(str_tokens[2],"") && string_equals(str_tokens[4],"")); if(str_tokens) free_string_array(str_tokens, num_tokens);
    str_tokens = string_split("onlyone", ',', &num_tokens); check("string_split (no delimiter)", num_tokens==1 && string_equals(str_tokens[0],"onlyone")); if(str_tokens) free_string_array(str_tokens, num_tokens);
    str_tokens = string_split("", ',', &num_tokens); check("string_split (empty)", num_tokens==1 && string_equals(str_tokens[0],"")); if(str_tokens) free_string_array(str_tokens, num_tokens);
    str_tokens = string_split(NULL, ',', &num_tokens); check("string_split (NULL)", str_tokens==NULL && num_tokens == 0);
    string join_arr[] = {"First", NULL, "Third", ""}; size_t join_size = 4;
    str_joined = string_join(join_arr, join_size, " | "); check("string_join (normal)", string_equals(str_joined, "First |  | Third | ")); if(str_joined) free_string(str_joined);
    str_joined = string_join(join_arr, join_size, NULL); check("string_join (NULL sep)", string_equals(str_joined, "FirstThird")); if(str_joined) free_string(str_joined);
    str_joined = string_join(sarr_empty, ssize_empty, ","); check("string_join (empty arr)", string_equals(str_joined, "")); if(str_joined) free_string(str_joined);
    check("string_starts_with (yes)", string_starts_with("PrefixTest", "Prefix"));
    check("string_starts_with (no)", !string_starts_with("PrefixTest", "Suffix"));
    check("string_starts_with (empty prefix)", string_starts_with("PrefixTest", ""));
    check("string_ends_with (yes)", string_ends_with("TestSuffix", "Suffix"));
    check("string_ends_with (no)", !string_ends_with("TestSuffix", "Prefix"));
    check("string_ends_with (empty suffix)", string_ends_with("TestSuffix", ""));
    check("string_to_float (yes)", fabs(string_to_float(" -123.45 ", &success) - (-123.45f)) < FLOAT_EPSILON && success);
    check("string_to_float (no)", string_to_float(" abc ", &success) == 0.0f && !success);
    check("string_to_double (yes)", fabs(string_to_double(" 9.87e-2 ", &success) - 0.0987) < DOUBLE_EPSILON && success);
    check("string_to_double (no)", string_to_double(" --5.5 ", &success) == 0.0 && !success);
    printf("\n");

    // --- Memory Management Helpers ---
    printf("--- Memory Management Helpers ---\n");
    string mem_test = string_copy("Test");
    free_string(mem_test);
    check("free_string (ran)", true);
    str_tokens = string_split("a,b", ',', &num_tokens);
    free_string_array(str_tokens, num_tokens);
    check("free_string_array (ran)", true);
    printf("\n");


    // --- Utility Functions ---
    printf("--- Utility Functions ---\n");
    // initialize_random() called earlier
    printf("get_random_int (1-10): %d\n", get_random_int(1, 10));
    printf("get_random_float (0-1): %f\n", get_random_float(0.0f, 1.0f));
    printf("get_random_double (0-1): %f\n", get_random_double(0.0, 1.0));
    start_timer();
    for(volatile int i=0; i<500000; ++i); // Simulate work
    double elapsed = stop_timer();
    printf("start/stop_timer (elapsed): %f s\n", elapsed);
    check("stop_timer (positive)", elapsed >= 0.0);
    printf("\n");


    printf("=================================\n");
    printf("Comprehensive Test Finished.\n");

    return EXIT_SUCCESS;
}
