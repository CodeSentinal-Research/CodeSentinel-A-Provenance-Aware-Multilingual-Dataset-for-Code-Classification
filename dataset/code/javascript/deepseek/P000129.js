Here is a simple JavaScript solution for the problem:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter the number of elements: ', (n) => {
  rl.question('Enter the elements: ', (elements) => {
    const arr = elements.split(' ').map(Number);
    const res = [];
    for (let i = 0; i < n; i++) {
      const j = i + 1;
      while (j < n) {
        if (arr[i] < arr[j]) {
          res.push(arr[j]);
          break;
        }
        j++;
      }
      if (res[i] === undefined) {
        res.push(-1);
      }
    }
    console.log(res.join(' '));
    rl.close();
  });
});

This program reads the number of elements and elements as input from the console, splits them into arrays, and then uses a loop to find the next greater element for each element. If there is no greater element, it pushes -1 to the result array. The result array is then printed to the console.