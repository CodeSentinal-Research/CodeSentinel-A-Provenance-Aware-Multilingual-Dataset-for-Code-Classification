function countFrequency(nums, target) {
    return nums.filter(x => x === target).length;
}
module.exports = { countFrequency };
