const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [dividend, divisor] = line.split(/\s+/).map(Number);
        if (dividend === -2147483648 && divisor === -1) { console.log(2147483647); rl.close(); return; }
        let sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        let a = Math.abs(dividend), b = Math.abs(divisor);
        let res = 0;
        while (a >= b) {
            let temp = b, m = 1;
            while (temp << 1 <= a) {
                temp <<= 1;
                m <<= 1;
            }
            a -= temp;
            res += m;
        }
        console.log(sign * res);
        rl.close();
    }
});
