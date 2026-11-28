#include <stdio.h>
#include <string.h>
int main() {
    char source[1001], target[1001]; scanf("%s %s", source, target);
    int count = 0, j = 0;
    while(j < strlen(target)) {
        int i = 0;
        while(i < strlen(source) && target[j] != source[i]) i++;
        if(i == strlen(source)) { printf("-1\n"); return 0; }
        while(i < strlen(source) && j < strlen(target)) {
            if(target[j] == source[i]) j++;
            i++;
        }
        count++;
    }
    printf("%d\n", count);
    return 0;
}
