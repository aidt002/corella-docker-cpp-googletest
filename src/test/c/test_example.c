#include "unity.h"
#include "example.h"

void test_empty_string(void) {
    TEST_ASSERT_TRUE(is_palindrome(""));
}

void test_single_char(void) {
    TEST_ASSERT_TRUE(is_palindrome("x"));
}

void test_even_palindrome(void) {
    TEST_ASSERT_TRUE(is_palindrome("abba"));
}

void test_odd_palindrome(void) {
    TEST_ASSERT_TRUE(is_palindrome("racecar"));
}

void test_not_palindrome(void) {
    TEST_ASSERT_FALSE(is_palindrome("hello"));
}

void test_two_diff_chars(void) {
    TEST_ASSERT_FALSE(is_palindrome("ab"));
}