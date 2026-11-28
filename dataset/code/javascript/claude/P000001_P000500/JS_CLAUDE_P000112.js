function secondSmallest(nums) {
    let first = Infinity, second = Infinity;
    for (const x of nums) {
        if (x < first) { second = first; first = x; }
        else if (x < second && x !== first) second = x;
    }
    return second === Infinity ? -1 : second;
}
module.exports = { secondSmallest };
