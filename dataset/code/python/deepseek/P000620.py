Sure, here is the Python code:

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def bin_to_decimal(head):
    num = 0
    while head:
        num = num * 2 + head.val
        head = head.next
    return num

def main():
    head = ListNode(1)
    head.next = ListNode(0)
    head.next.next = ListNode(1)

    result = bin_to_decimal(head)
    print(result)

if __name__ == "__main__":
    main()

In this code, we create a linked list class `ListNode` to represent each node of the linked list. Then in the `bin_to_decimal` function, we iterate through the linked list, and each time, we double the current number and add the value of the current node. This results in the binary representation of the linked list being converted to a decimal number. The final result is the decimal representation of the linked list.

In the `main` function, we create a linked list with the values `[1, 0, 1]`, and call the `bin_to_decimal` function with this list as the argument. The result is printed to the console.