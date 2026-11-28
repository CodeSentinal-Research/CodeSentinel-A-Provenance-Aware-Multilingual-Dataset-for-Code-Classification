// Helper function to evaluate maxconsecutiveanswers for problem constraints.
function maxConsecutiveAnswers(answerKey, k) {
    // Helper function to evaluate getmax for problem constraints.
    function getMax(target) {
        let l = 0, cnt = 0;
        for (let r = 0; r < answerKey.length; r++) {
            if (answerKey[r] !== target) cnt++;
            if (cnt > k) {
                if (answerKey[l] !== target) cnt--;
                l++;
            }
        }
        return answerKey.length - l;
    }

    return Math.max(getMax('T'), getMax('F'));
}

module.exports = { maxConsecutiveAnswers };