Sure, here is a Python solution using two queues. The stack uses the queue as a normal data structure, and when a new element is pushed, it is moved to the back of the queue. When popping, the front of the queue is moved to the back of the queue, and then the front of the queue is removed. The top of the queue is the front of the queue, and it can be accessed just by popping and pushing operations. The empty operation checks if the queue is empty.

from collections import deque

class Stack:
    def __init__(self):
        self.queue = deque()

    def push(self, x):
        self.queue.append(x)
        for _ in range(len(self.queue) - 1):
            self.queue.append(self.queue.popleft())

    def pop(self):
        return self.queue.popleft()

    def top(self):
        return self.queue[0]

    def empty(self):
        return not bool(self.queue)

def process_commands(q):
    stack = Stack()
    for command in q:
        if command[0] == 'p':
            stack.push(command[1])
        elif command[0] == 'r':
            print(stack.pop())
        elif command[0] == 't':
            print(stack.top())
        elif command[0] == 'e':
            print(stack.empty())

commands = [['p', 1], ['p', 2], ['r'], ['t'], ['e']]
process_commands(commands)

In the above code, the commands are processed in the order they are received. The `process_commands` function takes a list of commands as an input and processes each command in the list. The commands are processed using the `push`, `pop`, `top`, and `empty` operations of the stack. The result of each operation is printed.

Please replace `commands` list with your actual commands. This example uses the commands `['p', 1], ['p', 2], ['r'], ['t'], ['e']` as an example.