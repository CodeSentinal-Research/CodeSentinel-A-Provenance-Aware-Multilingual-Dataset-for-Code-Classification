#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main(){
    char s[101];scanf("%s",s);
    char*end;strtod(s,&end);
    while(*end)if(!isspace((unsigned char)*end++)){printf("No\n");return 0;}
    if(end==s){printf("No\n");return 0;}
    printf("Yes\n");
}
