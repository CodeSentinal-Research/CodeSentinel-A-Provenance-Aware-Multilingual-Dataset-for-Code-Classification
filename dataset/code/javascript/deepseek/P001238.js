process.stdin.resume();
process.stdin.on('data', (chunk) => {
  const N = parseInt(chunk.toString().trim());
  const intervals = [];
  let [start, end] = [0, 0];
  process.stdin.read();
  process.stdin.on('data', (chunk) => {
    const [newStart, newEnd] = chunk.toString().trim().split(/\s+/);
    start = Math.max(start, newStart);
    end = Math.min(end, newEnd);
    if (start === end) {
      intervals.push([start, end]);
      [start, end] = [newStart, newEnd];
    }
  });
  process.stdin.end();
  if (start !== 0 || end !== 0) {
    intervals.push([start, end]);
  }

  intervals.sort((a, b) => a[0] - b[0]);

  intervals.forEach((interval, index) => {
    if (index === 0) {
      console.log(`${interval[0]} ${interval[1]}`);
    } else {
      console.log(`${intervals[index - 1][1]} ${intervals[index][0]}`);
    }
  });
});
This JavaScript code reads the number of intervals and each interval's endpoints from stdin, merges overlapping intervals, and prints the merged intervals sorted by start position.