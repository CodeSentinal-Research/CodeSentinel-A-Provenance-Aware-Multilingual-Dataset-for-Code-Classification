let readline = require('readline');

let rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let N = parseInt(rl.readLine());
let words = [];

rl.on('line', function(line) {
    words.push(line);
    if(words.length === N) rl.close();
});

rl.on('close', function() {
    if(!canOrder(words)) {
        console.log('IMPOSSIBLE');
        process.exit();
    }
    let sortedWords = orderWords(words);
    console.log(sortedWords);
    process.exit();
});

function canOrder(words) {
    let first = words[0];
    for(let i = 1; i < words.length; i++) {
        if(!canBeReordered(words[i], first)) return false;
    }
    return true;
}

function canBeReordered(word, base) {
    for(let i = 0; i < base.length; i++) {
        if(indexOf(word, base[i]) < indexOf(word, base[i + 1])) return false;
    }
    return true;
}

function indexOf(word, char) {
    return word.indexOf(char);
}

function orderWords(words) {
    let sorted = words.slice().sort((a, b) => a.localeCompare(b));
    for(let i = 0; i < sorted.length; i++) {
        let word = sorted[i];
        for(let j = 0; j < words.length; j++) {
            if(canBeReordered(word, words[j])) {
                sorted[i] = words[j];
                sorted = sorted.slice().sort((a, b) => a.localeCompare(b));
                return sorted;
            }
        }
    }
    return sorted;
}
This code reads the number of words and the words themselves from stdin, checks if they can be reordered, and if so, prints them out. If they can't be reordered, it outputs 'IMPOSSIBLE'.