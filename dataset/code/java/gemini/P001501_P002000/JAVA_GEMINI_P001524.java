public class Solution {
    private int getMax(String answerKey, int k, char target) {
        int l = 0, cnt = 0;
        for (int r = 0; r < answerKey.length(); r++) {
            if (answerKey.charAt(r) != target) cnt++;
            if (cnt > k) {
                if (answerKey.charAt(l) != target) cnt--;
                l++;
            }
        }
        return answerKey.length() - l;
    }

    public int maxConsecutiveAnswers(String answerKey, int k) {
        return Math.max(getMax(answerKey, k, 'T'), getMax(answerKey, k, 'F'));
    }
}