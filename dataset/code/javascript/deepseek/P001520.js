const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter the number of elements: ', (N) => {
  rl.question('Enter elements: ', (elements) => {
    const numArray = elements.split(' ').map(Number);

    let maxChunks = 0;
    let maxEnd = 0;
    for (let i = 0; i < N; i++) {
      maxEnd = Math.max(maxEnd, numArray[i]);
      if (maxEnd === i) {
        maxChunks++;
      }
    }

    console.log(maxChunks);
    rl.close();
  });
});