function connect(root) {
    if (!root) return;
    let level = root, prev = null;
    while (level) {
        let dummy = new TreeLinkNode(0), p = dummy, prevPrev = prev;
        while (level) {
            if (prev) {
                p.next = level;
                p = p.next;
            }
            level = level.next;
        }
        if (prevPrev) prevPrev.next = dummy.next;
        prev = dummy;
        level = dummy.next;
    }
}

class TreeLinkNode {
    constructor(x) {
        this.val = x;
        this.left = this.right = this.next = null;
    }
}

In this code, we're creating a new TreeLinkNode for each node in the tree. Then, we're going through each node, connecting it to its immediate neighbor on the same level. We're also maintaining a pointer to the previous node so we can link it to the new node. If there is no previous node, it means we're at the root node and we don't need to link it to anything. Finally, we're updating the previous node and the level for the next iteration.