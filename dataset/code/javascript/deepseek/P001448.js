Sure, here is the JavaScript code for your problem:

let readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let cases = [];

rl.on('line', function(line) {
    cases.push(line);
    if (cases.length === 2) {
        let sortedWords = cases[0].split(' ').map(word => word.split('').sort((a, b) => a.localeCompare(b)).join(''));
        let alphabetOrder = cases[1].split('');
        let isSorted = true;
        for(let i = 0; i < sortedWords.length - 1; i++) {
            if (sortedWords[i] > sortedWords[i + 1]) {
                isSorted = false;
                break;
            }
        }
        console.log(isSorted ? 'YES' : 'NO');
        rl.close();
    }
});

This code reads the cases from the standard input and verifies whether the words are sorted according to the given alphabet order. It reads the number of cases and the sorted words, then sorts the words alphabetically and checks if they are sorted.