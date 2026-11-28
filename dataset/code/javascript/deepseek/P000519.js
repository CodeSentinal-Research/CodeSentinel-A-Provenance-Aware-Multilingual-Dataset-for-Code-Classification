Here is the JavaScript code for the given problem:

class Queue {
  constructor() {
    this.stack1 = [];
    this.stack2 = [];
  }

  enqueue(x) {
    this.stack1.push(x);
  }

  dequeue() {
    if (this.isEmpty()) {
      return;
    }
    if (this.stack2.length === 0) {
      while (this.stack1.length !== 0) {
        this.stack2.push(this.stack1.pop());
      }
    }
    return this.stack2.pop();
  }

  peek() {
    if (this.isEmpty()) {
      return;
    }
    if (this.stack2.length === 0) {
      while (this.stack1.length !== 0) {
        this.stack2.push(this.stack1.pop());
      }
    }
    return this.stack2.peek();
  }

  isEmpty() {
    return this.stack1.length === 0 && this.stack2.length === 0;
  }
}

function processQueue(q, operations) {
  let queue = new Queue();

  for (let i = 0; i < q; i++) {
    let operation = operations[i];

    if (operation[0] === "p") {
      queue.enqueue(operation[1]);
    } else if (operation[0] === "peek") {
      console.log(queue.peek());
    } else if (operation[0] === "empty") {
      console.log(queue.isEmpty());
    } else if (operation[0] === "pop") {
      console.log(queue.dequeue());
    }
  }
}

You can use the `processQueue` function to process the operations. The `processQueue` function takes two parameters: `q` (the number of operations), and the `operations` (an array of operation arrays). Each operation array must contain a string and an optional integer. The string will be either "p" (push), "peek", "empty", or "pop", and the integer will be the element to push or pop.

For example, if you call `processQueue(2, [["p", 1], ["p", 2], ["peek"], ["empty"], ["pop"]])`, it will process the operations and print the result of every pop, peek, and empty operation.