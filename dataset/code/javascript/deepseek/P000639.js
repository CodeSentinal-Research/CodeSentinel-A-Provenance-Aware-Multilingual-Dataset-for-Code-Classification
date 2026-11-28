Here is the JavaScript code for the given problem:

function countNodes(head) {
    let count = 0;
    let current = head;

    while(current) {
        count++;
        current = current.next;
    }

    return count;
}

This function uses a while loop to iterate through the linked list, incrementing a counter each time it encounters a node. Once it has iterated through all the nodes, it returns the count.

Please note that this function assumes that a Node object has a property `next` which is a reference to the next node in the list. If the linked list is not singly linked and instead has multiple linked lists, you would need to handle each linked list individually.