const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let testCases = [];

rl.on('line', (line) => {
    testCases.push(line);
    if (testCases.length == 2) {
        solve(testCases[0], testCases[1]);
        rl.close();
    }
});

function solve(str, char) {
    let distances = [];
    let minDistance = Infinity;
    let nearestCharIndex = -1;
    let nearestCharDistance = Infinity;

    for (let i = 0; i < str.length; i++) {
        if (str[i] == char) {
            minDistance = 0;
            nearestCharIndex = i;
            nearestCharDistance = Infinity;
        } else {
            minDistance++;
        }

        if (minDistance <= nearestCharDistance) {
            nearestCharDistance = minDistance;
        }

        distances.push(nearestCharDistance);
    }

    console.log(distances.join(" "));
}