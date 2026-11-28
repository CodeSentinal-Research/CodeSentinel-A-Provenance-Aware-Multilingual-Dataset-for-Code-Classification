class TreeAncestor {
    constructor(n, parent) {
        this.up = Array.from({ length: n }, () => new Array(20).fill(-1));
        for (let i = 0; i < n; i++) this.up[i][0] = parent[i];

        for (let j = 1; j < 20; j++) {
            for (let i = 0; i < n; i++) {
                if (this.up[i][j - 1] !== -1) {
                    this.up[i][j] = this.up[this.up[i][j - 1]][j - 1];
                }
            }
        }
    }

    getKthAncestor(node, k) {
        for (let j = 0; j < 20; j++) {
            // If current bit is set, multiply base into result
            if ((k >> j) & 1) {
                node = this.up[node][j];
                if (node === -1) break;
            }
        }
        return node;
    }
}

module.exports = { TreeAncestor };