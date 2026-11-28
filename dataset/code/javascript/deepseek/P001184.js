const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let N, K;
rl.question('Enter N and K (separated by space): ', (line) => {
  [N, K] = line.split(' ').map(Number);
  if (N < 2 || N > 100000 || K < 1 || K > N) {
    console.log('Invalid input');
    rl.close();
  } else {
    const stones = rl.question('Enter the heights of the stones (separated by space): ', (line) => {
      const heights = line.split(' ').map(Number);
      console.log(minEnergy(heights, K));
      rl.close();
    });
  }
});

function minEnergy(heights, K) {
  heights.sort((a, b) => a - b);
  let minEnergy = Infinity;
  for (let i = 0; i < heights.length - K + 1; i++) {
    const energy = Math.abs(heights[i] - heights[i + K - 1]);
    minEnergy = Math.min(minEnergy, energy);
  }
  return minEnergy;
}
This code uses readline to get the input from the user and then calls a helper function minEnergy that calculates and returns the minimum energy required to reach the last stone.