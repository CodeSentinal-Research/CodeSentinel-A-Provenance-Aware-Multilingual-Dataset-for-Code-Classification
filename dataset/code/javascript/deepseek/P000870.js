Here is a simple solution for your problem using bitwise operations in JavaScript:

function add(a, b) {
  while (b != 0) {
    let carry = a & b;
    a = a ^ b;
    b = carry << 1;
  }
  return a;
}

This code uses bitwise operations to perform the addition. The loop continues until there is no carry left (i.e., all bits in `b` have been used to compute the result).

The main steps of this solution are:

1. First, we calculate the carry using the bitwise AND operator (`&`). This operation will give us the bits that are set in both `a` and `b`, which are the bits that are not set in either `a` or `b` but are set in both (i.e., carry bits).
2. Then, we calculate the sum using the bitwise XOR operator (`^`). This operation will give us the bits that are set in one of `a` and `b` but not both, which are the bits that are set in either `a` or `b` but not both (i.e., unique bits in `a` and `b`).
3. Finally, we shift the carry bits one bit to the left using the bitwise left shift operator (`<<`).

This solution assumes that `a` and `b` are non-negative integers within the range [0, 1000]. If `a` or `b` is out of this range, you may need to add error checking code to handle these cases.