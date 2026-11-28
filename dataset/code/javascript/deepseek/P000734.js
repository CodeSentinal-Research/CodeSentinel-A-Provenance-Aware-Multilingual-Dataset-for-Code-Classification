Sure, here is the JavaScript code for the Knight's Tour problem.

function findTour(N, row, col) {
  let tour = [{row, col}];
  let moves = [
    [row - 1, col + 2],
    [row - 1, col - 2],
    [row + 1, col + 2],
    [row + 1, col - 2],
    [row - 2, col + 1],
    [row - 2, col - 1],
    [row + 2, col + 1],
    [row + 2, col - 1],
  ];

  function dfs(index, tour) {
    if (index === moves.length) {
      return true;
    }

    let [newRow, newCol] = moves[index];
    let newTour = [...tour, {row: newRow, col: newCol}];

    if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < N) {
      if (newTour.length === 2 * N - 1) {
        return true;
      }

      if (dfs(index + 1, newTour)) {
        return true;
      }
    }

    return false;
  }

  for (let i = 0; i < moves.length; i++) {
    if (dfs(i, tour)) {
      return newTour;
    }
  }

  return -1;
}

In this code, we start from the starting position and explore all possible moves. The `dfs` function tries to find a tour by exploring all possible moves. If it finds a tour, it returns the tour. If it can't find a tour, it returns `-1`.

Please note that this solution assumes that the chessboard is 8x8. If you want to use a different size, you need to adjust the size in the `findTour` function.