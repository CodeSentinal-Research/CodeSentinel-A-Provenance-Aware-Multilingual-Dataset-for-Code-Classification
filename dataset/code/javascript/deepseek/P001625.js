const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let arr = [];

rl.once('line', (line) => {
    let [N, M] = line.split(' ').map(Number);

    for (let i = 0; i < N; i++) {
        rl.once('line', (line) => {
            arr[i] = line.split(' ').map(Number);
        });
    }

    const prefixSum = new Array(N + 1).fill(0).map((_, i) => new Array(M + 1).fill(0));

    for (let i = 0; i < N; i++) {
        for (let j = 0; j < M; j++) {
            prefixSum[i + 1][j + 1] = prefixSum[i + 1][j] + prefixSum[i][j + 1] - prefixSum[i][j] + arr[i][j];
        }
    }

    for (let i = 0; i < N + 1; i++) {
        for (let j = 0; j < M + 1; j++) {
            console.log(prefixSum[i][j], ' ');
        }
        console.log();
    }

    rl.close();
});
This JavaScript code reads the input matrix dimensions, and then each line of the matrix. After reading all lines, it calculates the prefix sum matrix and prints it out.

Please note that this code assumes that the input will be provided one row at a time. The last row and column of the matrix can be calculated without reading the next line.