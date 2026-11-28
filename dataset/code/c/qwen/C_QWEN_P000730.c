#include <stdio.h>
int n;
void solve(int row, int *cols, int *d1, int *d2, char **board) { if(row==n) { for(int i=0;i<n;i++) printf("%s\n",board[i]); printf("\n"); return; } for(int c=0;c<n;c++) { if(!cols[c] && !d1[row-c+n-1] && !d2[row+c]) { cols[c]=d1[row-c+n-1]=d2[row+c]=1; board[row][c]='Q'; solve(row+1,cols,d1,d2,board); board[row][c]='.'; cols[c]=d1[row-c+n-1]=d2[row+c]=0; } } }
int main() { scanf("%d",&n); char **board=malloc(n*sizeof(char*)); for(int i=0;i<n;i++) { board[i]=malloc(n+1); for(int j=0;j<n;j++) board[i][j]='.'; board[i][n]='\0'; } int cols[n], d1[2*n], d2[2*n]; memset(cols,0,sizeof(cols)); memset(d1,0,sizeof(d1)); memset(d2,0,sizeof(d2)); solve(0,cols,d1,d2,board); return 0; }
