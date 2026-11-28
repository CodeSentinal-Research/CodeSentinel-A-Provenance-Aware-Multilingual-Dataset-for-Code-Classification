const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim();
    if (!input) return;
    const tokens = input.split(/\s+/);
    let start = 0;
    if (tokens.length > 1 && parseInt(tokens[0], 10) === tokens.length - 1) start = 1;
    console.log(tokens.slice(start).join(' '));
}
main();