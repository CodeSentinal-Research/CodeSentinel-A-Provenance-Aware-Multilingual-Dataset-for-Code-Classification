# problem title : Reconstruct Itinerary
# Solve the stated task using standard input and standard output.
from typing import List
from collections import defaultdict

class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        adj = defaultdict(list)
        for src, dst in sorted(tickets, reverse=True):
            adj[src].append(dst)

        itinerary = []
        def dfs(curr: str):
            while adj[curr]:
                dfs(adj[curr].pop())
            itinerary.append(curr)

        dfs("JFK")
        return itinerary[::-1]
