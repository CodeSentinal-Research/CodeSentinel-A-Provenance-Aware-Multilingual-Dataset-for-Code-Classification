const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let testCases = parseInt(rl.question()); // Read number of test cases

rl.on('line', function(line) {
    let nums = line.split(' ').map(Number);
    let output = new Array(nums.length).fill(1);

    let leftProduct = 1;
    let rightProduct = 1;

    for (let i = 0; i < nums.length; i++) {
        output[i] *= leftProduct;
        leftProduct *= nums[i];

        output[nums.length - 1 - i] *= rightProduct;
        rightProduct *= nums[nums.length - 1 - i];
    }

    console.log(output.join(' '));
});

rl.close();

This JavaScript program reads the number of test cases, then reads each test case as a string of space-separated numbers. It then processes each test case and prints the resulting array.