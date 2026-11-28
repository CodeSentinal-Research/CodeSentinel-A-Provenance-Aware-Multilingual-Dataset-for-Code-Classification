#include <stdio.h>

int main(void) {
    for (char ch = 'Z'; ch >= 'A'; ch--) printf("%c%s", ch, ch == 'A' ? "\n" : " ");
    return 0;
}
