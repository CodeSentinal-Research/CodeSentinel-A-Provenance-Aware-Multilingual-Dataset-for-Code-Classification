// P001439 - Unique Morse Code Words
const fs = require("fs");

const MORSE = [
    ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
    "-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-",
    "..-","...-",".--","-..-","-.--","--.."
];

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const seen = new Set();
    for (let i = 0; i < n; i++) {
        const word = input[1 + i];
        let trans = "";
        for (let j = 0; j < word.length; j++) {
            trans += MORSE[word.charCodeAt(j) - 97];
        }
        seen.add(trans);
    }
    console.log(seen.size);
}

main();
