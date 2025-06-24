#include "unity.h"

/* example tests */
extern void test_empty_string(void);
extern void test_single_char(void);
extern void test_even_palindrome(void);
extern void test_odd_palindrome(void);
extern void test_not_palindrome(void);
extern void test_two_diff_chars(void);

/* strings tests */
extern void test_hello_world(void);

int main(void)
{
    UnityBegin("C Unit Tests");

    /* example tests */
    RUN_TEST(test_empty_string);
    RUN_TEST(test_single_char);
    RUN_TEST(test_even_palindrome);
    RUN_TEST(test_odd_palindrome);
    RUN_TEST(test_not_palindrome);
    RUN_TEST(test_two_diff_chars);

    /* strings tests */
    RUN_TEST(test_hello_world);

    return UnityEnd();
}