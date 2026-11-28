const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter N: ', (N) => {
    rl.question('Enter M: ', (M) => {
        if (M !== N * N) {
            rl.close();
            rl.write('IMPOSSIBLE\n');
        } else {
            let matrix = [];
            for (let i = 1; i <= N; i++) {
                matrix[i] = [];
                for (let j = 1; j <= N; j++) {
                    matrix[i][j] = j + (i - 1) * N;
                }
            }

            rl.write(JSON.stringify(matrix, null, 2) + '\n');
        }
        rl.close();
    });
});
This code uses the readline module to read input from the command line. The first line of input is the size of the matrix N, and the second line is the number of constraints M. The constraints are then read and the matrix is created if the total number of constraints is equal to the size of the matrix squared, otherwise it outputs IMPOSSIBLE.