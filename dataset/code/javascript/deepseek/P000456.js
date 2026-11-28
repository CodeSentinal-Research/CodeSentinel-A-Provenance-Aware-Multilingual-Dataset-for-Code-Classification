Here is the JavaScript code for the Koko Eating Bananas problem:

function minEatingSpeed(piles, H) {
    let left = 1;
    let right = piles.reduce((acc, cur) => acc + cur);

    while (left < right) {
        let mid = Math.floor((left + right) / 2);
        if (canFinish(piles, mid, H)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

function canFinish(piles, speed, H) {
    let hours = 0;
    for (let pile of piles) {
        hours += Math.ceil(pile / speed);
    }
    return hours <= H;
}

let N = parseInt(readline());
let H = parseInt(readline());
let piles = readline().split(' ').map(Number).filter(Boolean);

console.log(minEatingSpeed(piles, H));

In this code, `minEatingSpeed` is a function that calculates the minimum eating speed for Koko to finish all bananas within H hours. The `canFinish` function checks if it is possible to finish all bananas within a certain speed. If it is possible, it updates the right boundary; otherwise, it updates the left boundary. The binary search algorithm is used to find the minimum eating speed.