Here is the Python code:

import heapq

def solve():
    Q = int(input().strip())
    maxHeap = []

    for _ in range(Q):
        line = input().strip().split()

        if line[0] == 'I':
            heapq.heappush(maxHeap, int(line[1]))

        elif line[0] == 'R':
            if maxHeap:
                print(heapq.heappop(maxHeap))
            else:
                print('Underflow')

        elif line[0] == 'D':
            if maxHeap:
                maxHeap = [i for i in maxHeap if i != heapq.heappop(maxHeap)]
                heapq.heapify(maxHeap)
            else:
                print('Underflow')

solve()

This program reads a number of operations (Q) from the standard input. For each operation, it reads an operation type (I for insert, R for retrieve, D for delete) followed by a value. Depending on the operation type, the program either inserts a value into the heap, retrieves and prints the highest value in the heap, or deletes the highest value in the heap.