function restoreIpAddresses(s) {
    const result = [];
    const current = [];

    function backtrack(startIndex) {
        if (current.length > 4) return;
        if (current.length === 4 && startIndex === s.length) {
            result.push(current.join('.'));
            return;
        }
        if (current.length + s.length - startIndex > 3 * (4 - current.length)) return;
        for (let i = startIndex; i < s.length; i++) {
            if (s[startIndex] === '0' && i > startIndex) break;
            const segment = s.slice(startIndex, i + 1);
            if (Number(segment) > 255) break;
            current.push(segment);
            backtrack(i + 1);
            current.pop();
        }
    }

    backtrack(0);
    return result;
}