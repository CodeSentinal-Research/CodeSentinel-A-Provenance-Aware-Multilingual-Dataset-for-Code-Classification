Here is a JavaScript solution using recursive approach. This solution will check all possible combinations of parentheses for a given boolean expression to evaluate to true.

let count = 0;

function countParentheses(booleanExpression, open, close, index) {
    if (index == booleanExpression.length) {
        if (open == close) {
            count++;
        }
        return;
    }

    if (open < close) {
        countParentheses(booleanExpression, open, close + 1, index + 1);
    }

    if (open > close) {
        countParentheses(booleanExpression, open + 1, close, index + 1);
    }

    countParentheses(booleanExpression, open, close, index + 1);
}

function solve(booleanExpression) {
    count = 0;
    countParentheses(booleanExpression, 0, 0, 0);
    console.log(count);
}

let input = process.argv[2];
solve(input);

This script takes the boolean expression as a command line argument. You can run this script by calling `node script.js 'Expression'` where `'Expression'` is the boolean expression you want to evaluate.

This script works by recursively checking all possible combinations of parentheses, starting from an empty string. It uses three parameters:

- `open`: The number of open parentheses.
- `close`: The number of close parentheses.
- `index`: The current index in the string.

If the current index is equal to the length of the string, we know that we have a valid parenthesization, and we increment the count. If the number of open parentheses is greater than the close parentheses, we add a closing parenthesis. If the number of open parentheses is less than the close parentheses, we add an opening parenthesis.

This process is repeated until the end of the string is reached.