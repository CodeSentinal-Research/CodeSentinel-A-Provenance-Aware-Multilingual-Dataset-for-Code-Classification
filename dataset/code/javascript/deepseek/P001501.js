let input = require('fs').readFileSync('/dev/stdin', 'utf8');
let lines = input.split('\n');
let N = Number(lines[0]);
let seats = lines[1].split(' ').map(Number).filter(Boolean);

let maxDist = 0;
let lastOccupiedSeatIndex = -1;

seats.forEach((seat, index) => {
    if (seat === 1) {
        if (lastOccupiedSeatIndex !== -1) {
            let dist = index - lastOccupiedSeatIndex;
            maxDist = Math.max(maxDist, dist);
        }
        lastOccupiedSeatIndex = index;
    }
});

console.log(maxDist);