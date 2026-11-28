// P001112 - Word Ladder Length
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 3) return;
    const beginWord = input[0];
    const endWord = input[1];
    const n = parseInt(input[2], 10);
    const wordList = new Set();
    for (let i = 0; i < n; i++) {
        wordList.add(input[3 + i]);
    }
    if (!wordList.has(endWord)) {
        console.log(0);
        return;
    }
    const queue = [{ word: beginWord, len: 1 }];
    const visited = new Set([beginWord]);
    while (queue.length > 0) {
        const { word, len } = queue.shift();
        if (word === endWord) {
            console.log(len);
            return;
        }
        for (let i = 0; i < word.length; i++) {
            for (let c = 97; c <= 122; c++) {
                const nextWord = word.slice(0, i) + String.fromCharCode(c) + word.slice(i + 1);
                if (wordList.has(nextWord) && !visited.has(nextWord)) {
                    visited.add(nextWord);
                    queue.push({ word: nextWord, len: len + 1 });
                }
            }
        }
    }
    console.log(0);
}

main();
