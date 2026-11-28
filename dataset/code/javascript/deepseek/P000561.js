Here's a solution for the problem:

function firstNonRepeatingCharacter(stream) {
    let frequency = {};
    let index = {};

    for (let i = 0; i < stream.length; i++) {
        let char = stream[i];

        if (frequency[char] === undefined) {
            frequency[char] = 0;
            index[char] = i;
        }

        frequency[char]++;
    }

    for (let i = 0; i < stream.length; i++) {
        let char = stream[i];

        if (frequency[char] === 1 && index[char] === i) {
            return char;
        }
    }

    return '#';
}

In this code, we first create two objects `frequency` and `index`. The `frequency` object will keep track of the frequency of each character in the stream and the `index` object will keep track of the last index where each character appears.

We then loop over the stream, incrementing the frequency and index of each character. After we've processed all characters, we again loop over the stream, and for each character, we check if its frequency is 1 and its last index is equal to the current index. If it is, that means we found the first non-repeating character, so we return it. If no such character is found after processing all characters, we return '

This solution has a time complexity of O(n) because it needs to process each character exactly once. The space complexity is also O(n) because in the worst case, we might have to store each character in the frequency and index objects.