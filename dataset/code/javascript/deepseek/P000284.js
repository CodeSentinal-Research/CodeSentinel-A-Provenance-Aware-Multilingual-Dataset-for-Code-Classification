Sure, here is a simple JavaScript solution using the concept of Dynamic Programming.

function editDistance(s1, s2) {
    var dp = [];
    var len1 = s1.length;
    var len2 = s2.length;
    for(var i=0; i<=len1; i++){
        dp[i] = [i];
    }
    for(var j=0; j<=len2; j++){
        dp[0][j] = j;
    }
    for(var i=1; i<=len1; i++){
        for(var j=1; j<=len2; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = Math.min(dp[i-1][j-1] + 1, //replace
                                   Math.min(dp[i][j-1] + 1, //insert
                                           dp[i-1][j] + 1)); //delete
            }
        }
    }
    return dp[len1][len2];
}

You can use the above function in the following way:

var s1 = "kitten";
var s2 = "sitting";
console.log(editDistance(s1, s2)); // Prints: 3
This function creates a 2D array (dp), where dp[i][j] is the minimum edit distance between the first i characters of s1 and the first j characters of s2. The edit distance is calculated by comparing the characters and taking the minimum number of operations to transform one string into the other.