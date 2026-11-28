function nextGreaterElement(nums) {
    let stack = [];
    let res = new Array(nums.length).fill(-1);
    
    for(let i = 0; i < nums.length; i++){
        while(stack.length && nums[i] > nums[stack.pop()]){
            res[stack.pop()] = nums[i];
        }
        stack.push(i);
    }
    return res;
}