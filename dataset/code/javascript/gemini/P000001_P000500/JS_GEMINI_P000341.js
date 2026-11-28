const fs = require('fs');

function wordToVal(w) {
    let val = 0;
    for (let i = 0; i < w.length; i++) {
        val = val * 10 + (w.charCodeAt(i) - 97);
    }
    return val;
}

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 3) {
        console.log(wordToVal(input[0]) + wordToVal(input[1]) === wordToVal(input[2]) ? "Yes" : "No");
    }
}

main();