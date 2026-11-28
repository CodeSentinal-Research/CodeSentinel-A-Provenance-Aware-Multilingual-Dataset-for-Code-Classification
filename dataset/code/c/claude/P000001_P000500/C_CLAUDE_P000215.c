#include <stdio.h>
int main(){
    int n,k; scanf("%d %d",&n,&k);
    double a[n]; for(int i=0;i<n;i++) scanf("%lf",&a[i]);
    double win=0;
    for(int i=0;i<k;i++) win+=a[i];
    double best=win;
    for(int i=k;i<n;i++){win+=a[i]-a[i-k];if(win>best)best=win;}
    printf("%.5f\n",best/k);
}
