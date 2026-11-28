#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    long long arr[n], m1=-2000000000LL, m2=-2000000000LL, m3=-2000000000LL;
    for(int i=0; i<n; i++) {
        scanf("%lld", &arr[i]);
        if(arr[i]>m1) { m3=m2; m2=m1; m1=arr[i]; }
        else if(arr[i]>m2 && arr[i]<m1) { m3=m2; m2=arr[i]; }
        else if(arr[i]>m3 && arr[i]<m2) m3=arr[i];
    }
    printf("%lld\n", m3 == -2000000000LL ? m1 : m3);
    return 0;
}
