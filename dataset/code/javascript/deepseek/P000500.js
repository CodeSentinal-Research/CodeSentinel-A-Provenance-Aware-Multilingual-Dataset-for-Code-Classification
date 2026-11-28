Here is a JavaScript solution for the problem:

function minOperations(operations) {
    let level = 0;
    let operationsNeeded = 0;

    for (let i = 0; i < operations.length; i++) {
        if (operations[i] === '../') {
            if (level > 0) {
                level--;
            }
        } else if (operations[i] === './') {
            continue;
        } else {
            level++;
        }

        operationsNeeded += Math.abs(level);
    }

    return operationsNeeded;
}
This function iterates over the operations array. When it encounters '../', it decreases the level (as it is moving up). When it encounters './', it simply ignores it (as it is staying in the current folder). Otherwise, it increases the level (as it is moving into a new folder).

After all operations have been processed, it returns the total number of operations needed.

The time complexity is O(n), where n is the number of operations, as it only requires a single pass through the operations array. The space complexity is O(1), as it uses a constant amount of space to store the level and operationsNeeded variables, regardless of the input size.