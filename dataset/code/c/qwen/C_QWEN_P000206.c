#include <stdio.h>
int main() {
    int m, n; scanf("%d %d", &m, &n);
    int a[m], b[n];
    for(int i=0; i<m; i++) scanf("%d", &a[i]);
    for(int i=0; i<n; i++) scanf("%d", &b[i]);
    int i=0, j=0, count=0;
    double med1=0, med2=0;
    int total = m+n;
    while(count <= total/2) {
        med2 = med1;
        med1 = (i<m && (j>=n || a[i]<b[j])) ? a[i++] : b[j++];
        count++;
    }
    if(total%2==0) printf("%.2f\n", (med1+med2)/2.0);
    else printf("%.2f\n", med1);
    return 0;
}
