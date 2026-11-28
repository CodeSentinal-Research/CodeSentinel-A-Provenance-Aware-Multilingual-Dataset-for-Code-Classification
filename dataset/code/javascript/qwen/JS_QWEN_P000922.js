const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [l, r] = line.split(/\s+/).map(BigInt);
        function digitSum(n) {
            let s = 0n;
            while(n > 0n) {
                s += n % 10n;
                n /= 10n;
            }
            return s;
        }
        // Efficient calculation needed for large ranges, but brute force for small constraints
        // Assuming constraints allow iteration or formula
        let total = 0n;
        for(let i=l; i<=r; i++) total += digitSum(i);
        console.log(total.toString());
        rl.close();
    }
});
