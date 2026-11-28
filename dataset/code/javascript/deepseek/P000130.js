process.stdin.resume();
process.stdin.on('data', function(data) {
    var N = parseInt(data);
    var arr = [];
    for(var i=0; i<N; i++) {
        arr.push(parseInt(process.stdin.read()));
    }
    console.log(findNextSmallerElement(arr));
});

function findNextSmallerElement(arr) {
    var res = [];
    for(var i=0; i<arr.length; i++) {
        var count = -1;
        for(var j=0; j<arr.length; j++) {
            if(arr[j] < arr[i]) {
                count = arr[j];
                break;
            }
        }
        res.push(count);
    }
    return res;
}
In this solution, we read the number of elements N and the elements of the array from the standard input. The `findNextSmallerElement` function is then used to find the next smaller element for every element in the array. The function `findNextSmallerElement` uses two nested loops to iterate over the array and find the next smaller element for each element. If no smaller element is found, the `count` variable is set to -1 and the function returns the `res` array.