const fs = require('fs');

function detectCapitalUse(word) {
    let caps = 0;
    for (let i = 0; i < word.length; i++) {
        if (word[i] >= 'A' && word[i] <= 'Z') caps++;
    }
    return caps === word.length || caps === 0 || (caps === 1 && word[0] >= 'A' && word[0] <= 'Z');
}

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1 && input[0] !== '') {
        console.log(detectCapitalUse(input[0]) ? "Yes" : "No");
    }
}

main();