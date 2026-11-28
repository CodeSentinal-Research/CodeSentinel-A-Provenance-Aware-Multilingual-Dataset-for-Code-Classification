const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let rowsCols = [];

rl.on('line', function(line) {
  rowsCols = line.split(' ');
  rowsCols[0] = parseInt(rowsCols[0]);
  rowsCols[1] = parseInt(rowsCols[1]);
  rowsCols.push(rl);
}).on('close', function() {
  let matrix = [];
  rowsCols[2] = parseInt(rowsCols[2]);
  for(let i = 0; i < rowsCols[0]; i++) {
    matrix[i] = rl.next().split(' ').map(Number);
    matrix[i].push(rl);
  }
  
  let target = parseInt(rl.next());
  
  matrix = matrix.map(row => row.sort((a, b) => a - b));
  
  for(let i = 0; i < matrix.length; i++) {
    for(let j = 0; j < matrix[i].length; j++) {
      if(matrix[i][j] === target) {
        console.log('Found');
        return;
      }
    }
  of (matrix[i].length - 1) {
      if(matrix[i][j] > target) {
        console.log('Not Found');
        return;
      }
    }
  }
});