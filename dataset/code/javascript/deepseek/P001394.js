Here is the JavaScript code:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let cases = [];

rl.on('line', function(line) {
    cases.push(line);
    if(cases.length === 3) {
        rl.close();
        solve(cases[0], cases[1], cases[2]);
    }
});

function solve(N, K, arr) {
    let [start, end] = [0, 0];
    let sum = 0;
    let maxLen = 0;
    let map = new Map();

    for(let i = 0; i < N; i++) {
        sum += arr[i];
        if(sum === K) {
            maxLen = Math.max(maxLen, i+1);
            start = i + 1;
            end = i + 1;
            sum -= arr[i];
        }
        if(map.has(sum - K)) {
            if(end - map.get(sum - K) + 1 > maxLen) {
                maxLen = end - map.get(sum - K) + 1;
                start = map.get(sum - K) + 1;
                end = i + 1;
            }
        }
        if(!map.has(sum)) {
            map.set(sum, i);
        }
    }

    if(maxLen ===0){
        console.log("No subarray exists");
    } else {
        console.log(maxLen);
    }
}

This code uses a map to store the sum of all elements up to the current index and if the difference between the current sum and K exists in the map, it updates the maxLen and the start and end indexes. If the difference does not exist, it adds the current sum to the map.