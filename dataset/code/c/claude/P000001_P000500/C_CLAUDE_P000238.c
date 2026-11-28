#include<stdio.h>
#include<math.h>
int main(){int n;scanf("%d",&n);double A[n][n];for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%lf",&A[i][j]);int ok=1;for(int i=0;i<n&&ok;i++)for(int j=0;j<n&&ok;j++){double d=0;for(int k=0;k<n;k++)d+=A[i][k]*A[j][k];double exp=(i==j)?1.0:0.0;if(fabs(d-exp)>1e-6)ok=0;}printf("%s\n",ok?"Yes":"No");}
