Here's a JavaScript code that solves the problem. This code takes the distances and speeds as inputs and calculates the maximum number of monsters that can be eliminated.

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter the number of monsters: ', (N) => {
    rl.question('Enter the distances of the monsters: ', (distances) => {
        rl.question('Enter the speeds of the monsters: ', (speeds) => {
            let distancesArray = distances.split(' ').map(Number);
            let speedsArray = speeds.split(' ').map(Number);
            let eliminations = 0;

            for (let i = 0; i < N; i++) {
                let distToCity = Math.abs(distancesArray[i] - speedsArray[i]);
                while (distToCity >= speedsArray[i]) {
                    distToCity -= speedsArray[i];
                    eliminations++;
                }
            }

            console.log(eliminations);
            rl.close();
        });
    });
});

You can run this code in a Node.js environment. When you run it, it will ask you to enter the number of monsters, the distances of the monsters, and the speeds of the monsters. After entering these values, it will calculate and print the maximum number of monsters that can be eliminated.