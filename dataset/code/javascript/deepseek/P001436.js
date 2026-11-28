Here is the JavaScript code for the problem:

function maxNumberOfBalloons(s) {
    let count = new Map();
    for(let char of s) {
        count.set(char, (count.get(char) || 0) + 1);
    }
    return Math.min(...count.get('b'), Math.floor(count.get('a')/2), Math.floor(count.get('l')/2), Math.floor(count.get('o')/2), Math.floor(count.get('n')));
}

console.log(maxNumberOfBalloons(readline())); // replace readline() with the function for reading the input from stdin
In this code, we first count the frequency of each character in the string. Then we take the minimum number of times that the string can be divided into balloons (because each balloon contains 2 of each type of letter).