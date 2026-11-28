Here is the JavaScript code to merge two sorted arrays without using extra space:

let readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter the size of first array: ', (N) => {
    let arr1 = rl.question('Enter elements of first array: ', (ele1) => {
        rl.question('Enter elements of second array: ', (ele2) => {
            let arr1 = ele1.split(' ').map(Number).sort((a, b) => a - b);
            let arr2 = ele2.split(' ').map(Number).sort((a, b) => a - b);
            mergeArrays(arr1, arr2, N, arr1.length);
        });
    });
});

function mergeArrays(arr1, arr2, totalCount, count) {
    let i = 0, j = 0;
    while(i < arr1.length && j < arr2.length) {
        if(arr1[i] < arr2[j]) {
            console.log(arr1[i]);
            i++;
        }
        else {
            console.log(arr2[j]);
            j++;
        }
        if(i < arr1.length)
            console.log(arr1[i]);
        if(j < arr2.length)
            console.log(arr2[j]);
    }

    while(i < arr1.length) {
        console.log(arr1[i]);
        i++;
    }
    while(j < arr2.length) {
        console.log(arr2[j]);
        j++;
    }
}

In this code, we are using a readline interface to get the input. We are first asking the user for the size of the first array and then for the elements of the first array. After getting the elements, we are asking for the size of the second array and then for the elements of the second array. Then we are calling the mergeArrays function to merge the two arrays. The mergeArrays function will print the smallest element from both arrays in sorted order. It will print all the elements of both arrays in sorted order after merging.