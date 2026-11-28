#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    double pos[n], spd[n], res[n];
    for(int i=0; i<n; i++) scanf("%lf %lf", &pos[i], &spd[i]);
    for(int i=0; i<n; i++) res[i]=-1;
    int stack[n], top=-1;
    for(int i=n-1; i>=0; i--) {
        while(top>=0) {
            int j=stack[top];
            if(spd[i]<=spd[j]) { top--; continue; }
            double t=(pos[j]-pos[i])/(spd[i]-spd[j]);
            if(res[j]==-1 || t<=res[j]) { res[i]=t; break; }
            top--;
        }
        stack[++top]=i;
    }
    for(int i=0; i<n; i++) printf("%.6f%c", res[i], i==n-1?'\n':' ');
    return 0;
}
