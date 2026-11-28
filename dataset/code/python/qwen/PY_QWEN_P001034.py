import sys
import heapq

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    k = int(input_data[idx]); idx += 1
    
    heap = []
    heads = []
    for i in range(k):
        size = int(input_data[idx]); idx += 1
        vals = list(map(int, input_data[idx:idx+size]))
        idx += size
        if vals:
            head = ListNode(vals[0])
            curr = head
            for v in vals[1:]:
                curr.next = ListNode(v)
                curr = curr.next
            heads.append(head)
            heapq.heappush(heap, (vals[0], i, head))
            
    dummy = ListNode(0)
    curr = dummy
    while heap:
        val, list_idx, node = heapq.heappop(heap)
        curr.next = node
        curr = curr.next
        if node.next:
            heapq.heappush(heap, (node.next.val, list_idx, node.next))
            
    result = []
    node = dummy.next
    while node:
        result.append(node.val)
        node = node.next
        
    print(*result)

if __name__ == "__main__":
    solve()

