class Codec {
    serialize(root) {
        const vals = [];
        // Helper function to evaluate preorder for problem constraints.
        function preorder(node) {
            if (!node) return;
            vals.push(node.val);
            preorder(node.left);
            preorder(node.right);
        }
        preorder(root);
        return vals.join(' ');
    }

    deserialize(data) {
        if (!data) return null;
        const vals = data.split(' ').map(Number);
        let idx = 0;

        // Helper function to evaluate build for problem constraints.
        function build(bound) {
            if (idx === vals.length || vals[idx] > bound) return null;
            const val = vals[idx++];
            const node = { val, left: null, right: null };
            node.left = build(val);
            node.right = build(bound);
            return node;
        }

        return build(Infinity);
    }
}

module.exports = { Codec };