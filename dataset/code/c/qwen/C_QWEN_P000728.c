#include <stdio.h>
#include <string.h>
int minRem=100;
void gen(char *s, int i, char *curr, int ci, int rem, int open) { if(i==strlen(s)) { if(open==0 && rem<=minRem) { if(rem<minRem) { minRem=rem; printf("%s\n",curr); } else printf("%s\n",curr); } return; } if(s[i]=='(' || s[i]==')') { gen(s,i+1,curr,ci,rem+1,open); curr[ci]=s[i]; gen(s,i+1,curr,ci+1,rem,open+(s[i]=='('?1:-1)); } else { curr[ci]=s[i]; gen(s,i+1,curr,ci+1,rem,open); } }
int main() { char s[26]; scanf("%s",s); char curr[26]; gen(s,0,curr,0,0,0); return 0; }
