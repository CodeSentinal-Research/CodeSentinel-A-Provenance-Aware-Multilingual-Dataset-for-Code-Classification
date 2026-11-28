const fs = require('fs');

function isSubsequence(sub, s) {
    let i = 0;
    for (let j = 0; j < s.length && i < sub.length; j++) {
        if (s[j] === sub[i]) i++;
    }
    return i === sub.length;
}

function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const s = tokens[0];
        const words = tokens.slice(1);
        words.sort((a, b) => {
            if (a.length !== b.length) return b.length - a.length;
            return a.localeCompare(b);
        });
        for (const w of words) {
            if (isSubsequence(w, s)) {
                console.log(w);
                return;
            }
        }
        console.log('');
    }
}

main();