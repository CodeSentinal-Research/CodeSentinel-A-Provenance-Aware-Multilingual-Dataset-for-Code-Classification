#include <stdio.h>
#include <string.h>
char *map[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void gen(char *d, int i, char *curr, int ci) { if(d[i]=='\0') { curr[ci]='\0'; printf("%s\n",curr); return; } int dig=d[i]-'0'; for(int j=0;map[dig][j];j++) { curr[ci]=map[dig][j]; gen(d,i+1,curr,ci+1); } }
int main() { char d[5]; scanf("%s",d); char curr[10]; gen(d,0,curr,0); return 0; }
