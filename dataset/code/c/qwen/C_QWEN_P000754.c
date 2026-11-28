#include <stdio.h>
#include <string.h>
#include <ctype.h>
void gen(char *s, int i, char *curr) { if(s[i]=='\0') { curr[i]='\0'; printf("%s\n",curr); return; } if(isalpha(s[i])) { curr[i]=tolower(s[i]); gen(s,i+1,curr); curr[i]=toupper(s[i]); gen(s,i+1,curr); } else { curr[i]=s[i]; gen(s,i+1,curr); } }
int main() { char s[16]; scanf("%s",s); char curr[16]; gen(s,0,curr); return 0; }
