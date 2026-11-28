function moveNegatives(nums) {
    return [...nums.filter(x=>x<0), ...nums.filter(x=>x>=0)];
}
module.exports = { moveNegatives };
