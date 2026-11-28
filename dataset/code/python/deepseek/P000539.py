Here is the Python code for the problem:

import collections

class FirstUnique:
    def __init__(self, arr):
        self.q = collections.deque(arr)
        self.f = collections.defaultdict(int)
        for x in arr:
            self.f[x] += 1

    def showFirstUnique(self):
        while self.q and self.f[self.q[0]] > 1:
            self.q.popleft()
        if not self.q:
            return -1
        return self.q[0]

    def add(self, x):
        self.f[x] += 1
        self.q.append(x)

def main():
    n, arr, q = int(input()), list(map(int, input().split())), int(input())
    fu = FirstUnique(arr)
    for _ in range(q):
        print(fu.showFirstUnique())
        if _ < q - 1:
            input()
    return

if __name__ == "__main__":
    main()

This program uses a double-ended queue (deque) to maintain the queue of integers and a dictionary (defaultdict) to count the frequency of each integer in the queue. The constructor of the class takes a list of integers as input, and initializes the queue and frequency dictionary. The showFirstUnique method returns the first unique integer in the queue. The add method adds an integer to the end of the queue and updates the frequency dictionary. The main function reads the number of integers in the queue, the list of integers, and the number of operations from the input.