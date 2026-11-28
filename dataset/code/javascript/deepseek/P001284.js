Here is a JavaScript solution for the problem:

let readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter the number of dominoes: ', (num) => {
    rl.question('Enter the top row: ', (topRow) => {
        rl.question('Enter the bottom row: ', (bottomRow) => {
            let top = topRow.split(' ').map(Number);
            let bottom = bottomRow.split(' ').map(Number);

            console.log(minDominoRotations(top, bottom, num));

            rl.close();
        });
    });
});

function minDominoRotations(top, bottom, n) {
    let result = -1;

    // First rotation
    let topRotations = rotations(top, bottom, n);
    if (topRotations != -1) return topRotations;
    // Second rotation
    return rotations(bottom, top, n);

    function rotations(a, b, n) {
        let rotations = 0;

        for (let i = 0; i < n; i++) {
            // Rotate top array
            if (a[i] != b[i]) {
                let idx = i;
                while (a[idx] != b[idx]) {
                    // If not possible to rotate, return -1
                    if (++idx == n) return -1;
                    rotations++;
                }
            }
        }

        return rotations;
    }
}

This code first reads the number of dominoes from the input, then reads the top and bottom halves of dominoes. It then calls the function `minDominoRotations` which returns the minimum number of rotations. If all elements in either row become identical, it returns the number of rotations. Otherwise, it tries the rotation in the first row and then in the second row. If it cannot find a solution, it returns -1.

Please note that this code assumes that the top and bottom halves of the dominoes have the same size and that the given inputs are valid.