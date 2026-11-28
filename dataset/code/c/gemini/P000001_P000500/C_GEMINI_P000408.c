#include <stdio.h>
#include <string.h>
#define MAX_N 10005
char emails[MAX_N][128];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%127s", emails[i]);
        char domain[64], target[64];
        scanf("%63s", domain);
        if (domain[0] != '@') snprintf(target, sizeof(target), "@%s", domain);
        else strcpy(target, domain);
        int tlen = strlen(target);
        for (int i = 0; i < n; i++) {
            int elen = strlen(emails[i]);
            if (elen >= tlen && strcmp(emails[i] + elen - tlen, target) == 0) {
                printf("%s\n", emails[i]);
            }
        }
    }
    return 0;
}