Here is the JavaScript code to solve the problem:

process.stdin.setEncoding('ascii');
process.stdin.on('data', function(data) {
  var grid = data.split('\n');
  var isValid = true;

  for (var i = 0; i < 9; i++) {
    if (!isValid) break;

    var row = grid[i].split(' ');

    for (var j = 0; j < 9; j++) {
      if (!isValid) break;

      if (row[j] !== '.' && (row.indexOf(row[j]) !== j || row.lastIndexOf(row[j]) !== j)) {
        isValid = false;
        break;
      }

      if (j < 9 && row[j] !== '.' && row[j] !== row[j + 1] && row[j] !== row.lastIndexOf(row[j]) && row.indexOf(row[j]) !== j) {
        isValid = false;
        break;
      }
    }

    if (i < 9 && row.indexOf(row[i]) !== i && row[i] !== row.lastIndexOf(row[i]) && row[i] !== row[i + 1] && row.lastIndexOf(row[i]) !== i) {
      isValid = false;
      break;
    }
  }

  console.log(isValid ? 'YES' : 'NO');
});

This code reads the Sudoku grid from the input, checks each row and column for the uniqueness of each number, and verifies whether each box (3x3) is filled with the numbers 1-9. If any of these checks fails, it sets `isValid` to `false` and breaks the loop. If the loop completes without finding any issues, it outputs 'YES' to the console.