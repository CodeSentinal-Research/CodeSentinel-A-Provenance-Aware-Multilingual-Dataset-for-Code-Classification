#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char regs[100000][20], models[100000][50];
    for(int i=0; i<n; i++) scanf("%s %s", regs[i], models[i]);
    char q[20]; scanf("%s", q);
    int found = 0;
    for(int i=0; i<n; i++) if(strcmp(regs[i], q)==0) { printf("%s %s\n", regs[i], models[i]); found=1; break; }
    if(!found) printf("Vehicle Not Found\n");
    return 0;
}
