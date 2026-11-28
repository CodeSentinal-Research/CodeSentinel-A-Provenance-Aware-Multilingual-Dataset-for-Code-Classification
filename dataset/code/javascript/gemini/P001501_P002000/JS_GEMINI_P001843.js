// Sorts the input array into ordered sequence.
function sortedListToBST(head) {
    if (!head) return null;
    if (!head.next) return { val: head.val, left: null, right: null };

    let prev = null, slow = head, fast = head;
    while (fast && fast.next) {
        prev = slow;
        slow = slow.next;
        fast = fast.next.next;
    }

    if (prev) prev.next = null;

    const root = { val: slow.val, left: null, right: null };
    root.left = sortedListToBST(prev ? head : null);
    root.right = sortedListToBST(slow.next);
    return root;
}

module.exports = { sortedListToBST };