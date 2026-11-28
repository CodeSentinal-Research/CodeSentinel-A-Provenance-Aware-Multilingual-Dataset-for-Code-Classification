#include<stdio.h>
#include<string.h>
int main(){char s[100001];fgets(s,sizeof(s),stdin);s[strcspn(s,"\n")]=0;
int slots=1;char*tok=strtok(s,",");
while(tok){if(slots==0){printf("false\n");return 0;}slots--;
    if(strcmp(tok,"#")!=0)slots+=2;tok=strtok(NULL,",");}
printf("%s\n",slots==0?"true":"false");}
