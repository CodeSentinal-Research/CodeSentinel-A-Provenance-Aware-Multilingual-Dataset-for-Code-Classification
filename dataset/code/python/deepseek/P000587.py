Here is a Python solution using a heap data structure to merge the k sorted linked lists. We use Python's built-in heapq module to create a min heap and add the head of each list into the heap. We then pop the smallest element from the heap and add its next node to the heap, and repeat the process until the heap is empty.

import heapq

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def mergeKLists(lists):
    heap = []
    for l in lists:
        if l:
            heapq.heappush(heap, l.val)
            l = l.next
    if not heap:
        return None
    head = ListNode(0)
    curr = head
    while heap:
        min_node = heapq.heappop(heap)
        curr.next = ListNode(min_node)
        curr = curr.next
    return head.next

def input_list():
    lists = []
    while True:
        k = int(input())
        if k is None:
            break
        else:
            l = ListNode(int(input()))
            curr = l
            for _ in range(k-1):
                curr.next = ListNode(int(input()))
                curr = curr.next
            lists.append(l)
    return lists

def main():
    lists = input_list()
    result = mergeKLists(lists)
    while result:
        print(result.val)
        result = result.next

if __name__ == "__main__":
    main()

This code first prompts the user to input the number of lists and then the values of the linked lists. It then merges the linked lists into a single sorted linked list and prints the values of the merged list.

Please note that this solution assumes that the linked lists are sorted and does not handle the case where the linked lists have no elements.