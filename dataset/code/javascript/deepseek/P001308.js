const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let inputs = [];

rl.on('line', function(line) {
    inputs.push(line.split(' '));

    if (inputs.length == 2) {
        rl.close();
    }
});

const [W, H, N] = inputs[0].map(Number);
const towers = inputs.slice(1).map(t => [t[0] * W, t[1] * H]).map(([x, y], i) => ({ id: i, x: x, y: y, w: x - (i === 0 ? 0 : towers[i - 1].x), h: y - (i === 0 ? 0 : towers[i - 1].y) }));

towers.sort((a, b) => a.id - b.id);

let largestArea = 0;
let endX = 0, endY = 0;

for (let { x, y, w, h } of towers) {
    if (x < endX) continue;

    const currentArea = w * h;

    if (currentArea > largestArea) {
        largestArea = currentArea;
        endX = x + w;
    }
}

console.log(largestArea);