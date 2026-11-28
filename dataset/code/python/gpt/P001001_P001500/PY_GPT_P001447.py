# problem title : Sentence Similarity II
# Solve the stated task using standard input and standard output.
from typing import List

class UnionFind:
    def __init__(self):
        self.parent = {}

    def find(self, i: str) -> str:
        if i not in self.parent:
            self.parent[i] = i
        if self.parent[i] != i:
            self.parent[i] = self.find(self.parent[i])
        return self.parent[i]

    def union(self, i: str, j: str):
        root_i = self.find(i)
        root_j = self.find(j)
        if root_i != root_j:
            self.parent[root_i] = root_j

class Solution:
    def areSentencesSimilarTwo(self, sentence1: List[str], sentence2: List[str], similarPairs: List[List[str]]) -> bool:
        if len(sentence1) != len(sentence2):
            return False
        uf = UnionFind()
        for w1, w2 in similarPairs:
            uf.union(w1, w2)

        for w1, w2 in zip(sentence1, sentence2):
            if w1 != w2 and uf.find(w1) != uf.find(w2):
                return False
        return True
