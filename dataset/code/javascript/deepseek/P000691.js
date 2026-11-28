function gcd(a, b) {
  // Corner cases
  if (b == 0) return a;
  if (a == 0) return b;
  
  // recursive call
  return gcd(b % a, a);
}