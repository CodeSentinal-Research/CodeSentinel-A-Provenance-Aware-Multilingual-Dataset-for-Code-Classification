Here's a JavaScript solution using a backtracking algorithm. This algorithm tries to place each word horizontally and vertically in the crossword grid. If a word can't be placed in the current cell, it tries the next cell. If all words can be placed, it returns the crossword grid.

function placeWord(grid, word, x, y) {
    for (let i = 0; i < word.length; i++) {
        if (grid[x][y + i] !== word[i]) {
            return false;
        }
    }
    return true;
}

function solveCrossword(grid, words) {
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[i].length; j++) {
            if (grid[i][j] === '*' && placeWord(grid, words[0], i, j)) {
                if (solvePuzzle(grid, words.slice(1))) {
                    return grid;
                }
            }
            if (grid[i][j] === '*' && placeWord(grid, words[1], i, j)) {
                if (solvePuzzle(grid, words.slice(2))) {
                    return grid;
                }
            }
        }
    }
    return false;
}

function solvePuzzle(grid, words) {
    if (words.length === 0) {
        return true;
    }
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[i].length; j++) {
            if (grid[i][j] === '*' && placeWord(grid, words[0], i, j)) {
                let nextGrid = [...grid];
                nextGrid[i][j] = ' ';
                if (solvePuzzle(nextGrid, words.slice(1))) {
                    return true;
                }
            }
            if (grid[i][j] === '*' && placeWord(grid, words[1], i, j)) {
                let nextGrid = [...grid];
                nextGrid[i][j] = ' ';
                if (solvePuzzle(nextGrid, words.slice(2))) {
                    return true;
                }
            }
        }
    }
    return false;
}

// Example usage:
let grid = [
    ['*', '*', '*', '*'],
    ['*', '*', '*', '*'],
    ['*', '*', '*', '*'],
    ['*', '*', '*', '*']
];

let words = ['cat', 'dog'];
console.log(solveCrossword(grid, words));

This code assumes the input grid is a character matrix (2D array) where '*' characters represent blocked cells and ' ' characters represent empty slots. The words array contains the words to be placed.

Please note that this code may not work correctly if the number of words is larger than the number of blocked cells. Also, this code may not work correctly if the grid is not a perfect crossword.