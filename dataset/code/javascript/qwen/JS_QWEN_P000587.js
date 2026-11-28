
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


    // Merge K Sorted Linked Lists
    function mergeKLists(lists) {
        if (lists.length === 0) return null;
        while (lists.length > 1) {
            let merged = [];
            for (let i = 0; i < lists.length; i += 2) {
                if (i + 1 < lists.length) {
                    merged.push(mergeTwoListsHelper(lists[i], lists[i+1]));
                } else {
                    merged.push(lists[i]);
                }
            }
            lists = merged;
        }
        return lists[0];
    }
    
    function mergeTwoListsHelper(l1, l2) {
        let dummy = new ListNode(0);
        let curr = dummy;
        while (l1 && l2) {
            if (l1.val <= l2.val) { curr.next = l1; l1 = l1.next; }
            else { curr.next = l2; l2 = l2.next; }
            curr = curr.next;
        }
        curr.next = l1 || l2;
        return dummy.next;
    }

    function solve(lines) {
        // Input format: Line 1: K, Line 2...K+1: Lists
        let k = parseInt(lines[0]);
        let lists = [];
        for(let i=1; i<=k; i++) lists.push(deserializeList(lines[i]));
        console.log(serializeList(mergeKLists(lists)));
    }
    
