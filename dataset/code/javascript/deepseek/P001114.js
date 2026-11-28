Here is the JavaScript code for the Rotten Oranges problem:

const ROWS = 500;
const COLS = 500;

function readInput(rows, cols) {
  const input = [];
  for (let i = 0; i < rows; i++) {
    input[i] = readLine();
  }
  return input;
}

function readLine() {
  return process.stdin.readLine();
}

function processInput(input) {
  const rows = input[0].split(' ')[0];
  const cols = input[0].split(' ')[1];

  const grid = [];
  for (let i = 1; i <= rows; i++) {
    const row = input[i].split(' ').map(Number);
    grid.push(row);
  }

  console.log(grid, rows, cols);
}

process.stdin.resume();
process.stdin.on('data', (chunk) => {
  const input = chunk.toString().trim().split('\n');
  processInput(input);
});

This code reads the input from stdin and processes it. It expects the input to be a grid of numbers. The grid is then printed to stdout.