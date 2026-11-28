Here is the JavaScript code for the problem:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let tests = process.argv[2] || 0;

rl.question('Enter the number of test cases: ', (tests) => {
  for(let i = 0; i < tests; i++) {
    rl.question('Enter target and numbers separated by space: ', (input) => {
      const [target, ...numbersStr] = input.split(' ');
      const numbers = [...numbersStr].map(Number);
      const sortedNumbers = [...numbers].sort((a, b) => a - b);
      let found = false;

      for (let i = 0; i < sortedNumbers.length - 2; i++) {
        let start = i + 1;
        let end = sortedNumbers.length - 1;
        while (start < end) {
          const sum = sortedNumbers[i] + sortedNumbers[start] + sortedNumbers[end];
          if (sum === target) {
            found = true;
            console.log('Yes');
            break;
          } else if (sum < target) {
            start++;
          } else {
            end--;
          }
        }
        if(found) break;
      }

      if (!found) {
        console.log('No');
      }

      rl.close();
    });
  }
});

This code uses readline module to read input from the command line. It handles multiple test cases from the input. For each test case, it reads the target and numbers, sorts them, and checks each triplet for a sum equal to the target. If it finds a triplet, it prints 'Yes' and stops. If it doesn't find any triplets, it prints 'No'.