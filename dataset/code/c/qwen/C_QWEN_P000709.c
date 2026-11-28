#include <stdio.h>
#include <string.h>
void swap(char *a, char *b) { char t=*a; *a=*b; *b=t; }
void gen(char *s, int l, int r) { if(l==r) { printf("%s\n",s); return; } for(int i=l;i<=r;i++) { swap(&s[l],&s[i]); gen(s,l+1,r); swap(&s[l],&s[i]); } }
int main() { char s[10]; scanf("%s",s); gen(s,0,strlen(s)-1); return 0; }
