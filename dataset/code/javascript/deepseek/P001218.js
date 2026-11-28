Here is a JavaScript solution for the word break problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let testCases = Number(rl.line());

rl.on('line', (line) => {
    let [length, numWords] = line.split(' ');
    let dictionary = {};

    for (let i = 0; i < numWords; i++) {
        dictionary[rl.line()] = true;
    }

    function canSegment(input, seen) {
        if (seen.hasOwnProperty(input)) {
            return seen[input];
        }
        if (dictionary.hasOwnProperty(input)) {
            seen[input] = true;
            return true;
        }
        for (let i = 1; i <= input.length; i++) {
            if (canSegment(input.substring(i), seen)) {
                seen[input] = true;
                return true;
            }
        }
        seen[input] = false;
        return false;
    }

    for (let i = 0; i < testCases; i++) {
        console.log(canSegment(rl.line(), {}) ? 'YES' : 'NO');
    }

    rl.close();
});

This solution works by reading the test cases, then reading the dictionary words one by one. It checks if the input string can be segmented using the dictionary words. It uses a depth-first search approach to solve this problem.