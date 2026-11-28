Here is a JavaScript function that prints the values of a linked list in reverse order.

function printLinkedListInReverse(head) {
    // Check if the list is empty
    if (head === null) {
        return;
    }

    // Recursively call the function for the next node in the list
    printLinkedListInReverse(head.next);

    // Print the current node's value
    console.log(head.value);
}

This function works by recursively calling itself on the next node in the list (head.next) until it reaches the end of the list. Then it prints the current node's value. This way, it prints the values of the nodes in reverse order.

Please note that this function assumes that you have a linked list represented as a node object with a value and a next property pointing to the next node in the list.