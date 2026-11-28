const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    
    class TreeNode {
        constructor(val) { this.val=val; this.left=null; this.right=null; }
    }
    
    function generateTrees(start, end) {
        if(start>end) return [null];
        let res = [];
        for(let i=start; i<=end; i++) {
            let lefts = generateTrees(start, i-1);
            let rights = generateTrees(i+1, end);
            for(let l of lefts) {
                for(let r of rights) {
                    let root = new TreeNode(i);
                    root.left = l;
                    root.right = r;
                    res.push(root);
                }
            }
        }
        return res;
    }
    
    let trees = generateTrees(1, n);
    console.log(trees.length);
    // Serialization omitted for brevity
    rl.close();
});
