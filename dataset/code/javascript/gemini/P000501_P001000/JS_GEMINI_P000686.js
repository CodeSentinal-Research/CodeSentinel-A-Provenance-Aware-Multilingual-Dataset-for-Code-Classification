const fs = require('fs');
function revStr(s) {
    if (s.length <= 1) return s;
    return s[s.length - 1] + revStr(s.slice(0, -1));
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        console.log(revStr(tokens[0]));
    }
}
main();