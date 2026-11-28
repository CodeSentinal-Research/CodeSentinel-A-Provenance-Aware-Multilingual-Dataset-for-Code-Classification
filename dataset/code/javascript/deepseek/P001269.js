const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let tests = parseInt(rl.question()); // Read the number of tests

rl.on('line', (line) => {
    let [N, K] = line.split(' ').map(Number);

    let arr = rl.line().split(' ').map(Number).sort((a, b) => a - b);

    let isPossible = true;
    let currentSet = arr[0];
    for (let i = 1; i < N; i++) {
        if (arr[i] !== arr[i - 1] + 1) {
            isPossible = false;
            break;
        }

        if (i !== 0 && (arr[i] - arr[i - 1]) % K !== 1) {
            isPossible = false;
            break;
        }
    }

    if (isPossible) {
        console.log('YES');
    } else {
        console.log('NO');
    }

    if (tests > 1) {
        console.log();
    }

    tests--;
});

rl.close();