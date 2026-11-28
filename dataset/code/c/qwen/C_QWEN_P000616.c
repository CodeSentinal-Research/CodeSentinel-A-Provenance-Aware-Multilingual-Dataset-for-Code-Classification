#include <stdio.h>
int main() {
    int n; scanf("%d", &n); int vals[n]; for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    int odd[n], even[n], o=0, e=0;
    for(int i=0; i<n; i++) { if(i%2==0) odd[o++]=vals[i]; else even[e++]=vals[i]; }
    for(int i=e-1; i>=0; i--) even[i] = even[i]; 
    int res[n], idx=0, ev_idx=e-1;
    for(int i=0; i<o; i++) { res[idx++]=odd[i]; if(ev_idx>=0) res[idx++]=even[ev_idx--]; }
    for(int i=0; i<n; i++) printf("%d ", res[i]);
    printf("\n");
    return 0;
}
