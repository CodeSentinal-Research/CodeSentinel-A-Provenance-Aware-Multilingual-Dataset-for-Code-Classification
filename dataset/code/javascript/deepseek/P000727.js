function wordBreak(s, wordDict) {
    const dp = [[]];
    for (let i = 0; i <= s.length; ++i) {
        dp[i] = [];
        for (let j = 0; j < i; ++j) {
            if (dp[j] && wordDict.includes(s.slice(j, i))) {
                dp[i].push(dp[j].map(str => s.slice(j, i) + ' ' + str));
            }
        }
    }
    return dp[s.length].map(arr => arr.join(''));
}

This function uses a dynamic programming approach. We create a 2D array `dp` to store the sentences that can be formed by inserting a space between every word in the string `s`. We traverse the string from left to right and for each position, we check all the previous words in the dictionary and if the previous word can form the sentence till that point, we add the sentence formed till that point to the dp array. The final result is the sentences formed by inserting a space between every word in the dictionary.