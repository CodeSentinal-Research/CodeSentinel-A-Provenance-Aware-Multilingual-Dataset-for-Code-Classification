#include <stdio.h>
int main() {
    int a, b, c; scanf("%d%d%d", &a, &b, &c);
    int res = 0;
    for(int i=0; i<32; i++) {
        int ba = (a >> i) & 1, bb = (b >> i) & 1, bc = (c >> i) & 1;
        if(bc) { if(!ba && !bb) res++; }
        else { res += ba + bb; }
    }
    printf("%d\n", res);
    return 0;
}
