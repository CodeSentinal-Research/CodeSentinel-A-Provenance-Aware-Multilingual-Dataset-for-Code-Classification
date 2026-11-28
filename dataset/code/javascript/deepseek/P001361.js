Here is the JavaScript code for the problem.

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let tests = [];

rl.on('line', (line) => {
  tests.push(line);
  if (tests.length == 51) {
    rl.close();
  }
});

rl.on('close', () => {
  solve(tests[0], tests[1], tests[2], tests[3]);
});

function solve(N, stickers, target) {
  const stickerMap = new Map();
  const targetMap = new Map();

  for (let i = 0; i < N; i++) {
    let sticker = stickers[i];
    if (stickerMap.has(sticker)) {
      stickerMap.set(sticker, stickerMap.get(sticker) + 1);
    } else {
      stickerMap.set(sticker, 1);
    }
  }

  for (let char of target) {
    if (!targetMap.has(char)) {
      console.log(-1);
      return;
    }
    if (targetMap.get(char) > stickerMap.get(char)) {
      stickerMap.set(char, targetMap.get(char));
    }
  }

  let total = 0;
  for (let [key, value] of stickerMap) {
    total += Math.floor(value / 50);
  }
  console.log(total);
}

This code reads the input line by line. When it gets N lines of stickers, it then checks the target word. If there's a sticker in the target word that doesn't exist, it prints -1 and ends. If there's a sticker in the target word that exists but its count is more than the sticker count in the word, it updates the sticker count in the word. Finally, it calculates the total number of stickers required and prints it.