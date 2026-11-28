// Helper function to evaluate lettercombinations for problem constraints.
function letterCombinations(digits) {
    if (!digits) return [];
    const phone = {
        '2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl',
        '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'
    };
    const res = [];

    // Helper function to evaluate backtrack for problem constraints.
    function backtrack(idx, cur) {
        if (idx === digits.length) {
            res.push(cur);
            return;
        }
        for (const c of phone[digits[idx]]) {
            backtrack(idx + 1, cur + c);
        }
    }

    backtrack(0, "");
    return res;
}

module.exports = { letterCombinations };