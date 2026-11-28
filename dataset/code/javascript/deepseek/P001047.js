const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let testCases = Number(rl.question()); // number of test cases

rl.on('line', (line) => {
    const [n, ...inputs] = line.split(' ').map(Number);

    let sum = 0;
    for(let i = 0; i < n; i++) {
        sum += inputs[i];
    }

    console.log(sum);

    if(testCases > 1) {
        testCases--;
    } else {
        rl.close();
    }
});