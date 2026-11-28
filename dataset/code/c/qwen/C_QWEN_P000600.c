#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int vals[n];
    for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    int odd[n], even[n], o=0, e=0;
    for(int i=0; i<n; i++) { if(i%2==0) odd[o++]=vals[i]; else even[e++]=vals[i]; }
    for(int i=0; i<o; i++) printf("%d ", odd[i]);
    for(int i=0; i<e; i++) printf("%d ", even[i]);
    printf("\n");
    return 0;
}
