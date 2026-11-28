Here is the JavaScript code to solve the problem:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter the number of rows: ', (N) => {
  let triangle = [];

  for(let i = 0; i < N; i++) {
    triangle[i] = [];
    rl.question(`Enter row ${i+1} of numbers: `, (input) => {
      triangle[i] = input.split(' ').map(Number);
      if(i != N - 1) rl.question(`Enter next row ${i+2} of numbers: `, (nextInput) => {
        triangle[i+1] = nextInput.split(' ').map(Number);
        findMinimumPathSum(triangle);
      });
    });
  }

  rl.close();
});

function findMinimumPathSum(triangle) {
  let minSum = Number.MAX_SAFE_INTEGER;
  let minPath = [];

  function findMinPathUtil(triangle, x, y, sum, path) {
    sum += triangle[x][y];
    path.push(triangle[x][y]);

    if (x == triangle.length - 1) {
      if (sum < minSum) {
        minSum = sum;
        minPath = [...path];
      }
    } else {
      findMinPathUtil(triangle, x + 1, y, sum, path);
      findMinPathUtil(triangle, x + 1, y + 1, sum, path);
    }
  }

  findMinPathUtil(triangle, 0, 0, 0, []);

  console.log(`Minimum path sum: ${minSum}\nPath: ${minPath.join(' -> ')}`);
}

This code uses a `readline` module to read the number of rows and the triangle from the user. It then uses recursion to find the minimum path sum and prints the result. The recursion is done by checking if we are at the bottom of the triangle and if we have a smaller sum than the current one, if so, we update the minimum sum and the path.