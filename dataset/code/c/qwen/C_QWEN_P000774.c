#include <stdio.h>
#include <string.h>
int n, m;
int solve(char board[10][10], char *word, int i, int x, int y, int visited[10][10]) { if(word[i]=='\0') return 1; int dx[]={1,-1,0,0}, dy[]={0,0,1,-1}; for(int d=0;d<4;d++) { int nx=x+dx[d], ny=y+dy[d]; if(nx>=0 && nx<n && ny>=0 && ny<m && !visited[nx][ny] && board[nx][ny]==word[i]) { visited[nx][ny]=1; if(solve(board,word,i+1,nx,ny,visited)) return 1; visited[nx][ny]=0; } } return 0; }
int main() { char board[10][10]; char word[101]; scanf("%d%d",&n,&m); for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf(" %c",&board[i][j]); scanf("%s",word); int visited[10][10]={0}; int found=0; for(int i=0;i<n && !found;i++) for(int j=0;j<m && !found;j++) if(board[i][j]==word[0]) { visited[i][j]=1; if(solve(board,word,1,i,j,visited)) found=1; visited[i][j]=0; } printf("%s\n",found?"true":"false"); return 0; }
