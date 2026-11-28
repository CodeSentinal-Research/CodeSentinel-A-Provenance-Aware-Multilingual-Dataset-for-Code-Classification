# problem title : Alien Dictionary
# Solve the stated task using standard input and standard output.
from typing import List
from collections import defaultdict, deque

class Solution:
    def alienOrder(self, words: List[str]) -> str:
        adj = defaultdict(set)
        in_deg = {c: 0 for w in words for c in w}

        for i in range(len(words) - 1):
            w1, w2 = words[i], words[i + 1]
            min_len = min(len(w1), len(w2))
            if len(w1) > len(w2) and w1[:min_len] == w2[:min_len]:
                return ""
            for j in range(min_len):
                if w1[j] != w2[j]:
                    if w2[j] not in adj[w1[j]]:
                        adj[w1[j]].add(w2[j])
                        in_deg[w2[j]] += 1
                    break

        q = deque([c for c in in_deg if in_deg[c] == 0])
        res = []
        while q:
            c = q.popleft()
            res.append(c)
            for nxt in adj[c]:
                in_deg[nxt] -= 1
                if in_deg[nxt] == 0:
                    q.append(nxt)

        if len(res) < len(in_deg):
            return ""
        return "".join(res)
