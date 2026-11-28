Here is a JavaScript solution that rearranges positive and negative numbers in alternating order.

process.stdin.resume();
process.stdin.on('data', function(chunk) {
    var input = chunk.toString().trim().split('\n');
    var arr = input[1].split(' ').map(Number);
    rearrangeNumbers(arr);
});

function rearrangeNumbers(arr) {
    var positive = arr.filter(num => num > 0).sort((a, b) => a - b);
    var negative = arr.filter(num => num < 0).sort((a, b) => a - b);
    var result = [...negative, ...positive];
    console.log(result.join(' '));
}

In this code, we first read the array from standard input. Then, we filter the positive and negative numbers separately and sort them. After that, we concatenate the sorted positive and negative numbers to get the final result.