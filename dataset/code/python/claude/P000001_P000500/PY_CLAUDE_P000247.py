
r, c = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(r)]
B = [list(map(int, input().split())) for _ in range(r)]
print('Identical' if A==B else 'Not Identical')
