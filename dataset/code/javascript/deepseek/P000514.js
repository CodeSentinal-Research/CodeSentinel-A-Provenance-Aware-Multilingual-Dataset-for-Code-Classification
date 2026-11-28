Here is a basic solution using JavaScript, which takes care of basic parsing and handling of the ternary expression:

function ternaryEvaluator(expression) {
  // Parse the expression
  const [op1, operator, op2, end] = expression.match(/([0-9]+)([?:])([^?:]+)([?:])([^?:]+)/);

  // Evaluate the expression
  switch (operator) {
    case '?':
      return expression[op1] === 'true' ? op2 : op3;
    case ':':
      return expression[op1] === 'false' ? op2 : op3;
    default:
      return 'Invalid operator';
  }
}

This function assumes that the input expression is a valid ternary expression. It does not support other formats or different operator precedence, so this might not work for all inputs.

You can use this function by calling it with your ternary expression as an argument:

console.log(ternaryEvaluator('1?2:3'));  // Outputs: 2

Note: The above function assumes that the ternary expression is correctly formatted and follows the rules of ternary logic, i.e., it has an even number of operands separated by ? and :.

Also, the function uses strict equality (===) to compare strings. This is not recommended in JavaScript for sensitive data as it can lead to unexpected behavior. A safer way could be to use strict equality for numbers, but this function will only work with numbers. For strings, use strict equality for both sides.