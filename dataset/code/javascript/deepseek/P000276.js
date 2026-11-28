Here's the JavaScript code for the Count and Say Sequence problem:

function countAndSay(n) {
    if(n === 0) return '';
    let str = '1';
    for(let i = 1; i < n; i++) {
        str = next(str);
    }
    return str;
}

function next(str) {
    let result = '';
    let count = 1;
    for(let i = 0; i < str.length; i++) {
        if(str[i] !== str[i + 1] && str[i] !== undefined) {
            result += count + str[i];
            count = 1;
        } else if(str[i] === str[i + 1]) {
            count++;
        } else if(str[i] === undefined) {
            result += count + str[i];
            count = 1;
        }
    }
    return result;
}

The `countAndSay` function generates the first `n` terms of the Count-and-Say sequence, and the `next` function generates the next term in the sequence.

Test this function with different inputs like:

console.log(countAndSay(1)); // "1"
console.log(countAndSay(2)); // "11"
console.log(countAndSay(3)); // "21"
console.log(countAndSay(4)); // "1211"
console.log(countAndSay(5)); // "111221"