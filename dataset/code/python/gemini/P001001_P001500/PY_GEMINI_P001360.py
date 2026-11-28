from typing import List
from collections import Counter

class Solution:
    def maxScoreWords(self, words: List[str], letters: List[str], score: List[int]) -> int:
        letter_count = Counter(letters)

        def get_word_score(w: str):
            w_count = Counter(w)
            w_score = sum(score[ord(c) - 97] for c in w)
            return w_count, w_score

        word_data = [get_word_score(w) for w in words]

        def backtrack(idx: int, cur_count: Counter) -> int:
            if idx == len(words):
                return 0
            # Option 1: skip word
            max_s = backtrack(idx + 1, cur_count)

            # Option 2: include word
            w_cnt, w_sc = word_data[idx]
            if all(cur_count[c] >= cnt for c, cnt in w_cnt.items()):
                for c, cnt in w_cnt.items():
                    cur_count[c] -= cnt
                max_s = max(max_s, w_sc + backtrack(idx + 1, cur_count))
                for c, cnt in w_cnt.items():
                    cur_count[c] += cnt

            return max_s

        return backtrack(0, letter_count)