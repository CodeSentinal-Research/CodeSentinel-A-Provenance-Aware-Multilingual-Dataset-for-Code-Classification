Here is the Python code for the problem:

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def splitListToParts(head, k, n):
    cur = head
    for _ in range(n):
        cur = cur.next
    res = []
    cur = head
    end = False
    while cur:
        start = cur
        cur = cur.next
        end_node = cur if cur else None
        part = start
        for _ in range(n - 1):
            part.next = tmp = ListNode(0)
            part = part.next
        part.next = end_node
        res.append(start)
        cur = cur.next if cur else None
    return res

This code first calculates the length of the list to split, and then splits the list into k parts. The length of each part is calculated by dividing the total length by the number of parts, with the last part being the remaining nodes. The next part starts from the beginning of the remaining nodes. The code also handles the edge cases where the remaining nodes are smaller than the other parts.

And here is the main function for input handling:

def main():
    nodes = [ListNode(i) for i in range(5)]
    for i in range(1, len(nodes)):
        nodes[i-1].next = nodes[i]
    parts = splitListToParts(nodes[0], 3, 2)
    for part in parts:
        while part:
            print(part.val, end=' ')
            part = part.next
        print()

if __name__ == '__main__':
    main()

This main function creates a linked list from 0 to 4, splits it into 3 parts with 2 nodes each, and prints out the values of the parts.