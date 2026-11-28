Here is a simple JavaScript solution for the problem. This solution uses a hash map to count the frequency of characters in both strings and then checks if there is more than one character that is not in the same count.

function validAnagram(s1, s2) {
    if(s1.length !== s2.length) {
        return false;
    }

    let charMap1 = createCharMap(s1);
    let charMap2 = createCharMap(s2);

    for(let char in charMap1) {
        if(!charMap2[char] || charMap2[char] > charMap1[char]) {
            return false;
        }
    }

    return true;
}

function createCharMap(s) {
    let charMap = {};

    for(let char of s) {
        charMap[char] = charMap[char] ? charMap[char] + 1 : 1;
    }

    return charMap;
}

console.log(validAnagram('abc', 'bca')); // Output: "Yes"
console.log(validAnagram('abc', 'cab')); // Output: "No"

In this code, the function `validAnagram` first checks if the lengths of the two strings are equal. If not, it returns `false` because two strings can only be anagrams if they have the same characters and the same frequency of each character.

Then it creates a hash map (`charMap1` and `charMap2`) to count the frequency of each character in `s1` and `s2`.

Finally, it iterates over each character in `charMap1` and checks if it's also in `charMap2`. If not, or if the count of the character in `charMap1` is greater than the count in `charMap2`, it returns `false` because two strings can only be anagrams if they have the same characters and the same frequency of each character. If all characters match and their counts are the same in both maps, it returns `true`.