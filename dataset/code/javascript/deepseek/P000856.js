Sure, here is the JavaScript code:

function countTrailingZeros(n) {
  let count = 0;
  while (n) {
    n >>= 1;
    count += n;
  }
  return count;
}

In this code, we use a while loop to count the number of trailing zeros in the binary representation of the input number. The `>>=` operator is a shorthand for `n = n >> 1`, which shifts all bits in `n` to the right by one bit. The loop continues until `n` becomes 0. The `count` variable keeps track of the total number of trailing zeros.