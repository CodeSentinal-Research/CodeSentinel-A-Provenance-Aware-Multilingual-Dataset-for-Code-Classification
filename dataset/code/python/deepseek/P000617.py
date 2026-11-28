Below is the Python solution for the problem:

import random

class Node:
    def __init__(self, level, element):
        self.level = level
        self.element = element
        self.next = [None] * level

class SkipList:
    def __init__(self):
        self.head = Node(0, None)

    def search(self, target):
        node = self.head
        for i in range(self.head.level-1, -1, -1):
            while node.next[i] and node.next[i].element < target:
                node = node.next[i]
        return node.next[0] is not None and node.next[0].element == target

    def add(self, num):
        node = self.head
        level = 0
        while random.randint(0, 1) and node.next[level] is not None:
            node = node.next[level]
            level += 1

        new_node = Node(level, num)
        new_node.next = node.next[level]
        node.next[level] = new_node

    def erase(self, num):
        node = self.head
        while node.next is not None:
            while node.next[0] and node.next[0].element < num:
                node = node.next[0]
            if node.next[0] is not None and node.next[0].element == num:
                node.next[0] = node.next[0].next[0]

def main():
    sl = SkipList()

    q = int(input())
    for i in range(q):
        op = input().split()
        if op[0] == 'add':
            sl.add(int(op[1]))
        elif op[0] == 'erase':
            sl.erase(int(op[1]))
        elif op[0] == 'search':
            print(sl.search(int(op[1])))

if __name__ == "__main__":
    main()

This python code creates a SkipList data structure. It has three methods: search(target), add(num), and erase(num). The search(target) method returns True if the target is found in the list, and False otherwise. The add(num) method adds a number to the list. The erase(num) method removes a number from the list. The main() function reads the number of operations, then reads the operations themselves and executes them accordingly.