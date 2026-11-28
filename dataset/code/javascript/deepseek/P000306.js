Here is a simple JavaScript solution using the concept of stack for this problem.

function calculate(s) {
    const stack = [];
    let sign = '+';
    let num = 0;
    s = s.replace(/\s+/g, '');
    for (let i = 0; i < s.length; i++) {
        if (s[i] === '(') {
            stack.push(sign);
            sign = '+';
        } else if (s[i] === ')') {
            if (sign === '+') {
                num += stack.reduce((a, b) => a + b, 0);
            } else if (sign === '-') {
                num -= stack.reduce((a, b) => a - b, 0);
            } else if (sign === '*') {
                num *= stack.reduce((a, b) => a * b, 1);
            } else if (sign === '/') {
                num /= stack.reduce((a, b) => a / b, 1);
            }
            stack = [num];
            sign = '+';
            num = 0;
        } else if (s[i] === '+' || s[i] === '-' || s[i] === '*' || s[i] === '/') {
            sign = s[i];
        } else {
            num = num * 10 + s[i] - '0';
        }
    }
    if (sign === '+') {
        num += stack.reduce((a, b) => a + b, 0);
    } else if (sign === '-') {
        num -= stack.reduce((a, b) => a - b, 0);
    } else if (sign === '*') {
        num *= stack.reduce((a, b) => a * b, 1);
    } else if (sign === '/') {
        num /= stack.reduce((a, b) => a / b, 1);
    }
    return num;
}

This code uses the concept of stack for handling the operator precedence in the expression. It keeps a running total of the numbers and handles the current sign based on the current character.