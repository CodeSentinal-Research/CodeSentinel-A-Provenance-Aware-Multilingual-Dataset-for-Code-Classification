function countEvenOdd(nums) {
    const even = nums.filter(x => x % 2 === 0).length;
    return [even, nums.length - even];
}
module.exports = { countEvenOdd };
