const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let inputs = [];

rl.on('line', function(line) {
    inputs.push(parseInt(line));
})

.on('close', function() {
    let N = inputs[0];
    let nums = inputs.slice(1, N + 1);
    let Q = inputs[N + 1];
    let queries = [];
    
    for(let i = 0; i < Q; i++) {
        queries.push([inputs[N + i + 2], inputs[N + i + 3]]);
    }

    for(let i = 0; i < N; i++) {
        nums[i] = 0;
    }

    for(let i = 0; i < Q; i++) {
        let sum = 0;
        let rangeStart = queries[i][0];
        let rangeEnd = queries[i][1];

        for(let j = rangeStart; j <= rangeEnd; j++) {
            sum += nums[j];
        }

        console.log((sum/((rangeEnd - rangeStart + 1) || 1)).toFixed(3));
    }

    rl.close();
})
This code will take in the number of integers N, followed by the integers themselves, and the number of queries Q, followed by the ranges for each query. It then calculates the average of the numbers in each range and prints it.