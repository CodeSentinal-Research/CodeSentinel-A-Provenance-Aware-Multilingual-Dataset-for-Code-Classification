const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const contacts = tokens.slice(1, n + 1);
        const target = tokens[n + 1].toLowerCase();
        contacts.filter(c => c.toLowerCase() === target).forEach(c => console.log(c));
    }
}
main();