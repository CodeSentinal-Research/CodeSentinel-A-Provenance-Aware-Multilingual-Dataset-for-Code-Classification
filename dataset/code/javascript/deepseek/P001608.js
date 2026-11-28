const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let cases = parseInt(rl.question().split(" ")[0]);

rl.close(() => {
    for(let c=0; c<cases; c++) {
        let [N, K] = rl.question().split(" ").map(Number);
        let arr = rl.question().split(" ").map(Number);

        console.log(subarraysDivisibleByK(arr, K));
    }
});

function subarraysDivisibleByK(nums, k) {
    let count = 0;
    let prefixSum = new Array(nums.length).fill(0);
    prefixSum[0] = nums[0] % k;
    
    for(let i=1; i<nums.length; i++) {
        prefixSum[i] = (prefixSum[i-1] + nums[i]) % k;
        if(prefixSum[i] === 0) count++;
    }

    for(let i=0; i<nums.length; i++) {
        let target = (prefixSum[i] * 1.0 / k) | 0;
        let targetCount = target === 0 ? count : targetCounts[target];
        count += targetCount;
    }

    return count;
}