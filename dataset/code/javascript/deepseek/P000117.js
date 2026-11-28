const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter the number of elements: ', (n) => {
  rl.question('Enter the elements: ', (elements) => {
    const nums = elements.split(' ').map(Number);

    const numsSet = new Set(nums);
    const numsFreq = nums.reduce((acc, num) => {
      acc[num] = (acc[num] || 0) + 1;
      return acc;
    }, {});

    for (let num of numsSet) {
      if (numsFreq[num] > 1) {
        console.log('Yes');
        return;
      }
    }

    console.log('No');
    rl.close();
  });
});