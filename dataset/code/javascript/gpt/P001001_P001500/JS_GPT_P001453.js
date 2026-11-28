// P001453 - Longest Consecutive Character Run
const fs = require("fs");

function main() {
    const s = fs.readFileSync(0, "utf8").trim();
    if (!s) return;
    let maxRun = 0;
    let curRun = 0;
    let prevChar = '';
    for (let i = 0; i < s.length; i++) {
        if (s[i] === prevChar) {
            curRun++;
        } else {
            prevChar = s[i];
            curRun = 1;
        }
        maxRun = Math.max(maxRun, curRun);
    }
    console.log(maxRun);
}

main();
