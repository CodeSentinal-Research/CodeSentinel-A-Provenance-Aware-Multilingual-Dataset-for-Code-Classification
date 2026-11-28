Here is a JavaScript solution:

function isIdentityMatrix(N, A) {
  for (let i = 0; i < N; i++) {
    for (let j = 0; j < N; j++) {
      if (i === j && A[i][j] !== 1) {
        return false;
      } else if (i !== j && A[i][j] !== 0) {
        return false;
      }
    }
  }
  return true;
}

In this code, we iterate over each element in the matrix and check if it's a 1 at the position (i, j) or a 0 if the element is not the diagonal element. If we find a non-diagonal element or a non-1 element, we return false as the matrix is not identity. If we iterate through all elements without finding any non-diagonal elements or non-1 elements, we return true as the matrix is identity.