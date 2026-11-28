const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter the number of elements: ', (N) => {
  rl.question('Enter the elements: ', (elements) => {
    const nums = elements.split(' ').map(Number);

    const segregateNums = (nums) => {
      let even = nums.filter(num => num % 2 === 0);
      let odd = nums.filter(num => num % 2 !== 0);

      return [...even, ...odd];
    }

    console.log(segregateNums(nums));

    rl.close();
  });
});