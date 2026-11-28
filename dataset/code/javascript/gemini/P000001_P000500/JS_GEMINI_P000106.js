const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 2) {
        const n = parseInt(input[0], 10);
        const arr = input.slice(1, n + 1);
        console.log(arr.reverse().join(' '));
    }
}
main();