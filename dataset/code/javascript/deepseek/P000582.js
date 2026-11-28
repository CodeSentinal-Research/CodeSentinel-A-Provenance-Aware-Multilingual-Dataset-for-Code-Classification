Here is the JavaScript solution for the given problem:

class ListNode {
  constructor(val = 0, next = null) {
    this.val = val;
    this.next = next;
  }
}

function removeDuplicates(head) {
  if (!head) return head;
  
  var currNode = head;
  
  while(currNode.next !== null) {
    if(currNode.val === currNode.next.val) {
      currNode.next = currNode.next.next;
    } else {
      currNode = currNode.next;
    }
  }
  
  return head;
}

This solution iterates over the linked list, and checks if the current node's value equals the next node's value. If they are equal, it skips over the next node. If they are not equal, it moves the current node to the next node. This way, all duplicates are removed and the linked list is returned.

Please note that this solution assumes that the given linked list is a sorted one, where each node contains a unique integer.