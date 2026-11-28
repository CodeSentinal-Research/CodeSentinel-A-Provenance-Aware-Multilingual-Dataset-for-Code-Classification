Here is the JavaScript code to rearrange the linked list into zigzag order. We will use two pointers to achieve this. The first pointer will move one step at a time (from head to tail), while the second pointer will move two steps at a time (from tail to head).

function rearrangeLinkedList(head) {
    if (!head || !head.next) return head;
    
    let prev = null;
    let slow = head;
    let fast = head.next;
    let next;
    
    while (fast) {
        next = fast.next;
        fast.next = prev;
        prev = fast;
        fast = next;
   
        if (slow) {
            slow.next = prev;
            prev = slow;
            slow = next;
            if (fast) {
                fast.next = slow;
                fast = fast.next;
            }
        }
    }
    
    if (head.next) {
        head.next.next = head;
        head = head.next;
    }
    
    return head;
}

In this code, we first check if the head or head.next exist. If not, we return the head.

Next, we set three pointers (prev, slow, and fast). Slow moves one step at a time from head to tail while fast moves two steps at a time from tail to head.

Inside the while loop, we set the next of the fast node to prev and move prev and fast to the next of fast.

Then we swap prev and slow if the slow exists. After this, if the slow exists, we connect prev and slow.

Finally, if the head.next exists, we connect head.next and head. If the head is not null, we set head.next.next to head to maintain the circular structure.

This solution works in O(n) time and O(1) space.