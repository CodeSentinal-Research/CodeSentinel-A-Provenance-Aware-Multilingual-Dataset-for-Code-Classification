Here is the JavaScript code for the given problem:

function solve(str) {
    let set = new Set();
    let maxLen = 0;
    let prevEnd = 0;

    for (let i = 0; i < str.length; i++) {
        if (set.has(str[i])) {
            prevEnd = Math.max(prevEnd, set.get(str[i]));
        }
        set.add(str[i]);
        maxLen = Math.max(maxLen, i - prevEnd + 1);
    }

    return maxLen;
}

let input = process.argv[2] || "abcdabc";
console.log(solve(input));

In this code, we use a Set to store the unique characters in the string. For each character, we update the previous end index if the character is repeated in the string. We calculate the length of the unique substrings as the maximum of the current index and the previous end index plus 1. We update the maximum length whenever a new unique character is found. Finally, we print the maximum length as the output.