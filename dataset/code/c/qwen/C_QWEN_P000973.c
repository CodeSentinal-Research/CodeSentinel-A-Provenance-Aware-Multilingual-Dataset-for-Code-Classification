#include <stdio.h>
int main() {
    int s; scanf("%d", &s);
    int count = 0;
    for(int i=1; i<=6; i++) for(int j=1; j<=6; j++) if(i+j == s) count++;
    printf("%.6f\n", count / 36.0);
    return 0;
}
