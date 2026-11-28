const fs = require('fs');
function splitDescending(s) {
    function backtrack(idx, prev) {
        if (idx === s.length) return true;
        let cur = 0n;
        for (let i = idx; i < s.length; i++) {
            cur = cur * 10n + BigInt(s[i]);
            if (prev !== 0n && cur === prev - 1n) {
                if (backtrack(i + 1, cur)) return true;
            } else if (prev !== 0n && cur >= prev) {
                break;
            }
        }
        return false;
    }
    let first = 0n;
    for (let i = 0; i < s.length - 1; i++) {
        first = first * 10n + BigInt(s[i]);
        if (backtrack(i + 1, first)) return true;
    }
    return false;
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        console.log(splitDescending(tokens[0]) ? "true" : "false");
    }
}
main();