#include<stdio.h>
#include<math.h>
double det(double A[][20],int n){double M[20][20];for(int i=0;i<n;i++)for(int j=0;j<n;j++)M[i][j]=A[i][j];double d=1;for(int i=0;i<n;i++){int p=i;for(int k=i+1;k<n;k++)if(fabs(M[k][i])>fabs(M[p][i]))p=k;if(p!=i){for(int j=0;j<n;j++){double t=M[i][j];M[i][j]=M[p][j];M[p][j]=t;}d*=-1;}if(M[i][i]==0)return 0;d*=M[i][i];for(int k=i+1;k<n;k++){double f=M[k][i]/M[i][i];for(int j=i;j<n;j++)M[k][j]-=f*M[i][j];}}return d;}
int main(){int n;scanf("%d",&n);double A[20][20];for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%lf",&A[i][j]);printf("%d\n",(int)round(det(A,n)));}
