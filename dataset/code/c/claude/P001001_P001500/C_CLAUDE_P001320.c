#include <stdio.h>
void h(int n,char f,char t,char a){if(n==1){printf("Move disk 1 from %c to %c\n",f,t);return;}h(n-1,f,a,t);printf("Move disk %d from %c to %c\n",n,f,t);h(n-1,a,t,f);}
int main(){int n;scanf("%d",&n);h(n,'A','C','B');return 0;}
