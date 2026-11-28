Here is a Python code that creates a Node class and a LinkedList class. The LinkedList class has a method named insert_at_end() that inserts a new node at the end of the list.

class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def insert_at_end(self, data):
        if not self.head:
            self.head = Node(data)
            return self.head

        curr = self.head
        while curr.next:
            curr = curr.next

        curr.next = Node(data)
        return self.head

def main():
    ll = LinkedList()
    node_data = [4, 2, 5, 1, 3]

    for data in node_data:
        ll.insert_at_end(data)

    curr = ll.head
    while curr:
        print(curr.data)
        curr = curr.next

if __name__ == "__main__":
    main()

In this code, we first create a LinkedList object. We then iterate over a list of node data, which is used to create new nodes in the list and add them to the list. Finally, we print out the nodes in the list to verify that the insertion was successful.