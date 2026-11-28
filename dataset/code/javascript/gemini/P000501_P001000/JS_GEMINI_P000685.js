const fs = require('fs');
function isPalRec(s, l, r) {
    if (l >= r) return true;
    if (s[l] !== s[r]) return false;
    return isPalRec(s, l + 1, r - 1);
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const s = tokens[0];
        console.log(isPalRec(s, 0, s.length - 1) ? "true" : "false");
    }
}
main();