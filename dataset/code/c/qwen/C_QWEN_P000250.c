#include <stdio.h>
int det(int mat[5][5], int n) {
    if(n==1) return mat[0][0];
    if(n==2) return mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0];
    int d=0, sub[5][5];
    for(int f=0; f<n; f++) {
        int si=0, sj=0;
        for(int i=1; i<n; i++) {
            sj=0;
            for(int j=0; j<n; j++) {
                if(j==f) continue;
                sub[si][sj++] = mat[i][j];
            }
            si++;
        }
        d += (f%2==0 ? 1 : -1) * mat[0][f] * det(sub, n-1);
    }
    return d;
}
int main() {
    int n; scanf("%d", &n);
    int mat[5][5];
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) scanf("%d", &mat[i][j]);
    printf("%d\n", det(mat, n));
    return 0;
}
