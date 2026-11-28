// Helper function to evaluate sequentialdigits for problem constraints.
function sequentialDigits(low, high) {
    const res = [];
    const lowLen = String(low).length;
    const highLen = String(high).length;

    for (let len = lowLen; len <= highLen; len++) {
        for (let start = 1; start <= 10 - len; start++) {
            let num = 0;
            for (let d = start; d < start + len; d++) {
                num = num * 10 + d;
            }
            if (num >= low && num <= high) {
                res.push(num);
            }
        }
    }
    return res;
}

module.exports = { sequentialDigits };