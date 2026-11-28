#include <stdio.h>
#include <string.h>
int match(char *s, int i, char *p, int j) { if(j==strlen(p)) return i==strlen(s); if(j+1<strlen(p) && p[j+1]=='*') return match(s,i,p,j+2) || (i<strlen(s) && (s[i]==p[j] || p[j]=='.') && match(s,i+1,p,j)); if(i<strlen(s) && (s[i]==p[j] || p[j]=='.')) return match(s,i+1,p,j+1); return 0; }
int main() { char s[21], p[21]; scanf("%s%s",s,p); printf("%s\n",match(s,0,p,0)?"true":"false"); return 0; }
