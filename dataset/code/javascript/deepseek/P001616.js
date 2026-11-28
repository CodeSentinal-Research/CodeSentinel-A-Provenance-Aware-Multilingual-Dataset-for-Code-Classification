Here is a JavaScript code snippet that calculates the sum of all elements inside each rectangle.

let input = require('fs').readFileSync('/dev/stdin', 'utf8');
let lines = input.split('\n');
let [N, M] = lines[0].split(' ').map(x => parseInt(x));
let matrix = [];
for (let i = 0; i < N; i++) {
    matrix[i] = lines[i+1].split(' ').map(x => parseInt(x));
}
let Q = parseInt(lines[N+1]);
let queries = [];
for (let i = 0; i < Q; i++) {
    let [r1, c1, r2, c2] = lines[N+2+i].split(' ').map(x => parseInt(x));
    queries.push([r1-1, c1-1, r2-1, c2-1]);
}
let result = [];
for (let [r1, c1, r2, c2] of queries) {
    let sum = 0;
    for (let i = r1; i <= r2; i++) {
        for (let j = c1; j <= c2; j++) {
            sum += matrix[i][j];
        }
    }
    result.push(sum);
}
console.log(result.join('\n'));

This code reads the matrix and queries from standard input, then for each query, it calculates the sum of all elements inside the rectangle and prints the result.

Please note that this code assumes that the rectangle is 1-indexed in the matrix (i.e., the first row and column of the matrix are 1, not 0).