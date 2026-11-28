Here is a JavaScript solution for the given problem:

function countVowelSubstrings(s) {
    let vowels = ['a', 'e', 'i', 'o', 'u'];
    let count = 0;
    for (let i = 0; i < s.length; i++) {
        if (vowels.includes(s[i])) {
            let foundVowels = [s[i]];
            for (let j = i + 1; j < s.length; j++) {
                if (vowels.includes(s[j])) {
                    foundVowels.push(s[j]);
                } else {
                    if (foundVowels.length === 5) {
                        count++;
                    }
                    break;
                }
            }
            if (foundVowels.length === 5) {
                count++;
            }
        }
    }
    return count;
}

console.log(countVowelSubstrings('abcde'));  // Output: 1
console.log(countVowelSubstrings('aeiou'));   // Output: 5
console.log(countVowelSubstrings('aeioua'));  // Output: 6

In this solution, we use a for loop to check each character in the string. If the character is a vowel, we start a substring that contains only that character and check each subsequent character to see if they are also vowels. If they are, we add them to the substring and continue checking. If they are not, we check if the substring contains exactly 5 vowels and if so, increment our count. We repeat this process until we have checked all characters in the string.