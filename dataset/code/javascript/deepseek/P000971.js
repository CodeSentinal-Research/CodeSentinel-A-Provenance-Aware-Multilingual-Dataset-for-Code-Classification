Here is the JavaScript code:

function linearRecurrence(A, B, F0, F1, N) {
  if(A === 0 && B === 0 && F0 !== F1) {
    throw new Error('Invalid input: A and B cannot both be 0 and F0 must be different from F1');
  }

  if(N < 0 || N > 10^6) {
    throw new Error('Invalid input: N must be between 0 and 10^6');
 
  }

  let Fn = F0;

  if(N > 0) {
    Fn = F0;
    F0 = F1;
    F1 = Fn * A + F1 * B;
  }

  if(N > 1) {
    Fn = F1;
    F1 = Fn * A + F1 * B;
  }

  if(N > 2) {
    Fn = F1;
    F1 = Fn * A + F1 * B;
  }

  return Fn;
}

This function will calculate the Nth value of the linear recurrence with the given constants A, B, and initial values F0 and F1. It first checks if the provided inputs are valid, then calculates the Nth value using the recurrence formula.