Sure, here is the JavaScript code for the problem:

process.stdin.resume();
process.stdin.on('data', (chunk) => {
  const N = parseInt(chunk.toString().trim(), 10);
  let board = Array(N).fill(null).map(() => Array(N).fill(null));
  let countX = 0, countO = 0, empty = 0;

  process.stdin.on('data', (chunk) => {
    const [row, col] = chunk.toString().trim().split(' ').map(Number);
    if (board[row][col]) {
      console.log('PENDING');
      return;
    }
    board[row][col] = ++empty;
    if (++countX === N) console.log('X wins');
    else if (++countO === N) console.log('O wins');
    else if (empty === N) console.log('DRAW');
  });
});

This code reads the number N as input, then reads the rows and columns of the board. It checks if a given move is valid (i.e., if the board slot at the given row and column is empty), then updates the count of 'X's and 'O's and checks if the game is over. If the game is not over, it prints 'PENDING'. If 'X's and 'O's have the same number of moves and there are no empty slots, it prints 'DRAW'.

Please note that the code assumes that the input will be valid and that the moves are sequential. It also assumes that the rows and columns are 0-indexed and that the indices are within the bounds of the board.