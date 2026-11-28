// Helper function to evaluate mctfromleafvalues for problem constraints.
function mctFromLeafValues(arr) {
    let res = 0;
    const stack = [Infinity];
    for (const x of arr) {
        while (stack[stack.length - 1] <= x) {
            const mid = stack.pop();
            res += mid * Math.min(stack[stack.length - 1], x);
        }
        stack.push(x);
    }
    while (stack.length > 2) {
        res += stack.pop() * stack[stack.length - 1];
    }
    return res;
}

module.exports = { mctFromLeafValues };