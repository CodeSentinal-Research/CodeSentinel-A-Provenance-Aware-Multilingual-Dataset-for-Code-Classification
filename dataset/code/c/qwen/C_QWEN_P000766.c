#include <stdio.h>
#include <string.h>
long long count(char *s, int l, int r) { if(l>r) return 1; if(l==r) return s[l]=='T'?1:0; long long total=0; for(int i=l+1;i<=r;i+=2) { char op=s[i]; long long lT=count(s,l,i-1), lF=count(s,l,i-1)-lT; long long rT=count(s,i+1,r), rF=count(s,i+1,r)-rT; if(op=='&') total+=lT*rT; else if(op=='|') total+=lT*rT+lT*rF+lF*rT; else total+=lT*rF+lF*rT; } return total; }
int main() { char s[201]; scanf("%s",s); printf("%lld\n",count(s,0,strlen(s)-1)); return 0; }
