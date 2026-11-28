import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        books = []
        idx = 1
        for _ in range(n):
            books.append((tokens[idx], tokens[idx+1], tokens[idx+2]))
            idx += 3
        target_author = tokens[idx]
        target_genre = tokens[idx+1]
        for title, author, genre in books:
            if author == target_author and genre == target_genre:
                print(title)
if __name__ == '__main__':
    main()