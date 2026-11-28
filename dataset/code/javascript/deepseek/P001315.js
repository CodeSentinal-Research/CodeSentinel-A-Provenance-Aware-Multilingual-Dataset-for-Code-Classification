Here is a JavaScript solution using Depth-First Search (DFS) algorithm:

let directions = [
    [0, 1],
    [1, 0],
    [0, -1],
    [-1, 0]
];
let visited = [];
let path = [];

function isValidMove(x, y, n) {
    return x >= 0 && x < n && y >= 0 && y < n && visited[x][y] === false;
}

function dfs(x, y, n) {
    if (x === n - 1 && y === n - 1) {
        console.log(path.join(', '));
        return;
    }

    visited[x][y] = true;
    for (let i = 0; i < 4; i++) {
        let newX = x + directions[i][0], newY = y + directions[i][1];
        if (isValidMove(newX, newY, n)) {
            path.push([x, y]);
            dfs(newX, newY, n);
            path.pop();
        }
    }
    visited[x][y] = false;
}

function solve(n) {
    visited = Array(n).fill(0).map(() => Array(n).fill(false));
    path = [[0, 0]];
    dfs(0, 0, n);
}

let n = parseInt(readline());
solve(n);

This code will print out all the possible paths from the top-left corner to the bottom-right corner through open cells in lexicographical order. It uses Depth-First Search to find all possible paths. It first initializes a 2D boolean array `visited` to keep track of visited cells. If a cell is visited, it is marked as true, otherwise it is marked as false. The `path` array is used to keep track of the path. The function `isValidMove` checks whether a cell can be moved to by considering the current cell and the direction. The function `dfs` performs the depth-first search.