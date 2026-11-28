const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter N, K, X: ', (N) => {
    rl.question('Enter N integers: ', (line) => {
        let arr = line.split(' ').map(Number);
        let K = parseInt(N / 2);
        let X = parseInt(line);
        let count = 0;
        let prefixSum = new Array(N).fill(0);
        prefixSum[0] = arr[0];
        for (let i = 1; i < N; i++) {
            prefixSum[i] = prefixSum[i - 1] + arr[i];
        }
        for (let i = K - 1; i < N; i++) {
            if (prefixSum[i] > X) {
                count++;
            }
        }
        console.log(count);
        rl.close();
    });
});