class Queue:
    def __init__(self):
        self.stack1 = []
        self.stack2 = []

    def enqueue(self, x):
        self.stack1.append(x)

    def dequeue(self):
        if not self.empty():
            if not self.stack2:
                while self.stack1:
                    self.stack2.append(self.stack1.pop())
            return self.stack2.pop()

    def peek(self):
        if not self.empty():
            if not self.stack2:
                while self.stack1:
                    self.stack2.append(self.stack1.pop())
            return self.stack2.peek()

    def empty(self):
        return not self.stack1 and not self.stack2


def main():
    q = int(input().strip())
    queue = Queue()
    for _ in range(q):
        operation = input().strip().split()
        if operation[0] == 'push':
            queue.enqueue(int(operation[1]))
        elif operation[0] == 'pop':
            print(queue.dequeue())
        elif operation[0] == 'peek':
            print(queue.peek())
        elif operation[0] == 'empty':
            print(int(queue.empty()))


if __name__ == "__main__":
    main()