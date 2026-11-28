class Stack {
  constructor() {
    this.queue = new Queue();
  }

  push(x) {
    this.queue.enqueue(x);

    for(let i = 0; i < this.queue.size() - 1; i++) {
      this.queue.enqueue(this.queue.dequeue());
    }
  }

  pop() {
    return this.queue.dequeue();
  }

  top() {
    for(let i = 0; i < this.queue.size() - 1; i++) {
      this.queue.enqueue(this.queue.dequeue());
    }
    let top = this.queue.peek();

    for(let i = 0; i < this.queue.size() - 1; i++) {
      this.queue.enqueue(this.queue.dequeue());
    }

    return top;
  }

  empty() {
    this.queue = new Queue();
  }

  isEmpty() {
    return this.queue.isEmpty();
  }
}

class Queue {
  constructor() {
    this.items = [];
  }

  enqueue(element) {
    this.items.push(element);
  }

  dequeue() {
    if(this.isEmpty()) {
      return "Underflow";
    }

    return this.items.shift();
  }

  peek() {
    if(this.isEmpty()) {
      return "No elements in Queue";
    }

    return this.items[0];
  }

  isEmpty() {
    return this.items.length == 0;
  }

  size() {
    return this.items.length;
  }
}

// Usage
let s = new Stack();

// Push operation
s.push(1);
s.push(2);
s.push(3);

// Print top
console.log(s.top()); // Should print 3

// Pop operation
console.log(s.pop()); // Should print 3
console.log(s.top()); // Should print 2

s.empty(); // Empty the stack

// Print empty
console.log(s.isEmpty()); // Should print true