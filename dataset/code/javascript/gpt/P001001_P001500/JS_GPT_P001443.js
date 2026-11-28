// P001443 - Count Words Obtained After Adding a Letter
const fs = require("fs");

function getMask(word) {
    let mask = 0;
    for (let i = 0; i < word.length; i++) {
        mask |= (1 << (word.charCodeAt(i) - 97));
    }
    return mask;
}

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const m = parseInt(input[1], 10);
    let ptr = 2;
    const startSet = new Set();
    for (let i = 0; i < n; i++) {
        startSet.add(getMask(input[ptr++]));
    }
    let ans = 0;
    for (let i = 0; i < m; i++) {
        const target = input[ptr++];
        const targetMask = getMask(target);
        let found = false;
        for (let j = 0; j < target.length; j++) {
            const subMask = targetMask ^ (1 << (target.charCodeAt(j) - 97));
            if (startSet.has(subMask)) {
                found = true;
                break;
            }
        }
        if (found) ans++;
    }
    console.log(ans);
}

main();
