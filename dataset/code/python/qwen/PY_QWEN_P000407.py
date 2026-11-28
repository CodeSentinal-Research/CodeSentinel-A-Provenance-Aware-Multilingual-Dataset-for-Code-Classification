n = int(input())
songs = []
for _ in range(n):
    songs.append(input().split())
artist = input().strip()
for s in songs:
    if s[-1] == artist:
        print(" ".join(s))
