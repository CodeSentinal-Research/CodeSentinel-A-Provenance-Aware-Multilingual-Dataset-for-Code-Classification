Here is a JavaScript code that solves the problem:

const countMaxValue = (expression) => {
    if (!expression) return 0;
    if (isNaN(expression)) return countMaxValue(expression.substring(1));
    return Math.max(
        countMaxValue(expression.substring(1)) + (expression[0] == '+' ? 1 : 0),
        countMaxValue(expression.substring(1)) + (expression[0] == '-' ? 1 : 0),
        countMaxValue(expression.substring(2)) + (expression[0] == '*' ? 1 : 0)
    );
};

console.log(countMaxValue("1+2*3"));

This code uses a recursive approach to solve the problem. It traverses the expression from left to right, whenever it encounters an operator, it computes the results of the two operands and chooses the maximum one. If the expression is a number it just returns the number.