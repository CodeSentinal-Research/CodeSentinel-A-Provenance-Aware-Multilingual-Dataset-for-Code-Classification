// Helper function to evaluate brokencalc for problem constraints.
function brokenCalc(startValue, target) {
    let ans = 0;
    while (target > startValue) {
        ans++;
        if (target % 2 === 1) {
            target++;
        } else {
            target /= 2;
        }
    }
    return ans + startValue - target;
}

module.exports = { brokenCalc };