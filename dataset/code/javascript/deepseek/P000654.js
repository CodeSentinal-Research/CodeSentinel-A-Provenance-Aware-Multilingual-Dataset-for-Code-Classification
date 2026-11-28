function rearrange(head) {
    if (!head || !head.next) {
        return head;
    }

    let less = new ListNode(0);
    let equal = new ListNode(0);
    let greater = new ListNode(0);

    let lessNode = less;
    let equalNode = equal;
    let greaterNode = greater;

    let lessNodeVal = head.val;
    let equalNodeVal = head.val;

    while (head) {
        if (head.val < lessNodeVal) {
            lessNode.next = head;
            lessNode = lessNode.next;
        } else if (head.val == equalNodeVal) {
            equalNode.next = head;
            equalNode = equalNode.next;
        } else {
            greaterNode.next = head;
            greaterNode = greaterNode.next;
        }
        head = head.next;
    }

    lessNode.next = equalNode.next;
    equalNode.next = greaterNode.next;
    greaterNode.next = null;

    lessNode.next = function(node) {
        return node || greater.next;
    };

    return less.next;
}
This JavaScript code uses three separate pointers (less, equal, greater) to partition the list. The less pointer points to the start of the less than nodes, the equal pointer to the start of the equal nodes, and the greater pointer to the start of the greater than nodes.

The main part of the function rearranges the linked list in place. For each node in the list, it checks if its value is less than the value of the less than node, if it's equal to, or if it's greater than the value of the greater than nodes. Depending on the cases, it assigns the node to the corresponding list and moves forward in the list.

After assigning all the nodes, it links the last node of less, equal, and greater nodes together. This ensures that the partitioned linked list is formed such that all nodes with values less than the last node's value appear before it, and all nodes with values greater than or equal to it appear after it.