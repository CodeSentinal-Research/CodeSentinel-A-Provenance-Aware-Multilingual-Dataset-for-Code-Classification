Sure, here is the JavaScript code that can solve the problem:

function swapPairs(head) {
  if (head === null || head.next === null) {
    return head;
  }

  let current = head;

  while (current !== null && current.next !== null) {
    let temp = current.val;
    current.val = current.next.val;
    current.next.val = temp;

    current = current.next.next;
  }

  return head;
}
This code will swap the first two nodes in the linked list and then move two steps forward in the list. It will continue until it has processed all nodes. If the number of nodes in the list is odd, it will not swap the last node as it doesn't have a pair to swap with.