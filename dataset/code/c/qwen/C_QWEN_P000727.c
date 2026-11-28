#include <stdio.h>
#include <string.h>
void gen(char *s, int i, char **dict, int m, char *curr, int ci) { if(s[i]=='\0') { curr[ci-1]='\0'; printf("%s\n",curr); return; } for(int j=0;j<m;j++) { int l=strlen(dict[j]); if(strncmp(s+i,dict[j],l)==0) { sprintf(curr+ci,"%s ",dict[j]); gen(s,i+l,dict,m,curr,ci+l+1); } } }
int main() { char s[21]; int m; scanf("%s%d",s,&m); char *dict[m]; for(int i=0;i<m;i++) { dict[i]=malloc(101); scanf("%s",dict[i]); } char curr[1001]; gen(s,0,dict,m,curr,0); return 0; }
