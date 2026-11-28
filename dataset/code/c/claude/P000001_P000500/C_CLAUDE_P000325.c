#include<stdio.h>
#include<string.h>
int main(){char a[101],b[101];scanf("%s %s",a,b);if(strcmp(a,b)==0)printf("-1\n");else{int la=strlen(a),lb=strlen(b);printf("%d\n",la>lb?la:lb);}}
