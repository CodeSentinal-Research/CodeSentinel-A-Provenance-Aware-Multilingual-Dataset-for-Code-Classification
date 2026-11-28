Here's a Python solution using the Floyd's cycle-finding algorithm (also known as the tortoise and hare algorithm) for detecting cycles in the linked list and a hash set for removing duplicates.

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def removeZeroSumSublists(head):
    dummy = ListNode(0)
    dummy.next = head
    prefix = 0
    hashtable = {0: dummy}

    while head:
        prefix += head.val
        if prefix in hashtable:
            temp = hashtable[prefix]
            temp.next = head.next
            hashtable.pop(prefix, None)
        else:
            hashtable[prefix] = head
        head = head.next

    return dummy.next

def createLinkedList(arr):
    dummy = cur = ListNode(0)
    for num in arr:
        cur.next = ListNode(num)
        cur = cur.next
    return dummy.next

def main():
    head = createLinkedList([1, 2, -3, 3, 1])
    new_head = removeZeroSumSublists(head)

    while new_head:
        print(new_head.val, end=' ')
        new_head = new_head.next

if __name__ == "__main__":
    main()

In this code, we first define a ListNode class that represents a node in the linked list.

Then, in the `removeZeroSumSublists` function, we create a dummy node and initialize two variables: a prefix sum and a hash table.

The `while` loop iterates over the linked list, summing the values in each node, and checking if the sum has been encountered before. If the sum has been encountered, it means we've found a sequence of nodes whose values sum to zero, so we remove that sequence from the list. Otherwise, we add the sum to the hash table.

The `createLinkedList` function is used to create a linked list from an array of integers.

Finally, the `main` function tests the `removeZeroSumSublists` function with a sample linked list.