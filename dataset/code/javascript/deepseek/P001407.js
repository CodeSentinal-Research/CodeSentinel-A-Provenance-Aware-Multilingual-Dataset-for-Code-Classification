// Input the number of elements
let num = parseInt(readline());
let arr = readline().split(' ').map(Number).sort((a, b) => a - b);

if (num % 2 === 1) {
    console.log(-1);
} else {
    let half = num / 2;
    if (arr.slice(0, half).join(' ') === arr.slice(half).reverse().join(' ')) {
        console.log(arr.slice(0, half).join(' '));
    } else {
        console.log(-1);
    }
}