Sure, here's the JavaScript code to solve the problem:

function addParentheses(expression, start = 0, result = '') {
  if (start === expression.length - 1) {
    if (/^[0-9]+$/.test(result)) {
      console.log(parseInt(result));
    }
    return;
  }

  if (expression[start] === '+') {
    addParentheses(expression, start + 1, result + '+' + expression[start + 1]);
  } else if (expression[start] === '-') {
    addParentheses(expression, start + 1, result + '+' + '-' + expression[start + 1]);
  } else if (expression[start] === '*') {
    addParentheses(expression, start + 1, result + '*' + expression[start + 1]);
  } else {
    for (let next = start + 1; next <= expression.length; next++) {
      addParentheses(expression, next, result + '(' + expression.slice(start, next + 1) + ')' + expression[next]);
    }
  }
}

console.log(addParentheses('2*3-45'));
This code defines a recursive function addParentheses, which takes an arithmetic expression string and two optional parameters start and result. The start parameter is the starting index of the expression, and the result parameter is the accumulated result so far. If the start index is equal to the length of the expression, then we check if the result is a valid integer. If it is, we log the result. If it's not, we return immediately. If the expression starts with a plus sign or minus sign, we recurse with the start index incremented. If the expression starts with a multiplication sign, we recurse with the start index incremented and add the multiplication sign to the result. If the expression starts with neither sign, we recurse with the start index incremented and add the sign to the result.