n = int(input())
books = []
for _ in range(n):
    books.append(input().split())
year = int(input())
for b in books:
    if int(b[-1]) > year:
        print(" ".join(b))
