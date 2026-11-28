const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let n;
rl.on('line', function(line) {
    n = parseInt(line);
});

let words = [];
rl.on('line', function(line) {
    words.push(line);
    if (words.length === n) {
        rl.close();
    }
});

rl.on('line', function(line) {
    let pattern = line;

    function matchPattern(word, pattern) {
        if (!pattern) return true;
        if (!word) return false;
        if (word.charAt(0) !== pattern.charAt(0)) return false;
        return matchPattern(word.slice(1), pattern.slice(1));
    }

    function lexicographicalOrder(a, b) {
        if (a.localeCompare(b) < 0) return -1;
        if (a.localeCompare(b) > 0) return 1;
        return 0;
    }

    let matches = words.filter(word => matchPattern(word, pattern));
    matches.sort(lexicographicalOrder);
    matches.forEach(match => console.log(match));
});

This code reads the input in two parts. The first part reads the number of words and each word, then reads the pattern. The second part of the code filters the list of words to match the pattern and sorts them in lexicographical order before printing them.