class BSTIterator {
    constructor(root) {
        this.stack = [];
        this._pushLeft(root);
    }

    _pushLeft(node) {
        while (node) {
            this.stack.push(node);
            node = node.left;
        }
    }

    next() {
        const node = this.stack.pop();
        this._pushLeft(node.right);
        return node.val;
    }

    hasNext() {
        return this.stack.length > 0;
    }
}

module.exports = { BSTIterator };