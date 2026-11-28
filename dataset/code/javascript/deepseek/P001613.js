Here is the JavaScript code for your problem:

let readline = require('readline');

let rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let NMK = rl.question('', (NMK) => {
    NMK = NMK.split(' ').map(s => parseInt(s, 10));
    let N = NMK[0], M = NMK[1], K = NMK[2];
    let matrix = [];
    for (let i = 0; i < N; i++) {
        matrix.push(rl.readline('').split(' ').map(s => parseInt(s, 10)));
    }

    let result = [];
    for (let i = 0; i < N; i++) {
        let row = [];
        for (let j = 0; j < M; j++) {
            let sum = 0;
            for (let a = Math.max(0, i - K); a <= Math.min(i + K, N - 1); a++) {
                for (let b = Math.max(0, j - K); b <= Math.min(j + K, M - 1); b++) {
                    sum += matrix[a][b];
                }
            }
            row.push(sum);
        }
        result.push(row);
    }

    result.forEach(row => {
        console.log(row.join(' '));
    });
    rl.close();
});

This code reads the matrix and the distance K from the input, and then constructs a new matrix where each cell contains the sum of all elements within a distance of K rows and K columns from that cell. It prints the resulting matrix.