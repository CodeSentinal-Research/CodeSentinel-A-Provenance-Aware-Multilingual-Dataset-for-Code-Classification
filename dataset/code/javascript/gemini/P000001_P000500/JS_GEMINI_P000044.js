const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1) {
        const n = parseInt(input[0], 10);
        const arr = [];
        for (let i = n; i >= 1; i--) arr.push(i);
        console.log(arr.join(' '));
    }
}
main();