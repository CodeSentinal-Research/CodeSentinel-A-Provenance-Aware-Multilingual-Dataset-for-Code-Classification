function binaryTreeToArray(root, array) {
    if (root !== null) {
        binaryTreeToArray(root.left, array);
        array.push(root.key);
        binaryTreeToArray(root.right, array);
    }
}

function intersection(root1, root2) {
    let array1 = [];
    let array2 = [];

    binaryTreeToArray(root1, array1);
    binaryTreeToArray(root2, array2);

    array1.sort((a, b) => a - b);
    array2.sort((a, b) => a - b);

    let result = array1.filter(value => array2.includes(value));

    return result;
}
This code defines the `binaryTreeToArray` function that converts a Binary Search Tree into an array. The `intersection` function takes two BSTs, converts them into arrays, sorts them and then finds the common elements between them.