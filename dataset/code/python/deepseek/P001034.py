import heapq
import sys

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def mergeKLists(lists):
    heap = []

    for i, lst in enumerate(lists):
        if lst:
            heapq.heappush(heap, (lst.val, i))
            lists[i] = lst.next

    head = point = ListNode()

    while heap:
        val, index = heapq.heappop(heap)

        point.next = ListNode(val)
        point = point.next

        if lists[index]:
            heapq.heappush(heap, (lists[index].val, index))
            lists[index] = lists[index].next

    return head.next

def main():
    k = int(sys.stdin.readline().strip())
    lists = [ListNode(int(x)) for _ in range(k)]
    for i in range(k-1, -1, -1):
        node = lists[i]
        for x in sys.stdin.readline().strip().split()[1:]:
            node.next = ListNode(int(x))
            node = node.next
    head = mergeKLists(lists)
    while head:
        print(head.val, end=' ')
        head = head.next
    print()

if __name__ == "__main__":
    main()
This code first reads the number of lists and then reads the list elements from stdin. The mergeKLists function then merges the lists together into a single sorted list. The main function then prints out the sorted list.