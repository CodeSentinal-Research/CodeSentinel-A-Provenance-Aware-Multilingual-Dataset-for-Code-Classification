const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const [n, k] = input.split(/\s+/).map(Number);
    function josephus(n, k) {
        if (n === 1) return 0;
        return (josephus(n-1, k) + k) % n;
    }
    console.log(josephus(n, k) + 1);
    rl.close();
});
