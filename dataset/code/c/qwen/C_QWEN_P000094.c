#include <stdio.h>

int main() {
    int n, s = 0;
    scanf("%d", &n);
    int t = n;
    while (t > 0) { s += t % 10; t /= 10; }
    printf("%s\n", n % s == 0 ? "Harshad" : "Not Harshad");
    return 0;
}
