Here is a simple JavaScript solution:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let n;
rl.question('Enter the number of elements: ', (n) => {
    let arr = rl.question('Enter the array elements: ', (str) => {
        let arr = str.split(' ').map(Number);
        let q = parseInt(rl.question('Enter the number of queries: '));
        for (let i = 0; i < q; i++) {
            let [l, r] = rl.question('Enter the query range (L, R): ').split(' ').map(Number);
            let count = arr.slice(l, r + 1).filter(num => num === 0).length;
            console.log(count);
        }
        rl.close();
    });
});

This code reads an integer `n` and an array of `n` integers, then reads `q` queries. For each query, it reads two integers `L` and `R` and prints the number of 0s in the range `L` to `R` (inclusive).