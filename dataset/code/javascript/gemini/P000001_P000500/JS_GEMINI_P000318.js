const fs = require('fs');

function validWordAbbreviation(word, abbr) {
    let i = 0, j = 0;
    while (i < word.length && j < abbr.length) {
        if (abbr[j] >= '0' && abbr[j] <= '9') {
            if (abbr[j] === '0') return false;
            let num = 0;
            while (j < abbr.length && abbr[j] >= '0' && abbr[j] <= '9') {
                num = num * 10 + parseInt(abbr[j++], 10);
            }
            i += num;
        } else {
            if (word[i] !== abbr[j]) return false;
            i++;
            j++;
        }
    }
    return i === word.length && j === abbr.length;
}

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 2) {
        console.log(validWordAbbreviation(input[0], input[1]) ? "Yes" : "No");
    }
}

main();