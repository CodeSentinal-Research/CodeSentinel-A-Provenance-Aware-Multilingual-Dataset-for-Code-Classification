Here is the JavaScript code for the given problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let N;
rl.question('Enter the number of elements: ', (N) => {
    rl.question('Enter the elements: ', (input) => {
        const nums = input.split(' ').map(Number);
        let count = 0;

        for (let i = 0; i < N; i++) {
            for (let j = i + 1; j < N; j++) {
                if (nums[i] + parseInt(String(nums[j]).split('').reverse().join(''), 10) === nums[j] + parseInt(String(nums[i]).split('').reverse().join(''), 10) && i < j) {
                    count++;
                }
            }
        }

        console.log(count);

        rl.close();
    });
});

In this code, we are first reading the number of elements N from the user. Then, we read the array of numbers from the user. We initialize a count variable to 0. We then iterate over the array and for every pair of numbers, we check if the sum of the numbers is equal to the sum of the reverses of the numbers. If it is, we increment the count. Finally, we print the count.

Please note that this solution assumes that the numbers are positive integers. If the numbers can be negative, we should convert the numbers to strings and reverse the strings.