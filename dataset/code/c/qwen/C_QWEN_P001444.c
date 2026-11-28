#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char words[n][3];
    int count[26][26] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%s", words[i]);
        count[words[i][0]-'a'][words[i][1]-'a']++;
    }
    
    int max_len = 0;
    int mid = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (i == j) {
                int pairs = count[i][j] / 2;
                max_len += pairs * 4;
                if (count[i][j] % 2 == 1) mid = 1;
            } else {
                int pairs = count[i][j] < count[j][i] ? count[i][j] : count[j][i];
                max_len += pairs * 4;
            }
        }
    }
    printf("%d\n", max_len + mid * 2);
    return 0;
}
