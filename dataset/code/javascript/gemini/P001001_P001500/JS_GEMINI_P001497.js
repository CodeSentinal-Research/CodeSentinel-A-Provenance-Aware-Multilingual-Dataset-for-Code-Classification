// Helper function to evaluate rearrangearray for problem constraints.
function rearrangeArray(nums) {
    const n = nums.length;
    const res = new Array(n);
    let pos = 0, neg = 1;

    for (const x of nums) {
        if (x > 0) {
            res[pos] = x;
            pos += 2;
        } else {
            res[neg] = x;
            neg += 2;
        }
    }
    return res;
}

module.exports = { rearrangeArray };