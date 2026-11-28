#include <stdio.h>
#include <string.h>

#define MAX_N 10005
char files[MAX_N][128];

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            scanf("%127s", files[i]);
        }
        char ext[32];
        scanf("%31s", ext);
        char target_ext[32];
        if (ext[0] != '.') {
            snprintf(target_ext, sizeof(target_ext), ".%s", ext);
        } else {
            strcpy(target_ext, ext);
        }
        int elen = strlen(target_ext);
        for (int i = 0; i < n; i++) {
            int flen = strlen(files[i]);
            if (flen >= elen && strcmp(files[i] + flen - elen, target_ext) == 0) {
                printf("%s\n", files[i]);
            }
        }
    }
    return 0;
}