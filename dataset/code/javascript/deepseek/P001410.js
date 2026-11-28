const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let testCases = Number(rl.line());

rl.on('line', (line) => {
    let N = Number(line);
    let nums = Array.from(rl.line().split(' '));
    let numsMap = new Map();
    let result = 0;

    for (let i = 0; i < N; i++) {
        numsMap.set(nums[i], i);
    }

    for (let i = 0; i < N; i++) {
        for (let j = i + 1; j < N; j++) {
            if (j - i !== numsMap.get(nums[j]) - numsMap.get(nums[i])) {
                result++;
            }
        }
    }

    console.log(result / 2);

    testCases--;
    if (testCases === 0) {
        rl.close();
    }
});
This code will take input for the number of test cases, then for each test case it will take an integer N and N integers as input. It will then calculate the number of bad pairs and print the number of bad pairs divided by 2. The test cases are handled by decrementing the counter `testCases` until it equals 0.