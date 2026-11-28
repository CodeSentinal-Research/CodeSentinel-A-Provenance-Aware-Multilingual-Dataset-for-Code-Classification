
// --- Helper Classes & Functions ---

class TreeNode {
    constructor(val, left, right) {
        this.val = (val === undefined ? 0 : val);
        this.left = (left === undefined ? null : left);
        this.right = (right === undefined ? null : right);
    }
}

class ListNode {
    constructor(val, next) {
        this.val = (val === undefined ? 0 : val);
        this.next = (next === undefined ? null : next);
    }
}

function deserializeTree(data) {
    if (!data || data === '[]') return null;
    let vals = data.replace(/[\[\]]/g, '').split(',').map(v => v.trim() === 'null' ? null : parseInt(v));
    if (vals.length === 0 || vals[0] === null) return null;
    
    let root = new TreeNode(vals[0]);
    let queue = [root];
    let i = 1;
    
    while (queue.length > 0 && i < vals.length) {
        let node = queue.shift();
        
        if (i < vals.length) {
            if (vals[i] !== null) {
                node.left = new TreeNode(vals[i]);
                queue.push(node.left);
            }
            i++;
        }
        
        if (i < vals.length) {
            if (vals[i] !== null) {
                node.right = new TreeNode(vals[i]);
                queue.push(node.right);
            }
            i++;
        }
    }
    return root;
}

function serializeTree(root) {
    if (!root) return '[]';
    let res = [];
    let queue = [root];
    while (queue.length > 0) {
        let node = queue.shift();
        if (node) {
            res.push(node.val);
            queue.push(node.left);
            queue.push(node.right);
        } else {
            res.push(null);
        }
    }
    // Remove trailing nulls
    while (res.length > 0 && res[res.length - 1] === null) res.pop();
    return '[' + res.join(',') + ']';
}

function deserializeList(data) {
    if (!data || data === '[]') return null;
    let vals = data.replace(/[\[\]]/g, '').split(',').map(v => parseInt(v.trim()));
    let dummy = new ListNode(0);
    let curr = dummy;
    for (let v of vals) {
        curr.next = new ListNode(v);
        curr = curr.next;
    }
    return dummy.next;
}

function serializeList(head) {
    let res = [];
    let curr = head;
    while (curr) {
        res.push(curr.val);
        curr = curr.next;
    }
    return '[' + res.join(',') + ']';
}

// --- Input Parsing Logic ---
const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];

rl.on('line', (line) => {
    lines.push(line.trim());
});

rl.on('close', () => {
    try {
        solve(lines);
    } catch (e) {
        console.error(e);
    }
});

function solve(lines) {
    // Implementation will be injected here
}


    // Binary Tree Maximum Width
    function widthOfBinaryTree(root) {
        if (!root) return 0;
        let queue = [[root, 0]]; // [node, index]
        let maxWidth = 0;
        while (queue.length) {
            let size = queue.length;
            let minIndex = queue[0][1];
            let first, last;
            for (let i = 0; i < size; i++) {
                let [node, idx] = queue.shift();
                let normalizedIdx = idx - minIndex;
                if (i === 0) first = normalizedIdx;
                if (i === size - 1) last = normalizedIdx;
                if (node.left) queue.push([node.left, 2 * normalizedIdx]);
                if (node.right) queue.push([node.right, 2 * normalizedIdx + 1]);
            }
            maxWidth = Math.max(maxWidth, last - first + 1);
        }
        return maxWidth;
    }

    function solve(lines) {
        let root = deserializeTree(lines[0]);
        console.log(widthOfBinaryTree(root));
    }
    
