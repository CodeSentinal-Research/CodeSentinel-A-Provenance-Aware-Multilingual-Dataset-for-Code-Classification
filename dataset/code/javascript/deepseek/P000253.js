Here is the JavaScript code:

function countVowels(str) {
    var vowels = ['a', 'e', 'i', 'o', 'u'];
    var count = 0;
    for(var i = 0; i < str.length; i++) {
        if(vowels.includes(str[i].toLowerCase())) {
            count++;
        }
    }
    return count;
}

console.log(countVowels("Hello World"));

In this code, we define a function `countVowels` that takes a string `str` as input. We first define an array `vowels` that contains all the vowels. Then we initialize a counter `count` to 0. We then iterate over each character in the string, and if the character is a vowel (i.e., it's included in `vowels`), we increment `count`. Finally, we return `count`.

The `console.log(countVowels("Hello World"));` at the end of the code is for testing the function with a string "Hello World", and it will print the number of vowels in that string.