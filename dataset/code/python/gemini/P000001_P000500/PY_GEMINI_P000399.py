import sys

def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        books = []
        idx = 1
        for _ in range(n):
            title = tokens[idx]
            year = int(tokens[idx+1])
            books.append((title, year))
            idx += 2
        min_year = int(tokens[idx])
        for title, year in books:
            if year > min_year:
                print(title)

if __name__ == '__main__':
    main()