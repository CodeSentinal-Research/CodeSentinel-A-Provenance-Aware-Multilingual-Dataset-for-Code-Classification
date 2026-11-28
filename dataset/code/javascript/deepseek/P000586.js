Here is a JavaScript solution:

function reverseKGroup(head, k) {
    let current = head;
    let newHead = null;
    let prevGroupEnd = null;

    while (current !== null) {
        let next;
        let endOfCurrentGroup;

        // Reverse current group and link to the next group
        next = current;
        endOfCurrentGroup = current;

        for (let i = 1; i < k; i++) {
            next = next.next;
            if (next === null) {
                // If we've reached the end of the list, break out of the loop
                break;
            }
        }

        endOfCurrentGroup.next = next;

        // If this was not the first group, link it to the previous group's end
        if (prevGroupEnd !== null) {
            prevGroupEnd.next = current;
        }

        // Move on to the next group
        prevGroupEnd = endOfCurrentGroup;
        current = next;
    }

    return newHead;
}

This function works by iterating over the linked list and reversing each group of `k` nodes. It maintains a reference to the previous group's end and updates it whenever a new group begins.