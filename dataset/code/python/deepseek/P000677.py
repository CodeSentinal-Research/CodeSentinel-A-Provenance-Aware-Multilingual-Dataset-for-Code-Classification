Here is a Python solution for the problem using Python's inbuilt dictionary and linked list. The solution includes classes for the dictionary, linked list and operations on them.

class Node:
    def __init__(self, key, value, prev=None, next=None):
        self.key = key
        self.value = value
        self.prev = prev
        self.next = next

class OrderedDictionary:
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    def put(self, key, value):
        if self.head is None:
            self.head = self.tail = Node(key, value)
        elif key < self.head.key:
            new_node = Node(key, value, prev=self.head)
            self.head.next = new_node
            self.head = new_node
        else:
            curr = self.head
            while curr.next and curr.next.key < key:
                curr = curr.next
            new_node = Node(key, value, curr, curr.next)
            curr.next.prev = new_node
            curr.next = new_node
            if curr == self.tail:
                self.tail = new_node

    def get(self, key):
        curr = self.head
        while curr:
            if curr.key == key:
                return curr.value
            curr = curr.next
        return None

    def remove(self, key):
        curr = self.head
        while curr:
            if curr.key == key:
                if curr.prev:
                    curr.prev.next = curr.next
                else:
                    self.head = curr.next
                if curr.next:
                    curr.next.prev = curr.prev
                else:
                    self.tail = curr.prev
                return True
            curr = curr.next
        return False

    def first_key(self):
        return self.head.key if self.head else None

    def last_key(self):
        return self.tail.key if self.tail else None

    def next_key(self, key):
        curr = self.head
        while curr:
            if curr.key == key:
                return curr.next.key if curr.next else None
            curr = curr.next
        return None

    def previous_key(self, key):
        curr = self.head
        while curr:
            if curr.key == key:
                return curr.prev.key if curr.prev else None
            curr = curr.next
        return None

def main():
    n = int(input().strip())
    od = OrderedDictionary()
    for _ in range(n):
        op = input().strip().split()
        if op[0] == 'put':
            od.put(op[1], op[2])
        elif op[0] == 'get':
            print(od.get(op[1]))
        elif op[0] == 'remove':
            print(od.remove(op[1]))
        elif op[0] == 'first':
            print(od.first_key())
        elif op[0] == 'last':
            print(od.last_key())
        elif op[0] == 'next':
            print(od.next_key(op[1]))
        elif op[0] == 'previous':
            print(od.previous_key(op[1]))

if __name__ == "__main__":
    main()

In this code, the `OrderedDictionary` class uses a doubly linked list to maintain the keys in sorted order. The `Node` class represents an element in the linked list. The `OrderedDictionary` class has methods for inserting a key-value pair, retrieving a value, removing a key, and getting the first, last, next, and previous keys in the dictionary. The `main` function reads the number of operations and performs them on the `OrderedDictionary`.