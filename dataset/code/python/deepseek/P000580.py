Here is a Python solution for the given problem:


class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        slow = fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        return slow

And here is the main function to handle input and run the solution:

def main():
    linked_list = [1, 2, 3, 4, 5]

    head = ListNode(linked_list[0])

    current = head
    for i in linked_list[1:]:
        current.next = ListNode(i)
        current = current.next

    solution = Solution()
    result = solution.middleNode(head)

    print(result.val)


if __name__ == "__main__":
    main()

This will print `3`, which is the middle value of the linked list `[1, 2, 3, 4, 5]`.