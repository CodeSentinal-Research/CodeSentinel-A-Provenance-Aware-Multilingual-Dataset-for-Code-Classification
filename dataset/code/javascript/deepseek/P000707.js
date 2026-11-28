Here is the JavaScript code:

function generateParenthesis(n) {
    let pairs = [];
    function generate(left, right, str) {
        if (left > right) return;
        if (left == 0 && right == 0) {
            pairs.push(str);
            return;
        }
        if (left > 0) generate(left-1, right, str + '(');
        if (right > left) generate(left, right-1, str + ')');
    }
    generate(n, n, '');
    return pairs;
}

console.log(generateParenthesis(3));

In this code, we start by initializing an empty array `pairs` to store the valid combinations. Then we define a function `generate` which takes the remaining number of left and right parentheses and the current string representation of parentheses. If the left and right parentheses are equal to zero, we have a valid combination, so we push it into the `pairs` array. If the left parentheses is greater than zero, we recursively call `generate` with the updated parameters for the next left parenthesis. Similarly, if the right parentheses is greater than the left, we recursively call `generate` with the updated parameters for the next right parenthesis. This process continues until we exhaust all the remaining parentheses. Finally, we return the `pairs` array.

For example, if we call `generateParenthesis(3)`, it will print all valid combinations of 3 balanced parentheses.