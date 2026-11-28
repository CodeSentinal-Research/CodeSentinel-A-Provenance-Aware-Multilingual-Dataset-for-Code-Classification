// Helper function to evaluate exist for problem constraints.
function exist(board, word) {
    const m = board.length, n = board[0].length;

    // Helper function to evaluate dfs for problem constraints.
    function dfs(r, c, k) {
        if (k === word.length) return true;
        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] !== word[k]) return false;

        const tmp = board[r][c];
        board[r][c] = '#';

        const found = dfs(r + 1, c, k + 1) ||
                      dfs(r - 1, c, k + 1) ||
                      dfs(r, c + 1, k + 1) ||
                      dfs(r, c - 1, k + 1);

        board[r][c] = tmp;
        return found;
    }

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (dfs(i, j, 0)) return true;
        }
    }
    return false;
}

module.exports = { exist };