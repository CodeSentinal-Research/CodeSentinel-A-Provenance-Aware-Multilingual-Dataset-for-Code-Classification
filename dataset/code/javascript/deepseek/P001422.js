Here is the JavaScript code for the problem:

process.stdin.setEncoding('utf8');
process.stdin.on('data', function(input) {
    var lines = input.split('\n');
    var N = parseInt(lines[0]);
    var words = lines.slice(1);

    var keyboard = [
        'qwertyuiopQWERTYUIOP',
        'asdfghjklASDFGHJKL',
        'zxcvbnmZXCVBNM',
        'qsdfjklQSDFJKLZ',
        'poiuytrewQSDFJKL',
        'ghjklzxcvbnmGHJK',
        'uiopasdfghJKLZ',
        'QWERTYUIOPASDFG',
        'ZXCVBNMWE',
        '1234567890'
    ].map(row => row.split(''));

    function isValidWord(word) {
        var letters = word.split('');
        return letters.every(letter => {
            var row = keyboard.find(row => row.includes(letter))
            return row.includes(letter);
        });
    }

    var validWords = words.filter(isValidWord);
    validWords.sort();

    validWords.forEach(word => {
        console.log(word);
    });
});

In this code, we first set up a keyboard array with all the rows of the QWERTY keyboard. Then, we define a function `isValidWord` that checks if a given word is valid by iterating over each letter in the word and checking if it exists in the keyboard. The `filter` method is then used to get only the words that pass the `isValidWord` test. The valid words are then sorted and printed to the console.