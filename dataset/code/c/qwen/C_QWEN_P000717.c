#include <stdio.h>
#include <string.h>
int isPal(char *s, int l, int r) { while(l<r) if(s[l++]!=s[r--]) return 0; return 1; }
void gen(char *s, int i, char **parts, int pi) { if(s[i]=='\0') { for(int j=0;j<pi;j++) printf("%s ",parts[j]); printf("\n"); return; } for(int j=i;s[j];j++) { if(isPal(s,i,j)) { parts[pi]=strndup(s+i,j-i+1); gen(s,j+1,parts,pi+1); } } }
int main() { char s[17]; scanf("%s",s); char *parts[17]; gen(s,0,parts,0); return 0; }
