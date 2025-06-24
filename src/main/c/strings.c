
#include <ctype.h>
#include <string.h>

#include "strings.h"

void to_lowercase(char *str)
{
    for (size_t i = 0; str[i] != '\0'; ++i)
    {
        // explicit cast back to char
        str[i] = (char)tolower((unsigned char)str[i]);
    }
}

void trim_string(char *str)
{
    // trim leading
    char *start = str;
    while (isspace((unsigned char)*start))
    {
        start++;
    }
    memmove(str, start, strlen(start) + 1);

    // trim trailing
    char *end = str + strlen(str) - 1;
    while (end >= str && isspace((unsigned char)*end))
    {
        *end-- = '\0';
    }
}
