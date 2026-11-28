const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const users = tokens.slice(1, n + 1);
        const prefix = tokens[n + 1];
        users.filter(u => u.startsWith(prefix)).forEach(u => console.log(u));
    }
}
main();