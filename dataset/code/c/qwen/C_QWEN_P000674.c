#include <stdio.h>
int main() {
    int n; scanf("%d", &n); int vals[n]; for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    for(int i=1; i<n; i+=2) { if(i+1<n && vals[i]<vals[i+1]) { int t=vals[i]; vals[i]=vals[i+1]; vals[i+1]=t; } }
    for(int i=0; i<n; i++) printf("%d ", vals[i]);
    printf("\n");
    return 0;
}
