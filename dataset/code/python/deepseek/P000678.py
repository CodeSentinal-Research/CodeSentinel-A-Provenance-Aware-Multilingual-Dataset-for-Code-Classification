Sure, here is the Python code for the Josephus Problem using Circular Linked List:

class Node:
    def __init__(self, x):
        self.val = x
        self.next = None

class CircularLinkedList:
    def __init__(self):
        self.head = None

    def append(self, val):
        if not self.head:
            self.head = Node(val)
            self.head.next = self.head
        else:
            cur = self.head
            while cur.next != self.head:
                cur = cur.next
            cur.next = Node(val)
            cur.next.next = self.head

    def remove(self):
        if self.head and self.head.next != self.head:
            cur = self.head.next
            while cur.next != self.head:
                cur = cur.next
            cur.next = self.head
            self.head = self.head.next

def josephus(n, k):
    cll = CircularLinkedList()
    for i in range(1, n+1):
        cll.append(i)

    cur = cll.head
    while cll.head.next != cur:
        for _ in range(k-1):
            cur = cur.next
        print('Remaining person is:', cur.val)
        cll.remove()

if __name__ == "__main__":
    n = int(input('Enter the number of people: '))
    k = int(input('Enter the gap between eliminations: '))
    josephus(n, k)

This code first creates a circular linked list and appends the people from 1 to n. Then it enters a game loop where it removes each person k times until only one person remains. The label of the remaining person is printed at the end of each round.

Please note that this code assumes that the input values for n and k are valid and within the constraints.