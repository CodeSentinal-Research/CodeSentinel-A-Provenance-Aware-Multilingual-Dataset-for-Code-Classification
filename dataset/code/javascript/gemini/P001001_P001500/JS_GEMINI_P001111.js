// Helper function to evaluate snakesandladders for problem constraints.
function snakesAndLadders(moves) {
    const board = new Array(31).fill(-1);
    for (const [u, v] of moves) board[u] = v;

    const vis = new Array(31).fill(false);
    const q = [[1, 0]];
    vis[1] = true;

    while (q.length > 0) {
        const [pos, steps] = q.shift();
        if (pos === 30) return steps;
        for (let d = 1; d <= 6; d++) {
            let next = pos + d;
            if (next <= 30) {
                if (board[next] !== -1) next = board[next];
                if (!vis[next]) {
                    vis[next] = true;
                    q.push([next, steps + 1]);
                }
            }
        }
    }
    return -1;
}

module.exports = { snakesAndLadders };