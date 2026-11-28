// Helper function to evaluate totalhammingdistance for problem constraints.
function totalHammingDistance(nums) {
    let total = 0;
    const n = nums.length;
    for (let i = 0; i < 32; i++) {
        let ones = 0;
        for (const x of nums) {
            ones += (x >> i) & 1;
        }
        total += ones * (n - ones);
    }
    return total;
}

module.exports = { totalHammingDistance };