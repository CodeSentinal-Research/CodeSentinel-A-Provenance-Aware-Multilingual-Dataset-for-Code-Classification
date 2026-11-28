const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let n;
rl.question('Enter the number of pairs: ', (num) => {
  n = parseInt(num);
  const pairs = [];
  let maxChain = 0;

  rl.setPrompt('Enter pair (a, b): ');
  rl.prompt();

  for (let i = 0; i < n; i++) {
    rl.prompt();
    pairs.push(rl.line().split(' '));
  }

  pairs.sort((a, b) => a[1] - b[1]);

  let chain = 1;
  let maxEnd = pairs[0][1];

  for (let i = 1; i < n; i++) {
    if (pairs[i][0] > maxEnd) {
      chain++;
      maxEnd = pairs[i][1];
    }
 
    if (chain > maxChain) {
      maxChain = chain;
    }
  }

  console.log('Longest chain: ' + maxChain);

  rl.close();
});

This JavaScript code prompts the user for the number of pairs and then for each pair. After all pairs have been entered, it sorts the pairs based on the second element of each pair (b) and then finds the length of the longest chain of pairs. The result is then printed to the console.