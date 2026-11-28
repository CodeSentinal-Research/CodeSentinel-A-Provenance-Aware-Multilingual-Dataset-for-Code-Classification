Here is the JavaScript code:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let firstSentence, secondSentence;

rl.question('Enter the first sentence: ', (sentence) => {
  firstSentence = sentence;
  rl.question('Enter the second sentence: ', (sentence) => {
    secondSentence = sentence;
    const map1 = new Map(), map2 = new Map();

    for (const word of firstSentence.split(' ')) {
      map1.set(word, (map1.get(word) || 0) + 1);
    }

    for (const word of secondSentence.split(' ')) {
      map2.set(word, (map2.get(word) || 0) + 1);
    }

    const result = [];
    for (const [word, count] of map1) {
      if (count === 1 && !map2.has(word) && word.toLowerCase() !== word.toUpperCase()) {
        result.push(word);
      }
    }

    result.sort();
    console.log(result);

    rl.close();
  });
});

This program uses the readline module to get the input from the user. It reads two sentences from the user, then counts the occurrences of each word in both sentences, and finally prints all words that appear only once in one sentence. The result is then sorted lexicographically and printed.