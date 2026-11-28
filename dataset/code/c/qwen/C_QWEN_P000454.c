#include <stdio.h>
int main() {
    int n, m; scanf("%d %d", &n, &m);
    int books[1000]; long long total=0, max_book=0;
    for(int i=0; i<n; i++) { scanf("%d", &books[i]); total+=books[i]; if(books[i]>max_book) max_book=books[i]; }
    long long l=max_book, r=total, res=total;
    while(l<=r) {
        long long mid = l+(r-l)/2;
        long long sum=0, students=1;
        for(int i=0; i<n; i++) {
            if(sum+books[i]>mid) { students++; sum=books[i]; }
            else sum+=books[i];
        }
        if(students<=m) { res=mid; r=mid-1; } else l=mid+1;
    }
    printf("%lld\n", res);
    return 0;
}
