#include <stdio.h>
int main() {
    int r, c; scanf("%d %d", &r, &c);
    int mat[r][c];
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) scanf("%d", &mat[i][j]);
    int first = 1;
    for(int sum=0; sum<r+c-1; sum++) {
        int start_i = sum < c ? 0 : sum - c + 1;
        int end_i = sum < r ? sum : r - 1;
        if(sum % 2 == 0) { for(int i=end_i; i>=start_i; i--) { if(!first) printf(" "); printf("%d", mat[i][sum-i]); first=0; } }
        else { for(int i=start_i; i<=end_i; i++) { if(!first) printf(" "); printf("%d", mat[i][sum-i]); first=0; } }
    }
    printf("\n");
    return 0;
}
