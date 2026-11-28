from typing import List
from collections import Counter

class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if not s or not words:
            return []

        word_len = len(words[0])
        num_words = len(words)
        total_len = word_len * num_words
        word_count = Counter(words)
        res = []

        for i in range(word_len):
            left = i
            cur_count = Counter()
            count = 0

            for j in range(i, len(s) - word_len + 1, word_len):
                w = s[j:j + word_len]
                if w in word_count:
                    cur_count[w] += 1
                    count += 1

                    while cur_count[w] > word_count[w]:
                        left_w = s[left:left + word_len]
                        cur_count[left_w] -= 1
                        count -= 1
                        left += word_len

                    if count == num_words:
                        res.append(left)
                else:
                    cur_count.clear()
                    count = 0
                    left = j + word_len

        return res