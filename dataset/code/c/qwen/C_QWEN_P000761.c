#include <stdio.h>
#include <string.h>
int count(char *s, int i, char *t, int j) { if(j==strlen(t)) return 1; if(i==strlen(s)) return 0; if(s[i]==t[j]) return count(s,i+1,t,j+1)+count(s,i+1,t,j); return count(s,i+1,t,j); }
int main() { char s[31], t[31]; scanf("%s%s",s,t); printf("%d\n",count(s,0,t,0)); return 0; }
