Here is the JavaScript code:

let fs = require('fs');
let input = fs.readFileSync('input.txt', 'utf8');
let [N, target] = input.split('\n').map(Number);
let nums = input.split('\n')[N + 1].split(' ').map(Number);

nums.sort((a, b) => a - b);

let closest = nums[0] + nums[1] + nums[2];

for(let i = 0; i < nums.length - 2; i++) {
    let l = i + 1;
    let r = nums.length - 1;
    while(l < r) {
        let sum = nums[i] + nums[l] + nums[r];
        if(Math.abs(target - sum) < Math.abs(target - closest)) {
            closest = sum;
        }
        sum > target ? r-- : l++;
    }
}

console.log(closest);

This code reads the input from the file 'input.txt', splits it into N, target, and nums arrays. It then sorts the nums array in ascending order. Then, it iterates over the sorted array, and for each element, it uses two pointers (left and right) to find a pair of numbers whose sum is closest to the target. If the absolute difference between the target and the sum is less than the current closest difference, it updates the closest sum. If the sum is greater than the target, it moves the right pointer to the left; if the sum is less than the target, it moves the left pointer to the right. This process continues until the two pointers meet. The closest sum is then printed out.