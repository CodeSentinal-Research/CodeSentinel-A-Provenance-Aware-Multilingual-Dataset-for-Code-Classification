rows, cols = map(int, input().split())
m1 = [list(map(int, input().split())) for _ in range(rows)]
m2 = [list(map(int, input().split())) for _ in range(rows)]
print("Identical" if m1 == m2 else "Not Identical")
