Here is a simple JavaScript solution for the given problem:

let readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter number of elements: ', (N) => {
  rl.question('Enter difference array: ', (diffArray) => {
    let arr = [diffArray[0]];

    for (let i = 1; i < N; i++) {
      arr[i] = arr[i - 1] + diffArray[i];
    }

    console.log('Reconstructed array:', arr);
    rl.close();
  });
});

This code first reads the number of elements (N) and then the difference array from the standard input. It then constructs the reconstructed array by iterating over the difference array and adding the current difference to the previous element of the array. Finally, it prints the reconstructed array.