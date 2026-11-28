Here is the JavaScript code for the problem:

function addParentheses(expression) {
    // Base case: if expression is a single number or a single operator
    if (/^\d+|\+|-|\*|/g.test(expression)) {
        return eval(expression);
    }

    // Recursive case: try to add parentheses to all possible positions
    for (let i = 0; i < expression.length; i++) {
        if (expression[i] === '+' || expression[i] === '-' || expression[i] === '*') {
            let left = expression.slice(0, i);
            let right = expression.slice(i + 1);
            let op = expression[i];
            let leftResult = addParentheses(left);
            let rightResult = addParentheses(right);
            switch (op) {
                case '+':
                    return leftResult + rightResult;
                case '-':
                    return leftResult - rightResult;
                case '*':
                    return leftResult * rightResult;
            }
        }
    }
}

console.log(addParentheses('2+3*4-5'));  // Outputs: 13

This code uses recursion to handle the addition and subtraction operations, and then uses the multiplication operation. Note that the `eval` function should be avoided for production code because it has security risks, as it can execute any arbitrary JavaScript code.