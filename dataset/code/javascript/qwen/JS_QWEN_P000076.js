const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const [a, b, c] = input.trim().split(/\s+/).map(Number);
    const d = b*b - 4*a*c;
    if(d > 0) {
        const r1 = (-b + Math.sqrt(d))/(2*a);
        const r2 = (-b - Math.sqrt(d))/(2*a);
        console.log(`${r1.toFixed(2)} ${r2.toFixed(2)}`);
    } else if (d === 0) {
        console.log((-b/(2*a)).toFixed(2));
    } else {
        const real = (-b/(2*a)).toFixed(2);
        const imag = (Math.sqrt(-d)/(2*a)).toFixed(2);
        console.log(`${real}+${imag}i ${real}-${imag}i`);
    }
    rl.close();
});
