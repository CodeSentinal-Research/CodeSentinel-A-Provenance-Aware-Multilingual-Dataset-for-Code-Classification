Here is a simple JavaScript solution for the problem. This code takes input N, then N lines. Each line contains three integers, representing the merit points obtained from different activities on a day. We keep track of the maximum merit points achieved by the ninja so far.

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let n;
rl.question('Enter the number of days: ', (n) => {
  let maxPoints = 0;
  let points;
  for(let i = 0; i < n; i++) {
    rl.question('Enter the merit points for the 1st, 2nd and 3rd activities on day ' + (i+1) + ': ', (strPoints) => {
      points = strPoints.split(' ').map(Number);
      maxPoints = Math.max(maxPoints, points[0] + points[1] + points[2]);
      console.log(`Max points so far: ${maxPoints}`);
    });
  }
  console.log(`Max points: ${maxPoints}`);
  rl.close();
});
In this code, we use the `readline` module to read the input. The first question asks for the number of days. For each day, it asks for the merit points for the 1st, 2nd and 3rd activities. We keep track of the maximum points obtained so far and update it whenever we get a new maximum. Finally, we print the maximum points.