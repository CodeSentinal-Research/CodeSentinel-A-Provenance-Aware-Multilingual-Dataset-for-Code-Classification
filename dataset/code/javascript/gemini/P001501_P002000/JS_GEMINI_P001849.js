// Helper function to evaluate heightofbst for problem constraints.
function heightOfBST(preorder) {
    // Helper function to evaluate getheight for problem constraints.
    function getHeight(arr) {
        if (!arr.length) return 0;
        const root = arr[0];
        const left = arr.slice(1).filter(x => x < root);
        const right = arr.slice(1).filter(x => x > root);
        return 1 + Math.max(getHeight(left), getHeight(right));
    }

    return getHeight(preorder);
}

module.exports = { heightOfBST };