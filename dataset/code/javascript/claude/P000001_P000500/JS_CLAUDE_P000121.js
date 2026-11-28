function majorityElement(nums) {
    let count = 0, candidate = 0;
    for (const x of nums) {
        if (count === 0) candidate = x;
        count += x === candidate ? 1 : -1;
    }
    return candidate;
}
module.exports = { majorityElement };
