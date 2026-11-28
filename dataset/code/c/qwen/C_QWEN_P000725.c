#include <stdio.h>
#include <string.h>
int split(char *s, int i, long long prev) { if(i==strlen(s)) return 1; long long num=0; for(int j=i;j<strlen(s);j++) { num=num*10+(s[j]-'0'); if(prev==-1 || prev-num==1) { if(split(s,j+1,num)) return 1; if(num>1000000000000000000LL) break; } } return 0; }
int main() { char s[21]; scanf("%s",s); printf("%s\n",split(s,0,-1)?"true":"false"); return 0; }
