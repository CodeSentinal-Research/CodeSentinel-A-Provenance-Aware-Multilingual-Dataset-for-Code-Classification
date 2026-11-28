Here is the JavaScript code that accomplishes this task:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let tree = [];

rl.on('line', (line) => {
    tree.push(+line);
    if(tree.length === (2**(tree.length + 1) - 1)) {
        rl.close();
    }
});

rl.on('close', () => {
    const result = checkTree(tree, 0, 0);
    console.log(result ? 'YES' : 'NO');
    process.exit();
});

function checkTree(arr, index, depth) {
    if(index >= arr.length) {
        return true;
    }
    if(depth % 2 === 0) {
        if(arr[index] % 2 !== 0 || (index !== 0 && arr[index] <= arr[index - 1])) {
            return false;
        }
    } else {
        if(arr[index] % 2 === 0 || (index !== 0 && arr[index] >= arr[index - 1])) {
            return false;
        }
    }
    return checkTree(arr, index + 1, depth + 1)
        && checkTree(arr, index + 1, depth + 1);
}

This code reads the tree input from the console and then calls the `checkTree` function. The `checkTree` function recursively checks if the tree satisfies the Even-Odd Tree property. It first checks if the index is out of the bounds of the tree, if so, it returns `true`. Then it checks if the depth is even or odd, and the value at the current index. If the value is not the expected one, it returns `false`. If both conditions are satisfied, it calls itself for both left and right children with the incremented index and depth. If all the trees satisfy the condition, it returns `true`.