#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int bills[n]; for(int i=0; i<n; i++) scanf("%d", &bills[i]);
    int five = 0, ten = 0;
    for(int i=0; i<n; i++) {
        if(bills[i] == 5) five++;
        else if(bills[i] == 10) { if(five == 0) { printf("NO\n"); return 0; } five--; ten++; }
        else {
            if(ten > 0 && five > 0) { ten--; five--; }
            else if(five >= 3) five -= 3;
            else { printf("NO\n"); return 0; }
        }
    }
    printf("YES\n");
    return 0;
}
