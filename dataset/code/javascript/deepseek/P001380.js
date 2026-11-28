Here is the JavaScript code to solve the problem:

function frequencySort(s) {
    let count = new Map();
    for(let i = 0; i < s.length; i++) {
        count.set(s[i], (count.get(s[i]) || 0) + 1);
    }

    let sortable = [];
    for(let [char, freq] of count.entries()) {
        sortable.push([char, freq]);
    }

    sortable.sort((a, b) => {
        if(a[1] > b[1]) return -1;
        if(a[1] < b[1]) return 1;
        return a[0] < b[0] ? -1 : 1;
    });

    let result = '';
    for(let i = 0; i < sortable.length; i++) {
        for(let j = 0; j < sortable[i][1]; j++) {
            result += sortable[i][0];
        }
    }

    return result;
}

console.log(frequencySort('tree'));

This code works by first creating a frequency map of characters in the input string, then creating an array of arrays, where each inner array contains a character and its frequency. The array is then sorted in descending order of frequency, and in lexicographic order if frequencies are equal. Finally, it builds the sorted string by concatenating the characters in the sorted array.