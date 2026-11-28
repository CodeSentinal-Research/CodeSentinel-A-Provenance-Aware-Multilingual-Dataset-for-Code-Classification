Here is the JavaScript code to solve the problem:

function firstUniqChar(s) {
    for (let i = 0; i < s.length; i++) {
        let count = 0;
        for (let j = 0; j < s.length; j++) {
            if (s[i] === s[j]) {
                count++;
            }
        }
        if (count === 1) {
            return i;
        }
    }
    return -1;
}
This code works by iterating through the string. For each character, it then iterates through the entire string to count the number of times it appears. If it only appears once, it returns the index of the character. If no such character is found, it returns -1.