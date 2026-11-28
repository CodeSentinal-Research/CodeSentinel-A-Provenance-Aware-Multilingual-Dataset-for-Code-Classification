const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const emails = tokens.slice(1, n + 1);
        let domain = tokens[n + 1];
        if (!domain.startsWith('@')) domain = '@' + domain;
        emails.filter(e => e.endsWith(domain)).forEach(e => console.log(e));
    }
}
main();