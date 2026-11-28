let readline = require('readline');

let rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let inputs = [];

rl.on('line', function(line) {
    inputs.push(Number(line));
}).on('close', function() {
    let n = inputs[0];
    let target = inputs[1];
    let nums = inputs.slice(2);

    let triplets = 0;

    nums.forEach((num, i) => {
        for(let j = i + 1; j < nums.length; j++) {
            for(let k = j + 1; k < nums.length; k++) {
                if(num + nums[j] + nums[k] === target) {
                    triplets++;
                }
            }
        }
    });

    console.log(triplets);

    rl.close();
});