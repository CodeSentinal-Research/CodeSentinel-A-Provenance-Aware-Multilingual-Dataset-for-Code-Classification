Here is the JavaScript code to solve the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let sequence;

rl.question('Enter number of elements in sequence: ', function(n) {
    rl.question('Enter sequence (space separated): ', function(sequenceInput) {
        sequence = sequenceInput.split(' ').map(Number);

        rl.question('Enter duplicate insertion rule (1 or 2): ', function(rule) {
            if (rule === '1') {
                console.log(findTrees(sequence, 0, sequence.length - 1));
            } else if (rule === '2') {
                console.log(findTreesWithDuplicates(sequence, 0, sequence.length - 1));
            } else {
                console.log('Invalid rule');
            }
        });
    });
});

function findTrees(sequence, start, end) {
    if (start > end) {
        return 1;
    }

    let trees = 0;

    for (let i = start; i <= end; i++) {
        trees += findTrees(sequence, start, i - 1) * findTrees(sequence, i + 1, end);
    }

    return trees;
}

function findTreesWithDuplicates(sequence, start, end) {
    if (start > end) {
        return 1;
    }

    let trees = 0;

    for (let i = start; i <= end; i++) {
        if (sequence[i] === sequence[start]) {
            trees += findTreesWithDuplicates(sequence, start, i - 1) * findTreesWithDuplicates(sequence, i + 1, end);
        }
    }

    return trees;
}
This code first reads the number of elements in the sequence and the sequence itself. Then it reads the duplicate insertion rule, and if it is 1, it calculates the number of distinct binary search trees using non-repeated numbers. If it is 2, it calculates the number of distinct binary search trees using repeated numbers.