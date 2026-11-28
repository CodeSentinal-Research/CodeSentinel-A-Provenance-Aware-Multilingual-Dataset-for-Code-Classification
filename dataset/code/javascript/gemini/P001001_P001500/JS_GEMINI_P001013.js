class MedianFinder {
    constructor() {
        this.arr = [];
    }

    addNum(num) {
        let l = 0, r = this.arr.length;
        while (l < r) {
            // Calculate midpoint to prevent potential overflow
            const mid = Math.floor((l + r) / 2);
            if (this.arr[mid] < num) l = mid + 1;
            else r = mid;
        }
        this.arr.splice(l, 0, num);
    }

    findMedian() {
        const n = this.arr.length;
        // Calculate midpoint to prevent potential overflow
        const mid = Math.floor(n / 2);
        if (n % 2 === 1) return this.arr[mid];
        return (this.arr[mid - 1] + this.arr[mid]) / 2.0;
    }
}

module.exports = { MedianFinder };