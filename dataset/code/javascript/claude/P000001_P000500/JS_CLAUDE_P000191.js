function sortArray012(nums) {
    let lo=0, mid=0, hi=nums.length-1;
    while (mid<=hi) {
        if (nums[mid]===0) { [nums[lo],nums[mid]]=[nums[mid],nums[lo]]; lo++; mid++; }
        else if (nums[mid]===1) mid++;
        else { [nums[mid],nums[hi]]=[nums[hi],nums[mid]]; hi--; }
    }
}
module.exports = { sortArray012 };
