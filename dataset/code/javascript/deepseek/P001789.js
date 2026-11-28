Sure, here is the JavaScript code:

process.stdin.resume();
process.stdin.on('data', function (chunk) {
  var n = parseInt(chunk.toString());
  var tree = [];
  for (var i = 0; i < n; i++) {
    tree.push(parseInt(process.stdin.readLine()));
  }
  console.log(isValidBST(tree, -Infinity, Infinity));
});

function isValidBST(arr, min, max) {
  for (var i = 0; i < arr.length; i++) {
    if (arr[i] < min || arr[i] > max) {
      return 'NO';
    }
    if (i < arr.length - 1) {
      if (arr[i] > arr[i + 1]) {
        if (!isValidBST(arr.slice(i + 1), min, arr[i])) {
          return 'NO';
        }
      } else {
        if (!isValidBST(arr.slice(i + 1), arr[i], max)) {
          return 'NO';
       
        }
      }
    }
  }
  return 'YES';
}

The code reads the input tree from stdin and then uses it to call the `isValidBST` function. The `isValidBST` function checks if a given tree is a binary search tree. It starts by comparing the root of the tree with the minimum and maximum values allowed (`-Infinity` and `Infinity`). If the root value is outside these bounds, it returns `'NO'`. If the root value is within these bounds, it calls itself recursively on the left and right subtrees, passing in the smaller and larger subtrees. If either subtree is not a valid BST, it returns `'NO'`. If the tree is a valid BST, it returns `'YES'`.