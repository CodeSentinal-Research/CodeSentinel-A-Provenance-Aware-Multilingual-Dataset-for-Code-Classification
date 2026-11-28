Here is the JavaScript solution for the problem:


const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let N = 0;
let K = 0;

rl.on('line', function(line) {
    let parts = line.split(' ');
    N = parseInt(parts[0]);
    K = parseInt(parts[1]);
});

rl.on('line', function(line) {
    let points = line.split(' ');
    points[0] = parseInt(points[0]);
    points[1] = parseInt(points[1]);
    points = points.map(x => Math.pow(x, 2));
    points.unshift(0);
    points.sort((a, b) => a - b);

    let closestPoints = points.slice(0, K);

    closestPoints.sort((a, b) => {
        let distanceA = Math.sqrt(a);
        let distanceB = Math.sqrt(b);
        return distanceA - distanceB;
    });

    closestPoints.forEach((point, index) => {
        console.log(point);
    });

    process.stdout.write('\n');

    if (--N > 0) {
        return rl.prompt();
    }

    rl.close();
});


This script reads the first line of input, and then the points. It calculates the distance from the origin for each point, sorts them by distance, and then prints the K smallest points. It handles the case when there are less than K points.