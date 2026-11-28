Here is the JavaScript code for the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter the number of points: ', (N) => {
    let points = [];
    let boomerangs = 0;

    rl.setEncoding('utf8');

    rl.write('Enter points:\n');
    rl.prompt();

    rl.on('line', (line) => {
        let [x, y] = line.split(' ');
        points.push({x: parseInt(x), y: parseInt(y)});

        if (points.length === N) {
            rl.close();
            countBoomerangs(points);
        }
    });

    function countBoomerangs(points) {
        for (let i = 0; i < points.length; i++) {
            let map = {};

            for (let j = 0; j < points.length; j++) {
                let dist = (points[i].x - points[j].x) ** 2 + (points[i].y - points[j].y) ** 2;

                if (map[dist]) {
                    map[dist]++;
                } else {
                    map[dist] = 1;
                }
            }

            for (let key in map) {
                boomerangs += map[key];
            }
        }

        console.log(boomerangs);
    }
});

This program reads the number of points from the user, and then reads the coordinates of the points. After reading all the points, it calculates the number of boomerangs and prints the result. It uses a map to count the occurrences of the distances, and then it increments the count for each distance that has occurred before.