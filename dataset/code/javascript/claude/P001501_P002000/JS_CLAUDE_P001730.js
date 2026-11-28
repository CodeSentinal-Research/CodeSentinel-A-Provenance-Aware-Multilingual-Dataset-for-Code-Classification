class ListNode {
    constructor(val) { this.val = val; this.next = null; }
}


function insertAtEnd(head, val) {
    const node = new ListNode(val);
    if (!head) return node;
    let curr = head;
    while (curr.next) curr = curr.next;
    curr.next = node;
    return head;
}

module.exports = { ListNode, insertAtEnd };
