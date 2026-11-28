Sure, here is a Python solution using Linked List for the text editor problem:

class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None

class TextEditor:
    def __init__(self):
        self.head = None
        self.tail = None

    def addText(self, text):
        if self.head is None:
            self.head = Node(text)
            self.tail = self.head
        else:
            self.tail.next = Node(text)
            self.tail = self.tail.next

    def deleteText(self, k):
        if k < 0:
            return
        current = self.head
        while k and current:
            current = current.next
            k -= 1
        self.head = current

    def cursorLeft(self, k):
        if k < 0:
            return
        k = min(k, 10)
        current = self.head
        while k and current:
            current = current.next
            k -= 1
        return current.data if current else None

    def cursorRight(self, k):
        if k < 0:
            return
        k = min(k, 10)
        current = self.head
        while k and current.next:
            current = current.next
            k -= 1
        return current.data if current else None

def main():
    textEditor = TextEditor()
    q = int(input().strip())
    for i in range(q):
        operation = input().strip().split(' ')
        if operation[0] == 'addText':
            textEditor.addText(operation[1])
        elif operation[0] == 'deleteText':
            textEditor.deleteText(int(operation[1]))
        elif operation[0] == 'cursorLeft':
            print(textEditor.cursorLeft(int(operation[1])))
        elif operation[0] == 'cursorRight':
            print(textEditor.cursorRight(int(operation[1])))

if __name__ == "__main__":
    main()

This code defines a linked list data structure with operations for adding text, deleting text, and moving the cursor. It takes the number of operations as input, processes each operation, and then prints the results of each operation.