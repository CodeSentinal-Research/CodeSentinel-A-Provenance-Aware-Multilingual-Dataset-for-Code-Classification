const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 3) {
        const n = parseInt(input[0], 10), target = input[1];
        const arr = input.slice(2, n + 2);
        console.log(arr.indexOf(target));
    }
}
main();