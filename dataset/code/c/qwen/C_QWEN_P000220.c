#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int mat[n][n];
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) scanf("%d", &mat[i][j]);
    int top=0, bottom=n-1;
    while(top < bottom) {
        if(mat[top][bottom]) top++;
        else bottom--;
    }
    int celeb = top;
    for(int i=0; i<n; i++) {
        if(i != celeb && (mat[celeb][i] || !mat[i][celeb])) { printf("-1\n"); return 0; }
    }
    printf("%d\n", celeb);
    return 0;
}
