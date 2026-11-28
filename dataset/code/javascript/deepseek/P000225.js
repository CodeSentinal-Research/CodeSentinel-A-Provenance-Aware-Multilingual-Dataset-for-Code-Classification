const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let arr = [];

rl.on('line', (line) => {
    if (arr.length) {
        rl.close();
        console.log(`Minimum swaps: ${minSwaps(arr)}`);
    } else {
        arr = line.split(' ').map(Number);
    }
});

function minSwaps(arr) {
    let n = arr.length;
    let ans = 0;
    let map = new Array(n + 1).fill(0).map((v, i) => [i, arr[i]]).sort((a, b) => a[1] - b[1]).map((v, i) => [v[0], v[1]]).reverse();

    map.forEach((el, i) => {
        if (el[0] != i) {
            ans++;
            let tmp = map[i].pop();
            map[i].unshift(map[el[0]].pop());
            map[el[0]] = [tmp];
        }
    });

    return ans;
}