Here is the JavaScript code for the problem:

function countPrefixes(words, s) {
    let count = 0;

    for (let word of words) {
        if (s.startsWith(word)) {
            count++;
        }
    }

    return count;
}

This code defines a function called `countPrefixes` that takes two parameters: an array of words and a string `s`. It initializes a count variable to 0.

It then iterates over each word in the list of words. If the current word in the list starts with the given string `s`, it increments the count.

Finally, it returns the count.