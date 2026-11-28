Here is the JavaScript code to solve the given problem:

function findAnagrams(s, p) {
    if (s.length < p.length) {
        return [];
    }

    let matches = [];
    let pCount = new Array(26).fill(0);
    let sCount = new Array(26).fill(0);

    for (let i = 0; i < p.length; i++) {
        pCount[p.charAt(i) - 'a']++;
    }

    for (let i = 0; i < s.length; i++) {
        sCount[s.charAt(i) - 'a']++;
        if (i >= p.length) {
            sCount[s.charAt(i - p.length) - 'a']--;
        }
        if (pCount.join('') === sCount.join('')) {
            matches.push(i - p.length + 1);
        }
    }

    return matches;
}

console.log(findAnagrams(readline(), readline()));

This code creates two character arrays (`pCount` and `sCount`) that represent the counts of each character in the pattern and the string respectively. It then iterates through each character in the string, incrementing the count in the `sCount` array and decrementing the count in the `pCount` array if the window size (i.e., the length of the pattern) has moved over. If the two character arrays are equal, it means that the window represented by the current characters in `s` forms a valid anagram of `p`, and the index of this window is added to the `matches` array.

Please note that you need to input the strings as command line arguments in your Node.js environment. Here is a mock implementation of `readline` function:

const readline = () => {
    return process.argv[2];
    process.argv.splice(0, 3); // remove command and args from process.argv
};

This function reads the first command line argument as the input string for the string `s` and the second command line argument as the input string for the string `p`. It uses the `process.argv` array to read the command line arguments.