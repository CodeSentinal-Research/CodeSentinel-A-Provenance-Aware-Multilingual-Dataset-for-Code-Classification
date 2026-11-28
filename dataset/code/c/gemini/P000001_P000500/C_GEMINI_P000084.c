#include <stdio.h>
int main() {
    int age;
    if (scanf("%d", &age) == 1) printf("%s\n", age >= 18 ? "Eligible" : "Not Eligible");
    return 0;
}