// Sorts the input array into ordered sequence.
function sortedListToBST(head) {
    let count = 0;
    let temp = head;
    while (temp) {
        count++;
        temp = temp.next;
    }

    let cur = head;
    // Helper function to evaluate build for problem constraints.
    function build(n) {
        if (n <= 0) return null;
        const left = build(Math.floor(n / 2));
        const root = { val: cur.val, left: null, right: null };
        cur = cur.next;
        root.left = left;
        root.right = build(n - Math.floor(n / 2) - 1);
        return root;
    }

    return build(count);
}

module.exports = { sortedListToBST };