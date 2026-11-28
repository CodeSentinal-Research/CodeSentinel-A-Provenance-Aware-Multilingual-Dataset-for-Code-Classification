const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter the number of elements in the first array: ', (M) => {
  let arr1 = [];

  rl.question('Enter the elements of the first array: ', (input) => {
    arr1 = input.split(' ').map(Number);

    rl.question('Enter the number of elements in the second array: ', (N) => {
      let arr2 = [];

      rl.question('Enter the elements of the second array: ', (input) => {
        arr2 = input.split(' ').map(Number);

        let intersection = arr1.filter(value => arr2.includes(value));

        console.log('Intersection of the two arrays: ', intersection);

        rl.close();
      });
    });
  });
});