#include <stdio.h>
int n, count=0;
void solve(int row, int *cols, int *d1, int *d2) { if(row==n) { count++; return; } for(int c=0;c<n;c++) { if(!cols[c] && !d1[row-c+n-1] && !d2[row+c]) { cols[c]=d1[row-c+n-1]=d2[row+c]=1; solve(row+1,cols,d1,d2); cols[c]=d1[row-c+n-1]=d2[row+c]=0; } } }
int main() { scanf("%d",&n); int cols[n], d1[2*n], d2[2*n]; memset(cols,0,sizeof(cols)); memset(d1,0,sizeof(d1)); memset(d2,0,sizeof(d2)); solve(0,cols,d1,d2); printf("%d\n",count); return 0; }
