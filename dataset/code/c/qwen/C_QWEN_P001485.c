#include <stdio.h>
#include <string.h>

int main() {
    char name[200001], typed[200001];
    scanf("%s %s", name, typed);
    
    int i = 0, j = 0;
    while (j < strlen(typed)) {
        if (i < strlen(name) && name[i] == typed[j]) { i++; j++; }
        else if (j > 0 && typed[j] == typed[j-1]) j++;
        else break;
    }
    printf("%s\n", i == strlen(name) ? "YES" : "NO");
    return 0;
}
