#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char ops[1001][10];
    for(int i=0; i<n; i++) scanf("%s", ops[i]);
    int depth=0;
    for(int i=0; i<n; i++) {
        if(strcmp(ops[i], "../")==0) { if(depth>0) depth--; }
        else if(strcmp(ops[i], "./")!=0) depth++;
    }
    printf("%d\n", depth);
    return 0;
}
