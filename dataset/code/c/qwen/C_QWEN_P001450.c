#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int v;
    scanf("%d", &v);
    char votes[v][27];
    for (int i = 0; i < v; i++) scanf("%s", votes[i]);
    
    int count[26][26] = {0};
    int teams = strlen(votes[0]);
    for (int i = 0; i < v; i++) {
        for (int j = 0; votes[i][j]; j++) {
            count[votes[i][j]-'a'][j]++;
        }
    }
    
    char res[27];
    strcpy(res, votes[0]);
    // Sort res based on count
    for (int i = 0; i < teams - 1; i++) {
        for (int j = i + 1; j < teams; j++) {
            int swap = 0;
            for (int k = 0; k < teams; k++) {
                if (count[res[i]-'a'][k] < count[res[j]-'a'][k]) { swap = 1; break; }
                if (count[res[i]-'a'][k] > count[res[j]-'a'][k]) break;
            }
            if (swap || (count[res[i]-'a'][teams-1] == count[res[j]-'a'][teams-1] && res[i] > res[j])) {
                char t = res[i]; res[i] = res[j]; res[j] = t;
            }
        }
    }
    printf("%s\n", res);
    return 0;
}
