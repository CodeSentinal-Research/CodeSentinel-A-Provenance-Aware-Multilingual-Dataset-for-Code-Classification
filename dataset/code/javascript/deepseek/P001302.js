Here is the JavaScript code for your problem:

process.stdin.resume();
process.stdin.on('data', (chunk) => {
    const N = parseInt(chunk.toString().trim());
    const meetings = [];

    for(let i = 0; i < N; i++) {
        const [start, end] = process.stdin.readLine().split(' ').map(Number);
        meetings.push({start, end});
    }

    meetings.sort((a, b) => a.start - b.start); // sort by start time

    // initialize variables
    let rooms = 0;
    let endTime = 0;

    for(let meeting of meetings) {
        if(meeting.start >= endTime) { // if no room is available
            rooms++;
        }
        endTime = Math.max(endTime, meeting.end); // update end time for the next meeting
    }

    console.log(rooms);

    process.stdin.pause();
});

In this code, we start by reading the number of meetings from the standard input. Then, we read the start and end times for each meeting and store them in an array. We sort the meetings by start time.

We then initialize a variable `rooms` to count the number of meeting rooms used, and another variable `endTime` to keep track of the end time of the last meeting that finishes.

We then iterate over the sorted meetings. If the start time of the current meeting is greater than or equal to `endTime`, it means a new meeting room is available, so we increment `rooms`. We also update `endTime` to be the maximum of its current value and the end time of the current meeting.

At the end of the loop, we print the number of rooms used.