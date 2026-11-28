function deleteNodes(head) {
    if (!head) return head;

    let prev = head;
    let map = new Map();
    let unique = new Map();
    let duplicate = new Set();

    while (prev) {
        if (map.has(prev.val)) {
            duplicate.add(prev.val);
        } else {
            map.set(prev.val, 1);
            unique.set(prev.val, prev);
        }
        prev = prev.next;
    }

    let newHead = unique.get(duplicate.keys().next().value);
    let current = newHead;

    while (current && current.next) {
        if (duplicate.has(current.next.val)) {
            current.next = current.next.next;
        } else {
            current = current.next;
        }
    }

    if (duplicate.has(current.next.val)) {
        current.next = null;
    }

    return newHead;
}