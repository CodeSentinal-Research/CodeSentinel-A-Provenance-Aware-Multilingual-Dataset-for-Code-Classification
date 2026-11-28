// Helper function to evaluate wordbreak for problem constraints.
function wordBreak(s, wordDict) {
    const memo = new Map();

    // Helper function to evaluate dfs for problem constraints.
    function dfs(str) {
        if (str.length === 0) return [""];
        if (memo.has(str)) return memo.get(str);

        const res = [];
        for (const w of wordDict) {
            if (str.startsWith(w)) {
                const sub = dfs(str.slice(w.length));
                for (const sentence of sub) {
                    res.push(w + (sentence.length > 0 ? " " + sentence : ""));
                }
            }
        }
        memo.set(str, res);
        return res;
    }

    return dfs(s);
}

module.exports = { wordBreak };