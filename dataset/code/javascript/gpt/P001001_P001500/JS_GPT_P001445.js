// P001445 - Number of Matching Subsequences
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const s = input[0];
    const n = parseInt(input[1], 10);
    const pos = Array.from({ length: 26 }, () => []);
    for (let i = 0; i < s.length; i++) {
        pos[s.charCodeAt(i) - 97].push(i);
    }
    let matches = 0;
    for (let i = 0; i < n; i++) {
        const word = input[2 + i];
        let cur = -1, ok = true;
        for (let j = 0; j < word.length; j++) {
            const list = pos[word.charCodeAt(j) - 97];
            let low = 0, high = list.length - 1, nextIdx = -1;
            while (low <= high) {
                const mid = (low + high) >> 1;
                if (list[mid] > cur) {
                    nextIdx = list[mid];
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            if (nextIdx === -1) {
                ok = false;
                break;
            }
            cur = nextIdx;
        }
        if (ok) matches++;
    }
    console.log(matches);
}

main();
