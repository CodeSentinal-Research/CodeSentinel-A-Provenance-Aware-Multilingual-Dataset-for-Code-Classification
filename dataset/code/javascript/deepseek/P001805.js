function Node(data) {
  this.data = data;
  this.left = null;
  this.right = null;
}

function BST() {
  this.root = null;
}

BST.prototype.insert = function(data) {
  var newNode = new Node(data);

  if(this.root === null) {
    this.root = newNode;
  } else {
    var currentNode = this.root;
    while(currentNode !== null) {
      if(newNode.data < currentNode.data) {
        if(currentNode.left === null) {
          currentNode.left = newNode;
          break;
        }
        currentNode = currentNode.left;
      } else if(newNode.data > currentNode.data) {
        if(currentNode.right === null) {
          currentNode.right = newNode;
          break;
        }
        currentNode = currentNode.right;
      } else {
        break;
      }
    }
  }
};

BST.prototype.findMedian = function() {
  var currentNode = this.root;
  var inOrder = [];

  // Convert the BST to an array in inOrder (left, node, right)
  while(currentNode !== null) {
    if(currentNode.left !== null) {
      currentNode = currentNode.left;
    } else {
      inOrder.push(currentNode.data);
      if(currentNode.right !== null) {
        currentNode = currentNode.right;
      } else {
        break;
      }
    }
  }

  // Find the median
  if(inOrder.length % 2 === 0) {
    return (inOrder[inOrder.length / 2 - 1] + inOrder[inOrder.length / 2]) / 2;
  } else {
    return inOrder[(inOrder.length - 1) / 2];
  }
};

var inputData = require('fs').readFileSync('input.txt', 'utf8');
var N = parseInt(inputData.split('\n')[0]);
var bst = new BST();

for(var i = 1; i < N; i++) {
  bst.insert(inputData.split('\n')[i].trim());
}

console.log(bst.findMedian());

This JavaScript solution uses a BST with a Node constructor and a BST prototype with insert and findMedian methods. The insert method first checks if the root is null. If it is, it sets the new node as the root. If not, it checks each node in the BST until it finds an appropriate location for the new node and sets it there. The findMedian method converts the BST to an array in in-order traversal (left, node, right) and then finds the median. If the array length is even, the median is the average of the two middle numbers. If the array length is odd, the median is the middle number.

This solution assumes that the input file is a text file named "input.txt" in the same directory as the script and that it contains one line for the number of nodes and each subsequent line for the nodes. The script reads the input from the file and processes it using the BST prototype methods.