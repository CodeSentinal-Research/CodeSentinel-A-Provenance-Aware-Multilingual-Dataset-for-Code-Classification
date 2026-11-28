const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter the size of the array: ', (n) => {
    rl.question('Enter the elements of the array: ', (elements) => {
        let frequency = new Array(1001).fill(0);
        let firstNonRepeating = -1;

        elements = elements.split(' ').map(Number);

        for (let num of elements) {
            frequency[num]++;
        }

        for (let i = 0; i < elements.length; i++) {
            if (frequency[elements[i]] == 1) {
                firstNonRepeating = elements[i];
                break;
            }
        }

        console.log(firstNonRepeating);
        rl.close();
    });
});
This JavaScript code uses readline module for getting input from the user. It reads the size of the array and array elements from the user, then counts the frequency of each element in the array using a frequency array. It then iterates over the elements and checks the frequency of each element. The first element that has frequency of 1 (meaning it is non-repeating) is the first non-repeating element. If no such element exists, it prints -1.