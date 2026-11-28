#include <stdio.h>
int main() {
    int d;
    if (scanf("%d", &d) == 1) {
        int y = d / 365;
        int rem = d % 365;
        int w = rem / 7;
        int days = rem % 7;
        printf("%d Years %d Weeks %d Days\n", y, w, days);
    }
    return 0;
}