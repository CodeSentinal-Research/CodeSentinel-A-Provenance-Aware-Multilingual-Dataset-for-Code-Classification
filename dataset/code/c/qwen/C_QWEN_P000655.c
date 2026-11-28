#include <stdio.h>
int main() {
    int n; scanf("%d", &n); int vals[n]; for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    int mid = n/2;
    printf("List1: "); for(int i=0; i<=mid; i++) printf("%d ", vals[i]); printf("\nList2: "); for(int i=mid+1; i<n; i++) printf("%d ", vals[i]);
    printf("\n");
    return 0;
}
