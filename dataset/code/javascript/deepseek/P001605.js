const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let cases = 0;
rl.once('line', line => {
    [cases, rl.close()] = line.split(' ').map(Number);
});

rl.once('line', line => {
    const nums = line.split(' ').map(Number);

    let map = new Map();
    let sum = 0;
    let maxLen = 0;

    for (let num of nums) {
        sum += num;
        if (sum === K) {
            maxLen = Math.max(maxLen, 1);
        } else if (map.has(sum - K)) {
            maxLen = Math.max(maxLen, map.get(sum - K) + 1);
        }
        map.set(sum, (map.get(sum) || 0) + 1);
    }

    console.log(maxLen === 0 ? 0 : maxLen);
});

rl.close();