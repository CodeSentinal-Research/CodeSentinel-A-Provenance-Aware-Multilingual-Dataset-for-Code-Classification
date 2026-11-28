const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter the number of elements in the array: ', (n) => {
  rl.question('Enter the elements of the array: ', (arrStr) => {
    const arr = arrStr.split(' ').map(Number);
    let set = new Set(arr);
    if (set.size !== arr.length) {
      console.log('No');
    } else {
      let min = Math.min(...set);
      let max = Math.max(...set);
      if (max - min + 1 === set.size && set.has(min)) {
        console.log('Yes');
      } else {
        console.log('No');
      }
    }
    rl.close();
  });
});
This program first reads the number of elements in the array from the user and then the array itself. It then checks if the array contains all integers from the smallest to the largest in the array (after removing duplicates). If it does, it prints 'Yes'; otherwise, it prints 'No'.

Please note that this solution assumes that the input is a space-separated string of numbers. If your input format is different, you'll need to modify the code accordingly.