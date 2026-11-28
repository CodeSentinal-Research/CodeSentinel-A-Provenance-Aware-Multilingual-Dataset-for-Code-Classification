Here is a JavaScript solution that takes two interval lists as input and outputs all intersecting intervals:

let readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter the number of intervals in the first list: ', (N) => {
    rl.setPrompt('Enter the start and end times for each interval: ');
    let firstList = [];
    for (let i = 0; i < N; i++) {
        rl.prompt();
        firstList.push(rl.line().split(' ').map(Number));
    }

    rl.question('Enter the number of intervals in the second list: ', (M) => {
        rl.setPrompt('Enter the start and end times for each interval: ');
        let secondList = [];
        for (let i = 0; i < M; i++) {
            secondList.push(rl.line().split(' ').map(Number));
        }

        let intersections = findIntersections(firstList, secondList);
        console.log(intersections);
        rl.close();
    });
});

function findIntersections(list1, list2) {
    let i = 0, j = 0;
    let result = [];
    while (i < list1.length && j < list2.length) {
        if (list1[i][1] >= list2[j][0] && list1[i][0] <= list2[j][1]) {
            result.push([Math.max(list1[i][0], list2[j][0]), Math.min(list1[i][1], list2[j][1])]);
        }
        if (list1[i][1] > list2[j][1]) {
            j++;
        } else {
            i++;
        }
    }
    return result;
}

This script reads the number of intervals in the first and second lists from the standard input, then reads the interval lists themselves. It uses a helper function `findIntersections` to find all intersecting intervals between the two input lists. The result is then printed to the standard output.