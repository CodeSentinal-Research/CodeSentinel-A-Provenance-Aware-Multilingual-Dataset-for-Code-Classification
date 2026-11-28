Here is the JavaScript code for the mentioned problem:

class ListNode {
    constructor(val = 0, next = null) {
        this.val = val;
        this.next = next;
    }
}

function partition(head, x) {
    let lessThan = new ListNode(0);
    let moreOrEqualTo = new ListNode(0);
    let lessThanPtr = lessThan;
    let moreOrEqualToPtr = moreOrEqualTo;
    
    while(head !== null) {
        if(head.val < x) {
            lessThanPtr.next = head;
            lessThanPtr = lessThanPtr.next;
        } else {
            moreOrEqualToPtr.next = head;
            moreOrEqualToPtr = moreOrEqualToPtr.next;
        }
        head = head.next;
    }
    
    moreOrEqualToPtr.next = null;
    lessThanPtr.next = moreOrEqualTo.next;
    
    return lessThan.next;
}

This code first initializes two new lists, lessThan and moreOrEqualTo. Then it iterates over the original list, adding each node to the appropriate list. After the loop, we set the next of the last node in lessThan and the head of the list to be the result of the partitioned list. 

Please note that this solution assumes the input linked list is correctly constructed and it's not a circular linked list. Also, this solution doesn't handle cases where the input linked list is empty, i.e., the head is null.