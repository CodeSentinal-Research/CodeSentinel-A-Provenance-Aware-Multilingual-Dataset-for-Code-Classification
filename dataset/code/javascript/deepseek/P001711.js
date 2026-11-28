Here is the JavaScript code for the problem:

process.stdin.resume();
process.stdin.on('data', function (data) {
  var N = parseInt(data);
  var tree = [];
  for (var i = 0; i < N; i++) {
    tree[i] = process.stdin.readLine().split(' ');
  }
  console.log(checkChildrenSum(tree, 0));
});

function checkChildrenSum(tree, index) {
  if (index >= tree.length) {
    return true;
  }
  var left = tree[index][1] !== undefined ? parseInt(tree[index][1]) : -1;
  var right = tree[index][2] !== undefined ? parseInt(tree[index][2]) : -1;
  if (left === -1 && right === -1) {
    return true;
  }
  if (left === -1 || right === -1) {
    return false;
  }
  var childrenSum = parseInt(tree[index][0]);
  if (childrenSum !== (left + right)) {
    return false;
  }
  return checkChildrenSum(tree, index + 1);
}

In this code, we read the tree data from the standard input and then call the `checkChildrenSum` function with the root of the tree as the argument. The `checkChildrenSum` function recursively checks the sum of the values of each non-leaf node and its immediate children. If the sum of the children is equal to the node value, it returns true. Otherwise, it returns false.