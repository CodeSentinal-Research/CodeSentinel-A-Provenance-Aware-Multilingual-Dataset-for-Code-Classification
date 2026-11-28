Here is a Python solution for the problem:

class Queue:
    def __init__(self, capacity):
        self.front = self.size = 0
        self.rear = capacity - 1
        self.queue = [None]*capacity
        self.capacity = capacity

    def isFull(self):
        return self.size == self.capacity

    def isEmpty(self):
        return self.size == 0

    def enqueue(self, item):
        if self.isFull():
            print("Full")
            return
        self.rear = (self.rear + 1) % self.capacity
        self.queue[self.rear] = item
        self.size += 1
        print("Enqueued", item)

    def dequeue(self):
        if self.isEmpty():
            print("Empty")
            return
        print("Dequeued", self.queue[self.front])
        self.front = (self.front + 1) % self.capacity
        self.size -= 1

    def front(self):
        if self.isEmpty():
            print("Empty")
            return
        print("Front", self.queue[self.front])

def main():
    capacity = int(input("Enter capacity: "))
    q = int(input("Enter number of operations: "))
    queue = Queue(capacity)
    operations = []
    for _ in range(q):
        operation = input().split()
        operations.append(operation)
    for operation in operations:
        if operation[0] == 'enqueue':
            queue.enqueue(int(operation[1]))
        elif operation[0] == 'dequeue':
            queue.dequeue()
        elif operation[0] == 'front':
            queue.front()

if __name__ == "__main__":
    main()

In this code, we first create a Queue class with methods for enqueue, dequeue, and front operations. The enqueue operation adds an element at the rear of the queue if the queue is not full, while dequeue and front operations remove and return the front element respectively, if the queue is not empty.

In the main function, we first get the capacity and number of operations from input. Then we create a Queue instance with the given capacity. We also get the operations from input and perform each operation based on the operation type.