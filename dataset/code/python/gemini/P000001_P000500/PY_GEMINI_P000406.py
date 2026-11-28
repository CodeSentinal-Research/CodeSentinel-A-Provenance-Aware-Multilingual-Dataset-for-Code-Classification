import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        movies = []
        idx = 1
        for _ in range(n):
            movies.append((tokens[idx], tokens[idx+1]))
            idx += 2
        genre = tokens[idx]
        for m, g in movies:
            if g == genre:
                print(m)
if __name__ == '__main__':
    main()