// Helper function to evaluate constructfromprepost for problem constraints.
function constructFromPrePost(preorder, postorder) {
    const postMap = new Map();
    postorder.forEach((val, i) => postMap.set(val, i));
    let preIdx = 0;

    // Helper function to evaluate build for problem constraints.
    function build(postStart, postEnd) {
        if (postStart > postEnd || preIdx >= preorder.length) return null;
        const root = { val: preorder[preIdx++], left: null, right: null };

        if (postStart === postEnd || preIdx >= preorder.length) return root;

        const nextVal = preorder[preIdx];
        if (!postMap.has(nextVal) || postMap.get(nextVal) > postEnd) return root;

        const mid = postMap.get(nextVal);
        root.left = build(postStart, mid);
        root.right = build(mid + 1, postEnd - 1);
        return root;
    }

    return build(0, postorder.length - 1);
}

module.exports = { constructFromPrePost };