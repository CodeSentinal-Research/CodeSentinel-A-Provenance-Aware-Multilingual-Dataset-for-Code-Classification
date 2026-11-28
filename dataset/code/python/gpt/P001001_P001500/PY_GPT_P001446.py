# problem title : Sentence Similarity
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def areSentencesSimilar(self, sentence1: List[str], sentence2: List[str], similarPairs: List[List[str]]) -> bool:
        if len(sentence1) != len(sentence2):
            return False
        sim = set()
        for p in similarPairs:
            sim.add((p[0], p[1]))
            sim.add((p[1], p[0]))

        for w1, w2 in zip(sentence1, sentence2):
            if w1 != w2 and (w1, w2) not in sim:
                return False
        return True
