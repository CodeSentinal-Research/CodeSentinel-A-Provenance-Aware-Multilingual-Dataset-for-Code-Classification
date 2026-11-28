Here is a simple JavaScript solution for the problem:

function Solution(head) {
    // Initialize current, next, prev and head
    let current = head;
    let prev = null;
    let next = null;
    
    // Traverse the doubly linked list
    while (current !== null) {
        // Save the next node
        next = current.next;
        
        // Reverse the 'next' and 'prev' pointer of current node
        current.next = prev;
        current.prev = next;
        
        // Move to the next node
        prev = current;
        current = next;
    }
    
    // Return the new head of the reversed linked list
    return prev;
}
This solution traverses the doubly linked list, and for each node, it updates the 'next' and 'prev' pointers to reverse the list. It also handles the case when there is no node (i.e., when the input head is null) by returning null.

For testing this solution, you can pass a doubly linked list to it and it will return the reversed list:

let node1 = {val: 1, prev: null, next: null};
let node2 = {val: 2, prev: node1, next: null};
let node3 = {val: 3, prev: node2, next: null};
node1.next = node2;
node2.prev = node1;
node2.next = node3;
node3.prev = node2;

let head = node1;
let result = Solution(head);
console.log(result); // prints reversed linked list