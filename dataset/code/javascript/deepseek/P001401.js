Here is the JavaScript code that solves the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let testCases = Number(rl.question().split(' ')[0]);

rl.close(() => {
    for(let i=0; i<testCases; i++){
        let input = rl.question().split(' ').map(Number);
        let [N, K] = [input[0], input[1]];
        let nums = input.slice(2);
        console.log(maxSubArrayLen(nums, K));
    }
});

function maxSubArrayLen(nums, k) {
    let hashMap = new Map();
    hashMap.set(0, 0);
    let sum = 0;
    let maxLen = 0;
    for(let i = 0; i < nums.length; i++){
        sum += nums[i];
        if(hashMap.has(sum - k)){
            maxLen = Math.max(maxLen, i - hashMap.get(sum - k));
        }
        if(!hashMap.has(sum)){
            hashMap.set(sum, i);
        }
    }
    return maxLen;
}

This JavaScript code reads input from the console and then calls the `maxSubArrayLen` function, which finds the length of the longest subarray with sum equal to `K`.

The `maxSubArrayLen` function uses a hashmap to store the prefix sum with the index and then it checks if the difference between the current sum and `K` is in the hashmap. If it is, then it updates the maximum length. If not, it stores the current sum in the hashmap. The time complexity of this function is O(n), where n is the length of the input array.