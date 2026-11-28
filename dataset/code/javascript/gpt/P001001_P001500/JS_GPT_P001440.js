// P001440 - Longest Word Through Deleting
const fs = require("fs");

function isSubsequence(sub, s) {
    let i = 0, j = 0;
    while (i < sub.length && j < s.length) {
        if (sub[i] === s[j]) i++;
        j++;
    }
    return i === sub.length;
}

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const s = input[0];
    const n = parseInt(input[1], 10);
    const words = [];
    for (let i = 0; i < n; i++) words.push(input[2 + i]);
    words.sort((a, b) => {
        if (b.length !== a.length) return b.length - a.length;
        return a.localeCompare(b);
    });
    for (const w of words) {
        if (isSubsequence(w, s)) {
            console.log(w);
            return;
        }
    }
    console.log("");
}

main();
