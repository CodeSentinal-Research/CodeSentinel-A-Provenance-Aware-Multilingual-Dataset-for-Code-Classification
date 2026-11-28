# problem title : Count Prefixes of a Given String
# A word counts when it is a prefix of S.
n=int(input()); words=[input() for _ in range(n)]; s=input();print(sum(s.startswith(w) for w in words))
