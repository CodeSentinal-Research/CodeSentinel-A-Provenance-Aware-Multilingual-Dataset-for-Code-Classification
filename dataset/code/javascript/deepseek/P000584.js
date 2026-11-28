Here is the JavaScript code for the problem:

function removeNthFromEnd(head, n) {
  let dummy = new ListNode(0);
  dummy.next = head;
  let fast = dummy;
  let slow = dummy;

  // Move fast to n nodes ahead
  for(let i = 1; i <= n + 1; i++){
    fast = fast.next;
  }

  // Move fast until the end of the list, slow will be the node before the node we want to delete
  while(fast){
    fast = fast.next;
    slow = slow.next;
 
  }

  slow.next = slow.next.next;
  return dummy.next;
}

In this code, a dummy node is created before the input list. Then, the fast pointer moves `n` steps ahead of the slow pointer. After that, both pointers move together until fast reaches the end of the list. The node before the node we want to delete (which is the slow.next node in this case) is then connected to the node next to the node we want to delete.