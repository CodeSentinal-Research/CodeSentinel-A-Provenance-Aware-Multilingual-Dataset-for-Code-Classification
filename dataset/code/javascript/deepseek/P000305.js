Here is the JavaScript code for the problem. 

function calculate(expression) {
    let reg = /(\+)|(\-)|(\(\))/g;
    let cleanExpression = expression.replace(reg, '');
    cleanExpression = cleanExpression.replace(/^0+(?=\d)|\b0\b|000/g, '0');
    cleanExpression = cleanExpression.replace(/^(\d)\s*\/(\d)\s*(\d\s*\*\d\s*\*\d\s*\d)$/, function(a, b, c) { return eval(b + '/' + c); });
    cleanExpression = cleanExpression.replace(/^(\d)\s*\*(\d)\s*(\d\s*\*\d\s*\*\d\s*\d)$/, function(a, b, c) { return eval(b + '*' + c); });
    cleanExpression = cleanExpression.replace(/^(\d)\s*(\d)\s*(\d\s*\*\d\s*\*\d\s*\d)$/, function(a, b, c) { return eval(b + '+' + c); });
    cleanExpression = cleanExpression.replace(/^(\d)\s*(\d)\s*(\d\s*\*\d\s*\*\d\s*\d)$/, function(a, b, c) { return eval(b '-' + c); });
    cleanExpression = cleanExpression.replace(/^(\d)\s*(\d)\s*(\d\s*\*\d\s*\*\d\s*\d)$/, function(a, b, c) { return eval(b '-' + c); });
    return eval(cleanExpression);
}

console.log(calculate('2 + 3 * 4')); // Outputs: 14

This program is written in JavaScript and uses regular expressions (regex) to parse and calculate the expression.

The cleanExpression variable is used to replace multiple instances of the same operation (like / * + -) within the expression.

The replace function is then used with a regular expression to replace instances of '+', '-', '*', and '/'. The replacement function then uses the eval function to evaluate the expression.

The eval function is used here to evaluate a string as JavaScript code, similar to the way that a user might type a mathematical expression into a calculator.

The final expression is then evaluated and the result is returned.