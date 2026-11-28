Here is the JavaScript code to rotate an array to the left by K positions.

// Function to rotate array to left by k positions
function rotateLeft(arr, k) {
    let n = arr.length;
    k = k % n; // Handling K > N
    let d = n - k;
    let rotatedArr = [...arr.slice(d), ...arr.slice(0, d)];
    return rotatedArr;
}

// Function to read input from console
function readInput() {
    let inputArr = process.stdin.readline().toString().trim().split(' ');
    let N = parseInt(inputArr[0]);
    let K = parseInt(inputArr[1]);

    if (N < 1 || N > 1000 || K < 0 || K > N) {
        console.log('Invalid input');
        process.exit();
    }

    inputArr = process.stdin.readline().toString().trim().split(' ').map(Number);

    if (inputArr.length !== N) {
        console.log('Invalid input');
        process.exit();
    }

    return {
        N: N,
        K: K,
        arr: inputArr
    };
}

// Function to print the output
function printOutput(rotatedArr) {
    process.stdout.write(rotatedArr.join(' ') + '\n');
}

// Main program
let input = readInput();
let rotatedArr = rotateLeft(input.arr, input.K);
printOutput(rotatedArr);

This program reads N and K from the console, then reads N integers. Afterwards, it rotates the array to the left by K positions. Finally, it prints the rotated array.

The readInput function is responsible for reading the input from the console. It validates the input to make sure it is a valid N and K. The rotateLeft function is responsible for rotating the array to the left by K positions. The printOutput function is responsible for printing the output.