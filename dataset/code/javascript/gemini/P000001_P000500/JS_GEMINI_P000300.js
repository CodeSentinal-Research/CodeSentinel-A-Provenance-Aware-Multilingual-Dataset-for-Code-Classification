const fs = require('fs');

const MAPPING = {
    '2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl',
    '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'
};

function backtrack(digits, index, path, res) {
    if (index === digits.length) {
        res.push(path.join(''));
        return;
    }
    const letters = MAPPING[digits[index]] || '';
    for (let i = 0; i < letters.length; i++) {
        path.push(letters[i]);
        backtrack(digits, index + 1, path, res);
        path.pop();
    }
}

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1 && input[0] !== '') {
        const digits = input[0];
        const res = [];
        if (digits.length > 0) {
            backtrack(digits, 0, [], res);
        }
        res.forEach(s => console.log(s));
    }
}

main();