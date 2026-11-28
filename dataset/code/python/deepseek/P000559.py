Here's the Python code to solve the problem:

from collections import deque

def reverse_queue(n, queue, k):
    dq = deque(queue[:k])
    
    dq.reverse()
    
    queue = queue[k:]
    
    queue.extend(dq)
    
    return queue

And here's the main function:

if __name__ == "__main__":
    n, queue, k = int(input()), input(), int(input())
    result = reverse_queue(n, queue, k)
    print(result)

This code reads the number of elements in the queue, the queue itself, and the number of elements to be reversed as input and prints the result.