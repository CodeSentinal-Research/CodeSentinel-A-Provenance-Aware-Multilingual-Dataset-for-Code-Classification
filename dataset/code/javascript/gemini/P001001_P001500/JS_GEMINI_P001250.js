// Helper function to evaluate ispossible for problem constraints.
function isPossible(nums) {
    const count = new Map();
    const end = new Map();
    for (const x of nums) count.set(x, (count.get(x) || 0) + 1);

    for (const x of nums) {
        if (count.get(x) === 0) continue;
        count.set(x, count.get(x) - 1);
        if ((end.get(x - 1) || 0) > 0) {
            end.set(x - 1, end.get(x - 1) - 1);
            end.set(x, (end.get(x) || 0) + 1);
        } else if ((count.get(x + 1) || 0) > 0 && (count.get(x + 2) || 0) > 0) {
            count.set(x + 1, count.get(x + 1) - 1);
            count.set(x + 2, count.get(x + 2) - 1);
            end.set(x + 2, (end.get(x + 2) || 0) + 1);
        } else {
            return false;
        }
    }
    return true;
}

module.exports = { isPossible };