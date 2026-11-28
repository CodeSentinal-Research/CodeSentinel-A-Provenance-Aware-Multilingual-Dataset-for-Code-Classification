#include <stdio.h>
int main(){long long n,o,r=0;scanf("%lld",&n);o=n;while(n>0){r=r*10+n%10;n/=10;}printf("%s\n",o==r?"Yes":"No");return 0;}
