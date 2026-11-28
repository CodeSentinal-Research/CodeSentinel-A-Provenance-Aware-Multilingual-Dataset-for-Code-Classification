Here is a simple JavaScript solution using a Set to store vowels and a sliding window approach to find valid substrings:

function countVowelSubstrings(str) {
    let vowels = new Set(['a', 'e', 'i', 'o', 'u']);
    let count = 0;

    for (let i = 0; i < str.length; i++) {
        let vowelSet = new Set();
        for (let j = i; j < str.length; j++) {
            if (vowels.has(str[j])) {
                vowelSet.add(str[j]);
            }
            if (vowelSet.size === vowels.size) {
                count++;
            }
        }
    }

    return count;
}

This function works by iterating over each character in the input string, and for each character, it creates a set (vowelSet) of vowels. It then checks each character in the string from the current character to the end of the string. If a vowel is found in this subset, it adds it to the vowelSet. If the size of vowelSet (i.e., the number of vowels in it) is equal to the number of vowels (i.e., the length of the vowelSet), it increments the count. At the end of the function, it returns the count.

You can use this function by calling it with a string as input:

console.log(countVowelSubstrings('aeiouaeeioueioua'));

This will print out the number of valid substrings that consist only of vowels and each vowel is at least once.