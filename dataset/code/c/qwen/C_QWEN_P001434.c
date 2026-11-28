#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int moves[n][2];
    for (int i = 0; i < n; i++) scanf("%d %d", &moves[i][0], &moves[i][1]);
    
    int board[3][3] = {0};
    char winner = ' ';
    for (int i = 0; i < n; i++) {
        int r = moves[i][0], c = moves[i][1];
        board[r][c] = (i % 2 == 0) ? 1 : 2;
        
        // Check win
        if (board[r][0] == board[r][1] && board[r][1] == board[r][2] && board[r][0] != 0) winner = (board[r][0] == 1) ? 'A' : 'B';
        if (board[0][c] == board[1][c] && board[1][c] == board[2][c] && board[0][c] != 0) winner = (board[0][c] == 1) ? 'A' : 'B';
        if (r == c && board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != 0) winner = (board[0][0] == 1) ? 'A' : 'B';
        if (r + c == 2 && board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != 0) winner = (board[0][2] == 1) ? 'A' : 'B';
    }
    
    if (winner != ' ') printf("%c\n", winner);
    else if (n == 9) printf("Draw\n");
    else printf("Pending\n");
    return 0;
}
