const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 3) {
        const a = parseFloat(input[0]), b = parseFloat(input[1]), c = parseFloat(input[2]);
        const valid = (a + b > c) && (a + c > b) && (b + c > a);
        console.log(valid ? "Valid" : "Invalid");
    }
}
main();