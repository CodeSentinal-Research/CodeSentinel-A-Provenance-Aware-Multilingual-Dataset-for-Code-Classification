function solve() {
    const tree = {};
    let n = parseInt(readline());
    for (let i = 0; i < n; i++) {
        const line = readline().split(' ');
        const node = line[0];
        const children = line[1] ? line[1].split(',').map(Number) : [];
        tree[node] = children;
    }
    const k = parseInt(readline());
    console.log(countDescendants(tree, k));
}

function countDescendants(tree, k) {
    let count = 0;
    for (let node in tree) {
        count += countDescendants(tree, k, node);
    }
    return count;
}

function countDescendants(tree, k, node) {
    const children = tree[node];
    if (!children) return 0;
    let descendantCount = children.map(n => countDescendants(tree, k, n)).reduce((a, b) => a + b, 0);
    if (descendantCount === k) return 1;
    return 0;
}

function readline() {
    return process.env.NODE_ENV !== "production" ? require('readline-sync')({input: process.stdin, output: process.stdout}) : null;
}

solve();