function segregate01(nums) {
    const zeros = nums.filter(x => x === 0).length;
    return Array(zeros).fill(0).concat(Array(nums.length - zeros).fill(1));
}
module.exports = { segregate01 };
