#include <stdio.h>
#include <limits.h>
int main() {
    int r, c; scanf("%d %d", &r, &c);
    int mat[r][c];
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) scanf("%d", &mat[i][j]);
    int max_sum = INT_MIN;
    for(int l=0; l<c; l++) {
        int temp[r]; for(int i=0; i<r; i++) temp[i] = 0;
        for(int rr=l; rr<c; rr++) {
            for(int i=0; i<r; i++) temp[i] += mat[i][rr];
            int cur=0, max_cur=INT_MIN;
            for(int i=0; i<r; i++) { cur += temp[i]; if(cur > max_cur) max_cur = cur; if(cur < 0) cur = 0; }
            if(max_cur > max_sum) max_sum = max_cur;
        }
    }
    printf("%d\n", max_sum);
    return 0;
}
