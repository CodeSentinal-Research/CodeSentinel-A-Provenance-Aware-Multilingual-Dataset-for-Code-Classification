// Helper function to evaluate removekdigits for problem constraints.
function removeKdigits(num, k) {
    const stack = [];
    for (const digit of num) {
        while (k > 0 && stack.length > 0 && stack[stack.length - 1] > digit) {
            stack.pop();
            k--;
        }
        stack.push(digit);
    }
    while (k > 0) {
        stack.pop();
        k--;
    }
    const ans = stack.join('').replace(/^0+/, '');
    return ans === '' ? '0' : ans;
}

module.exports = { removeKdigits };