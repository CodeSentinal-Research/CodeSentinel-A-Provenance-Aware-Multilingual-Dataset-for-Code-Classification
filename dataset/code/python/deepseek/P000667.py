Here is a Python solution for your problem:

class Node:
    def __init__(self, value=None):
        self.value = value
        self.next = None
        self.prev = None

class CircularDeque:
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    def insertFront(self, value):
        node = Node(value)
        if self.size:
            node.next = self.head
            self.head.prev = node
            self.head = node
        else:
            self.head = node
            self.tail = node
            self.tail.next = self.head
        self.size += 1

    def insertLast(self, value):
        node = Node(value)
        if self.size:
            node.prev = self.tail
            self.tail.next = node
            self.tail = node
            self.tail.next = self.head
        else:
            self.head = node
            self.tail = node
            self.tail.next = self.head
        self.size += 1

    def deleteFront(self):
        if not self.isEmpty():
            self.head = self.head.next
            self.head.prev = self.tail
            self.tail.next = self.head
            self.size -= 1
        else:
            print("Deque is empty")

    def deleteLast(self):
        if not self.isEmpty():
            self.tail = self.tail.prev
            self.tail.next = self.head
            self.head.prev = self.tail
            self.size -= 1
        else:
            print("Deque is empty")

    def getFront(self):
        if not self.isEmpty():
            return self.head.value
        else:
            print("Deque is empty")

    def getRear(self):
        if not self.isEmpty():
            return self.tail.value
        else:
            print("Deque is empty")

    def isEmpty(self):
        return self.size == 0

    def size(self):
        return self.size

def main():
    cDeque = CircularDeque()
    operations = [('insertFront', 10), ('insertFront', 20), ('insertFront', 30), ('insertLast', 40), ('insertLast', 50), ('getFront',), ('getRear',), ('deleteFront',), ('deleteLast',), ('getFront',), ('getRear',), ('isEmpty',)]
    for operation in operations:
        if operation[0] == 'insertFront':
            cDeque.insertFront(operation[1])
        elif operation[0] == 'insertLast':
            cDeque.insertLast(operation[1])
        elif operation[0] == 'deleteFront':
            cDeque.deleteFront()
        elif operation[0] == 'deleteLast':
            cDeque.deleteLast()
        elif operation[0] == 'getFront':
            print(cDeque.getFront())
        elif operation[0] == 'getRear':
            print(cDeque.getRear())
        elif operation[0] == 'isEmpty':
            print(cDeque.isEmpty())
        elif operation[0] == 'size':
            print(cDeque.size())

if __name__ == '__main__':
    main()

In this code, we first define a Node class which will be used to create new nodes. Each node will have a value and a next and a previous pointer.

Then we define a CircularDeque class that will manage the doubly linked list. It will have methods to add and remove elements, get the front and rear elements, and check if the deque is empty or not.

In the main function, we create a CircularDeque object and define an array of operations. For each operation, we check the operation type and call the corresponding method on the CircularDeque object.

Please note that this code uses Python's in-built print function to print the result of each operation. Also, the size of the operations array is assumed to be less than or equal to 20.