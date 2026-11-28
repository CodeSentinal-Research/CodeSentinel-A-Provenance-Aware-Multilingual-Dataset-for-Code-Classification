Here is the JavaScript code for the problem:

function maxScore(s) {
    let score = 0, maxScore = 0;
    for(let i = 0; i < s.length; i++) {
        if(s[i] === '1') {
            score++;
        } else {
            maxScore = Math.max(maxScore, score);
            score = 0;
        }
    }
    maxScore = Math.max(maxScore, score);
    return maxScore;
}

This function iterates through the binary string, counting the number of 1's. When a 0 is found, it compares the current score to the maxScore and updates maxScore if the current score is higher. If a 1 is found, it resets the score back to 0. After going through all the characters, it returns the maxScore as it is the maximum score after splitting the binary string into two non-empty parts.