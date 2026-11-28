function findUnsortedSubarray(nums) {
    let sortedNums = [...nums];
    sortedNums.sort((a, b) => a - b);
    let start = nums.length, end = -1;

    for(let i = 0; i < nums.length; i++){
        if(nums[i] !== sortedNums[i]){
            start = Math.min(start, i);
            end = Math.max(end, i);
        }
    }

    if(start === nums.length){
        return 0;
    }

    return end - start + 1;
}