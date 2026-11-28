const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let NK = rl.question('', (NK_input) => {
    const [N, K] = NK_input.split(' ').map(Number);
    const arr = rl.question('', (arr_input) => {
        const arr = arr_input.split(' ').map(Number);
        console.log(findShortestSubarray(arr, N, K));
        rl.close();
    });
});

function findShortestSubarray(arr, N, K) {
    if (N === 1) return 1;
    let minLen = Infinity;
    let sum = 0;
    let left = 0;
    let right = 0;

    while (right < N) {
        sum += arr[right];
        right++;

        while (sum >= K) {
            minLen = Math.min(minLen, right - left);
            sum -= arr[left];
            left++;
        }
    }

    if (minLen === Infinity) return -1;
    return minLen;
}