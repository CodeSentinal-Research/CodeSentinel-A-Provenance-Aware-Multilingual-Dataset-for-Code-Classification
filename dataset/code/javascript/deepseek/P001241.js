const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let testCases = process.argv[2] || process.env.NODE_ENV === "test";

if (testCases === 'true') {
  rl.question('Enter the number of gas stations: ', (N) => {
    rl.question('Enter gas available at each station: ', (gas) => {
      rl.question('Enter travel cost at each station: ', (cost) => {
        solve(N, gas, cost);
        rl.close();
      });
    });
  });
} else {
  rl.question('Enter the number of gas stations: ', (N) => {
    rl.question('Enter gas available at each station: ', (gas) => {
      rl.question('Enter travel cost at each station: ', (cost) => {
        solve(N, gas, cost);
        rl.close();
      });
    });
  });
}

function solve(N, gas, cost) {
  // convert input into int array
  gas = gas.split(" ").map(Number);
  cost = cost.split(" ").map(Number);

  // initialize current gas and total cost
  let currentGas = 0;
  let totalCost = 0;

  // loop through each gas station
  for (let i = 0; i < N; i++) {
    // if we run out of gas, then return -1
    if (currentGas < 0) {
      console.log(-1);
      return;
    }

    // add the gas to current gas and subtract the cost from total cost
    currentGas += gas[i];
    totalCost += cost[i];
  }

  // if current gas is still negative after looping through all gas stations, return -1
  if (currentGas < 0) {
    console.log(-1);
    return;
  }

  console.log(totalCost);
}
The code above reads the number of gas stations and gas and cost from the standard input. It then solves the problem and outputs the minimum cost.

It handles the input by reading from standard input when running in a test environment, or command line arguments when running in a non-test environment.