Here is the JavaScript code for generating all combinations of well-formed parentheses:

function generateParentheses(n) {
    if (n === 0) {
        return ['']
    } else if (n === 1) {
        return ['()']
    }

    var res = [];
    for (var i = 0; i < n; i++) {
        for (var left in generateParentheses(i)) {
            for (var right in generateParentheses(n - i - 1)) {
                res.push('(' + left + ')' + right);
            }
        }
    }
    return res;
}

console.log(generateParentheses(3));

The code above uses recursion to generate the parentheses. It generates parentheses for the left part of the parenthesis and the right part, and concatenates the results with the left parenthesis in the middle.

The base cases are when n is 0 or 1, in these cases we simply return a string of '()'.

Then for n greater than 1, we generate all parentheses combinations for the left part and right part recursively and concatenate the results with '(' and ')' in the middle.

The recursion will generate all combinations of parentheses for the given number.

Note that the time complexity of this code is very high. It has a time complexity of O(4^n / n^(3/2)).