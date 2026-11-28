let input = require('fs').readFileSync('/dev/stdin', 'utf8');
let N = parseInt(input.split('\n')[0]);
let A = input.split('\n')[1].split(' ').map(Number);
let Q = parseInt(input.split('\n')[2]);
let queries = [];
for (let i = 0; i < Q; i++) {
    queries.push(input.split('\n')[i + 3].split(' ').map(Number));
}

for (let query of queries) {
    let [L, R, X] = query;
    let count = 0;
    for (let i = L; i <= R; i++) {
        if (A[i] === X) {
            count++;
        }
    }
    console.log(count);
}
This JavaScript code reads input from stdin and splits it into N, A, and Q. It then creates an array of queries and for each query, it counts the number of occurrences of X in the range L to R (inclusive). The result is then printed to stdout.