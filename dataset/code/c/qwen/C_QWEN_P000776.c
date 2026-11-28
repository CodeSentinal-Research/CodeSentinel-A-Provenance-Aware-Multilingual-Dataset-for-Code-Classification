#include <stdio.h>
#include <string.h>
void gen(char *s, int i, char **dict, int m, char **parts, int pi) { if(s[i]=='\0') { for(int j=0;j<pi;j++) printf("%s ",parts[j]); printf("\n"); return; } for(int j=0;j<m;j++) { int l=strlen(dict[j]); if(strncmp(s+i,dict[j],l)==0) { parts[pi]=dict[j]; gen(s,i+l,dict,m,parts,pi+1); } } }
int main() { char s[21]; int m; scanf("%s%d",s,&m); char *dict[m]; for(int i=0;i<m;i++) { dict[i]=malloc(101); scanf("%s",dict[i]); } char *parts[21]; gen(s,0,dict,m,parts,0); return 0; }
