#include "example.h"
#include <string.h>

bool is_palindrome(const char *s) {
    size_t len = strlen(s);
    for (size_t i = 0; i < len/2; ++i) {
        if (s[i] != s[len - 1 - i]) {
            return false;
        }
    }
    return true;
}