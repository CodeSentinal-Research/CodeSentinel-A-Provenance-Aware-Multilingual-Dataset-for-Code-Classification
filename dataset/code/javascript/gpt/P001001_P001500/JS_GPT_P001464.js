// P001464 - Move Zeroes
const fs = require("fs");

function main() {
    const s = fs.readFileSync(0, "utf8").trim();
    if (!s) return;
    const count = new Map();
    for (let i = 0; i < s.length; i++) {
        count.set(s[i], (count.get(s[i]) || 0) + 1);
    }
    for (let i = 0; i < s.length; i++) {
        if (count.get(s[i]) === 1) {
            console.log(i);
            return;
        }
    }
    console.log(-1);
}

main();
