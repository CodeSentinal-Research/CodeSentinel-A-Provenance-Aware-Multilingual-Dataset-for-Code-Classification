const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter the number of elements (1 <= N <= 2000): ', (N) => {
    rl.question('Enter the target sum: ', (target) => {
        const nums = [];
        rl.setPrompt(`Enter ${N} integers: `);
        rl.prompt();
        for(let i=0; i<N; i++) {
            nums.push(parseInt(rl.line()));
        }
        const result = fourSum(nums, target);
        console.log(JSON.stringify(result));
        rl.close();
    });
});

function fourSum(nums, target) {
    nums.sort((a, b) => a - b);
    const results = [];
    for (let i = 0; i < nums.length - 3; i++) {
        if (i > 0 && nums[i] === nums[i - 1]) continue;
        for (let j = i + 1; j < nums.length - 2; j++) {
            if (j > i + 1 && nums[j] === nums[j - 1]) continue;
            let left = j + 1, right = nums.length - 1;
            while (left < right) {
                const sum = nums[i] + nums[j] + nums[left] + nums[right];
                if (sum === target) {
                    results.push([nums[i], nums[j], nums[left], nums[right]]);
                    while (nums[left] === nums[left + 1]) left++;
                    while (nums[right] === nums[right - 1]) right--;
                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }
    return results;
}