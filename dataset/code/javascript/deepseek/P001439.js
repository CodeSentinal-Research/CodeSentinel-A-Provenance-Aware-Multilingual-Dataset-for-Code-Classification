let readline = require('readline');

let rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter number of words: ', (N) => {
    let words = [];
    rl.setPrompt('Enter word: ');

    for(let i = 0; i < N; i++) {
        rl.prompt();
    }

    let distinctWords = new Set();
    words.forEach((word) => {
        distinctWords.add(word);
    });

    console.log(`Number of distinct words: ${distinctWords.size}`);

    rl.close();
});
This code uses Node.js's readline module to read input from the user. The first line of input is the number of words, and the rest are the words themselves. It then creates a Set, which automatically removes duplicates, and prints the size of this set, which is the number of unique words.