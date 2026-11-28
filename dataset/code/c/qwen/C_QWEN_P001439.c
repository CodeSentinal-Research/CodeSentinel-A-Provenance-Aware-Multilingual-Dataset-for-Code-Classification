#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char words[n][101];
    for (int i = 0; i < n; i++) scanf("%s", words[i]);
    
    char morse[][5] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
    char codes[n][101];
    for (int i = 0; i < n; i++) {
        codes[i][0] = '\0';
        for (int j = 0; words[i][j]; j++) {
            strcat(codes[i], morse[words[i][j] - 'a']);
        }
    }
    
    int unique = 0;
    for (int i = 0; i < n; i++) {
        int dup = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(codes[i], codes[j]) == 0) { dup = 1; break; }
        }
        if (!dup) unique++;
    }
    printf("%d\n", unique);
    return 0;
}
