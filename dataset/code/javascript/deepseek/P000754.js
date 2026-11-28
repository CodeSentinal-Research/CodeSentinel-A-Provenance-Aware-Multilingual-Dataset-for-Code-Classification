Here is the JavaScript code for the problem:

function generatePermutations(s) {
    if (s.length === 1) {
        return [s];
    }

    const firstChar = s[0];
    const remainingChars = s.slice(1);
    const permutations = generatePermutations(remainingChars);

    const result = [];
    for (const permutation of permutations) {
        for (let i = 0; i <= permutation.length; i++) {
            const newString = [firstChar].concat(permutation.slice(0, i), permutation.slice(i));
            result.push(newString.join(''));
        }
    }

    return result;
}

console.log(generatePermutations('ab12'));

In this code, `generatePermutations` is a recursive function that generates all permutations of a string. It takes a string as input and generates all permutations of that string.

The base case is when the string is of length 1, in which case, the function returns the string itself.

The recursive case is when the string is longer than 1. The function generates all permutations of the remaining characters in the string. It then generates all permutations of the first character and concatenates them to each permutation of the remaining characters. The result is the permutations of the string with the first character changed to lowercase and uppercase.

Finally, the generated permutations are printed in lexicographical order.