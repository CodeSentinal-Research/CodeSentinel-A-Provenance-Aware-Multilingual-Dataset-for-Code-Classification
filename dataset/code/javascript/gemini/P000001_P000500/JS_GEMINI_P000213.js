function thirdMax(nums) {
    let first = -Infinity, second = -Infinity, third = -Infinity;
    for (const x of nums) {
        if (x === first || x === second || x === third) continue;
        if (x > first) {
            third = second;
            second = first;
            first = x;
        } else if (x > second) {
            third = second;
            second = x;
        } else if (x > third) {
            third = x;
        }
    }
    return third !== -Infinity ? third : first;
}

module.exports = { thirdMax };