class MinStack {
    constructor() {
        this.stack = [];
        this.minStack = [];
    }

    push(x) {
        this.stack.push(x);
        if (this.minStack.length === 0 || x <= this.minStack[this.minStack.length - 1]) {
            this.minStack.push(x);
        }
    }

    pop() {
        if (this.stack.length === 0) {
            return;
        }

        if (this.stack.pop() === this.minStack[this.minStack.length - 1]) {
            this.minStack.pop();
        }
    }

    top() {
        return this.stack[this.stack.length - 1];
    }

    getMin() {
        return this.minStack[this.minStack.length - 1];
    }
}

function solve() {
    let stack = new MinStack();

    process.stdin.resume();
    process.stdin.on('data', (chunk) => {
        let data = chunk.toString().trim();
        if (data.length === 0) {
            return;
        }

        let [operation, x] = data.split(' ');

        if (operation === 'push') {
            stack.push(Number(x));
        } else if (operation === 'pop') {
            stack.pop();
        } else if (operation === 'top') {
            console.log(stack.top());
        } else if (operation === 'getMin') {
            console.log(stack.getMin());
        }
    });
}

solve();

In this code, we create a new class `MinStack` to define the operations required in the problem. It contains an empty stack `stack` and a separate min stack `minStack`.

The `push(x)` method pushes the element x onto the stack. If the min stack is empty or x is less than or equal to the top of the min stack, it also pushes x onto the min stack.

The `pop()` method pops the top element from the stack. If the popped element is the same as the top of the min stack, it also pops the top element from the min stack.

The `top()` method returns the top element of the stack.

The `getMin()` method returns the minimum element in the stack.

In the `solve()` function, we read the operations from the standard input. For each operation, we call the appropriate method on the `MinStack` instance and print the result.

To solve the problem, we run the `solve()` function and provide the input to the program. The program reads the operations from the standard input and processes them. It then prints the result of each top() and getMin() operation.