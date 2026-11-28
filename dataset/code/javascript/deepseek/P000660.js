class ListNode {
    constructor(value) {
        this.value = value;
        this.next = null;
    }
}

function findMaxValue(head) {
    if (!head) {
        return -1;
    }

    let max = -Infinity;
    let current = head;

    while (current) {
        if (current.value > max) {
            max = current.value;
        }
        current = current.next;
    }

    return max;
}