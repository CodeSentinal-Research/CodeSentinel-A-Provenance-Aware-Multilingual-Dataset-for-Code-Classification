class ListNode {
  constructor(val = 0, next = null) {
    this.val = val;
    this.next = next;
  }
}

function oddEvenList(head) {
  if(!head) return head;

  let odd = new ListNode(0), even = new ListNode(0);
  let oddTail = odd, evenTail = even;

  let isOdd = true;
  while(head){
      if(isOdd){
          oddTail.next = head;
          oddTail = oddTail.next;
      }else{
          evenTail.next = head;
          evenTail = evenTail.next;
      }
      head = head.next;
      isOdd = !isOdd;
  }

  oddTail.next = even.next;
  return odd.next;
}

This JavaScript code defines a `ListNode` class to represent nodes in a linked list. The `oddEvenList` function takes the head of a linked list as input, then creates new nodes for the odd and even groups. The function iterates through the linked list, and for each node, it checks whether the index is odd (i.e., `isOdd` is true) or even (i.e., `isOdd` is false). Then, it appends the node to the appropriate group and moves on to the next node. Finally, it reassigns the `next` pointer of the tail node of the odd and even groups and returns the head of the reordered linked list.