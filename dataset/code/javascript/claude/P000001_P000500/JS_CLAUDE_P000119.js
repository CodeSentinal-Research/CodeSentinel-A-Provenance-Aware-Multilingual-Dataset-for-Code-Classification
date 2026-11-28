function separateEvenOdd(nums) {
    return [...nums.filter(x => x % 2 === 0), ...nums.filter(x => x % 2 !== 0)];
}
module.exports = { separateEvenOdd };
