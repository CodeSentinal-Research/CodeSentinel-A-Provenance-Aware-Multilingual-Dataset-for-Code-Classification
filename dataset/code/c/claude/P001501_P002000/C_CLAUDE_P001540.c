#include <stdio.h>
int vow(char c){return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U';}
int main(){char s[1001];scanf(" %[^\n]",s);int c=0;for(int i=0;s[i];i++)if(vow(s[i]))c++;printf("%d\n",c);return 0;}
