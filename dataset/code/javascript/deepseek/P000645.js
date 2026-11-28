function pairWiseReverse(head) {
    let current = head;
    let next = null;
    let prev = null;
    while (current !== null) {
        next = current.next;
        current.next = prev;
        current.prev = next;
        prev = current;
        current = next;
    }
    return prev;
}
This solution works by initializing three pointers: `prev`, `current`, and `next`. `prev` points to the last node in the reversed list (since reversing a list changes the links of each node), `current` points to the current node in the list, and `next` points to the next node.

The solution then enters a while loop that continues until `current` is null (i.e., we have processed all nodes). In each iteration of the loop, the code updates the `next` and `current` pointers as follows:

- `next` is set to the `next` of `current`
- `current`'s `next` is set to `prev`
- `current`'s `prev` is set to `next`
- `prev` is then moved to `current`
- `current` is then moved to `next`

After the loop ends, `prev` is the new head of the reversed list. The function then returns `prev`, which is the head of the reversed list.

This solution assumes that the input list is a doubly linked list with each node having two links: one for the next node and one for the previous node.