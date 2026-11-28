const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
});

let N;
readline.question('', N);

for(let i = 0; i < N; i++) {
    let arr = readline.readline().split(' ').map(Number);
    if(isSymmetric(arr)) {
        console.log("Symmetric");
    } else {
        console.log("Not Symmetric");
    }
}

function isSymmetric(arr) {
    for(let i = 0; i < arr.length / 2; i++) {
        if(arr[i] !== arr[arr.length - i - 1]) {
            return false;
        }
    }
    return true;
}