Here is the JavaScript code to solve the problem:

class ListNode {
  constructor(x) {
    this.val = x;
    this.next = null;
  }
}

function findCycleLength(head) {
  if (head === null || head.next === null) {
    return 0;
  }

  let slow = head;
  let fast = head;

  while(fast !== null && fast.next !== null) {
    slow = slow.next;
    fast = fast.next.next;

    if (slow === fast) {
      slow = head;
      let cycleLength = 0;

      while(slow !== fast) {
        slow = slow.next;
        cycleLength++;
      }

      return cycleLength;
    }
  }

  return 0;
}

This code uses two pointers, slow and fast, to traverse the list. The slow pointer moves one node at a time while the fast pointer moves two nodes at a time. If there is a cycle, the fast pointer will eventually catch up to the slow pointer. We then find the length of the cycle by counting the number of nodes.

Please note, the code assumes the input is a list of nodes. If the input is not a list of nodes, you will need to create a list from the input. For example, if the input is a number array or a string of numbers, you will need to convert them to nodes and pass them to the `findCycleLength` function.