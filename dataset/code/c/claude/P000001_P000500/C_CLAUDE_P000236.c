#include<stdio.h>
int max2(int a,int b){return a>b?a:b;}
int main(){int n;scanf("%d",&n);int A[n][n],sm[n][n];for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d",&A[i][j]);sm[n-1][n-1]=A[n-1][n-1];for(int j=n-2;j>=0;j--)sm[n-1][j]=max2(A[n-1][j],sm[n-1][j+1]);for(int i=n-2;i>=0;i--)sm[i][n-1]=max2(A[i][n-1],sm[i+1][n-1]);for(int i=n-2;i>=0;i--)for(int j=n-2;j>=0;j--)sm[i][j]=max2(A[i][j],max2(sm[i+1][j],sm[i][j+1]));int ans=-2147483647;for(int i=0;i<n-1;i++)for(int j=0;j<n-1;j++){int d=sm[i+1][j+1]-A[i][j];if(d>ans)ans=d;}printf("%d\n",ans);}
