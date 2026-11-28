// Helper function to evaluate countnumberswithuniquedigits for problem constraints.
function countNumbersWithUniqueDigits(n) {
    if (n === 0) return 1;
    let ans = 10, uniqueDigits = 9, available = 9;
    for (let i = 2; i <= Math.min(n, 10); i++) {
        uniqueDigits *= available;
        ans += uniqueDigits;
        available--;
    }
    return ans;
}

module.exports = { countNumbersWithUniqueDigits };