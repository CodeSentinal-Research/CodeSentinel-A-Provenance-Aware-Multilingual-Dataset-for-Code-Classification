Here is a simple JavaScript solution for the problem.

class ListNode {
    constructor(val) {
        this.val = val;
        this.next = null;
    }
}

class TreeNode {
    constructor(val) {
        this.val = val;
        this.left = null;
        this.right = null;
    }
}

function sortedListToBST(head) {
    if (!head) {
        return null;
    }

    var fast = head, slow = head;

    //Find the middle node
    while (fast.next && fast.next.next) {
        fast = fast.next.next;
        slow = slow.next;
    }

    //Cut off the right half and connect it with the left half
    var temp = slow.next;
    slow.next = null;
    var node = new TreeNode(temp.val);

    node.left = sortedListToBST(head);
    node.right = sortedListToBST(temp.next);

    return node;
}

function linkedListToBST(head) {
    var arr = [];
    while (head) {
        arr.push(head.val);
        head = head.next;
    }
    arr.sort((a, b) => a - b);

    return sortedListToBST(new ListNode(arr.shift()));
}

//Test the function
var node1 = new ListNode(1);
var node2 = new ListNode(2);
var node3 = new ListNode(3);
var node4 = new ListNode(4);
var node5 = new ListNode(5);
node1.next = node2;
node2.next = node3;
node3.next = node4;
node4.next = node5;

console.log(JSON.stringify(linkedListToBST(node1), null, 2));

In this code, we first define two classes `ListNode` and `TreeNode` to represent linked list and binary tree node, respectively. 

Then, we define a function `sortedListToBST` to convert a sorted linked list to a height-balanced binary search tree. The function works by finding the middle of the linked list, and then dividing the list into two halves, and recursively constructing a binary search tree from the two halves.

Finally, we define a function `linkedListToBST` to convert a linked list to a binary search tree. It first converts the linked list to an array, sorts it, and then uses the sorted array to create a balanced binary search tree.

The test part of this code creates a linked list with 5 nodes, values from 1 to 5, then converts this list to a binary search tree and prints the result.