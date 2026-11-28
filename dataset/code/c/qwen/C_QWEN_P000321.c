#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char words[100][21];
    for(int i=0; i<n; i++) scanf("%s", words[i]);
    char r1[] = "qwertyuiop", r2[] = "asdfghjkl", r3[] = "zxcvbnm";
    for(int i=0; i<n; i++) {
        int row = -1, valid = 1;
        for(int j=0; words[i][j]; j++) {
            char c = words[i][j] | 32;
            int cur_row = strchr(r1, c) ? 1 : (strchr(r2, c) ? 2 : 3);
            if(row == -1) row = cur_row;
            else if(row != cur_row) { valid = 0; break; }
        }
        if(valid) printf("%s\n", words[i]);
    }
    return 0;
}
