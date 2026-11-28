// Helper function to evaluate deleteandearn for problem constraints.
function deleteAndEarn(nums) {
    let maxVal = 0;
    for (const x of nums) maxVal = Math.max(maxVal, x);

    const count = new Array(maxVal + 1).fill(0);
    for (const x of nums) count[x] += x;

    let rob1 = 0, rob2 = 0;
    for (const v of count) {
        const tmp = Math.max(rob1 + v, rob2);
        rob1 = rob2;
        rob2 = tmp;
    }
    return rob2;
}

module.exports = { deleteAndEarn };