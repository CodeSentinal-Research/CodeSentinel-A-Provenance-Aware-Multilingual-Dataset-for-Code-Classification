#include <stdio.h>
int main() { int n; scanf("%d",&n); int a[n]; for(int i=0;i<n;i++) scanf("%d",&a[i]); int q; scanf("%d",&q); while(q--) { int l,r; scanf("%d%d",&l,&r); printf("%d\n",r-l+1); } return 0; }
