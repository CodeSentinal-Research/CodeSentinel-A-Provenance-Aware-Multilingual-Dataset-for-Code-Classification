Here is a JavaScript implementation of the Circular Queue:

class CircularQueue {
  constructor(capacity) {
    this.capacity = capacity;
    this.queue = Array(capacity).fill(-1);
    this.head = this.tail = 0;
  }

  enQueue(x) {
    if ((this.tail + 1) % this.capacity == this.head) {
      console.log("Queue is full");
      return;
    }
    this.queue[this.tail] = x;
    this.tail = (this.tail + 1) % this.capacity;
  }

  deQueue() {
    if (this.tail == this.head) {
      console.log("Queue is empty");
      return;
    }
    console.log("Deleted: " + this.queue[this.head]);
    this.head = (this.head + 1) % this.capacity;
  }

  Front() {
    if (this.tail == this.head) {
      console.log("Queue is empty");
      return;
    }
    console.log("Front: " + this.queue[this.head]);
  }

  Rear() {
    if (this.tail == this.head) {
      console.log("Queue is empty");
      return;
   
    }
    console.log("Rear: " + this.queue[this.tail - 1]);
  }

  isEmpty() {
    return this.tail == this.head;
  }

  isFull() {
    return (this.tail + 1) % this.capacity == this.head;
  }
}

let queue = new CircularQueue(5);

function processQueries(queries) {
  for (let query of queries) {
    switch (query[0]) {
      case 1:
        queue.enQueue(query[1]);
        break;
      case 2:
        queue.deQueue();
        break;
      case 3:
        queue.Front();
        break;
      case 4:
        queue.Rear();
        break;
      case 5:
        console.log(queue.isEmpty() ? "Yes" : "No");
        break;
      case 6:
        console.log(queue.isFull() ? "Yes" : "No");
        break;
    }
  }
}

processQueries([
  [1, 1],
  [2],
  [3],
  [4],
  [5],
  [6],
  [1, 2],
  [2],
  [3],
  [4],
  [5],
  [6]
]);

In this code, we first define a `CircularQueue` class with the given properties and methods. Then we define a `processQueries` function which takes an array of queries as input and processes each query accordingly. Each query is an array of two integers, where the first integer is the type of operation to be performed and the second integer is the data to be passed to the operation.

Please note that this code is a simple implementation and may need to be adjusted to fit your specific use case.