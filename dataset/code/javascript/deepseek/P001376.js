Here is the JavaScript code that solves the problem:

let readline = require('readline');

let rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter the number of strings: ', function(N) {
    let strings = [];
    rl.setPrompt('Enter a string: ');
    rl.prompt();

    rl.on('line', function(line) {
        strings.push(line);
        if (strings.length === Number(N)) {
            groupAnagrams(strings);
            rl.close();
        }
    });
});

function groupAnagrams(strings) {
    let map = {};
    strings.forEach(function(str) {
        let sortedStr = str.split('').sort().join('');
        if (!map[sortedStr]) map[sortedStr] = [];
        map[sortedStr].push(str);
    });

    for (let key in map) {
        let sortedKey = key.split('').sort().join('');
        let group = map[key];
        group.sort();
        console.log(sortedKey + ': ' + group.join(' '));
    }
}

In this code, we use `readline` module to get the user input. After getting the user input, we loop through each line of input and add it to the `strings` array. When the length of `strings` array is equal to the input number, we call the `groupAnagrams` function. This function sorts the strings in the array and groups them by their sorted string.