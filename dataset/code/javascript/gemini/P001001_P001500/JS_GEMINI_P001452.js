// Helper function to evaluate countdistinct for problem constraints.
function countDistinct(nums) {
    const set = new Set();
    for (const x of nums) {
        set.add(x);
        set.add(Number(String(x).split('').reverse().join('')));
    }
    return set.size;
}

module.exports = { countDistinct };