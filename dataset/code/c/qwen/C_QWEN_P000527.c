#include <stdio.h>
#include <string.h>
int eval(char *s, int *idx) {
    if(s[*idx]=='t') { (*idx)++; return 1; }
    if(s[*idx]=='f') { (*idx)++; return 0; }
    if(s[*idx]=='!') { (*idx)+=2; int res=eval(s, idx); (*idx)++; return !res; }
    if(s[*idx]=='&') { (*idx)+=2; int res=1; while(s[*idx]!=')') { if(s[*idx]==',') (*idx)++; res &= eval(s, idx); } (*idx)++; return res; }
    if(s[*idx]=='|') { (*idx)+=2; int res=0; while(s[*idx]!=')') { if(s[*idx]==',') (*idx)++; res |= eval(s, idx); } (*idx)++; return res; }
    return 0;
}
int main() {
    char s[20001]; scanf("%s", s);
    int idx=0;
    printf("%s\n", eval(s, &idx) ? "true" : "false");
    return 0;
}
