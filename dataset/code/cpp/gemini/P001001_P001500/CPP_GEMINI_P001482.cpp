#include <vector>
#include <algorithm>

class Solution {
public:
    int bagOfTokensScore(std::vector<int>& tokens, int power) {
        std::sort(tokens.begin(), tokens.end());
        int l = 0, r = (int)tokens.size() - 1;
        int score = 0, maxScore = 0;

        // Binary search loop to narrow down range
        while (l <= r) {
            if (power >= tokens[l]) {
                power -= tokens[l++];
                score++;
                maxScore = std::max(maxScore, score);
            } else if (score > 0) {
                power += tokens[r--];
                score--;
            } else {
                break;
            }
        }
        return maxScore;
    }
};