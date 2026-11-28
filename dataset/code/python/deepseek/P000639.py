def countNodes(head):
    if head is None:
        return 0
    
    count = 0
    current = head
    while current is not None:
        count += 1
        current = current.next
        
    return count

def main():
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)

    print(countNodes(head))  

if __name__ == "__main__":
    main()