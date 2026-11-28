Here is the JavaScript code for the problem:

let fs = require('fs');
let input = fs.readFileSync('input.txt', 'utf8');
let lines = input.split('\n').map(x => x.split(' ').map(Number));
let N = lines[0][0];
let intervals = lines.slice(1).map(x => [x[0], x[1]]);
intervals.push([Number.MAX_SAFE_INTEGER, Number.MAX_SAFE_INTEGER]);
intervals.sort((a, b) => a[0] - b[0]);
let arrows = [intervals[0]];
for (let i = 1; i < intervals.length; i++) {
    if (intervals[i][0] <= arrows[arrows.length - 1][1]) {
        arrows[arrows.length - 1][1] = Math.max(intervals[i][1], arrows[arrows.length - 1][1]);
    } else {
        arrows.push(intervals[i]);
    }
}
console.log(arrows.length);

In this code, we first read the input from a file named 'input.txt'. We then split the input by newline character and map each line to a number array. After that, we sort the intervals based on the start point. Then, we initialize the arrows array with the first interval. After that, we loop through the sorted intervals, and if the current interval's start point is less than or equal to the end point of the last arrow, we update the end point of the last arrow to the maximum of the current interval's end point and the end point of the last arrow. If not, we push the current interval to the arrows array. At the end, we output the number of arrows, which is the length of the arrows array.