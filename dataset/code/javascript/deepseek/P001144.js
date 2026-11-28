Here is a JavaScript solution for the problem:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter the number of elements: ', (n) => {
    rl.question('Enter elements: ', (inputs) => {
        const arr = inputs.split(' ').map(Number);
        console.log(lengthOfLIS(arr));
        rl.close();
    });
});

function lengthOfLIS(nums) {
    if (nums.length === 0) return 0;

    let dp = new Array(nums.length).fill(1);
    let max = 1;

    for (let i = 0; i < nums.length; i++) {
        for (let j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = Math.max(dp[i], dp[j] + 1);
            }
       
        }
        max = Math.max(max, dp[i]);
    }

    return max;
}

In this code, we first read the number of elements from the first line. Then, we read the elements from the second line. The elements are converted to integers and then passed to the `lengthOfLIS` function. The result is printed out.

Please note that this solution uses a dynamic programming approach to solve the problem. The `dp` array keeps track of the length of the longest increasing subsequence ending at each index. The `max` variable keeps track of the maximum length found so far.