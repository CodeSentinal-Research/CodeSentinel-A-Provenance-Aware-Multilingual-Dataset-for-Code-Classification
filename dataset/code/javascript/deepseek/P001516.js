let readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let N, CarpetLength;

rl.on('line', function(line) {
  let parts = line.split(' ');
  N = parseInt(parts[0]);
  CarpetLength = parseInt(parts[1]);
  const tileIntervals = [];

  rl.on('line', function(line) {
    if (line === '') {
      solve(tileIntervals, CarpetLength);
      rl.close();
    } else {
      let tileInterval = line.split('-').map(Number);
      tileIntervals.push(tileInterval);
    }
  });
});

function solve(tileIntervals, CarpetLength) {
  tileIntervals.sort((a, b) => a[0] - b[0]);

  let maxTiles = 0;
  let currentEnd = 0;

  for (let i = 0; i < tileIntervals.length; i++) {
    if (tileIntervals[i][0] <= currentEnd) {
      if (tileIntervals[i][1] > currentEnd) {
        currentEnd = tileIntervals[i][1];
      }
    } else {
      maxTiles += currentEnd - currentEnd + CarpetLength;
      currentEnd = tileIntervals[i][1];
    }
  }

  maxTiles += currentEnd - currentEnd + CarpetLength;

  console.log(maxTiles);
}