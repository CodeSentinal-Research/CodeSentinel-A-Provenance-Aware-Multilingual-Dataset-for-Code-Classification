const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let cases = 0;
rl.on('line', (line) => {
    if (cases) rl.pause();
    const [N, ...A] = line.split(' ').map(x => parseInt(x));
    if (N === 0) return rl.close();
    console.log(sumPartitions(A, N));
    cases++;
});

function sumPartitions(arr, N) {
    if (N % 3 !== 0) return 0;
    const target = N / 3;
    let count = 0;
    const cache = new Map();
    function dp(i, a, b, c) {
        if (i < 0) return a === b && b === c;
        const key = `${i}-${a}-${b}-${c}`;
        if (cache.has(key)) return cache.get(key);
        count += dp(i - 1, a, b, c) || dp(i - 1, a + arr[i], b, c) || dp(i - 1, a, b + arr[i], c) || dp(i - 1, a, b, c + arr[i]);
        return cache.set(key, count).get(key);
    }
    return dp(N - 1, 0, 0, 0);
}