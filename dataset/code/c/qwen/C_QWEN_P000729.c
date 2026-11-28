#include <stdio.h>
int board[9][9];
int solve(int i, int j) { if(i==9) return 1; if(j==9) return solve(i+1,0); if(board[i][j]!='.') { return solve(i,j+1); } for(int n=1;n<=9;n++) { int ok=1; for(int k=0;k<9;k++) if(board[i][k]==n+'0' || board[k][j]==n+'0') ok=0; int r=(i/3)*3, c=(j/3)*3; for(int x=0;x<3 && ok;x++) for(int y=0;y<3 && ok;y++) if(board[r+x][c+y]==n+'0') ok=0; if(ok) { board[i][j]=n+'0'; if(solve(i,j+1)) return 1; board[i][j]='.'; } } return 0; }
int main() { for(int i=0;i<9;i++) for(int j=0;j<9;j++) scanf(" %c",&board[i][j]); solve(0,0); for(int i=0;i<9;i++) { for(int j=0;j<9;j++) printf("%c ",board[i][j]); printf("\n"); } return 0; }
