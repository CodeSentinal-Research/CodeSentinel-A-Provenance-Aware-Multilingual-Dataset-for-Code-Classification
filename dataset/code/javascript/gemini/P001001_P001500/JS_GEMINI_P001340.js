// Helper function to evaluate distributecookies for problem constraints.
function distributeCookies(cookies, k) {
    cookies.sort((a, b) => b - a);
    const children = new Array(k).fill(0);
    let ans = Infinity;

    // Helper function to evaluate backtrack for problem constraints.
    function backtrack(idx) {
        if (idx === cookies.length) {
            ans = Math.min(ans, Math.max(...children));
            return;
        }
        if (Math.max(...children) >= ans) return;

        for (let i = 0; i < k; i++) {
            children[i] += cookies[idx];
            backtrack(idx + 1);
            children[i] -= cookies[idx];
            if (children[i] === 0) break;
        }
    }

    backtrack(0);
    return ans;
}

module.exports = { distributeCookies };