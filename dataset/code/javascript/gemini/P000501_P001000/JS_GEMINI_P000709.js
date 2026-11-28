const fs = require('fs');
function perm(chars, cur, used) {
    if (cur.length === chars.length) {
        console.log(cur);
        return;
    }
    for (let i = 0; i < chars.length; i++) {
        if (!used[i]) {
            used[i] = true;
            perm(chars, cur + chars[i], used);
            used[i] = false;
        }
    }
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const chars = tokens[0].split('').sort();
        perm(chars, "", new Array(chars.length).fill(false));
    }
}
main();