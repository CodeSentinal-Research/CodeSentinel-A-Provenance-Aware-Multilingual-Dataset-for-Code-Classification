Here is the JavaScript code for the problem. This solution uses level order traversal to check if every level is palindromic.

function checkPalindrome() {
    // Read N and the tree structure from the standard input
    var N = readline();
    var tree = [];
    for (var i = 0; i < N; i++) {
        tree.push(readline().split(' ').map(Number));
    }

    // Perform level order traversal
    var levels = [];
    var currentLevel = 0;
    var queue = [[0, 0]];
    while (queue.length > 0) {
        var current = queue.shift();
        if (current[1] > currentLevel) {
            currentLevel = current[1];
            levels.push([]);
        }
        levels[currentLevel].push(current[0]);
        for (var j = 0; j < 2; j++) {
            if (current[j + 1] !== undefined) {
                queue.push([current[j + 1], current[1] + 1]);
            }
        }
    }

    // Check if every level is palindromic
    for (var i = 0; i < levels.length; i++) {
        if (!isPalindrome(levels[i])) {
            console.log('NO');
            return;
        }
    }
    console.log('YES');
}

function isPalindrome(arr) {
    for (var i = 0; i < arr.length / 2; i++) {
        if (arr[i] !== arr[arr.length - i - 1]) {
            return false;
        }
    }
    return true;
}

function readline() {
    return process.stdin.readline();
}

Please note that this code uses the Node.js `process.stdin.readline()` function to read the input from the standard input, which is provided by the test cases. You might need to adjust this code to fit your specific implementation.

This code also uses a Breadth-First Search (BFS) approach to traverse the binary tree level by level. It is important to note that this approach assumes the input tree is a perfect binary tree, as it is the case in this problem. If the input tree is not a perfect binary tree, this approach will not work correctly.