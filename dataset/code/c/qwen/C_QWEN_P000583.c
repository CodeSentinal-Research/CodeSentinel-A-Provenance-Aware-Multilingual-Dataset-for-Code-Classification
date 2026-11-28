#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int vals[n];
    for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    int slow=0, fast=0;
    do { slow=vals[slow]; fast=vals[vals[fast]]; } while(slow!=fast);
    slow=0;
    while(slow!=fast) { slow=vals[slow]; fast=vals[fast]; }
    printf("%s\n", slow>=0 ? "true" : "false");
    return 0;
}
