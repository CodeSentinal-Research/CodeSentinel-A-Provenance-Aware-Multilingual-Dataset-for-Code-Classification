Here is the JavaScript code:

process.stdin.setEncoding('utf8');
process.stdin.on('data', function(input) {
    var N = parseInt(input);
    var arr = process.stdin.read().split(' ').map(Number);

    arr.sort((a, b) => a - b);

    var positiveIndex = 0;
    var negativeIndex = arr.length - 1;

    var result = [];

    while (negativeIndex >= positiveIndex) {
        result.push(arr[negativeIndex]);
        result.push(arr[positiveIndex]);

        negativeIndex -= 2;
        positiveIndex += 2;
    }

    if (negativeIndex > positiveIndex) {
        result.push(arr[negativeIndex]);
    }

    console.log(result.join(' '));
});
This program reads the number of elements, then reads the elements, sort them, and then alternates between positive and negative numbers. The final result is printed to the console.