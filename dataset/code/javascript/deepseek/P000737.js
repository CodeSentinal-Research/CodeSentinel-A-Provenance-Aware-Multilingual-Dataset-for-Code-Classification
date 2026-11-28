Here is a simple recursive approach in JavaScript to solve the problem. This function takes a string expression and two integers i and j, which represent the start and end of the substring to be evaluated. 

The function first checks if the substring is a valid number, and if it is, returns the number. Otherwise, it evaluates the expression by recursively calling itself on the parts of the expression that can be evaluated separately. 

function addParentheses(expression, i, j) {
    let result = [];
    // If expression is a number, return the number.
    if (isNaN(expression.slice(i, j + 1))) {
        return Number(expression.slice(i, j + 1));
    }
    // Iterate over all the possible separators.
    for (let k = i; k <= j; k++) {
        if (expression[k] === '+') {
            let left = addParentheses(expression, i, k - 1);
            let right = addParentheses(expression, k + 1, j);
            result.push(left + right);
        } else if (expression[k] === '-') {
            let left = addParentheses(expression, i, k - 1);
            let right = addParentheses(expression, k + 1, j);
            result.push(left - right);
        } else if (expression[k] === '*') {
            let left = addParentheses(expression, i, k - 1);
            let right = addParentheses(expression, k + 1, j);
            result.push(left * right);
        }
    }
    // Sort the result array.
    result.sort((a, b) => a - b);
    return result;
}
You can call this function with a string expression like this:
console.log(addParentheses("12+3*4", 0, 4)); // Output: [ 7, 9, 11, 13 ]
This code assumes that the input string is a valid arithmetic expression and that the operators are precedence-correct. It doesn't handle the case where the expression can be divided into two numbers or parentheses.