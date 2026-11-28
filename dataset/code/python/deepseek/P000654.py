class Node:
    def __init__(self, x):
        self.val = x
        self.next = None

def rearrange(head):
    if not head or not head.next:
        return head

    last_node = head
    while last_node.next:
        last_node = last_node.next

    curr_node = head
    while curr_node.val >= last_node.val:
        curr_node = curr_node.next

    next_node = curr_node.next
    curr_node.next = None
    last_node.next = rearrange(next_node)
    return curr_node

def main():
    input = [4, 1, 2, 3, 6]

    head = Node(input[0])
    curr_node = head
    for num in input[1:]:
        curr_node.next = Node(num)
        curr_node = curr_node.next

    rearranged_head = rearrange(head)

    while rearranged_head:
        print(rearranged_head.val, end=" ")
        rearranged_head = rearranged_head.next

if __name__ == "__main__":
    main()