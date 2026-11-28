Here is a JavaScript solution for your problem:

const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
});

let arr1 = [];
let arr2 = [];

readline.question('Enter the size of array1: ', size => {
    for(let i = 0; i < size; i++) {
        readline.question(`Enter element ${i + 1}: `, val => {
            arr1.push(parseInt(val));
        });
    });

readline.question('Enter the size of array2: ', size => {
    for(let i = 0; i < size; i++) {
        readline.question(`Enter element ${i + 1}: `, val => {
            arr2.push(parseInt(val));
        });
    });

readline.close();

const findMedian = () => {
    let mergedArray = arr1.concat(arr2).sort((a, b) => a - b);

    if(mergedArray.length % 2 === 0) {
        return (mergedArray[mergedArray.length / 2 - 1] + mergedArray[mergedArray.length / 2]) / 2;
    }

    return mergedArray[Math.floor(mergedArray.length / 2)];
};

console.log(`Median is: ${findMedian()}`);

This program reads the sizes of two sorted arrays and their elements from the standard input, then calculates the median of the two arrays. The median is calculated by concatenating the two arrays and sorting the merged array in ascending order. If the merged array's length is even, then the median is the average of the two middle numbers. Otherwise, it is the middle number.