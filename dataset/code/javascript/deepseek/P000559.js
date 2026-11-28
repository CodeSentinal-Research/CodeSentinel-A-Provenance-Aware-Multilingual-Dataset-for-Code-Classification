Here is a JavaScript solution for the problem:

function reverseFirstKElements(N, queue, K) {
  // Create a stack to simulate the reversal process
  const stack = [];

  // Push the first K elements from the queue to the stack
  for (let i = 0; i < K; i++) {
    stack.push(queue.dequeue());
  }

  // Enqueue all elements from the stack back to the queue
  while (!stack.isEmpty()) {
    queue.enqueue(stack.pop());
  }

  // Dequeue the rest of the queue elements
  for (let i = 0; i < N - K; i++) {
    queue.enqueue(queue.dequeue());
  }

  return queue;
}

This function works by first pushing the first K elements of the queue into a stack. Then, it dequeues the stack and enqueues them back to the queue. This process is repeated K times to reverse the first K elements of the queue. The remaining elements in the queue are then enqueued back into the queue. The function finally returns the modified queue.

Please note that this solution assumes that you have a `Queue` data structure and methods to enqueue and dequeue elements. If you're using a different data structure or methods, you'll need to adapt the code accordingly.