const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim();
    if (input) {
        const tokens = input.split(/\s+/).filter(t => !['null', '#', 'N'].includes(t));
        console.log(tokens.join(' '));
    }
}
main();