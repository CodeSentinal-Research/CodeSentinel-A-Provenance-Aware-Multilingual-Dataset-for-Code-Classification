Here is the JavaScript code:

function countPS(s)
{
    let dp = new Array(s.length+1);
    for(let i=0; i<=s.length; i++)
        dp[i] = new Array(s.length+1).fill(0);

    for(let i=1; i<=s.length; i++)
    {
        dp[i][i] = 1;
        for(let j=i-1; j<i; j++)
        {
            if(s[i-1] === s[j])
            {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + 1;
            }
            else
            {
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
           
            }
        }
    }

    let res = 0;
    for(let i=1; i<=s.length; i++)
        res = (res + dp[s.length][i]) % 1000000007;

    return res;
}

This code uses Dynamic Programming to solve the problem. The idea is to create a 2D table where dp[i][j] stores the number of palindromic subsequences in the string s[i:j]. For each character in the string, it checks if it is the same as the character before it. If it is, it considers the 2 cases: (1) it can be a part of the palindromic subsequence that is to the left of the current character, and (2) it can be a part of the palindromic subsequence that is to the right of the current character. 

Finally, the code sums up all dp[s.length][i] where i ranges from 1 to s.length and returns the sum modulo 1000000007.

You can call this function by providing a string as a parameter.