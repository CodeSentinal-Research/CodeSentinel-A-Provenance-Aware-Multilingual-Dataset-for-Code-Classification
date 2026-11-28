#include <stdio.h>

int main(void) {
    for (char ch = 'A'; ch <= 'Z'; ch++) printf("%c%s", ch, ch == 'Z' ? "\n" : " ");
    return 0;
}
