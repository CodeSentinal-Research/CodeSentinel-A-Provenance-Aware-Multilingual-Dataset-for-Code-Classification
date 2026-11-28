#include <stdio.h>
#include <string.h>
void gen(char *s, int i, char *curr, int ci) { if(s[i]=='\0') { curr[ci]='\0'; printf("%s\n",curr); return; } gen(s,i+1,curr,ci); curr[ci]=s[i]; gen(s,i+1,curr,ci+1); }
int main() { char s[21]; scanf("%s",s); char curr[21]; gen(s,0,curr,0); return 0; }
