process.stdin.setEncoding('utf8');
process.stdin.on('data', function(data){
  var input = data.split('\n');
  var N = parseInt(input[0]);
  var TotalTrips = parseInt(input[1]);
  var tripTimes = input[2].split(' ').map(Number);

  function minTime(times, totalTrips) {
    times.sort((a, b) => a - b);

    var min = 0;
    var max = totalTrips * Math.max(...times);

    while (min < max) {
      var mid = Math.floor((min + max) / 2);

      if (isValid(times, totalTrips, mid)) min = mid + 1;
      else max = mid;
    }

    return min;
  }

  function isValid(times, totalTrips, target) {
    var count = 0;

    for (var i = 0; i < times.length; i++) {
      count += Math.floor(target / times[i]);
    }

    return count >= totalTrips;
  }

  console.log(minTime(tripTimes, TotalTrips));
});

This JavaScript code implements a binary search algorithm to find the minimum time needed to complete all trips. The binary search is done using the `minTime` function, which sorts the trip times array and then uses a while loop to incrementally narrow down the possible minimum time.

The `isValid` function checks if it is possible to complete all trips with a given time using the given array of trip times and totalTrips. It increments a count for each trip time and checks if the count is greater than or equal to the totalTrips. If it is, it means we can complete all trips in the given time and returns true. Otherwise, it returns false.