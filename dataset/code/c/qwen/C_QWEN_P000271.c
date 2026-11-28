#include <stdio.h>
#include <string.h>
int main() {
    char s1[1001], s2[1001]; scanf("%s %s", s1, s2);
    if(strlen(s1) != strlen(s2)) { printf("No\n"); return 0; }
    char concat[2002]; strcpy(concat, s1); strcat(concat, s1);
    printf("%s\n", strstr(concat, s2) ? "Yes" : "No");
    return 0;
}
