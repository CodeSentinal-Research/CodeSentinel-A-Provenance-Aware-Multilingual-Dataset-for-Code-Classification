Here is the JavaScript code for Longest Palindromic Subsequence:

function longestPalindromicSubsequence(s) {
    const dp = Array(s.length).fill(null).map(() => Array(s.length).fill(0));

    for(let i = 0; i < s.length; i++){
        dp[i][i] = 1;
    }

    let maxLength = 1;
    for(let i = 0; i < s.length - 1; i++){
        if(s[i] === s[i+1]){
            dp[i][i+1] = 2;
            maxLength = 2;
        }
    }

    for(let gap = 3; gap <= s.length; gap++){
        for(let i = 0; i < s.length - gap + 1; i++){
            let j = i + gap - 1;
            if(s[i] === s[j] && dp[i+1][j-1] === gap - 1){
                dp[i][j] = gap;
                maxLength = Math.max(maxLength, gap);
            }
        }
    }

    return maxLength;
}

console.log(longestPalindromicSubsequence(readline()));

This JavaScript code uses the dynamic programming approach to solve the problem. The dp array is initialized to store the lengths of the longest palindromic subsequences for all possible substrings. The base cases are handled separately for the length of 1 and 2 and then for larger gaps. For each gap, it checks if the characters at the current index and the next index are equal and if the length of the previous substring is one less than the current gap. If so, it updates the dp array and the maxLength. Finally, it returns the maxLength.

Please note that you need to run this in a Node.js environment or you can run it in the browser console in a webpage.