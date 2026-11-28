// Helper function to evaluate minimumsteps for problem constraints.
function minimumSteps(s) {
    let ans = 0;
    let ones = 0;
    for (const c of s) {
        if (c === '1') ones++;
        else ans += ones;
    }
    return ans;
}

module.exports = { minimumSteps };