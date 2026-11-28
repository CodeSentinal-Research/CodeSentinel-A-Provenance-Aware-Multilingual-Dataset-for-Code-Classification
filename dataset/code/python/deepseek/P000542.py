Here is the Python code for the mentioned problem:

class Queue:
    def __init__(self):
        self.queue = []

    def pushFront(self, x):
        self.queue.insert(0, x)

    def pushMiddle(self, x):
        mid = len(self.queue) // 2
        self.queue = self.queue[:mid] + [x] + self.queue[mid:]

    def pushBack(self, x):
        self.queue.append(x)

    def popFront(self):
        if self.queue:
            return self.queue.pop(0)
        else:
            return -1

    def popMiddle(self):
        if self.queue:
            mid = len(self.queue) // 2
            popped = self.queue.pop(mid)
            return popped
        else:
            return -1

    def popBack(self):
        if self.queue:
            return self.queue.pop()
        else:
            return -1

def main():
    queue = Queue()
    q = int(input())
    for i in range(q):
        operation = input().split()
        if operation[0] == 'pushFront':
            queue.pushFront(int(operation[1]))
        elif operation[0] == 'pushMiddle':
            queue.pushMiddle(int(operation[1]))
        elif operation[0] == 'pushBack':
            queue.pushBack(int(operation[1]))
        elif operation[0] == 'popFront':
            print(queue.popFront())
        elif operation[0] == 'popMiddle':
            print(queue.popMiddle())
        elif operation[0] == 'popBack':
            print(queue.popBack())

if __name__ == "__main__":
    main()

This code creates a Queue data structure, and then reads in a sequence of operations and performs them on the queue. The operations are read in as a space-separated string, and then split by space to separate the operation and the argument. The pop operation returns -1 if the queue is empty, so it is important to check whether the queue is not empty before attempting to pop an element.