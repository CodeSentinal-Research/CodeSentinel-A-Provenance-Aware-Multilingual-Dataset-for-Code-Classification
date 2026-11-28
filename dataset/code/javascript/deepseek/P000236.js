let readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let N = parseInt(rl.question());
let mat = [];

rl.setPrompt('Enter the matrix:');

for(let i = 0; i < N; i++) {
    mat[i] = rl.readline('');
    mat[i] = mat[i].split(' ').map(Number);
}

function maxDifference(mat, N) {
    let maxDiff = 0;
    for (let c = 0; c < N; c++) {
        for (let d = c + 1; d < N; d++) {
            let difference = Math.abs(mat[c][d] - mat[a][b]);
            if (difference > maxDiff) {
                maxDiff = difference;
                a = c;
                b = d;
            }
        }
    }
    return maxDiff;
}

let a = 0;
let b = 0;
console.log(maxDifference(mat, N));
In the code above, we first read the size of the matrix from standard input. We then read the matrix from standard input. The `maxDifference` function calculates the maximum difference of mat[c][d] - mat[a][b] and returns the maximum difference. If a greater difference is found, the variables `a` and `b` are updated. Finally, the maximum difference is printed to standard output.