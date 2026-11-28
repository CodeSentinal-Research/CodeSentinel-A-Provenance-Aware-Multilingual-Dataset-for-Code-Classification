function isLinkedListSorted(head) {
    let current = head;

    while (current !== null && current.next !== null) {
        if (current.value > current.next.value) {
            return false;
        }
        current = current.next;
    }

    return true;
}
This function starts from the head of the linked list and keeps moving to the next node in the list. If the current node's value is greater than the next node's value, it returns false because the list is not sorted in non-decreasing order. If it reaches the end of the list without finding a node with a value greater than its next node, it returns true.