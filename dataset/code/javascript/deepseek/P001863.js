function optimalBST(keys, successful, unsuccessful) {
    // Calculate the sum of all successful and unsuccessful search frequencies
    let total = successful.reduce((a, b) => a + b, 0) + unsuccessful.reduce((a, b) => a + b, 0);

    // Initialize an array to store the cumulative successful and unsuccessful search frequencies
    let cumulative = successful.map((f, i) => {
        return successful[i - 1] ? successful[i - 1] + successful[i] : successful[i];
    }).concat(unsuccessful.map((f, i) => {
        return unsuccessful[i - 1] ? unsuccessful[i - 1] + unsuccessful[i] : unsuccessful[i];
    }).concat(new Array(total - successful.length).fill(0));

    // Calculate the cumulative sum of the cumulative array
    for (let i = 1; i < cumulative.length; i++) {
        cumulative[i] += cumulative[i - 1];
    }

    // Initialize the data structure for storing the optimal binary search tree
    let bst = {
        key: keys[Math.floor(Math.random() * keys.length)],
        left: null,
        right: null
    };

    // Construct the optimal binary search tree
    for (let i = 0; i < keys.length; i++) {
        if (keys[i] < bst.key) {
            if (bst.left) {
                bst.right = {
                    key: keys[i],
                    left: null,
                    right: null
                };
            } else {
                bst.left = {
                    key: keys[i],
                    left: null,
                    right: null
                };
            }
        } else {
            if (bst.right) {
                bst.right = {
                    key: keys[i],
                    left: null,
                    right: null
                };
            } else {
                bst.right = {
                    key: keys[i],
                    left: null,
                    right: null
                };
            }
        }
    }

    // Calculate the expected search cost
    let cost = cumulative[unsuccessful.length] * 2 + cumulative[unsuccessful.length - 1] * 3;

    return {
        cost,
        bst
    };
}

console.log(optimalBST([1, 2, 3, 4, 5], [0, 1, 1, 1, 0], [2, 1]));