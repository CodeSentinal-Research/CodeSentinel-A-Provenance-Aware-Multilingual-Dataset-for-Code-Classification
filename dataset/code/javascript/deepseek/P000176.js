Here's the JavaScript code for the Chocolate Distribution Problem:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let NK = [];

rl.on('line', function(line) {
  NK = line.split(' ').map(Number);
}).on('close', function() {
  console.log(chocolateDistribution(NK[0], NK[1]));
  process.exit();
});

function chocolateDistribution(N, K) {
  const packets = Array(N).fill(0);
  const sortedPackets = Array.from(packets).sort((a, b) => a - b);
  
  let minDiff = Number.MAX_SAFE_INTEGER;
  
  for (let i = 0; i < N - K + 1; i++) {
    minDiff = Math.min(minDiff, sortedPackets[i + K - 1] - sortedPackets[i]);
  }
  
  return minDiff;
}

This program reads the number of packets and the number of packets to choose from them. It then sorts the packets in ascending order. It iterates over the packets, choosing the largest and smallest (K-1) packets at a time, and computes the difference. It keeps track of the smallest difference found and updates it whenever a smaller difference is found. Finally, it returns the smallest difference found.