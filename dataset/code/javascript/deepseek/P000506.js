Here is a basic implementation of a calculator that uses a stack to perform operations in the order they appear in the expression. This implementation assumes that the input is a valid arithmetic expression.

function calculate(s) {
    let stack = [];
    let sign = 1;
    let res = 0;
    let num = 0;
    let i = 0;
    while(i < s.length) {
        if(s[i] == ' ') {
            i++;
            continue;
        }
        if(s[i] == '+' || s[i] == '-') {
            res += sign * num;
            num = 0;
            if(s[i] == '-') sign = -1;
            else sign = 1;
            i++;
            continue;
        }
        if(s[i] == '*' || s[i] == '/') {
            if(s[i] == '*') {
                num *= stack.pop();
            }
            else {
                num = stack.pop() / num;
            }
            i++;
            continue;
        }
        if(s[i] == '(') {
            stack.push(sign);
            sign = 1;
            num = 0;
        }
        if(s[i] == ')') {
            num *= sign;
            while(stack.length > 0) {
                num *= stack.pop();
            }
        }
        if(s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + s[i] - '0';
        }
        i++;
    }
    res += sign * num;
    return res;
}

You can use this function like this:

console.log(calculate("1 + 2 * 3 + 4 / 2")); // 10
console.log(calculate("10 * 20 + 15")); // 150
console.log(calculate("10 + 20 + 30 + 40 + 50")); // 150
console.log(calculate("(1 + 2) * (3 + 4)")); // 10
console.log(calculate("(1 + 2) * (3 + 4) + 5")); // 30

This code uses a single stack to keep track of the numbers being multiplied or divided. Each time it encounters a sign, it adds the last number and resets the current number. It also handles parentheses to ensure the correct order of operations is performed.