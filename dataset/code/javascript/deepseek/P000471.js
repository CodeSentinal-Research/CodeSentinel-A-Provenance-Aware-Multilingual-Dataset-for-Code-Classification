const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter the number of elements: ', (N) => {
    rl.question('Enter the elements: ', (elements) => {
        const numArray = elements.split(' ').map(Number);

        const counts = [];
        let count = 0;
        for(let i=0; i<numArray.length; i++){
            for(let j=i+1; j<numArray.length; j++){
                if(numArray[i] > numArray[j]) count++;
            }
            counts.push(count);
            count = 0;
        }

        console.log(counts.join(' '));

        rl.close();
    });
});