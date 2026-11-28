const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    function climb(n) {
        if(n<=1) return 1;
        return climb(n-1) + climb(n-2);
    }
    console.log(climb(n));
    rl.close();
});
