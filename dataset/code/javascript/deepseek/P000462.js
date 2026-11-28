let readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter the number of elements: ', (N) => {
    rl.question('Enter the elements of AP (space separated): ', (AP) => {
        const array = AP.split(' ').map(Number);
        const GAP = array[1] - array[0];
        for(let i = 0; i < N; i++) {
            if(array[i+1] - array[i] !== GAP) {
                console.log('Missing element: ', array[i] + GAP);
                return;
            }
        }
        console.log('Missing element: ', array[N-1] + GAP);
    });
});