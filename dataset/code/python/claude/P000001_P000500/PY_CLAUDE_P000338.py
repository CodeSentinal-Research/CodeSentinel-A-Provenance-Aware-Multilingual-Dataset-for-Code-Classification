
n=int(input())
a=''.join(input() for _ in range(n))
m=int(input())
b=''.join(input() for _ in range(m))
print('Yes' if a==b else 'No')
