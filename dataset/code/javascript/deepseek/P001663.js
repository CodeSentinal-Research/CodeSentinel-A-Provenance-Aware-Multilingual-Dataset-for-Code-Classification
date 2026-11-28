Here is a JavaScript solution for the problem:

function isComplete(root) {
    let level = [root];
    while (level.length > 0) {
        let currentLevel = level.splice(0, level.length);
        for (let i = 0; i < currentLevel.length; i++) {
            if (currentLevel[i] === null) {
                continue;
            }
            if (level.length > 0) {
                if (currentLevel[i].left !== undefined) {
                    level.push(currentLevel[i].left);
                }
                if (currentLevel[i].right !== undefined) {
                    level.push(currentLevel[i].right);
                }
            } else {
                if (currentLevel[i].left !== undefined) {
                    return 'NO';
                }
            }
        }
    }
    return 'YES';
}

This function works by level order traversal of the binary tree. If it encounters a null node, it immediately returns 'NO' because the tree is not a complete binary tree. It also checks if the last node of each level is the last node and if it is, it returns 'YES'. Otherwise, it returns 'NO'.