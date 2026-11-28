Here is the JavaScript solution:

function reverseVowels(s) {
    let vowels = 'aeiouAEIOU';
    let sArr = Array.from(s);
    let i = 0, j = s.length - 1;

    while (i < j) {
        if (vowels.includes(sArr[i]) && vowels.includes(sArr[j])) {
            let temp = sArr[i];
            sArr[i] = sArr[j];
            sArr[j] = temp;
            i++;
            j--;
        } else if (!vowels.includes(sArr[i])) {
            i++;
        } else {
            j--;
        }
    }

    return sArr.join('');
}

This function works by using two pointers, one at the start of the string and the other at the end. It keeps swapping characters from both ends, if the characters at both ends are vowels, until they meet.

You can use it like this:

console.log(reverseVowels("Hello World")); // "Holle Wrld"