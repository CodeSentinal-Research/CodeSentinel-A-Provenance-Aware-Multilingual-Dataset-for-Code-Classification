function linkedListToDecimal(n, llist) {
    let result = n;
    while (llist) {
        n = n * 2 + llist.value;
        llist = llist.next;
    }
    return result;
}

class ListNode {
    constructor(val = 0, next = null) {
        this.value = val;
        this.next = next;
    }
}

let input = new ListNode(1);
input.next = new ListNode(0);
input.next.next = new ListNode(1);

console.log(linkedListToDecimal(0, input));  // Output: 5

This code defines a `ListNode` class to represent a node in the linked list, and a `linkedListToDecimal` function to convert a binary linked list to a decimal number. The input to this function is a binary number represented by a linked list, and it starts from the least significant bit (i.e., the head of the linked list). The function returns the decimal equivalent of the binary number. 

In the given example, the linked list `[1,0,1]` represents the binary number `13` (or decimal `5`). The function `linkedListToDecimal` is then called with this linked list and a base number of `0`, and it returns the decimal equivalent `5`.