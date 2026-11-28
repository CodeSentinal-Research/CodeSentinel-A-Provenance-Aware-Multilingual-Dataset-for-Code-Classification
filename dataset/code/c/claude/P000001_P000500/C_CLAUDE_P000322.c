#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){char w[101];scanf("%s",w);int n=strlen(w),allU=1,allL=1;for(int i=0;w[i];i++){if(!isupper(w[i]))allU=0;if(!islower(w[i]))allL=0;}int camel=isupper(w[0]);if(camel)for(int i=1;w[i];i++)if(!islower(w[i])){camel=0;break;}printf("%s\n",(allU||allL||camel)?"Yes":"No");}
