#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Concatenates two strings and returns a newly allocated string.
char* concat_strings(char* s1, char* s2) {
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    char* result = (char*) malloc(len1 + len2 + 1);
    if (!result) return NULL;
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}
