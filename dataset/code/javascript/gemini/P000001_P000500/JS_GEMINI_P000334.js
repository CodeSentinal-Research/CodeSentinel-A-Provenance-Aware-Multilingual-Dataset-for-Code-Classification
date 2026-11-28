const fs = require('fs');

function shortestWay(source, target) {
    let i = 0, count = 0;
    while (i < target.length) {
        const initialI = i;
        for (let j = 0; j < source.length; j++) {
            if (i < target.length && source[j] === target[i]) {
                i++;
            }
        }
        if (i === initialI) return -1;
        count++;
    }
    return count;
}

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 2) {
        console.log(shortestWay(input[0], input[1]));
    }
}

main();