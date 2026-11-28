def delete_alternate_nodes(head):
    if not head:
        return None
    if not head.next:
        return head

    prev = head
    curr = head.next

    while curr:
        prev.next = curr.next
        prev = curr
        curr = curr.next if curr.next else None

    return head

This is the Python code to solve the given problem. This code uses a two-pointer approach to traverse the linked list. The first pointer (prev) always points to the node before the current node (curr), and the second pointer (curr) points to the current node and the next node. If there is a next node, the current node is removed, and the next node is set as the new current node. If there is no next node (i.e., it is the last node in the list), the current node is removed.

Input: A head node of a singly linked list
Output: The head node of the modified linked list

You can input the head node of a linked list in Python like this:
head = ListNode(1)
head.next = ListNode(2)
head.next.next = ListNode(3)
head.next.next.next = ListNode(4)
head.next.next.next.next = ListNode(5)

head = delete_alternate_nodes(head)
This will create a linked list: 1 <-> 3 <-> 5.