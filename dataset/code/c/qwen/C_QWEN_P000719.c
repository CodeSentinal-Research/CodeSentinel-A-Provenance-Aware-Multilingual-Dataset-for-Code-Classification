#include <stdio.h>
#include <string.h>
void gen(char *s, int i, int dots, char *curr, int ci) { if(dots==3) { if(i<strlen(s)) { int num=atoi(s+i); if(num>=0 && num<=255 && (num==0 || s[i]!='0')) { sprintf(curr+ci,"%d",num); printf("%s\n",curr); } } return; } for(int j=1;j<=3 && i+j<=strlen(s);j++) { int num=atoi(s+i); if(num>=0 && num<=255 && (num==0 || s[i]!='0')) { sprintf(curr+ci,"%d.",num); gen(s,i+j,dots+1,curr,ci+j+1); } } }
int main() { char s[13]; scanf("%s",s); char curr[20]; gen(s,0,0,curr,0); return 0; }
