function countCollisions(movements) {
    let collisions = 0;
    let currentDirection = movements[0];
    for (let i = 1; i < movements.length; i++) {
        if (currentDirection === movements[i]) {
            if (currentDirection === 'S') {
                collisions++;
            }
            currentDirection = 'S';
        } else {
            currentDirection = movements[i];
        }
    }
    return collisions;
}

console.log(countCollisions('RRSSLLRLRR')); // 2
console.log(countCollisions('RLRLLRRLLL')); // 3