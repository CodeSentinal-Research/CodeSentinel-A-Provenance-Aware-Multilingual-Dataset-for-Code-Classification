function getMaxLen(nums) {
    let pos = 0, neg = 0, ans = 0;
    for (const x of nums) {
        if (x === 0) {
            pos = 0;
            neg = 0;
        } else if (x > 0) {
            pos++;
            neg = neg > 0 ? neg + 1 : 0;
        } else {
            const newPos = neg > 0 ? neg + 1 : 0;
            const newNeg = pos + 1;
            pos = newPos;
            neg = newNeg;
        }
        if (pos > ans) ans = pos;
    }
    return ans;
}

module.exports = { getMaxLen };