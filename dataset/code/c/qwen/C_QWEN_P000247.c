#include <stdio.h>
int main() {
    int r, c; scanf("%d %d", &r, &c);
    int a[r][c], b[r][c], ident=1;
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) scanf("%d", &a[i][j]);
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) scanf("%d", &b[i][j]);
    for(int i=0; i<r && ident; i++) for(int j=0; j<c && ident; j++) if(a[i][j] != b[i][j]) ident = 0;
    printf("%s\n", ident ? "Identical" : "Not Identical");
    return 0;
}
