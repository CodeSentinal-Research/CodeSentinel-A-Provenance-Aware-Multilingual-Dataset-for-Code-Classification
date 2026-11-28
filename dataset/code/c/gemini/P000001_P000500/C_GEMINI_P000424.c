#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_N 10005
char emails[MAX_N][64];
bool printed[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%63s", emails[i]);
        for (int i = 0; i < n; i++) {
            if (printed[i]) continue;
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (strcmp(emails[i], emails[j]) == 0) count++;
            }
            if (count > 1) {
                printf("%s\n", emails[i]);
                for (int j = i; j < n; j++) {
                    if (strcmp(emails[i], emails[j]) == 0) printed[j] = true;
                }
            }
        }
    }
    return 0;
}