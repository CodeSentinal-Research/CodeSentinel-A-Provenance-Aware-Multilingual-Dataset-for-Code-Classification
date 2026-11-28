Here is the Python code implementing the queue using a linked list.

class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None

class Queue:
    def __init__(self):
        self.front = self.rear = None

    def isEmpty(self):
        return self.front is None

    def enqueue(self, data):
        temp = Node(data)
        if self.rear is None:
            self.front = self.rear = temp
            return
        self.rear.next = temp
        self.rear = temp

    def dequeue(self):
        if self.isEmpty():
            return None
        temp = self.front
        self.front = self.front.next
        if self.front is None:
            self.rear = None
        return temp.data

    def front(self):
        if self.isEmpty():
            return None
        return self.front.data

    def size(self):
        if self.isEmpty():
            return 0
        count = 0
        temp = self.front
        while temp is not None:
            count += 1
            temp = temp.next
        return count

def main():
    q = int(input())
    q1 = Queue()
    for i in range(q):
        query = input().split(' ')
        operation = query[0]
        if operation == 'enqueue':
            q1.enqueue(int(query[1]))
        elif operation == 'dequeue':
            print(q1.dequeue())
        elif operation == 'front':
            print(q1.front())
        elif operation == 'size':
            print(q1.size())
        elif operation == 'isEmpty':
            if q1.isEmpty():
                print('true')
            else:
                print('false')

if __name__ == '__main__':
    main()

This code implements a queue using a singly linked list. The main function gets the number of operations from the input, processes them, and prints the result for each operation. The enqueue operation adds an element to the rear of the queue, dequeue operation removes an element from the front of the queue, front operation returns the front element of the queue, size operation returns the size of the queue, and isEmpty operation checks if the queue is empty.