#include <stdio.h>
#include <string.h>
void gen(char *s, int i, char *curr, int ci) { if(s[i]=='\0') { curr[ci]='\0'; printf("%s\n",curr); return; } for(int j=i;j<strlen(s);j++) { if(s[j]>='0' && s[j]<='9') { long long num=0; for(int k=i;k<=j;k++) num=num*10+(s[k]-'0'); sprintf(curr+ci,"%lld",num); gen(s,j+1,curr,ci+j-i+1); } } }
int main() { char s[21]; scanf("%s",s); char curr[50]; gen(s,0,curr,0); return 0; }
