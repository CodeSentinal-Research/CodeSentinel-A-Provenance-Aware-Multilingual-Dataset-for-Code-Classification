Here is the JavaScript code to solve the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let arr1 = [], arr2 = [], arr3 = [];

rl.question('Enter size of first array: ', (size1) => {
    rl.setPrompt('Enter elements of first array: ');
    rl.question(`Enter ${size1} elements: `, (input1) => {
        arr1 = input1.split(' ').map(Number);
        arr1.sort((a, b) => a - b);

        rl.question('Enter size of second array: ', (size2) => {
            rl.setPrompt('Enter elements of second array: ');
            rl.question(`Enter ${size2} elements: `, (input2) => {
                arr2 = input2.split(' ').map(Number);
                arr2.sort((a, b) => a - b);

                rl.question('Enter size of third array: ', (size3) => {
                    rl.setPrompt('Enter elements of third array: ');
                    rl.question(`Enter ${size3} elements: `, (input3) => {
                        arr3 = input3.split(' ').map(Number);
                        arr3.sort((a, b) => a - b);

                        console.log('Common Elements are:', findCommonElements(arr1, arr2, arr3));

                        rl.close();
                    });
                });
            });
        });
    });
});

function findCommonElements(a, b, c) {
    let i = 0, j = 0, k = 0;
    let result = [];

    while (i < a.length && j < b.length && k < c.length) {
        if (a[i] === b[j] && b[j] === c[k]) {
            result.push(a[i]);
            i++; j++; k++;
        } else if (a[i] < b[j]) i++;
        else if (b[j] < c[k]) j++;
        else k++;
    }

    return result;
}

This program first reads the sizes of the three arrays and then the elements of each array. It then sorts the arrays and finds the common elements using a helper function `findCommonElements`. The common elements are then printed out in sorted order.

Please note that you'll need to run this code in an environment that supports `readline` module, such as Node.js.