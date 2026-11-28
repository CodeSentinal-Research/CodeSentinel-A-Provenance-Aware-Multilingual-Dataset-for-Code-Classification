Here is the JavaScript code that solves the problem.

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let inputData = [];

rl.on('line', (line) => {
    inputData = line.split(" ").map(Number);
    let [N, K] = inputData;
    inputData = rl.question('Enter speeds separated by space: ', (speed) => {
        inputData = speed.split(" ").map(Number);
        let speeds = inputData.sort((a, b) => a - b);
        inputData = rl.question('Enter efficiencies separated by space: ', (efficiency) => {
            let efficiencies = inputData.map(Number);
            let performance = speeds.slice(0, K).reduce((a, b) => a + b, 0) * Math.min(...efficiencies);
            console.log(performance);
            rl.close();
        });
    });
});
This code uses Node.js's readline module to read input from the console in an interactive way. The input is first read as a string, and then split into an array of numbers. The numbers are then used to define the size of the team (N) and the maximum number of engineers to select (K).

Then, the speeds of the engineers are read and sorted. This is because the team must maximize the sum of their speeds, and speeds should be as small as possible (to minimize the efficiency of the engineers). 

Finally, the efficiencies of the engineers are read. The sum of the speeds of the selected engineers (times their efficiency) is then multiplied by the smallest efficiency (using the `Math.min` function to find the smallest efficiency among the engineers). The result is printed to the console.