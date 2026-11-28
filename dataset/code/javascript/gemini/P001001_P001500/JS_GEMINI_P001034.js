// Helper function to evaluate mergeklists for problem constraints.
function mergeKLists(lists) {
    const vals = [];
    for (let head of lists) {
        while (head) {
            vals.push(head.val);
            head = head.next;
        }
    }
    vals.sort((a, b) => a - b);
    const dummy = { val: 0, next: null };
    let curr = dummy;
    for (const v of vals) {
        curr.next = { val: v, next: null };
        curr = curr.next;
    }
    return dummy.next;
}

module.exports = { mergeKLists };