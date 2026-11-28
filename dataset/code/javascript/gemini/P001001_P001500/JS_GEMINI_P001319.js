// Helper function to evaluate findwords for problem constraints.
function findWords(board, words) {
    const root = {};
    for (const w of words) {
        let node = root;
        for (const c of w) {
            if (!node[c]) node[c] = {};
            node = node[c];
        }
        node.word = w;
    }

    const m = board.length, n = board[0].length;
    const res = [];

    // Helper function to evaluate dfs for problem constraints.
    function dfs(r, c, node) {
        const ch = board[r][c];
        if (ch === '#' || !node[ch]) return;

        const next = node[ch];
        if (next.word) {
            res.push(next.word);
            next.word = null;
        }

        board[r][c] = '#';
        const dirs = [[1, 0], [-1, 0], [0, 1], [0, -1]];
        for (const [dr, dc] of dirs) {
            const nr = r + dr, nc = c + dc;
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] !== '#') {
                dfs(nr, nc, next);
            }
        }
        board[r][c] = ch;
    }

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            dfs(i, j, root);
        }
    }
    return res;
}

module.exports = { findWords };