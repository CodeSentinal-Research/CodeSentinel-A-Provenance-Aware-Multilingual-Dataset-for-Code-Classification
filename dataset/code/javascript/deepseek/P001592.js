const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let arr = [];

rl.on('line', function(line) {
    arr = line.split(' ').map(Number);
}).on('close', function() {
    const N = arr[0];
    const X = arr[1];
    let sum = 0;
   let minIndex = N+1;

    for(let i = 0; i < N; i++){
        sum += arr[i];
        if(sum >= X && i + 1 < minIndex){
            minIndex = i + 1;
        }
    }

    if(minIndex === N+1){
        console.log(-1);
    } else {
        console.log(minIndex);
    }
    rl.close();
});
In this code, we read the input line by line and store the integer values in the array. When all lines are read, we calculate the prefix sum and find the smallest index such that the prefix sum is greater than or equal to X. If no such index is found, we print -1.