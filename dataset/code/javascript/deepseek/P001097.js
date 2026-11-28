Sure, here is the JavaScript code for your problem:

class UnionFind {
    constructor(size) {
        this.parent = Array(size).fill(-1);
        this.rank = Array(size).fill(0);
    }

    find(x) {
        if (this.parent[x] === -1) {
            return x;
        }
        this.parent[x] = this.find(this.parent[x]);
        return this.parent[x];
    }

    union(x, y) {
        x = this.find(x);
        y = this.find(y);
        if (x === y) {
            return;
        }
        if (this.rank[x] < this.rank[y]) {
            [x, y] = [y, x];
        }
        this.parent[y] = x;
        if (this.rank[x] === this.rank[y]) {
            this.rank[x]++;
        }
    }

    connected(x, y) {
        return this.find(x) === this.find(y);
    }
}

function solve(n, q, operations) {
    const uf = new UnionFind(n);
    operations.forEach(op => {
        if (op.startsWith('UNION')) {
            uf.union(op[7], op[8]);
        } else {
            console.log(uf.connected(op[7], op[8]) ? 'YES' : 'NO');
        }
    });
}

// Example usage:
solve(5, 3, [
    'UNION 0 1',
    'UNION 2 3',
    'FIND 0 4',
]);

This code defines a UnionFind data structure with union and find operations. The `solve` function takes the size of the set (`n`), the number of operations (`q`), and an array of operations as arguments. It creates a UnionFind instance, and then for each operation, if it's a union operation, it calls the union operation. Otherwise, it calls the find operation. Finally, it prints out the result of each find operation.