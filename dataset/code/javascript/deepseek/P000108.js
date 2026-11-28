let readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter the number of elements: ', (num) => {
    var arr = rl.question('Enter elements: ', (input) => {
        var arr = input.split(' ').map(Number);
        console.log(isSortedDescending(arr));
        rl.close();
    });
});

function isSortedDescending(arr) {
    for (let i = 0; i < arr.length - 1; i++) {
        if (arr[i] < arr[i + 1]) {
            return "Not Sorted";
        }
    }
    return "Sorted";
}