Here is a Python solution using a queue-based approach to solve the problem.

import queue

def generate_binary(n):
    q = queue.Queue()
    q.put(1)
    while not q.empty():
        num = q.get()
        print(bin(num)[2:])
        if num + 1 <= n:
            q.put(num + 1)

def main():
    n = int(input())
    generate_binary(n)

if __name__ == "__main__":
    main()

This program uses a queue data structure to store all the numbers from 1 to N. It then enters a loop where it retrieves a number from the queue and prints its binary representation. Then it enqueues the next number (num + 1) and continues until the queue is empty.