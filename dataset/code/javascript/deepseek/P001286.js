Here is the JavaScript code:

let readline = require('readline');

let rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let inputs = [];
rl.on('line', function(line){
    inputs.push(parseInt(line));
});

rl.on('close', function(){
    let N = inputs[0];
    let additionalRocks = inputs[1];
    let capacities = inputs.slice(2, inputs.length).map(capacity => Math.min(capacity, additionalRocks));
    let currentRocks = inputs.slice(2, inputs.length);

    capacities.sort((a, b) => b - a);
    currentRocks.sort((a, b) => b - a);

    let count = 0;
    let currentCapacity = capacities.shift();
    while(currentCapacity <= additionalRocks){
        count++;
        currentCapacity += capacities.shift();
    }

    console.log(count);

    process.exit();
});

This code will read the number of bags N and the additional rocks from the input, then it will read the capacities and current rocks of each bag, and finally it will print the maximum number of bags that can be completely filled.