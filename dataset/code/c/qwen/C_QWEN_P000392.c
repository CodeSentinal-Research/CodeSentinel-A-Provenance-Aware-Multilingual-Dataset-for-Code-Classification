#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char files[100000][101];
    for(int i=0; i<n; i++) scanf("%s", files[i]);
    char ext[10]; scanf("%s", ext);
    int found = 0;
    for(int i=0; i<n; i++) {
        int len = strlen(files[i]), elen = strlen(ext);
        if(len > elen && strcmp(files[i]+len-elen, ext)==0) { printf("%s\n", files[i]); found=1; }
    }
    if(!found) printf("No Files Found\n");
    return 0;
}
