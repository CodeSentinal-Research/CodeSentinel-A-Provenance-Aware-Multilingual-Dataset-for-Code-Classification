Here is the JavaScript code that solves the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let arr1 = [];
let arr2 = [];

rl.question('Enter the number of elements for the first array: ', (num) => {
    rl.question('Enter the elements of the first array: ', (elements) => {
        arr1 = elements.split(' ').map(Number);
        rl.question('Enter the number of elements for the second array: ', (num) => {
            rl.question('Enter the elements of the second array: ', (elements) => {
                arr2 = elements.split(' ').map(Number);
                if (arr1.length !== arr2.length) {
                    console.log('NO');
                    rl.close();
                    return;
                }
                const map1 = new Map();
                const map2 = new Map();
                for (let i of arr1) {
                    map1.set(i, (map1.get(i) || 0) + 1);
                }
                for (let i of arr2) {
                    map2.set(i, (map2.get(i) || 0) + 1);
                }
                if (map1.size !== map2.size) {
                    console.log('NO');
                    rl.close();
                    return;
                }
                for (let [key, value] of map1) {
                    if (map2.get(key) !== value) {
                        console.log('NO');
                        rl.close();
                        return;
                    }
                }
                console.log('YES');
                rl.close();
                return;
            });
        });
    });
});

This code reads the number of elements for the first and second array, and the elements themselves. It then checks if the arrays are equal by comparing the frequency of each element. If all elements and their frequencies are equal, it prints 'YES'; otherwise, it prints 'NO'.