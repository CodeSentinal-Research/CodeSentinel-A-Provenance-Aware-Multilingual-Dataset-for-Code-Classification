Here is the Python code:

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def mergeTwoLists(l1, l2):
    dummy = ListNode(0)
    current = dummy
    while l1 and l2:
        if l1.val < l2.val:
            current.next = l1
            l1 = l1.next
        else:
            current.next = l2
            l2 = l2.next
        current = current.next
    if l1 or l2:
        current.next = l1 if l1 else l2
    return dummy.next

def main():
    l1 = ListNode(1, ListNode(2, ListNode(4)))
    l2 = ListNode(1, ListNode(3, ListNode(4)))
    merged_list = mergeTwoLists(l1, l2)
    while merged_list:
        print(merged_list.val, end=' ')
        merged_list = merged_list.next

if __name__ == "__main__":
    main()

In this Python solution, we use a dummy node to start our merged linked list. Then, we use a while loop to compare the values of the two linked lists. If one linked list is shorter than the other, we add the remaining nodes to the end of the merged list. Finally, we return the new head of the merged list.

In the `main` function, we are testing our `mergeTwoLists` function by creating two sorted linked lists (l1 and l2), and printing the merged sorted linked list.