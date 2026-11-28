Sure, here is a simple JavaScript solution for the problem:

function exclusiveTime(n, logs) {
    let time = new Array(n).fill(0);
    let prev = 0, i = 0;

    while (i < logs.length) {
        let curr = logs[i++], type = curr[1] === 'start' ? 1 : -1;
        time[curr[0]] += type * (curr[2] - prev);
        prev = curr[2];
    }

    return time;
}

// Example usage:
console.log(exclusiveTime(3, [[0, "start", 1], [1, "start", 2], [2, "end", 3], [0, "end", 4]])); // [0, 1, 4]

In this solution, we use a stack to keep track of function calls. We keep track of the current time and the previous time of a function call. If a function starts, we add the time difference between its start and the previous time to its total time. If a function ends, we subtract the time difference from the total time.

Please note that the provided input in the problem is in string format. If it's not in this format, you would need to convert it to an array of integers for the JavaScript code to work.