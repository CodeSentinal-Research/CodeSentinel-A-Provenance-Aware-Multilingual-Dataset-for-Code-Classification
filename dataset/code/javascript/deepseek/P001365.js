Here is a JavaScript solution using depth-first search (DFS) for the problem.

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter number of rows (R) and columns (C): ', (R) => {
  rl.question('Enter grid: ', (grid) => {
    const gridData = grid.split(' ').map(Number);
    const goldMines = [];
    for(let i = 0; i < R; i++) {
      goldMines.push([]);
      for(let j = 0; j < C; j++) {
        goldMines[i].push(gridData[i * C + j]);
      }
    }
    rl.question('Enter starting point (row, col): ', (start) => {
      const [startRow, startCol] = start.split(',').map(Number);
      const maxGold = dfs(goldMines, startRow, startCol, R, C);
      console.log(maxGold);
      rl.close();
    });
  });
});

function dfs(grid, startRow, startCol, R, C) {
  if(startRow < 0 || startRow >= R || startCol < 0 || startCol >= C || grid[startRow][startCol] === 0) {
    return 0;
  }

  const gold = grid[startRow][startCol];
  grid[startRow][startCol] = 0;

  const up = dfs(grid, startRow - 1, startCol, R, C);
  const down = dfs(grid, startRow + 1, startCol, R, C);
  const left = dfs(grid, startRow, startCol - 1, R, C);
  const right = dfs(grid, startRow, startCol + 1, R, C);

  return gold + Math.max(0, up, down, left, right);
}

This code first reads the grid and the starting point. Then it calculates the maximum gold that can be collected starting from the given point using a depth-first search. The search continues until all gold is collected or the search hits a cell that is blocked (0). For each cell, the function collects the gold, blocks it, and then tries to collect gold from the four neighboring cells. The maximum gold collected is returned as the final result.