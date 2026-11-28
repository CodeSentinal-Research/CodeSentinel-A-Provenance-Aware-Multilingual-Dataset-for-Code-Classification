const fs = require('fs');

function wordPattern(pattern, s) {
    const words = s.trim().split(/\s+/);
    if (pattern.length !== words.length) return false;
    const pw = new Map(), wp = new Map();
    for (let i = 0; i < pattern.length; i++) {
        const p = pattern[i], w = words[i];
        if (pw.has(p) && pw.get(p) !== w) return false;
        if (wp.has(w) && wp.get(w) !== p) return false;
        pw.set(p, w);
        wp.set(w, p);
    }
    return true;
}

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split('\n');
    if (input.length >= 2) {
        console.log(wordPattern(input[0].trim(), input[1].trim()) ? "Yes" : "No");
    } else if (input.length === 1) {
        const parts = input[0].trim().split(/\s+/);
        if (parts.length >= 2) {
            console.log(wordPattern(parts[0], parts.slice(1).join(' ')) ? "Yes" : "No");
        }
    }
}

main();