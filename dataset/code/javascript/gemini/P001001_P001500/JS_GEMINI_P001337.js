// Helper function to evaluate countarrangement for problem constraints.
function countArrangement(n) {
    const visited = new Array(n + 1).fill(false);

    // Helper function to evaluate backtrack for problem constraints.
    function backtrack(pos) {
        if (pos > n) return 1;
        let count = 0;
        for (let i = 1; i <= n; i++) {
            if (!visited[i] && (pos % i === 0 || i % pos === 0)) {
                visited[i] = true;
                count += backtrack(pos + 1);
                visited[i] = false;
            }
        }
        return count;
    }

    return backtrack(1);
}

module.exports = { countArrangement };