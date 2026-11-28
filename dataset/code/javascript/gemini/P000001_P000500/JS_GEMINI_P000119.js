function separateEvenOdd(nums) {
    const evens = nums.filter(x => x % 2 === 0);
    const odds = nums.filter(x => x % 2 !== 0);
    return evens.concat(odds);
}

module.exports = { separateEvenOdd };