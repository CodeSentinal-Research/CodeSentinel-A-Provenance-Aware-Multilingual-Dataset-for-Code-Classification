function letterCombinations(digits) {
    if (!digits) return [];
    const phone = ['', '', 'abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz'];
    const result = [];
    function bt(idx, curr) {
        if (idx === digits.length) { result.push(curr); return; }
        for (const c of phone[parseInt(digits[idx])]) bt(idx + 1, curr + c);
    }
    bt(0, '');
    return result;
}

module.exports = { letterCombinations };
