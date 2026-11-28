n = int(input())
movies = []
for _ in range(n):
    movies.append(input().split())
genre = input().strip()
for m in movies:
    if m[-1] == genre:
        print(" ".join(m))
