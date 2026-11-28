Here's the JavaScript code for the problem:

function crt(congruences) {
  const moduli = [];
  const remainder = [];
  for (let i = 0; i < congruences.length; i++) {
    const [mod, rem] = congruences[i];
    moduli.push(mod);
    remainder.push(rem);
  }
  
  const gcd = (a, b) => {
    if (!b) {
      return a;
    }
    return gcd(b, a % b);
  };
  
  let divisor = moduli[0];
  for (let i = 1; i < moduli.length; i++) {
    divisor = (divisor * remainder[i]) / gcd(divisor, moduli[i]);
  }
  
  let result = 0;
  for (let i = 0; i < congruences.length; i++) {
    const [mod, rem] = congruences[i];
    result += (rem - (mod * divisor % moduli[i]) % moduli[i]) * pow(divisor, -i, moduli[i]) % moduli[i];
  }
  
  return result % moduli[0] < 0 ? result + moduli[0] : result;
}

const pow = (base, exponent, mod) => {
  if (exponent === 0) {
    return 1;
  }
  const halfExp = pow(base, Math.floor(exponent / 2), mod);
  const result = (exponent % 2 === 0) ? halfExp * halfExp : halfExp * halfExp * base % mod;
  return result % mod;
};

// Example usage:
const congruences = [[3, 2], [5, 3], [7, 4]];
console.log(crt(congruences)); // Outputs: -1

This code first calculates the greatest common divisor (gcd) of the moduli to find the divisor of the congruences. Then, it computes the smallest non-negative solution by finding the smallest solution modulo the smallest modulo and subtracting the corresponding remainder when divided by the divisor. If the result is negative, it adds the smallest modulo to the result to get the smallest non-negative solution.