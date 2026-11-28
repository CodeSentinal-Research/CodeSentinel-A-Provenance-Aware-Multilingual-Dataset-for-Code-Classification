#include <stdio.h>

int main() {
    int u;
    scanf("%d", &u);
    double b = 0;
    if (u <= 100) b = u * 10;
    else if (u <= 200) b = 1000 + (u - 100) * 15;
    else if (u <= 300) b = 2500 + (u - 200) * 20;
    else b = 4500 + (u - 300) * 25;
    printf("%.2f\n", b);
    return 0;
}
