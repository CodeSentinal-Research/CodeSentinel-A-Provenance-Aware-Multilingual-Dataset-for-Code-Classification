function levelOrder(root) {
    if(root === null) {
        return [];
    }

    let result = [];
    let currentLevel = [root];

    while(currentLevel.length > 0) {
        let nextLevel = [];
        result.push(currentLevel.map(node => node.val));
        for(let node of currentLevel) {
            if(node.left !== null) {
                nextLevel.push(node.left);
            }
            if(node.right !== null) {
                nextLevel.push(node.right);
            }
        }
        currentLevel = nextLevel;
    }

    return result;
}