Here is a simple recursive solution for the problem using JavaScript:

function matrixChainMultiplication(dims, l, r) {
  if (l === r) {
    return 0;
  }

  let min = Infinity;

  for (let i = l; i < r; i++) {
    const temp = matrixChainMultiplication(dims, l, i)
      + matrixChainMultiplication(dims, i + 1, r)
      + dims[l] * dims[i] * dims[r];

    if (temp < min) {
      min = temp;
    }
  }

  return min;
}

// Input handling
const dims = [10, 20, 30, 40];
console.log(matrixChainMultiplication(dims, 0, dims.length - 1));

This solution iterates over all possible splits for the matrix chain, and for each split, it recursively calculates the minimum scalar multiplications and updates the minimum if the current minimum is less. The recursion ends when the length of the array `dims` is 2, because a matrix chain of 2 matrices is a multiple of the multiplication of those matrices.