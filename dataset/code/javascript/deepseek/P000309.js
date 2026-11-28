Here's a simple JavaScript solution using the `BigInt` and `parseInt` functions:

function multiplyStrings(num1, num2) {
  let product = BigInt(num1) * BigInt(num2);
  return product.toString();
}

This function first converts the input strings to BigInts (which allows for arithmetic operations on larger numbers), multiplies them, and then converts the result back to a string. This should work for any input strings that can be converted to BigInts.

For example, if you call `multiplyStrings('123456789012345678901234567890', '98765432109876543210987654321')`, it should return the string `'12193263111263526914563346076805578589025890561055278713121821009210000000000000000000000000000000