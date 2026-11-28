Here is the JavaScript code for the problem:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let cases = Number(rl.line());

rl.on('line', (line) => {
  let input = line.split(' ');
  let n = Number(input[0]);
  let nums = input[1].split(' ').map(Number).sort((a, b) => a - b);
  let points = [0, 0]; // initialize points for two possible outcomes

  nums.forEach((num) => {
    if (points[num % 2] < points[(num + 1) % 2] + num) {
      points[num % 2] = points[(num + 1) % 2] + num;
    }
  });

  console.log(Math.max(points[0], points[1]));

  cases--;
  if (cases === 0) {
    rl.close();
  }
});

This code reads the number of test cases from the input, then for each test case, it reads the number of elements and the elements itself. It then calculates the maximum points possible by choosing each element x and all occurrences of x−1 and x+1 become unavailable. The maximum points is then printed to the console. After all test cases are processed, the script ends.