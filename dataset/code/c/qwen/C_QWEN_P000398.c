#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char regs[100000][20], mans[100000][50];
    for(int i=0; i<n; i++) scanf("%s %s", regs[i], mans[i]);
    char q[50]; scanf("%s", q);
    int found = 0;
    for(int i=0; i<n; i++) if(strcmp(mans[i], q)==0) { printf("%s %s\n", regs[i], mans[i]); found=1; }
    if(!found) printf("No Vehicles Found\n");
    return 0;
}
