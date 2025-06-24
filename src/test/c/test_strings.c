#include <string.h>

#include "unity.h"
#include "strings.h"

void test_hello_world(void)
{
    char str[] = "Hello World";
    to_lowercase(str);
    TEST_ASSERT_EQUAL_STRING("hello world", str);
}
