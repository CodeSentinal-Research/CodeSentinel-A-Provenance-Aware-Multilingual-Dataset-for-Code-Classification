// P001499 - Reverse Prefix of Word
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const word = input[0];
    const ch = input[1];
    const idx = word.indexOf(ch);
    if (idx === -1) {
        console.log(word);
        return;
    }
    const prefix = word.substring(0, idx + 1).split("").reverse().join("");
    const suffix = word.substring(idx + 1);
    console.log(prefix + suffix);
}

main();
