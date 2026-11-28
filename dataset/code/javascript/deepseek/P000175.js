Here's the JavaScript code for the given problem:

let readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter the number of elements: ', (n) => {
    rl.question('Enter the elements: ', (inputs) => {
        let arr = inputs.split(' ').map(Number);

        arr.sort((a, b) => a - b);

        let wave = [arr[0]];
        for (let i = 1; i < arr.length; i += 2) {
            wave.push(arr[i]);
            if (i + 1 < arr.length)
                wave.push(arr[i + 1]);
        }

        console.log(wave.join(' '));

        rl.close();
    });
});
This program first reads the number of elements, then reads the elements themselves. After sorting the input array, it creates a new array that represents the wave form. This is done by alternating between adding the first element and the next even element in the sorted array to the wave array. Finally, it logs the wave array to the console.