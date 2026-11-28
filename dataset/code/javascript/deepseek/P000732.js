Here is the JavaScript code that solves the problem:

let solveMaze = (n, maze) => {
  let res = [];
  let path = '';
  let visited = Array(n).fill(0).map(() => Array(n).fill(0));

  const dfs = (x, y) => {
    if (x == n-1 && y == n-1) {
      res.push(path);
      return;
    }

    if (x < n-1) {
      visited[x+1][y] = 1;
      path += 'D';
      dfs(x+1, y);
      path = path.substring(0, path.length - 1);
      visited[x+1][y] = 0;
    }

    if (y < n-1) {
      visited[x][y+1] = 1;
      path += 'R';
      dfs(x, y+1);
      path = path.substring(0, path.length - 1);
      visited[x][y+1] = 0;
    }
  };

  visited[0][0] = 1;
  dfs(0, 0);
  return res;
};

// Test the function
let maze = [
  [1, 0, 1, 1],
  [1, 0, 0, 1],
  [1, 1, 0, 1],
  [1, 1, 1, 1]
];
console.log(solveMaze(4, maze));

In this code, we use depth-first search (DFS) to find all paths from the top-left corner to the bottom-right corner. The path is stored in `path` and if the current cell is the destination, the path is added to the result. The visited array is used to track which cells have been visited.

The DFS function is called recursively for both right and down moves, unless we reach the destination. For each move, we update the path and call the DFS function for the next cell. After a move, we reset the cell to unvisited.

Finally, we test the function with a 4x4 maze. The output of this test case will be all possible paths from the top-left corner to the bottom-right corner.