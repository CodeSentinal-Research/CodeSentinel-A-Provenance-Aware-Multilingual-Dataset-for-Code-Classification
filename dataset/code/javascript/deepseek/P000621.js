Here is the JavaScript code to remove elements from the linked list that are greater than a given threshold:

function removeElements(head, n, threshold) {
    if(n === 0) return head;

    head.next = removeElements(head.next, n - 1, threshold);

    if(head.val > threshold) {
        return head.next;
    }
    else {
        return head;
    }
}

This function works by recursively calling itself on the next node of the current node. The recursion is done by decreasing the threshold value by 1 for each recursive call. 

When the recursion ends, the function checks if the current node's value is greater than the threshold. If it is, the function returns the next node (which is the new head of the list). If it's not, the function returns the current node (which is the new head of the list).