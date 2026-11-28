let fs = require('fs');
let input = fs.readFileSync('input.txt', 'utf8');
input = input.split('\n');

let N = parseInt(input[0]);
let seats = input[1].split(' ').map(Number);

let maxDistance = 0;
let maxDistanceSeat1 = -1;
let maxDistanceSeat2 = -1;
let prevSeat = -1;

for (let i = 0; i < N; i++) {
    if (seats[i] === 1) {
        if (prevSeat !== -1) {
            let distance = i - prevSeat;
            if (distance > maxDistance) {
                maxDistance = distance;
                maxDistanceSeat1 = prevSeat;
                maxDistanceSeat2 = i;
            }
        }
        prevSeat = i;
    }
}

console.log(maxDistanceSeat1, maxDistanceSeat2);

Please note that this code assumes that there are two occupied seats. If you are only looking for one occupied seat, you would need to slightly modify the logic.