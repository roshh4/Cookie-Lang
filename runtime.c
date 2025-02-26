#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Runtime helper: Concatenates two strings.
char* concat_strings(char* s1, char* s2) {
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    char* result = (char*) malloc(len1 + len2 + 1);
    if (!result) return NULL;
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

// Reads a line from stdin into buffer (up to size-1 characters).
// Returns 1 on success, 0 on failure.
static int read_line(char *buffer, size_t size) {
    if (fgets(buffer, size, stdin) == NULL)
        return 0;
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n')
        buffer[len - 1] = '\0';
    return 1;
}

// read_int(): Reads and validates an integer.
int read_int() {
    char buffer[128];
    if (!read_line(buffer, sizeof(buffer))) {
        fprintf(stderr, "Error reading input.\n");
        return 0;
    }
    char *endptr;
    long val = strtol(buffer, &endptr, 10);
    while (isspace((unsigned char)*endptr)) endptr++;
    if (*endptr != '\0') {
        printf("Input Is not of type: Int\n");
        return 0;
    }
    return (int)val;
}

// read_float(): Reads and validates a float.
float read_float() {
    char buffer[128];
    if (!read_line(buffer, sizeof(buffer))) {
        fprintf(stderr, "Error reading input.\n");
        return 0.0f;
    }
    char *endptr;
    float val = strtof(buffer, &endptr);
    while (isspace((unsigned char)*endptr)) endptr++;
    if (*endptr != '\0') {
        printf("Input Is not of type: Float\n");
        return 0.0f;
    }
    return val;
}

// read_bool(): Reads and validates a boolean (only accepts "true" or "false").
int read_bool() {
    char buffer[128];
    if (!read_line(buffer, sizeof(buffer))) {
        fprintf(stderr, "Error reading input.\n");
        return 0;
    }
    if (strcmp(buffer, "true") == 0)
        return 1;
    else if (strcmp(buffer, "false") == 0)
        return 0;
    else {
        printf("Input Is not of type: Bool\n");
        return 0;
    }
}

// read_char(): Reads and validates a single character.
char read_char() {
    char buffer[128];
    if (!read_line(buffer, sizeof(buffer))) {
        fprintf(stderr, "Error reading input.\n");
        return '\0';
    }
    char *ptr = buffer;
    while (isspace((unsigned char)*ptr)) ptr++;
    size_t len = strlen(ptr);
    if (len != 1) {
        printf("Input Is not of type: Char\n");
        return '\0';
    }
    return ptr[0];
}

// read_string(): Reads a line as a string (any input is accepted).
char* read_string() {
    char buffer[1024];
    if (!read_line(buffer, sizeof(buffer))) {
        fprintf(stderr, "Error reading input.\n");
        return strdup("");
    }
    return strdup(buffer);
}


// Converts an integer to its string representation.
// Caller is responsible for freeing the returned string.
char* int_to_string(int x) {
    char buffer[32];
    snprintf(buffer, sizeof(buffer), "%d", x);
    return strdup(buffer);
}

// Converts a float to its string representation.
// Caller is responsible for freeing the returned string.
char* float_to_string(float f) {
    char buffer[32];
    snprintf(buffer, sizeof(buffer), "%.6g", f);
    return strdup(buffer);
}

// Converts a boolean (0 or 1) to its string representation.
// Caller is responsible for freeing the returned string.
char* bool_to_string(int b) {
    return strdup(b ? "true" : "false");
}

// Converts a character to a string.
// Caller is responsible for freeing the returned string.
char* char_to_string(char c) {
    char buffer[2];
    buffer[0] = c;
    buffer[1] = '\0';
    return strdup(buffer);
}

// Converts a string to an integer.
// If the string does not represent a valid int, prints an error and exits.
int string_to_int(const char* s) {
    char* endptr;
    long result = strtol(s, &endptr, 10);
    if (s == endptr || *endptr != '\0') {
        fprintf(stderr, "Conversion Error: Input \"%s\" is not a valid int.\n", s);
        exit(EXIT_FAILURE);
    }
    return (int)result;
}

// Converts a string to a float.
// If the string does not represent a valid float, prints an error and exits.
float string_to_float(const char* s) {
    char* endptr;
    float result = strtof(s, &endptr);
    if (s == endptr || *endptr != '\0') {
        fprintf(stderr, "Conversion Error: Input \"%s\" is not a valid float.\n", s);
        exit(EXIT_FAILURE);
    }
    return result;
}

// Converts a string to a boolean.
// Only accepts exactly "true" or "false" (case-sensitive).
// If the input is not valid, prints an error and exits.
int string_to_bool(const char* s) {
    if (strcmp(s, "true") == 0)
        return 1;
    else if (strcmp(s, "false") == 0)
        return 0;
    else {
        fprintf(stderr, "Conversion Error: Input \"%s\" is not a valid bool.\n", s);
        exit(EXIT_FAILURE);
    }
}

// Converts a string to a char by taking its first character.
// If the string is empty, prints an error and exits.
char string_to_char(const char* s) {
    if (s == NULL || strlen(s) == 0) {
        fprintf(stderr, "Conversion Error: Input string is empty; cannot convert to char.\n");
        exit(EXIT_FAILURE);
    }
    return s[0];
}