#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char words[n][101];
    for (int i = 0; i < n; i++) scanf("%s", words[i]);
    
    char row1[] = "qwertyuiop";
    char row2[] = "asdfghjkl";
    char row3[] = "zxcvbnm";
    
    for (int i = 0; i < n; i++) {
        int r = -1;
        int valid = 1;
        for (int j = 0; words[i][j]; j++) {
            char c = words[i][j];
            if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
            int cur_r = -1;
            if (strchr(row1, c)) cur_r = 1;
            else if (strchr(row2, c)) cur_r = 2;
            else if (strchr(row3, c)) cur_r = 3;
            
            if (r == -1) r = cur_r;
            else if (r != cur_r) {
                valid = 0;
                break;
            }
        }
        if (valid) printf("%s\n", words[i]);
    }
    return 0;
}
