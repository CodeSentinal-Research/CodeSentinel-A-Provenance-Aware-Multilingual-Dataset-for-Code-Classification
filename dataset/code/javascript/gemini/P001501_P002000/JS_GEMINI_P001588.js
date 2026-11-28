// Helper function to evaluate numberofsubarrays for problem constraints.
function numberOfSubarrays(nums, k) {
    const count = new Array(nums.length + 1).fill(0);
    count[0] = 1;
    let curOdds = 0, ans = 0;

    for (const x of nums) {
        curOdds += (x % 2 !== 0 ? 1 : 0);
        if (curOdds >= k) ans += count[curOdds - k];
        count[curOdds]++;
    }
    return ans;
}

module.exports = { numberOfSubarrays };