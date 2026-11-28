Here is a Python solution using a priority queue (heapq). The main idea is to iterate over each list, add each node into the priority queue, and then pop out the smallest node in each iteration. After all lists are merged, the head of the final doubly linked list is returned.

import heapq

class ListNode:
    def __init__(self, val=0, next=None, prev=None):
        self.val = val
        self.next = next
        self.prev = prev

class Solution:
    def mergeKLists(self, lists):
        head = point = ListNode(0)
        q = PriorityQueue()
        for l in lists:
            if l:
                q.put((l.val, l))
        while not q.empty():
            val, l = q.get()
            point.next = ListNode(val)
            point.next.prev = point
            point = point.next
            l = l.next
            if l:
                q.put((l.val, l))
        return head.next

In the main function, you can handle the input for each list:

if __name__ == "__main__":
    s = Solution()

    lists = [ListNode(x) for x in [1, 3, 5, 7]]
    for i in range(len(lists) - 1):
        lists[i].next = lists[i + 1]
        lists[i + 1].prev = lists[i]

    head = s.mergeKLists(lists)

    while head:
        print(head.val, end=' ')
        head = head.next

Please note that the provided input is a list of integers. You may need to modify it to a list of ListNode objects if you want to use this code with doubly linked lists.

Also, the code assumes that the lists are sorted. If the lists are not sorted, you may need to sort them before merging. The sorted lists are not provided in the problem statement.