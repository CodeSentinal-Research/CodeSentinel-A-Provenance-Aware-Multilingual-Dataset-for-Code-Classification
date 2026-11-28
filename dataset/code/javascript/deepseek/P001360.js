Here is the JavaScript code that can solve the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let cases;
rl.on('line', (line) => {
    if (cases === undefined) {
        cases = parseInt(line);
    } else {
        const words = line.split(' ').map(s => s.trim());
        const letters = line.split('');
        const scores = letters.slice(0, 26).map(c => parseInt(c));
        console.log(maxScore(words, scores));
        cases--;
    }
});

function maxScore(words, scores) {
    let maxScore = 0;

    function recurse(index, usedChars) {
        if (index === words.length) {
            let score = 0;
            for (let i = 0; i < words.length; i++) {
                let word = words[i];
                let found = true;
                for (let c of word) {
                    if (usedChars[c.charCodeAt() - 'a'.charCodeAt()] === 0) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    score += word.length;
                }
            }
            maxScore = Math.max(maxScore, score);
        } else {
            for (let i = 0; i < 26; i++) {
                usedChars[i] = 1;
                recurse(index + 1, usedChars);
                usedChars[i] = 0;
            }
        }
    }

    recurse(0, new Array(26).fill(0));
    return maxScore;
}

This code uses a recursive approach to solve the problem. It iterates through all possible combinations of words that can be formed using the available letters, and calculates the total score for each combination. It then returns the maximum score found.