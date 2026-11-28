"""
=========================================================
QUEUE.PY
Part 1
Basic Queue Algorithms
=========================================================
"""

from collections import deque
import heapq


# -------------------------------------------------------
# Queue Class
# -------------------------------------------------------

class Queue:

    def __init__(self):
        self.queue = deque()

    # Enqueue
    def enqueue(self, value):
        self.queue.append(value)

    # Dequeue
    def dequeue(self):

        if self.is_empty():
            return None

        return self.queue.popleft()

    # Front
    def front(self):

        if self.is_empty():
            return None

        return self.queue[0]

    # Rear
    def rear(self):

        if self.is_empty():
            return None

        return self.queue[-1]

    # Size
    def size(self):
        return len(self.queue)

    # Empty
    def is_empty(self):
        return len(self.queue) == 0

    # Display
    def display(self):
        print(list(self.queue))


# -------------------------------------------------------
# Circular Queue
# -------------------------------------------------------

class CircularQueue:

    def __init__(self, capacity):

        self.capacity = capacity
        self.queue = [None] * capacity

        self.front = -1
        self.rear = -1

    def enqueue(self, value):

        if (self.rear + 1) % self.capacity == self.front:
            print("Queue Full")
            return

        if self.front == -1:
            self.front = 0

        self.rear = (self.rear + 1) % self.capacity

        self.queue[self.rear] = value

    def dequeue(self):

        if self.front == -1:
            return None

        value = self.queue[self.front]

        if self.front == self.rear:

            self.front = -1
            self.rear = -1

        else:

            self.front = (
                self.front + 1
            ) % self.capacity

        return value

    def display(self):

        if self.front == -1:
            print([])
            return

        i = self.front

        result = []

        while True:

            result.append(self.queue[i])

            if i == self.rear:
                break

            i = (i + 1) % self.capacity

        print(result)


# -------------------------------------------------------
# Priority Queue
# -------------------------------------------------------

class PriorityQueue:

    def __init__(self):

        self.heap = []

    def push(self, value):

        heapq.heappush(
            self.heap,
            value
        )

    def pop(self):

        if not self.heap:
            return None

        return heapq.heappop(
            self.heap
        )

    def top(self):

        if not self.heap:
            return None

        return self.heap[0]


# -------------------------------------------------------
# Reverse Queue
# -------------------------------------------------------

def reverse_queue(queue):

    stack = []

    while queue:

        stack.append(
            queue.popleft()
        )

    while stack:

        queue.append(
            stack.pop()
        )

    return queue


# -------------------------------------------------------
# Generate Binary Numbers
# -------------------------------------------------------

def generate_binary(n):

    answer = []

    queue = deque(["1"])

    for _ in range(n):

        current = queue.popleft()

        answer.append(current)

        queue.append(current + "0")
        queue.append(current + "1")

    return answer


# -------------------------------------------------------
# First Non-Repeating Character
# -------------------------------------------------------

def first_non_repeating(stream):

    freq = {}

    queue = deque()

    answer = []

    for ch in stream:

        freq[ch] = freq.get(ch, 0) + 1

        queue.append(ch)

        while queue and freq[queue[0]] > 1:
            queue.popleft()

        if queue:
            answer.append(queue[0])
        else:
            answer.append("#")

    return "".join(answer)


# -------------------------------------------------------
# Queue Using Two Stacks
# -------------------------------------------------------

class QueueUsingStacks:

    def __init__(self):

        self.s1 = []
        self.s2 = []

    def enqueue(self, value):

        self.s1.append(value)

    def dequeue(self):

        if not self.s2:

            while self.s1:
                self.s2.append(
                    self.s1.pop()
                )

        if not self.s2:
            return None

        return self.s2.pop()


# -------------------------------------------------------
# Example Usage
# -------------------------------------------------------

if __name__ == "__main__":

    q = Queue()

    q.enqueue(10)
    q.enqueue(20)
    q.enqueue(30)

    print("Queue")
    q.display()

    print("Front")
    print(q.front())

    print("Rear")
    print(q.rear())

    print("Dequeue")
    print(q.dequeue())

    q.display()

    print("\nCircular Queue")

    cq = CircularQueue(5)

    cq.enqueue(1)
    cq.enqueue(2)
    cq.enqueue(3)

    cq.display()

    print(cq.dequeue())

    cq.display()

    print("\nPriority Queue")

    pq = PriorityQueue()

    pq.push(20)
    pq.push(5)
    pq.push(15)
    pq.push(2)

    print(pq.top())

    print(pq.pop())

    print("\nReverse Queue")

    d = deque([1,2,3,4])

    print(reverse_queue(d))

    print("\nBinary Numbers")

    print(generate_binary(10))

    print("\nFirst Non-Repeating Character")

    print(first_non_repeating("aabc"))

    print("\nQueue Using Two Stacks")

    qs = QueueUsingStacks()

    qs.enqueue(10)
    qs.enqueue(20)
    qs.enqueue(30)

    print(qs.dequeue())
    print(qs.dequeue())