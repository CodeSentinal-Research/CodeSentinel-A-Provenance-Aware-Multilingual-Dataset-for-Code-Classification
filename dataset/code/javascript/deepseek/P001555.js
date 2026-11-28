Here is a simple JavaScript code to solve the problem. This code reads the input string and length of substring K from the standard input. It then finds the maximum number of vowels in any substring of length K.

process.stdin.setEncoding('utf-8');

process.stdin.on('data', function(input) {
    var [S, K] = input.trim().split(' ');
    S = S.split('');
    var vowels = ['a', 'e', 'i', 'o', 'u'];
    var vowel_count = 0;
    var curr_vowel_count = 0;

    for(var i = 0; i < S.length; i++) {
        if (vowels.includes(S[i].toLowerCase())) {
            curr_vowel_count++;
        }
        if(i >= K-1) {
            vowel_count = Math.max(vowel_count, curr_vowel_count);
            if(S[i-K+1] && vowels.includes(S[i-K+1].toLowerCase())) {
                curr_vowel_count--;
            }
        }
    }
    console.log(vowel_count);
    process.exit();
});
This code works by iterating over the characters in the string, and for each character, checking if it is a vowel. If it is, it increments the count of vowels. It also checks if the current substring is larger than the previous longest, and if so, it updates the count of vowels. If the current character is not a vowel, it only updates the count if the previous character was a vowel.