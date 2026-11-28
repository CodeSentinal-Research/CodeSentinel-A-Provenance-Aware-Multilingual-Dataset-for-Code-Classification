Here's the JavaScript code to implement the online stock span problem:

class StockSpanner {
    constructor() {
        this.stack = [];
    }

    next(price) {
        let res = 1;
        while (this.stack.length && this.stack[this.stack.length - 1] <= price) {
            res += this.stack.pop();
        }
        this.stack.push(res);
        return res;
    }
}

Explanation:

This solution works by maintaining a stack. We start by pushing the default value 1 into the stack.

For each new price, we keep popping from the stack until we find a price greater than or equal to the current price. Then we add the count of popped prices to our result.

After popping all prices that are less than or equal to the current price, we push the result back to the stack. This ensures that we are not losing any prices in the stack.

In the end, the number at the top of the stack is our span for the current price.

For example, if we call next(10), it returns 1 because there is only one number less than or equal to 10 (10 is the only number less than or equal to 10). Then we call next(20), it returns 2 because there are two numbers less than or equal to 20 (20 and 10 are less than or equal to 20).

The time complexity is O(n), where n is the number of incoming prices.