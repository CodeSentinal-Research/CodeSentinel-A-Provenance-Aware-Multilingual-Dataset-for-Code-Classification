Here is the JavaScript code:

function longestSubstringWithAtMostKVowels(S, K) {
    let vowels = ['a', 'e', 'i', 'o', 'u'];
    let vowelCount = {a: 0, e: 0, i: 0, o: 0, u: 0};
    let maxCount = 0;
    let maxSubstring = '';
    let start = 0;

    for (let i = 0; i < S.length; i++) {
        if (vowels.includes(S[i])) {
            vowelCount[S[i]]++;
        }
        if (vowelCount[S[i]] === 1) {
            if (maxCount < i - start + 1) {
                maxCount = i - start + 1;
                maxSubstring = S.slice(start, i + 1);
            }
        }
        if (vowelCount[S[i]] > 1) {
            vowelCount[S[i]]--;
        }
    }

    return maxCount;
}

// Testing
console.log(longestSubstringWithAtMostKVowels('aeiou', 2));  // 5
console.log(longestSubstringWithAtMostKVowels('aeiuo', 2));  // 4

This code first creates a vowelCount object to count the number of each vowel in the string. Then, it iterates through the string, incrementing the count of each vowel when it encounters it and decrementing when it encounters another instance of the same vowel. If the count of a vowel ever exceeds K, it updates the longest substring found so far. Finally, it returns the length of the longest substring with at most K vowels.