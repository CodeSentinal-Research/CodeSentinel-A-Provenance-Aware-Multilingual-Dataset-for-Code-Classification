import sys

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def sorted_list_to_bst(head):
    if not head:
        return None
    if not head.next:
        return TreeNode(head.val)
        
    slow = head
    fast = head
    prev = None
    while fast and fast.next:
        prev = slow
        slow = slow.next
        fast = fast.next.next
        
    prev.next = None
    root = TreeNode(slow.val)
    root.left = sorted_list_to_bst(head)
    root.right = sorted_list_to_bst(slow.next)
    return root

def level_order(root):
    if not root:
        return []
    from collections import deque
    q = deque([root])
    res = []
    while q:
        node = q.popleft()
        res.append(str(node.val))
        if node.left: q.append(node.left)
        if node.right: q.append(node.right)
    return " ".join(res)

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    vals = list(map(int, input_data[idx:idx+n]))
    
    # Create linked list
    head = None
    curr = None
    for v in vals:
        if not head:
            head = ListNode(v)
            curr = head
        else:
            curr.next = ListNode(v)
            curr = curr.next
            
    root = sorted_list_to_bst(head)
    print(level_order(root))

solve()

