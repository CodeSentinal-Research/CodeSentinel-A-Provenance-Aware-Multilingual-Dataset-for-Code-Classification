#include<stdio.h>
int main(){int n;scanf("%d",&n);double a[n];for(int i=0;i<n;i++)scanf("%lf",&a[i]);int k;scanf("%d",&k);
double s=0;for(int i=0;i<k;i++)s+=a[i];double best=s;
for(int i=k;i<n;i++){s+=a[i]-a[i-k];if(s>best)best=s;}
printf("%.5f\n",best/k);}
