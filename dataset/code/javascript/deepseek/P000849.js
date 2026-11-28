function checkEvenOrOdd(N) {
  // Check if N is negative or positive or zero.
  // Negative means even, positive means odd, zero means even.
  if (N < 0) {
    N = -N;
  }

  // Use bitwise AND operation with 1.
  // If the result is 0, N is even. Otherwise, N is odd.
  if ((N & 1) == 0) {
    console.log('Even');
  } else {
    console.log('Odd');
  }
}

// Test the function.
checkEvenOrOdd(-10);
checkEvenOrOdd(10);
checkEvenOrOdd(0);
checkEvenOrOdd(9);