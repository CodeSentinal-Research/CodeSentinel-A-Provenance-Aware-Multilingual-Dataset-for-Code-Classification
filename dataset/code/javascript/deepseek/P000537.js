Here is the JavaScript code for the problem:

function maxSlidingWindow(nums, k) {
    if (!nums || nums.length === 0 || k > nums.length || k < 1) {
        return [];
    }
    
    const res = [];
    const queue = [];
    
    for (let i = 0; i < nums.length; i++) {
        if (queue.length === k && queue[0] === i - k) {
            queue.shift();
        }
        
        while (queue.length > 0 && nums[queue[queue.length - 1]] < nums[i]) {
            queue.pop();
        }
        
        queue.push(i);
        
        if (i >= k - 1) {
            res.push(nums[queue[0]]);
        }
    }
    
    return res;
}

This function uses a deque (double-ended queue) data structure to track the indices of the maximum elements in each window of size k. The deque is populated first, and then when the window moves forward, the maximum element is checked and replaced if necessary.

The time complexity is O(n), and the space complexity is also O(n), where n is the size of the input array.