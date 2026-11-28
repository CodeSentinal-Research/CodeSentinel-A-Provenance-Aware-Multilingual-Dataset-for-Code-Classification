const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter the number of elements: ', (N) => {
  rl.question('Enter the target number: ', (target) => {
    const array = rl.question('Enter the sorted array elements: ', (elements) => {
      const numArray = elements.split(' ').map(Number);
      numArray.sort((a, b) => a - b);
      let minDiff = Infinity;
      let result;

      for (let i = 0; i < N; i++) {
        const diff = Math.abs(numArray[i] - target);
        if (diff < minDiff) {
          minDiff = diff;
          result = numArray[i];
        }
      }

      console.log(result);
      rl.close();
    });
  });
});