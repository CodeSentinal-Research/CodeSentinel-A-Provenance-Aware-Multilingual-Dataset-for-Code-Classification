const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim();
    if (!input) return;
    const vals = input.split(/\s+/).map(Number).sort((a, b) => a - b);
    console.log(vals.join(' '));
}
main();