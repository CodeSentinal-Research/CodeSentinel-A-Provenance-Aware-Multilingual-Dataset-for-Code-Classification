// Definition for singly-linked list.
function ListNode(val) {
    this.val = val;
    this.next = null;
}

function findKthFromEnd(head, k) {
    let p1 = head;
    let p2 = head;
    
    // Setting p2 pointer to k nodes from head
    for(let i=0; i<k; i++) {
        if(p2 === null)
            return -1;
        p2 = p2.next;
    }
    
    // Moving both pointers until p2 reaches the end
    while(p2 !== null) {
        p2 = p2.next;
        p1 = p1.next;
    }
    
    // Returning kth node from end
    return p1.val;
}

This JavaScript function, findKthFromEnd, uses two pointers (p1 and p2) to traverse the linked list. It initializes p2 to point to the k-th node from the head. Then, it moves p2 forward until p2 is null. At this point, p1 is the k-th node from the end. If p2 is null (i.e., we've reached the end), we return -1. If not, we return p1's value.