Here is the JavaScript code for the problem:

class Node {
  constructor(x, next = null, random = null) {
    this.val = x;
    this.next = next;
    this.random = random;
  }
}

var copyRandomList = function(head) {
  if (head === null) return null;
  
  let nodes = new Map();
  let newHead = new Node(head.val);
  let currentNode = head.next;
  let newNode = newHead;
  
  nodes.set(newHead, newNode);
  
  while (currentNode !== null) {
    if (!nodes.has(currentNode)) {
      nodes.set(currentNode, new Node(currentNode.val));
    }
    newNode.next = nodes.get(currentNode);
    newNode = newNode.next;
    currentNode = currentNode.next;
  }
  
  if (head.random !== null) {
    newNode.random = nodes.get(head.random);
  }
  
  return newHead;
};

In this code, we use a Map to store the copied nodes, so that we don't need to worry about duplicate values. When a node is copied, we check if it's already been copied, and if not, we copy it and store it in the Map. Then we set the next pointer of the new node to the corresponding copied node, and the random pointer of the new node to the corresponding copied random node. 

Please note that this code assumes that the input linked list is a circular linked list with a `random` pointer pointing to a different node in the list.