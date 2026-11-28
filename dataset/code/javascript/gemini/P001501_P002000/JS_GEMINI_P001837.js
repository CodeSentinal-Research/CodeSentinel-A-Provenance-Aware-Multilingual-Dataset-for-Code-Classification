class BSTReverseIterator {
    constructor(root) {
        this.stack = [];
        this._pushRight(root);
    }

    _pushRight(node) {
        while (node) {
            this.stack.push(node);
            node = node.right;
        }
    }

    next() {
        const node = this.stack.pop();
        this._pushRight(node.left);
        return node.val;
    }

    hasNext() {
        return this.stack.length > 0;
    }
}

module.exports = { BSTReverseIterator };