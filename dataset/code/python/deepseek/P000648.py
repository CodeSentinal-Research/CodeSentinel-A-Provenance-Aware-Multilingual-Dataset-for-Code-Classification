Here is a Python solution for your problem:

class Node:
    def __init__(self, content):
        self.content = content
        self.next = None

class TextEditor:
    def __init__(self):
        self.head = None
        self.tail = None
        self.current = None

    def append(self, text):
        node = Node(text)
        if self.head is None:
            self.head = node
            self.tail = node
            self.current = self.head
        else:
            self.tail.next = node
            self.tail = node
            self.current = node

    def undo(self):
        if self.head is not None:
            if self.head is self.current:
                self.head = self.head.next
            if self.head.next is not None:
                self.tail = self.tail.next
                self.current = self.current.next
                self.head.next = None
            else:
                self.tail = None
                self.head = None
                self.current = None

    def redo(self):
        if self.current.next is not None:
            self.head = self.current.next
            self.tail = self.current
            self.current = self.current.next

    def print_document(self):
        if self.head is not None:
            current = self.head
            while current:
                print(current.content)
                current = current.next

def main():
    editor = TextEditor()

    operations = int(input().strip())
    for _ in range(operations):
        operation, *params = input().strip().split()

        if operation == 'type':
            editor.append(' '.join(params))
        elif operation == 'undo':
            editor.undo()
        elif operation == 'redo':
            editor.redo()
        elif operation == 'print':
            editor.print_document()

if __name__ == '__main__':
    main()

This Python code first declares the Node class, which is used to create elements in the linked list. The TextEditor class is used to manage the linked list and execute the operations. The main function reads the number of operations, then for each operation, it reads the operation and parameters, and executes it.