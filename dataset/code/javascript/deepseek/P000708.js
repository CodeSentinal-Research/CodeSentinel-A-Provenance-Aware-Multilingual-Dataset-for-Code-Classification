Here's the JavaScript code for the problem:

function towerOfHanoi(n) {
    if (n > 20 || n < 1) {
        console.log('Invalid input. Please enter a number between 1 and 20.');
        return;
    }

    let moves = '';
    let movesCount = 0;

    function moveDisks(n, source, target, auxiliary) {
        if (n > 0) {
            moveDisks(n - 1, source, auxiliary, target);
            moves += `Move disk ${n} from rod ${source} to rod ${target}.\n`;
            movesCount++;
            moveDisks(n - 1, auxiliary, target, source);
        }
    }

    moveDisks(n, 1, 3, 2);

    console.log(moves);
    console.log('Total number of moves: ' + movesCount);
}

// Test the function
towerOfHanoi(3);

This code defines a function `towerOfHanoi(n)` that solves the Tower of Hanoi problem for `n` disks. It then calls this function with `n = 3` for a 3-disk example. The function first checks if the input is valid, then it declares a recursive function `moveDisks(n, source, target, auxiliary)` to move the disks. The `moveDisks` function recursively moves the disks in a circle. It calls itself with smaller arguments to move the smaller disks on top of the larger ones.

After defining the function, it tests the function with `n = 3`.