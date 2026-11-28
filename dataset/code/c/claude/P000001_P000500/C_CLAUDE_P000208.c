#include <stdio.h>
int main(){int n;scanf("%d",&n);long long A[n][n],s=0;for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%lld",&A[i][j]);for(int i=0;i<n;i++){s+=A[i][i];if(i!=n-1-i)s+=A[i][n-1-i];}printf("%lld\n",s);return 0;}
