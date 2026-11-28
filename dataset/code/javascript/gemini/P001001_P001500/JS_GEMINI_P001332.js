// Helper function to evaluate removeinvalidparentheses for problem constraints.
function removeInvalidParentheses(s) {
    let lRem = 0, rRem = 0;
    for (const c of s) {
        if (c === '(') lRem++;
        else if (c === ')') {
            if (lRem > 0) lRem--;
            else rRem++;
        }
    }

    const res = new Set();

    // Helper function to evaluate backtrack for problem constraints.
    function backtrack(idx, open, close, l, r, cur) {
        if (idx === s.length) {
            if (l === 0 && r === 0) res.add(cur.join(''));
            return;
        }

        const c = s[idx];
        if (c === '(' && l > 0) {
            backtrack(idx + 1, open, close, l - 1, r, cur);
        } else if (c === ')' && r > 0) {
            backtrack(idx + 1, open, close, l, r - 1, cur);
        }

        cur.push(c);
        if (c !== '(' && c !== ')') {
            backtrack(idx + 1, open, close, l, r, cur);
        } else if (c === '(') {
            backtrack(idx + 1, open + 1, close, l, r, cur);
        } else if (close < open) {
            backtrack(idx + 1, open, close + 1, l, r, cur);
        }
        cur.pop();
    }

    backtrack(0, 0, 0, lRem, rRem, []);
    return [...res];
}

module.exports = { removeInvalidParentheses };