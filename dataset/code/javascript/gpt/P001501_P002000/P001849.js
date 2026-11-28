const fs = require("fs");

const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/);
if (!tokens.length || tokens[0] === "") process.exit(0);

const n = Number(tokens[0]);
if (n <= 0) {
    console.log(0);
    process.exit(0);
}

class Node {
    constructor(value) {
        this.value = value;
        this.left = null;
        this.right = null;
    }
}

const values = new Array(n);
for (let i = 0; i < n; i++) values[i] = Number(tokens[i + 1]);

const root = new Node(values[0]);
let height = 0;

for (let i = 1; i < n; i++) {
    let cur = root;
    let depth = 0;

    while (true) {
        depth++;

        if (values[i] < cur.value) {
            if (cur.left === null) {
                cur.left = new Node(values[i]);
                height = Math.max(height, depth);
                break;
            }
            cur = cur.left;
        } else {
            if (cur.right === null) {
                cur.right = new Node(values[i]);
                height = Math.max(height, depth);
                break;
            }
            cur = cur.right;
        }
    }
}

console.log(height);
