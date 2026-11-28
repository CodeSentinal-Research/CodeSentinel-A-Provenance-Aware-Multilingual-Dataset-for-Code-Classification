#include <stdio.h>
#include <string.h>
int match(char *s, int i, char *p, int j) { if(j==strlen(p)) return i==strlen(s); if(p[j]=='?') return i<strlen(s) && match(s,i+1,p,j+1); if(p[j]=='*') return match(s,i,p,j+1) || (i<strlen(s) && match(s,i+1,p,j)); return i<strlen(s) && s[i]==p[j] && match(s,i+1,p,j+1); }
int main() { char s[201], p[201]; scanf("%s%s",s,p); printf("%s\n",match(s,0,p,0)?"true":"false"); return 0; }
