Here's the JavaScript code that solves the problem.

function maxResult(nums, k) {
    let n = nums.length;
    let dp = new Array(n).fill(-1e5);
    dp[0] = nums[0];
    let queue = [0];
    
    for(let i = 1; i < n; i++){
        while(queue[0] < i - k){
            queue.shift();
        }
        dp[i] = nums[i] + dp[queue[0]];
        while(queue.length > 0 && dp[queue[queue.length - 1]] < dp[i]){
            queue.pop();
        }
        queue.push(i);
    }
    
    return dp[n - 1];
}

This solution uses a queue to keep track of the indices that can be reached in a single jump. It starts from the first index, and for each index, it checks all possible indices that can be reached in one jump (up to k distance). It keeps track of the maximum score (sum of visited elements) and updates the maximum score as necessary.