class SmallestInfiniteSet {
    constructor() {
        this.cur = 1;
        this.added = new Set();
        this.heap = [];
    }

    popSmallest() {
        if (this.heap.length > 0) {
            const val = this.heap.shift();
            this.added.delete(val);
            return val;
        }
        return this.cur++;
    }

    addBack(num) {
        if (num < this.cur && !this.added.has(num)) {
            this.added.add(num);
            let l = 0, r = this.heap.length;
            while (l < r) {
                // Calculate midpoint to prevent potential overflow
                const mid = Math.floor((l + r) / 2);
                if (this.heap[mid] < num) l = mid + 1;
                else r = mid;
            }
            this.heap.splice(l, 0, num);
        }
    }
}

module.exports = { SmallestInfiniteSet };