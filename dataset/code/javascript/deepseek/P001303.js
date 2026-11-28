Here is a JavaScript solution for the problem. The code reads the input from the console, processes the input, and prints the output.

// Read the initial capital and the number of projects from the console
let [N, K, InitialCapital] = readline().split(' ').map(Number);

let capital = InitialCapital;
let maxProfit = 0;

// Read each project's required investment and expected profit
for(let i = 0; i < N; i++) {
    let [requiredInvestment, expectedProfit] = readline().split(' ').map(Number);
    capital += requiredInvestment;
    maxProfit = Math.max(maxProfit, capital - expectedProfit);
}

console.log(maxProfit);

This code first reads the initial capital and the number of projects from the console. It then iterates over each project, reading the required investment and expected profit. After each iteration, the code updates the current capital and the maximum profit if the required investment surpasses the current capital. Finally, it prints the maximum profit.

Please note that you need to provide the `readline` function to read the input from the console. If you're using Node.js, you can use `require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
})` to create a readline interface that can read from and write to the console.