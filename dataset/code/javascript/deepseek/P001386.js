let readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter the number of integers: ', (n) => {
  rl.question('Enter the integers separated by space: ', (input) => {
    const nums = input.split(' ').map(Number);
    const numSet = new Set();
    let duplicatedNum;

    for (let num of nums) {
      if (numSet.has(num)) {
        duplicatedNum = num;
        break;
      }
      numSet.add(num);
    }

    console.log(duplicatedNum);
    rl.close();
  });
});