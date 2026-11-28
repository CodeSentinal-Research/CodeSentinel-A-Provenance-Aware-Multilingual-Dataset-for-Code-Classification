#include <stdio.h>
#include <string.h>
int main(){int n,d=0;scanf("%d",&n);char op[20];for(int i=0;i<n;i++){scanf("%s",op);if(strcmp(op,"../")==0){if(d>0)d--;}else if(strcmp(op,"./")==0){}else d++;}printf("%d\n",d);return 0;}
