import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        songs = []
        idx = 1
        for _ in range(n):
            songs.append((tokens[idx], tokens[idx+1]))
            idx += 2
        artist = tokens[idx]
        for s, a in songs:
            if a == artist:
                print(s)
if __name__ == '__main__':
    main()