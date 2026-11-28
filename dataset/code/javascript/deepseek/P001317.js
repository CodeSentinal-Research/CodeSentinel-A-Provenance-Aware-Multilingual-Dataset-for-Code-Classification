Here is the JavaScript code for the problem:

const N = 8;
let board = [];
let path = [];

// Function to find the Knight's tour
function solveKnightTour(row, col) {
    if (path.length === N * N) {
        console.log(path.join(", "));
        return true;
    }

    const moves = [
        [-2, -1],
        [-2, 1],
        [-1, -2],
        [-1, 2],
        [1, -2],
        [1, 2],
        [2, -1],
        [2, 1]
    ];

    moves.forEach(([rowMove, colMove]) => {
        const newRow = row + rowMove;
        const newCol = col + colMove;

        if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < N) {
            const cellId = newRow * N + newCol;

            if (!path[cellId]) {
                path[cellId] = true;
                board[newRow][newCol] = path.length;

                if (solveKnightTour(newRow, newCol)) {
                    return true;
                }

                path[cellId] = false;
                board[newRow][newCol] = -1;
            }
        }
    });

    return false;
}

// Main function to solve the problem
function solveProblem() {
    const startRow = parseInt(prompt("Enter the start row:"));
    const startCol = parseInt(prompt("Enter the start column:"));

    if (startRow < 0 || startRow >= N || startCol < 0 || startCol >= N) {
        console.log("Invalid start position");
        return;
    }

    board = Array.from({ length: N }, () => Array(N).fill(-1));
    board[startRow][startCol] = 0;
    path = Array.from({ length: N * N }, () => false);

    if (!solveKnightTour(startRow, startCol)) {
        console.log("IMPOSSIBLE");
    }
}

solveProblem();
This JavaScript code uses the A* search algorithm to find the Knight's Tour. It starts from the given position and explores all possible moves in a way that it follows the Knight's rules. If it finds a valid move, it makes that move and repeats the process for the new position.