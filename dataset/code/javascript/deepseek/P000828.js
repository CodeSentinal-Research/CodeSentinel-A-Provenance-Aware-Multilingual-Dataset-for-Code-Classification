function findRightInterval(intervals) {
    let result = [];
    let sortedIntervals = [...intervals].sort((a, b) => a[1] - b[1]);
    for (let interval of intervals) {
        let index = sortedIntervals.findIndex(i => i[0] >= interval[1]);
        result.push(index !== -1 ? sortedIntervals[index][0] : -1);
        sortedIntervals.shift();
    }
    return result;
}

console.log(findRightInterval([[1, 2], [2, 3], [3, 4]])); // [1, 2, -1]
console.log(findRightInterval([[1, 3], [2, 4]])); // [1, 2]
console.log(findRightInterval([[1, 2], [3, 4]])); // [-1, -1]