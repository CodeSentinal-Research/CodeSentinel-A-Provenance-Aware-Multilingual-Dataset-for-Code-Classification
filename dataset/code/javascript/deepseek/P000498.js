Here is the JavaScript code for the problem:

function calculate(s) {
    // Function to parse integer from string
    function getInt(s) {
        let sign = 1;
        if (s[0] == '-') {
            sign = -1;
            s = s.substring(1);
        }
        let res = 0;
        for (let i = 0; i < s.length; i++) {
            res = res * 10 + s[i] - '0';
        }
        return res * sign;
    }

    // Function to parse operator from string
    function getOperator(s) {
        if (s.length == 0) {
            return null;
        }
        if (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/') {
            return s[0];
        }
        return null;
    }

    // Function to parse parentheses from string
    function getParentheses(s) {
        let stack = [];
        let res = [];
        for (let i = 0; i < s.length; i++) {
            if (s[i] == '(') {
                stack.push(i);
            } else if (s[i] == ')') {
                let start = stack.pop();
                let sub = s.substring(start + 1, i);
                let val = calculate(sub);
                s = s.substring(0, start) + val + s.substring(i + 1);
                i = start;
            }
        }
        res.push(calculate(s));
        s = res.join('');
        return res;
    }

    // Main function
    let nums = [];
    let ops = [];
    for (let i = 0; i < s.length; i++) {
        if (s[i] == ' ') {
            continue;
        }
        let start = i;
        while (i + 1 < s.length && s[i + 1] != ' ') {
            i++;
        }
        nums.push(getInt(s.substring(start, i + 1)));
        if (getOperator(s.substring(i + 1)) != null) {
            ops.push(getOperator(s.substring(i + 1)));
        }
    }
    for (let i = 0; i < ops.length; i++) {
        if (ops[i] == '+') {
            nums[i] = nums[i] + nums[i + 1];
        } else if (ops[i] == '-') {
            nums[i] = nums[i] - nums[i + 1];
        } else if (ops[i] == '*') {
            nums[i] = nums[i] * nums[i + 1];
        } else if (ops[i] == '/') {
            nums[i] = Math.floor(nums[i] / nums[i + 1]);
        }
    }
    return nums[0];
}

This code first separates the input string into numbers and operators, then applies the operators to the numbers in a way that makes the result a valid arithmetic expression. The final result is then returned.

Please note that this code assumes that the input string is a valid arithmetic expression. If the input string can contain invalid characters, you should add error checking code to handle these cases.