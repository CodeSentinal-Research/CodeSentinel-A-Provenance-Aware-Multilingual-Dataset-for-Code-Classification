// P001398 - Find Common Characters
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const words = [];
    for (let i = 0; i < n; i++) words.push(input[1 + i]);
    const minFreq = new Array(26).fill(Infinity);
    for (const w of words) {
        const curFreq = new Array(26).fill(0);
        for (const c of w) curFreq[c.charCodeAt(0) - 97]++;
        for (let i = 0; i < 26; i++) minFreq[i] = Math.min(minFreq[i], curFreq[i]);
    }
    const res = [];
    for (let i = 0; i < 26; i++) {
        for (let k = 0; k < minFreq[i]; k++) {
            res.push(String.fromCharCode(97 + i));
        }
    }
    console.log(res.join(" "));
}

main();
