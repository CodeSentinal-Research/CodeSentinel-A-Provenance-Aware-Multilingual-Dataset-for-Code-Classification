Here is the JavaScript code for the problem.

class ListNode {
  constructor(x) {
    this.val = x;
    this.next = null;
  }
}

var hasCycle = function(head) {
  if (head === null || head.next === null) {
    return false;
  }

  let slow = head;
  let fast = head.next;

  while(slow !== fast) {
    if(fast === null || fast.next === null) {
      return false;
    }
    slow = slow.next;
    fast = fast.next.next;
  }

  return true;
};

In this code, we have two pointers, slow and fast. Slow pointer moves one step at a time, while fast pointer moves two steps at a time. If there is a cycle, fast pointer will eventually meet slow pointer because there is a loop in the list. If there is no cycle, fast pointer will reach the end of the list.