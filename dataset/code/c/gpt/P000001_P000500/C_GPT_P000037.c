#include <stdio.h>
#include <string.h>

int main(void) {
    char binary[65];
    unsigned long long decimal = 0;
    if (scanf("%64s", binary) != 1) return 1;
    for (int i = 0; binary[i] != '\0'; i++) decimal = decimal * 2 + (binary[i] - '0');
    printf("%llu\n", decimal);
    return 0;
}
