Here is a Python solution that uses recursion to check if a linked list exists as a downward path in a binary tree.

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def sortedListToBST(head):
    if not head:
        return None

    slow, fast = head, head.next
    prev, mid = None, head
    while fast and fast.next:
        prev = slow
        slow = slow.next
        fast = fast.next.next

    if prev:
        prev.next = None

    root = TreeNode(slow.val)
    root.left = sortedListToBST(head)
    root.right = sortedListToBST(slow.next)
    return root

def isSubPath(head, root):
    if not root:
        return False

    if head.val == root.val and (isSubPath(head.next, root.right) or isSubPath(head.next, root.left)):
        return True

    return isSubPath(head, root.right) or isSubPath(head, root.left)

def main():
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)

    root = sortedListToBST(head)

    print(isSubPath(head, root))  

if __name__ == "__main__":
    main()
In this code, we first convert the linked list to a binary tree using the `sortedListToBST` function. This function uses a slow and fast pointer to find the middle of the linked list and then cuts off the linked list there. This is done by advancing the slow pointer and fast pointer one step at a time until fast.next is None.

Then, we use recursion to check if the current node is a subpath. If the current node's value is equal to the root's value, we check if the remaining linked list exists as a downward path in the right or left subtree of the root.

Finally, we test the function with a linked list [1, 2, 3, 4, 5] and a binary tree rooted at node with value 1. The output should be True, indicating that the linked list exists as a downward path in the binary tree.