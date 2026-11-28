const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let memo = {};
    function countBST(n) {
        if (n <= 1) return 1;
        if (memo[n] !== undefined) return memo[n];
        let res = 0;
        for (let i = 0; i < n; i++) {
            res += countBST(i) * countBST(n - 1 - i);
        }
        memo[n] = res;
        return res;
    }
    console.log(countBST(n));
    rl.close();
});
