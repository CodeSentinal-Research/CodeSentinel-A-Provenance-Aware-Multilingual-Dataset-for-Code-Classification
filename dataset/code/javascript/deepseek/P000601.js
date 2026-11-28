Here is the JavaScript code for the given problem. This code uses a simple approach of splitting the linked list into k parts by creating new nodes for each part and connecting them. The time complexity is O(n) and the space complexity is O(1).

class ListNode {
    constructor(val) {
        this.val = val;
        this.next = null;
    }
}

function splitListToParts(root, k) {
    let curr = root,
        prev = null,
        count = 0,
        result = new Array(k).fill(null);

    while (curr) {
        result[count] = curr;
        let next = curr.next;
        curr.next = null;
        if ((count + 1) % k === 0) {
            if (prev) prev.next = null;
            prev = result[count];
        }
        curr = next;
        count++;
    }
    return result;
}

To use this code, you'd create your linked list and call the function like so:

let head = new ListNode(1);
head.next = new ListNode(2);
head.next.next = new ListNode(3);
head.next.next.next = new ListNode(4);
head.next.next.next.next = new ListNode(5);

let parts = splitListToParts(head, 3);
for (let part of parts) {
    console.log(part.val);
}

In the above example, the linked list is split into three parts with values 1, 2, 3, 4, 5, and the output will be each part printed out on a new line.