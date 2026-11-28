Here is the JavaScript code that solves the problem:

function canPurchase(A, B, N) {
  // Check if N is a multiple of 2
  if (N % 2 !== 0) {
    console.log(false);
    return;
  }

  // Check if A and B can be subtracted together
  while (A > 0 && B > 0) {
    if (A >= B) {
      A -= B;
    } else {
      B -= A;
    }
  }

  // If A is now 0, then N is even, else N is odd
  if (A === 0) {
    console.log(N % 2 === 0);
  } else {
    console.log(false);
  }
}

canPurchase(5, 2, 10); // Should print true
canPurchase(4, 1, 10); // Should print false

In this code, the function `canPurchase` takes three arguments: `A`, `B`, and `N`. It first checks if `N` is a multiple of 2. If not, it prints `false` and exits the function.

Then, it enters a while loop that continues until `A` and `B` are both 0. In each iteration of the loop, it checks if `A` is greater than or equal to `B`. If it is, it subtracts `B` from `A`. If not, it subtracts `A` from `B`.

After the loop, it checks if `A` is 0. If it is, it checks if `N` is even. If it is, it prints `true`. Otherwise, it prints `false`.