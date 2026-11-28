#include <stdio.h>
#include <string.h>
int main() {
    int q; scanf("%d", &q); char doc[100001]=""; int len=0;
    while(q--) {
        char op[20]; scanf("%s", op);
        if(strcmp(op, "type")==0) { char t[1001]; scanf("%s", t); strcat(doc, t); }
        else if(strcmp(op, "print")==0) printf("%s\n", doc);
    }
    return 0;
}
