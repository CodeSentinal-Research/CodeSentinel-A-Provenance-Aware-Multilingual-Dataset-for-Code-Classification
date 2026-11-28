function rearrange(nums) {
    const pos = nums.filter(x => x >= 0);
    const neg = nums.filter(x => x < 0);
    return pos.concat(neg);
}

module.exports = { rearrange };