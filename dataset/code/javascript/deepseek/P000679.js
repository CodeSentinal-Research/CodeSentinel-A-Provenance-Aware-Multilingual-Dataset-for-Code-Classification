function printNumbers(n) {
  if (n < 1 || n > 100000) {
    throw new Error('Invalid input. Please input a number between 1 and 100000.');
  }

  if (n > 0) {
    console.log(n);
    printNumbers(n - 1);
  }
}

printNumbers(10);