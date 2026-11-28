#include <stdio.h>
int main() {
    int q; scanf("%d", &q); char doc[100001]="";
    while(q--) { char op[20]; scanf("%s", op); if(op[0]=='p') printf("%s\n", doc); }
    return 0;
}
