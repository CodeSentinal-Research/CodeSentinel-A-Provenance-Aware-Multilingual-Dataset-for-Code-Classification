Here is a simple implementation using JavaScript.

class PriorityQueue {
  constructor() {
    this.collection = [];
  }

  insert(element) {
    if (this.isEmpty()) {
      this.collection.push(element);
    } else {
      let added = false;
      for (let i = 0; i < this.collection.length; i++) {
        if (element[1] > this.collection[i][1]) {
          this.collection.splice(i, 0, element);
          added = true;
          break;
        }
      }
      if (!added) {
        this.collection.push(element);
      }
    }
  }

  remove() {
    return this.collection.shift();
  }

  peek() {
    return this.collection[0];
  }

  isEmpty() {
    return (this.collection.length === 0) ? true : false;
  }
}

let pq = new PriorityQueue();

let operations = [
  [1, 3],
  [2, 1],
  [3, 2],
  [4, 1],
  [5, 1],
  [6, 2]
];

for (let i = 0; i < operations.length; i++) {
  pq.insert(operations[i]);
  console.log("Inserted: " + operations[i]);
  console.log("Peak: " + pq.peek());
}

while (!pq.isEmpty()) {
  console.log("Removed: " + pq.remove());
  console.log("Peak: " + pq.peek());
}

In this code, a priority queue is implemented. The insert operation adds an element to the correct position based on the priority value. The remove operation removes the highest priority element. The isEmpty function checks if the queue is empty. The peak operation returns the highest priority element without removing it.