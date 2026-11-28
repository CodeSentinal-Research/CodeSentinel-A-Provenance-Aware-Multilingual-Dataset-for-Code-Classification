const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let inputs = [];

rl.on('line', (line) => {
    inputs.push(line);
    if (inputs.length === 3) {
        const array1 = inputs[0].split(' ').map(Number);
        const array2 = inputs[1].split(' ').map(Number);
        const sortedArray = relativeSort(array1, array2);
        console.log(sortedArray.join(' '));
        process.exit();
    }
});

function relativeSort(array1, array2) {
    array2.sort((a, b) => array1.indexOf(a) - array2.indexOf(b));
    const notInArray2 = array1.filter(x => !array2.includes(x));
    notInArray2.sort((a, b) => a - b);
    return array2.concat(notInArray2);
}