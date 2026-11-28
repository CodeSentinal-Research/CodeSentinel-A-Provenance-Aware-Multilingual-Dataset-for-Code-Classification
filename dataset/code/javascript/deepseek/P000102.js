Here is the JavaScript code for your problem:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let cases;
rl.question('Enter the number of test cases: ', (cases) => {
  for (let i = 0; i < cases; i++) {
    rl.question('Enter number of elements: ', (numElements) => {
      let arr = [];
      rl.question('Enter elements: ', (elements) => {
        arr = elements.split(' ').map(Number);
        console.log('Smallest element is: ' + Math.min(...arr));
      });
    });
  }
  rl.close();
});
In this code, we use the readline module to handle multi-line input. The user is asked to enter the number of test cases and then for each test case, the user is asked to enter the number of elements. Afterwards, the user is asked to enter the elements. After all the test cases are processed, the program ends.