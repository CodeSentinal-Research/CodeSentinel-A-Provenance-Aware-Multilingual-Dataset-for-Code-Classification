Here is a JavaScript solution for the given problem:

let N = parseInt(readline());

for(let i = 0; i < N; i++) {
  let row = readline().split(' ').map(Number);
  for(let j = 0; j < i+1; j++) {
    console.log(row[j]);
  }
}

This program reads the number of rows `N` from the first line of input. Then it reads `N` lines containing `N` numbers each. The numbers are split into an array and mapped to their respective numbers. The outer loop iterates over the rows, and the inner loop iterates over the elements of the current row. The numbers are printed to the console.

This code assumes that the input is a single line for the number of rows, followed by `N` lines for the matrix. Each line contains `N` numbers separated by spaces.