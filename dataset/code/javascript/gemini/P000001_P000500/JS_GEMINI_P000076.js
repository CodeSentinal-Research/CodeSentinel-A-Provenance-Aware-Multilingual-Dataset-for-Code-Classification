const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 3) {
        const a = parseFloat(input[0]), b = parseFloat(input[1]), c = parseFloat(input[2]);
        const d = b * b - 4 * a * c;
        if (d > 0) {
            const r1 = (-b + Math.sqrt(d)) / (2 * a);
            const r2 = (-b - Math.sqrt(d)) / (2 * a);
            console.log(`${r1} ${r2}`);
        } else if (d === 0) {
            console.log(-b / (2 * a));
        } else {
            console.log("Complex Roots");
        }
    }
}
main();