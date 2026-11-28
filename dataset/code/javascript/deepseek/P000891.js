function nextPrime(N) {
  if (N < 2) {
    return 2;
  }

  function isPrime(num) {
    for (let i = 2, sqrt = Math.sqrt(num); i <= sqrt; i++) {
      if (num % i === 0) {
        return false;
      }
    }
    return num > 1;
  }

  for (N = N > 1 ? N : 2; !isPrime(N); N++) {}

  return N;
}