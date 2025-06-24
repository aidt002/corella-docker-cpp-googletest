#include <stdio.h>

#include "example.h"
#include "strings.h"


int main(void)
{
    const char *inputs[] = {
        "", "x", "abba", "racecar", "hello", "ab"};

    for (size_t i = 0; i < sizeof(inputs) / sizeof(inputs[0]); ++i)
    {
        char buf[256];
        // copy into mutable buffer
        strncpy(buf, inputs[i], sizeof(buf) - 1);
        buf[sizeof(buf) - 1] = '\0';

        trim_string(buf);
        to_lowercase(buf);

        bool result = is_palindrome(buf);
        // print true/false as strings
        printf("is_palindrome? \"%s\" => %s\n",
               buf,
               result ? "true" : "false");
    }

    return 0;
}