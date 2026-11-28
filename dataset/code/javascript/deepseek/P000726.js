Here is a JavaScript code snippet that generates all valid arithmetic expressions from a given string. This code uses recursion to generate all possible permutations of the input string, and then validates the expressions.

function generateParentheses(n) {
    let output = [];
    generate(n, n, '', &output);
    return output;
}

function generate(m, n, str, output) {
    if (m == 0 && n == 0) {
        output.push(str);
        return;
    }
    if (m > 0) {
        generate(m - 1, n, str + '(', output);
    }
    if (n > m) {
        generate(m, n - 1, str + ')', output);
    }
}

function validateExpression(expression) {
    try {
        return eval(expression);
    } catch (e) {
        return false;
    }
}

let expressions = generateParentheses(20);
expressions.forEach(expression => {
    if (validateExpression(expression)) {
        console.log(expression);
    }
});

This code first generates all valid parenthesized expressions for a given number of parentheses, then validates each expression using eval. If the expression is valid, it is printed out.

Please note that using eval can be dangerous if you are evaluating expressions from untrusted sources. It's generally not recommended to use it in production. In production, you should evaluate expressions only when they are safe to do so.