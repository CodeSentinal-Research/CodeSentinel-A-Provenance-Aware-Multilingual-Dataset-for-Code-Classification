Here is a simple JavaScript program that calculates the earliest possible full bloom day. 

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter the number of flowers: ', (numFlowers) => {

    rl.question('Enter planting times: ', (plantingTimes) => {

        rl.question('Enter growing times: ', (growingTimes) => {

            let plantingTimesArray = plantingTimes.split(' ').map(Number);
            let growingTimesArray = growingTimes.split(' ').map(Number);

            let earliestFullBloom = plantingTimesArray.indexOf(Math.min(...plantingTimesArray));
            let earliestBloomTime = Math.min(...plantingTimesArray.concat(growingTimesArray));

            console.log('Earliest possible full bloom day: ' + earliestBloomTime);

            rl.close();
        });
    });
});
This program first reads the number of flowers and the planting and growing times from the console. It then uses the `indexOf` method to find the planting time that is the earliest (i.e., the earliest when all flowers will be in full bloom). Finally, it uses the `concat` method to combine the planting times and growing times into a single array, and then uses the `Math.min` function to find the earliest possible full bloom time.