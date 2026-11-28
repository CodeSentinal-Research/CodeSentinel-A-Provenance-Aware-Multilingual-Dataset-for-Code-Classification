Here is the JavaScript code to solve the problem:

class ListNode {
  constructor(val) {
    this.val = val;
    this.next = null;
  }
}

class LinkedList {
  constructor() {
    this.head = null;
  }

  add(val) {
    let node = new ListNode(val);
    if (!this.head) {
      this.head = node;
    } else {
      let current = this.head;
      while (current.next) {
        current = current.next;
      }
      current.next = node;
    }
  }

  findMiddleNode() {
    let slow = this.head;
    let fast = this.head;

    while(fast && fast.next) {
      slow = slow.next;
      fast = fast.next.next;
    }

    return slow.val;
  }
}

// Test the LinkedList and findMiddleNode function
let linkedList = new LinkedList();
linkedList.add(1);
linkedList.add(2);
linkedList.add(3);
linkedList.add(4);
linkedList.add(5);
console.log(linkedList.findMiddleNode()); // Outputs: 3
In this solution, we use two pointers (`slow` and `fast`). The `slow` pointer moves one step at a time while the `fast` pointer moves two steps at a time. When `fast` reaches the end of the list, the `slow` pointer will be at the middle of the list.