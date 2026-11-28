// Solves 'Surrounded Regions' by applying optimal Graphs logic.
function solve(board) {
    if (!board || board.length === 0) return;
    const m = board.length, n = board[0].length;

    // Helper function to evaluate dfs for problem constraints.
    function dfs(r, c) {
        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] !== 'O') return;
        board[r][c] = 'E';
        dfs(r + 1, c);
        dfs(r - 1, c);
        dfs(r, c + 1);
        dfs(r, c - 1);
    }

    for (let i = 0; i < m; i++) {
        dfs(i, 0);
        dfs(i, n - 1);
    }
    for (let j = 0; j < n; j++) {
        dfs(0, j);
        dfs(m - 1, j);
    }

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (board[i][j] === 'O') board[i][j] = 'X';
            else if (board[i][j] === 'E') board[i][j] = 'O';
        }
    }
}

module.exports = { solve };