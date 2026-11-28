Here is the JavaScript code to solve the problem:

process.stdin.on('data', function(data) {
    var n = parseInt(data);
    var arr = [];
    for (var i = 0; i < n; i++) {
        arr.push(parseInt(process.stdin.readline()));
    }
    arr.sort(function(a, b) { return a - b; });
    var result = [];
    while(arr.length) {
        result.push(arr.shift());
        if(arr.length) {
            result.push(arr.pop());
        }
    }
    console.log(result.join(' '));
});

This code reads the number of elements `n` from the standard input, then reads the `n` elements and sorts them in ascending order. It then rearranges the sorted array in max-min alternating order by pushing the max element from the start of the array and the min element from the end of the array, and then repeating this process until the array becomes empty. The rearranged array is then printed to the standard output.