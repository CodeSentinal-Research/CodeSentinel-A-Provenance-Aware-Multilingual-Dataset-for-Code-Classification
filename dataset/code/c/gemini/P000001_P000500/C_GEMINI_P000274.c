#include <string.h>

int strStr(char* haystack, char* needle) {
    char* pos = strstr(haystack, needle);
    if (!pos) return -1;
    return (int)(pos - haystack);
}