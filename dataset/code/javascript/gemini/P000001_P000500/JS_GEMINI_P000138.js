const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 2) {
        const m = parseInt(input[0], 10), n = parseInt(input[1], 10);
        const arr1 = input.slice(2, 2 + m).map(Number);
        const arr2 = input.slice(2 + m, 2 + m + n).map(Number);
        const res = [...arr1, ...arr2].sort((a, b) => a - b);
        console.log(res.join(' '));
    }
}
main();