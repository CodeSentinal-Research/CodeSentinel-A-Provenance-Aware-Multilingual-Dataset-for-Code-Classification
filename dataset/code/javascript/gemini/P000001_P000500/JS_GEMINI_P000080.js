const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1) {
        const c = input[0][0];
        console.log(/^[a-zA-Z]$/.test(c) ? "Alphabet" : "Not Alphabet");
    }
}
main();