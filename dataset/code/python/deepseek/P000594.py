Here is the Python code for rotating a linked list:

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def rotateRight(head, k):
    if not head:
        return None
    tail, head_tail = head, head
    for _ in range(k):
        tail = tail.next
    tail.next = head
    new_head = head_tail.next
    head_tail.next = None
    return new_head

def take_input():
    data = list(map(int, input("Enter linked list data: ").strip().split()))[1:]
    head = None
    last = None
    for num in data:
        if num is None:
            break
        node = ListNode(num)
        if last is None:
            last = node
            head = node
        else:
            last.next = node
            last = node
    k = int(input("Enter the rotation factor k: "))
    return head, k

def main():
    head, k = take_input()
    new_head = rotateRight(head, k)
    print("Rotated Linked List: ")
    while new_head:
        print(new_head.val, end=" -> " if new_head.next else "")
        new_head = new_head.next
    print("None")

if __name__ == "__main__":
    main()

This code defines a ListNode class for linked list nodes. It then defines a function rotateRight that rotates the list to the right by k steps. It uses the same method as in the question, but instead of changing the next pointer of the tail to None, it changes the next pointer of the head to None, effectively removing the last node.