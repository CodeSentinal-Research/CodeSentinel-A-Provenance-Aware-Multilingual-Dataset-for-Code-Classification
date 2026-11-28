// P001498 - Separate Black and White Balls
const fs = require("fs");

function main() {
    const s = fs.readFileSync(0, "utf8").trim();
    if (!s) return;
    let blackCount = 0, swaps = 0;
    for (let i = 0; i < s.length; i++) {
        if (s[i] === '1') {
            blackCount++;
        } else {
            swaps += blackCount;
        }
    }
    console.log(swaps);
}

main();
