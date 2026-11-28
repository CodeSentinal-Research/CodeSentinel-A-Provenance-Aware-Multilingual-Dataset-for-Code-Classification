Here is a Python code snippet that solves the problem:

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def swapNodes(head, x, y):
    if x == y:
        return head
    prevX = None
    currX = head
    while currX and currX.val != x:
        prevX = currX
        currX = currX.next
    prevY = None
    currY = head
    while currY and currY.val != y:
        prevY = currY
        currY = currY.next
    if prevX:
        prevX.next = currY
    else:
        head = currY
    if prevY:
        prevY.next = currX
    else:
        head = currX
    currX.next, currY.next = currY.next, currX.next
    return head
This code first locates the two nodes by traversing the list. It then swaps the nodes if they are not the same. The time complexity is O(n) and the space complexity is O(1), where n is the number of nodes in the list.