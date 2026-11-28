
n=int(input())
words=[input().strip() for _ in range(n)]
s=input().strip()
print(sum(1 for w in words if s.startswith(w)))
