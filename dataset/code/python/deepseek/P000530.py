Here is the Python code for the given problem:

class CircularQueue:
    def __init__(self, capacity):
        self.queue = [None] * capacity
        self.head = self.tail = -1
        self.elements = 0
        self.capacity = capacity

    def enQueue(self, data):
        if self.elements == self.capacity:
            return "Queue is full"
        elif self.elements == 0:
            self.head = self.tail = 0
        else:
            self.tail = (self.tail + 1) % self.capacity
        self.queue[self.tail] = data
        self.elements += 1
        return "Success"

    def deQueue(self):
        if self.elements == 0:
            return "Queue is empty"
        elif self.elements == 1:
            self.head = self.tail = -1
        else:
            self.head = (self.head + 1) % self.capacity
        self.elements -= 1
        return "Success"

    def Front(self):
        if self.elements == 0:
            return "Queue is empty"
        return self.queue[self.head]

    def Rear(self):
        if self.elements == 0:
            return "Queue is empty"
        return self.queue[self.tail]

    def isEmpty(self):
        return self.elements == 0

    def isFull(self):
        return self.elements == self.capacity

def handle_operations(operations):
    n = int(operations[0])
    queue = CircularQueue(n)
    for operation in operations[2:]:
        if operation[0] == 'E':
            print(queue.enQueue(operation[1]))
        elif operation[0] == 'D':
            print(queue.deQueue())
        elif operation[0] == 'F':
            print(queue.Front())
        elif operation[0] == 'R':
            print(queue.Rear())
        elif operation[0] == 'I':
            print(queue.isEmpty())
        elif operation[0] == 'F':
            print(queue.isFull())

def main():
    while True:
        capacity = int(input())
        if capacity == -1:
            break
        n = int(input())
        operations = [input().split(' ') for _ in range(n)]
        handle_operations(operations)

if __name__ == '__main__':
    main()

This code first defines a class `CircularQueue` with methods to enqueue, dequeue, get the front, rear, and check if the queue is empty or full. It uses the modulo operator to handle the circular nature of the queue.

In the `main` function, it reads the capacity of the queue and the number of operations, then reads each operation and calls the appropriate method to perform the operation. The operations are read as a list of strings, where each string is a space-separated pair of operation and argument.

The `handle_operations` function processes a list of operations and calls the appropriate methods of the queue.

The program continues to run until it is manually terminated with `-1` as the capacity.