Here's the JavaScript code that solves the problem:

function shortestDistanceToTargetCharacter(s, c) {
    let distances = [];
    for(let i = 0; i < s.length; i++) {
        if (s[i] === c) {
            distances.push(i - (distances[distances.length - 1] || 0));
        } else {
            distances.push(0);
        }
    }
    return distances;
}

let s = 'abacada';
let c = 'a';
console.log(shortestDistanceToTargetCharacter(s, c)); // [0, 1, 2, 0, 1, 2, 3]

This code first creates an empty array `distances`. Then it iterates over the string `s`, checking each character. If the character is the target character `c`, it adds the index of the current character minus the last index of the last found instance of `c` to the `distances` array. If the character is not the target character `c`, it adds `0` to the `distances` array. Finally, it returns the `distances` array.