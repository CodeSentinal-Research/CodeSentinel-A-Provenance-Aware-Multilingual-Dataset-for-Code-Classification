function flipEquivalentBinaries(tree1, tree2) {
  if (tree1 === tree2) {
    return "YES";
  }

  if ((tree1 === null) !== (tree2 === null)) {
    return "NO";
  }

  if (tree1.left !== null !== tree2.left) {
    return "NO";
  }

  if (tree1.right !== null !== tree2.right) {
    return "NO";
  }

  return flipEquivalentBinaries(tree1.left, tree2.left) &&
         flipEquivalentBinaries(tree1.right, tree2.right);
}

// Input handling
const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let tree1 = null;
let tree2 = null;

rl.on('line', (line) => {
  if (tree1 === null) {
    tree1 = {
      left: line === 'X' ? null : {left: null, right: null},
      right: line === 'X' ? null : {left: null, right: null}
    };
  } else {
    tree1.left = line === 'X' ? null : {left: null, right: null};
    tree1.right = line === 'X' ? null : {left: null, right: null};
  }

  if (tree1.left !== null) {
    tree1.left.left = line === 'X' ? null : {left: null, right: null};
    tree1.left.right = line === 'X' ? null : {left: null, right: null};
  }

  if (tree1.right !== null) {
    tree1.right.left = line === 'X' ? null : {left: null, right: null};
    tree1.right.right = line === 'X' ? null : {left: null, right: null};
  }

  if (tree1.left === null && tree1.right === null) {
    tree2 = {
      left: line === 'X' ? null : {left: null, right: null},
      right: line === 'X' ? null : {left: null, right: null}
    };
  } else {
    tree2.left = line === 'X' ? null : {left: null, right: null};
    tree2.right = line === 'X' ? null : {left: null, right: null};

    if (tree2.left !== null) {
      tree2.left.left = line === 'X' ? null : {left: null, right: null};
      tree2.left.right = line === 'X' ? null : {left: null, right: null};
    }

    if (tree2.right !== null) {
      tree2.right.left = line === 'X' ? null : {left: null, right: null};
      tree2.right.right = line === 'X' ? null : {left: null, right: null};
    }
  }
});

rl.on('close', () => {
  console.log(flipEquivalentBinaries(tree1, tree2));
  rl.close();
});