Here is the JavaScript code using the built-in `eval` function, which can evaluate a string as a JavaScript expression. This function can be used to parse and execute code. However, this could be unsafe if used with untrusted input as it opens up a security risk. In case of user input, we should use a safer alternative such as the `math.js` library.

function calculate(expression) {
    var result;
    try {
        result = eval(expression);
    } catch(e) {
        console.log('Invalid expression.', e);
        return;
    }
    return result;
}

Note: This code uses `eval` function which can potentially open up a security risk if used with untrusted inputs. This is because `eval` function can execute any JavaScript code, which could be a potential security risk if used with user-provided input.

To avoid this risk, you should use a library like `math.js`. Here is how you can do it:

const math = require('mathjs');

function calculate(expression) {
    try {
        return math.evaluate(expression);
    } catch(e) {
        console.log('Invalid expression.', e);
        return null;
    }
}

In this code, `math.js` is used to evaluate the expression. If an error occurs during the evaluation, it will be caught and logged.

These codes are using the standard `math.js` library to evaluate the arithmetic expressions. The `math.js` library will automatically parse and evaluate the expression, which is safer than using the `eval` function.