#include <stdio.h>
#include <math.h>
int main(){int n,t,d=0,s=0;scanf("%d",&n);t=n;while(t>0){d++;t/=10;}t=n;while(t>0){int r=t%10;s+=(int)pow(r,d);t/=10;}printf("%s\n",s==n?"Armstrong":"Not Armstrong");return 0;}
