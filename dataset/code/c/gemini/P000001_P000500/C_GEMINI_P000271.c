#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool areRotations(char* s1, char* s2) {
    if (strlen(s1) != strlen(s2)) return false;
    int n = strlen(s1);
    char* temp = (char*)malloc((2 * n + 1) * sizeof(char));
    strcpy(temp, s1);
    strcat(temp, s1);
    bool ans = strstr(temp, s2) != NULL;
    free(temp);
    return ans;
}