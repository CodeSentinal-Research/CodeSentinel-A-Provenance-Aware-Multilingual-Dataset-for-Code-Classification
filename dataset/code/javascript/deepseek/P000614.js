Here is a JavaScript solution for the problem:

class ListNode {
  constructor(val = 0, next = null) {
    this.val = val;
    this.next = next;
  }
}

function swapNodes(head, k) {
  if (k <= 0 || k > head.length) {
    return head;
  }

  let arr = [];
  let current = head;
  let index = 0;

  // Store the values of the linked list in an array
  while (current !== null) {
    arr.push(current.val);
    current = current.next;
    index++;
  }

  // Swap values of k-th node from beginning and k-th node from end
  [arr[k - 1], arr[index - k]] = [arr[index - k], arr[k - 1]];

  // Reconstruct the linked list and return
  current = head;
  for (let i = 0; i < index; i++) {
    current.val = arr[i];
    if (i < index - 1) {
      current.next = new ListNode(arr[i + 1]);
      current = current.next;
    }
  }

  return head;
}

In this code, we first convert the linked list to an array, then swap the values of the k-th node from the beginning and the k-th node from the end. Finally, we reconstruct the linked list from the array and return the modified head of the linked list.

This solution assumes that the input linked list has a method `length` to get the length of the linked list. The time complexity of this solution is O(n), where n is the length of the linked list, since we need to traverse the linked list once to store its values in an array, and once to reconstruct the linked list. The space complexity is O(n), as we need to store the values of the linked list in an array.