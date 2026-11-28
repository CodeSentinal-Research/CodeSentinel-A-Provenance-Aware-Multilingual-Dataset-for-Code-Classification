Here is the JavaScript code for the problem:

process.stdin.resume();
process.stdin.on('data', function(data) {
    var N = parseInt(data);
    var arr = [];
    process.stdin.read();
    process.stdin.on('data', function(data) {
        arr.push(parseInt(data));
        if (arr.length === N) {
            console.log(findPeak(arr));
            process.stdin.pause();
        }
    });
});

function findPeak(arr) {
    var max = -Infinity;
    var maxIndex = -1;
    for(var i = 0; i < arr.length; i++) {
        if (arr[i] > max) {
            max = arr[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}

In this code, we first read the number N from stdin. Then we read N integers from stdin, push them into an array. When we have N integers, we call the `findPeak` function, which finds the index of the peak in the array. The peak is the maximum element in the array.