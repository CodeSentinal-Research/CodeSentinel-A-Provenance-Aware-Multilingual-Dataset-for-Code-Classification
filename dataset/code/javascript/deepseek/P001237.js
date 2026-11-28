process.stdin.setEncoding('utf8');
process.stdin.on('data', function(input){
    var arr = input.split('\n');
    var n = parseInt(arr.shift());
    var intervals = [];
    for(var i=0; i<n; i++){
        var s_e = arr[i].split(' ');
        var start = parseInt(s_e[0]);
        var end = parseInt(s_e[1]);
        intervals.push({start: start, end: end});
    }
    intervals.sort(function(a, b){return a.start - b.start});
    var count = 1;
    var end = intervals[0].end;
    for(var i=1; i<intervals.length; i++){
        if(intervals[i].start >= end){
            count++;
            end = intervals[i].end;
        }
    }
    console.log(n - count);
});
This JavaScript code reads the number of intervals `N` and then reads the start and end times for each interval. It then sorts the intervals by start time. It then iterates through the sorted intervals and checks if the start time of the next interval is greater than or equal to the end time of the current interval. If it is, it increments the count and updates the end time of the interval. Finally, it prints the count of removed intervals, which is the total number of intervals minus the count of intervals that can be merged.