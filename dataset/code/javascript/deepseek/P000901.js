function checkDivisibilityBy11(N) {
  if (N % 11 === 0) {
    console.log(true);
  } else {
    console.log(false);
  }
}
This function takes a single parameter, N, which is the number you want to check. It first checks if N is divisible by 11 (i.e., if N mod 11 equals 0). If N is divisible by 11, it logs "true" to the console. Otherwise, it logs "false".