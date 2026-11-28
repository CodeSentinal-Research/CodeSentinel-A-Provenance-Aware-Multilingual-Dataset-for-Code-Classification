function moveNodeToFront(head) {
    if (!head.next) {
        return head;
    }

    let prev = head;
    let current = head.next;
    let end = head;

    while (current.next !== null) {
        prev = current;
        current = current.next;
        end.next = current.next;
        current.next = head;
        head = current;
    }

    return head;
}