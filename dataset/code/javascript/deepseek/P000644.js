Here is a JavaScript code to solve the problem:

function swapNodes(head, x, y) {
    if (x === y) return head;

    let prevX = null;
    let currX = head;

    while (currX !== null && currX.data !== x) {
        prevX = currX;
        currX = currX.next;
    }

    let nextY = null;
    let currY = head;

    while (currY !== null && currY.data !== y) {
        nextY = currY.next;
        currY = currY.next;
    }

    if (currX === null || currY === null) return head;

    if (prevX === null) {
        head = currY;
    } else {
        prevX.next = currY;
    }

    if (nextY === null) {
        head = currX;
    } else {
        nextY.next = currX;
    }

    let temp = currX.next;
    currX.next = currY.next;
    currY.next = temp;

    return head;
}

This function works by finding the nodes `x` and `y` in the linked list and swapping their `next` pointers. If either `x` or `y` is not in the list, it returns the original head of the list. 

The code assumes a linked list with nodes having a `data` and a `next` property. If the linked list is not a singly linked list, you may need to adjust the code accordingly.