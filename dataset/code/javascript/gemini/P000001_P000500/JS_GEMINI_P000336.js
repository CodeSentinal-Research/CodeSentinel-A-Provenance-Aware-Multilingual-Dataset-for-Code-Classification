const fs = require('fs');

function isPalindrome(s, i, j) {
    while (i < j) {
        if (s[i++] !== s[j--]) return false;
    }
    return true;
}

function check(a, b) {
    let i = 0, j = a.length - 1;
    while (i < j && a[i] === b[j]) {
        i++;
        j--;
    }
    return isPalindrome(a, i, j) || isPalindrome(b, i, j);
}

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 2) {
        console.log(check(input[0], input[1]) || check(input[1], input[0]) ? "Yes" : "No");
    }
}

main();