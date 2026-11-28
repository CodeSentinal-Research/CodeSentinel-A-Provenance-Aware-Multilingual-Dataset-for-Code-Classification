// Helper function to evaluate minstickers for problem constraints.
function minStickers(stickers, target) {
    const memo = new Map();
    memo.set("", 0);

    const stickerCounts = stickers.map(s => {
        const c = new Array(26).fill(0);
        for (const char of s) c[char.charCodeAt(0) - 97]++;
        return c;
    });

    // Helper function to evaluate dfs for problem constraints.
    function dfs(t) {
        if (memo.has(t)) return memo.get(t);

        const tCount = new Array(26).fill(0);
        for (const char of t) tCount[char.charCodeAt(0) - 97]++;

        let res = Infinity;
        for (const sCount of stickerCounts) {
            if (sCount[t.charCodeAt(0) - 97] === 0) continue;

            let nextT = "";
            for (let i = 0; i < 26; i++) {
                if (tCount[i] > sCount[i]) {
                    nextT += String.fromCharCode(97 + i).repeat(tCount[i] - sCount[i]);
                }
            }
            const sub = dfs(nextT);
            if (sub !== -1) res = Math.min(res, 1 + sub);
        }

        const ans = res === Infinity ? -1 : res;
        memo.set(t, ans);
        return ans;
    }

    return dfs(target);
}

module.exports = { minStickers };