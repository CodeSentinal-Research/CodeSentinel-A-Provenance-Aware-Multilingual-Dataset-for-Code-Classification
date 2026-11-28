Here is a simple JavaScript code snippet that solves the problem:

let input = require('fs').readFileSync('stdin', 'utf8');
let N = parseInt(input.trim());
let strings = [];

for(let i=0; i<N; i++) {
    strings[i] = input.trim();
}

let count = 0;

for(let i=0; i<N; i++) {
    for(let j=i+1; j<N; j++) {
        if(strings[i].length == strings[j].length) {
            if(checkSimilarity(strings[i], strings[j])) {
                count++;
            }
        }
    }
}

console.log(count);

function checkSimilarity(s1, s2) {
    let set1 = new Set(s1.split(''));
    let set2 = new Set(s2.split(''));
    return JSON.stringify(set1) == JSON.stringify(set2);
}
This code reads the number of strings from the standard input, reads the strings, and then counts the pairs of similar strings. The `checkSimilarity` function checks if two strings are similar. It does this by converting the strings into sets, which only allow unique elements. If the sets are equal, then the strings are similar.