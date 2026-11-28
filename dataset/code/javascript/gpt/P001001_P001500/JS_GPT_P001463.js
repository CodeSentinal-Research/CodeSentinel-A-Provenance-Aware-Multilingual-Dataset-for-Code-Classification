// P001463 - Remove Element
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const s = input[0];
    const p = input[1];
    if (s.length < p.length) {
        console.log("");
        return;
    }
    const pCount = new Array(26).fill(0);
    const sCount = new Array(26).fill(0);
    for (let i = 0; i < p.length; i++) {
        pCount[p.charCodeAt(i) - 97]++;
        sCount[s.charCodeAt(i) - 97]++;
    }
    function match() {
        for (let i = 0; i < 26; i++) {
            if (pCount[i] !== sCount[i]) return false;
        }
        return true;
    }
    const res = [];
    if (match()) res.push(0);
    for (let i = p.length; i < s.length; i++) {
        sCount[s.charCodeAt(i) - 97]++;
        sCount[s.charCodeAt(i - p.length) - 97]--;
        if (match()) res.push(i - p.length + 1);
    }
    console.log(res.join(" "));
}

main();
