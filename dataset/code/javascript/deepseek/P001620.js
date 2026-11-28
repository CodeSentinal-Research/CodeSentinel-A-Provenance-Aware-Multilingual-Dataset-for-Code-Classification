const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let tests = Number(rl.readline()); // Number of test cases

rl.on('line', (line) => {
    let [N, ...arr] = line.split(' ').map(Number);

    let sum = 0;
    for(let i=0; i<arr.length; i++){
        sum += arr[i] * (i % 2 === 0 ? 1 : -1);
    }

    console.log(sum);

    if(tests > 1){
        tests--;
    } else {
        rl.close();
    }
});

This code first reads the number of test cases (N). Then, for each test case, it reads the length of the array (N) and the elements of the array (N integers). It then calculates the sum of the elements at alternate positions and prints the sum. If there are more test cases, it decreases the number of test cases by 1 before it exits the loop.