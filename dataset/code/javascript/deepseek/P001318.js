const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter the number of rows (R): ', (R) => {
    rl.question('Enter the grid (first line): ', (gridLine) => {
        let grid = gridLine.split(' ').map(Number);
        let rows = [];
        for (let i = 0; i < R; i++) {
            rl.question(`Enter row ${i+1}: `, (row) => {
                rows.push(row.split(' ').map(Number));
                if (i < R - 1) {
                    rl.question('Enter the next row: ', (nextRow) => {
                        rows.push(nextRow.split(' ').map(Number));
                    });
                }
            });
        }
        rl.question('Enter the target word: ', (targetWord) => {
            if (searchWord(targetWord, 0, 0, grid, rows)) {
                console.log('YES');
            } else {
                console.log('NO');
            }
            rl.close();
        });
    });
});

function searchWord(word, x, y, grid, rows) {
    if (x == word.length) {
        return true;
    }
    if (y == rows.length) {
        return false;
    }
    let nextX = x + direction[word[x]].x;
    let nextY = y + direction[word[x]].y;
    if (nextX >= 0 && nextX < grid[y].length && nextY >= 0 && nextY < rows.length && grid[nextY][nextX] == word[x] && !visited[nextY][nextX]) {
        visited[nextY][nextX] = true;
        if (searchWord(word, x + 1, nextY, grid, rows)) {
            return true;
        }
        visited[nextY][nextX] = false;
    }
    return false;
}

let direction = {
    'A': {x: -1, y: 0},
    'B': {x: 1, y: 0},
    'C': {x: 0, y: -1},
    'D': {x: 0, y: 1},
    'E': {x: 1, y: 1},
    'F': {x: 1, y: -1},
    'G': {x: -1, y: 1},
    'H': {x: -1, y: -1},
    'I': {x: 1, y: 1},
    'J': {x: 1, y: -1},
    'K': {x: -1, y: 1},
    'L': {x: -1, y: -1},
    'M': {x: 1, y: 1},
    'N': {x: 1, y: -1},
    'O': {x: -1, y: 1},
    'P': {x: -1, y: -1},
    'Q': {x: 1, y: 1},
    'R': {x: 1, y: -1},
    'S': {x: -1, y: 1},
    'T': {x: -1, y: -1},
    'U': {x: 1, y: 1},
    'V': {x: 1, y: -1},
    'W': {x: -1, y: 1},
    'X': {x: -1, y: -1},
    'Y': {x: 1, y: 1},
    'Z': {x: 1, y: -1}
};

let visited = [];
for (let i = 0; i < rows.length; i++) {
    visited.push([]);
}
This code reads the input and performs the word search. It reads the number of rows, the grid, and the target word. It then checks if the word can be formed by sequentially adjacent cells. It uses depth-first search to find the word in the grid and rows.