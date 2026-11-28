from typing import List
from collections import defaultdict

class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        parent = {}
        email_to_name = {}

        def find(s):
            if parent[s] == s: return s
            parent[s] = find(parent[s])
            return parent[s]

        for acc in accounts:
            name = acc[0]
            first_email = acc[1]
            for email in acc[1:]:
                if email not in parent:
                    parent[email] = email
                email_to_name[email] = name
                root1 = find(first_email)
                root2 = find(email)
                if root1 != root2:
                    parent[root1] = root2

        unions = defaultdict(list)
        for email in parent:
            unions[find(email)].append(email)

        return [[email_to_name[root]] + sorted(emails) for root, emails in unions.items()]