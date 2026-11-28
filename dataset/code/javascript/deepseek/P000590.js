Sure, here is the JavaScript code to solve the problem:

// Definition for singly-linked list.
function ListNode(val) {
  this.val = val;
  this.next = null;
}

function isPalindrome(head) {
  var slow = head;
  var fast = head;
  var prev = null;
  
  // Find the middle of the linked list
  while(fast && fast.next) {
    prev = slow;
    slow = slow.next;
    fast = fast.next.next;
  }
  
  // Reverse the second half
  prev.next = null;
  
  // Compare the first half and the reversed second half
  slow = slow.next;
  while(slow) {
    if(head.val !== slow.val) return false;
    head = head.next;
    slow = slow.next;
 
  }
  return true;
}

This code first finds the middle of the linked list and reverses the second half. Then it compares the first half and the reversed second half. If they match, the linked list is a palindrome, otherwise it is not.