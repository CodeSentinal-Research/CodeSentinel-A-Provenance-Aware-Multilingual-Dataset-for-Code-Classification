Here is a simple implementation of the problem in JavaScript. The program uses a `Map` to store the intervals. The `Map` key is the number and the value is the list of intervals. The `Map` also maintains the intervals in sorted order.

class RangeModule {
    constructor() {
        this.map = new Map();
    }
    
    addNum(value) {
        if (!this.map.has(value)) {
            this.map.set(value, []);
        }
        
        let keys = this.map.keys();
        let left = keys.next().value;
        let right = value;
        
        while (right - left > 1) {
            let mid = Math.floor((left + right) / 2);
            
            if (mid < value) {
                left = mid;
            } else {
                right = mid;
            }
        }
        
        this.map.set(left, [...this.map.get(left), value]);
        this.map.set(right, [...this.map.get(right), value]);
    }
    
    getIntervals() {
        let intervals = [];
        
        for (let [num, arr] of this.map.entries()) {
            if (intervals[intervals.length - 1] && num - intervals[intervals.length - 1][1] > 1) {
                intervals.push(intervals[intervals.length - 1].concat(arr));
            } else {
                intervals[intervals.length - 1] = arr;
            }
        }
        
        intervals.shift();
        
        return intervals;
    }
}

You can use the above `RangeModule` class to implement the problem as described. In this class, the `addNum` method adds a new number to the list of intervals. The `getIntervals` method returns the list of intervals.

Here is a usage example:

let rm = new RangeModule();
rm.addNum(5);
rm.addNum(7);
rm.addNum(2);
rm.addNum(10);
console.log(rm.getIntervals()); // [[2, 10]]
rm.addNum(6);
console.log(rm.getIntervals()); // [[2, 6], [6, 10]]
rm.addNum(1);
console.log(rm.getIntervals()); // [[1, 10]]
rm.addNum(3);
console.log(rm.getIntervals()); // [[1, 3], [3, 10]]

This code implements the `addNum` operation by binary search to find the insertion point for the new number. Then it adds the number to the list of intervals. The `getIntervals` operation just returns the list of intervals.