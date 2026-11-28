const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let cases = +rl.readline();

rl.once('line', (cases) => {
    let arr = rl.readline().split(' ').map(Number);
    let x = arr.pop();
    let operations = 0;
    let sum = 0;
    arr.forEach(num => {
        sum += num;
    });

    while(sum !== x) {
        if(sum < x) {
            arr.unshift(arr.pop());
            sum++;
        } else if(sum > x) {
            arr.push(arr.shift());
            sum--;
        } else {
            break;
        }
        operations++;
    }

    if(sum === x) {
        console.log(operations);
    } else {
        console.log(-1);
    }

    cases--;
    if(cases > 0) {
        rl.once('line', () => {
            let arr = rl.readline().split(' ').map(Number);
            let x = arr.pop();
            let operations = 0;
            let sum = 0;
            arr.forEach(num => {
                sum += num;
            });

            while(sum !== x) {
                if(sum < x) {
                    arr.unshift(arr.pop());
                    sum++;
                } else if(sum > x) {
                    arr.push(arr.shift());
                    sum--;
                } else {
                    break;
                }
                operations++;
            }

            if(sum === x) {
                console.log(operations);
            } else {
                console.log(-1);
            }
            cases--;
        });
    }

    rl.close();
});