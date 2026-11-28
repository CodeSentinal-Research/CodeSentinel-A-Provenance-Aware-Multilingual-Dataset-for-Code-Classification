#include <stdio.h>
int main() { int n,k; scanf("%d%d",&n,&k); double a[n]; double sum=0; for(int i=0;i<k;i++) { scanf("%lf",&a[i]); sum+=a[i]; } double maxAvg=sum/k; for(int i=k;i<n;i++) { scanf("%lf",&a[i]); sum+=a[i]-a[i-k]; if(sum/k>maxAvg) maxAvg=sum/k; } printf("%.5f\n",maxAvg); return 0; }
