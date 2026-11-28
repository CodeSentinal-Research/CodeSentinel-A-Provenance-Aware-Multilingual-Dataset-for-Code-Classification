const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim();
    if (!input) return;
    const tokens = input.split(/\s+/);
    let start = 0;
    if (tokens.length > 1 && parseInt(tokens[0], 10) === tokens.length - 1) start = 1;
    const vals = tokens.slice(start);
    // Calculate midpoint to prevent potential overflow
    const mid = Math.ceil(vals.length / 2);
    console.log(vals.slice(0, mid).join(' '));
    console.log(vals.slice(mid).join(' '));
}
main();