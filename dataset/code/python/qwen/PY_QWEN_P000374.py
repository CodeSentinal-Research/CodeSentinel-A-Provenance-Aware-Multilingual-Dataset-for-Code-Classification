n = int(input())
books = {}
for _ in range(n):
    parts = input().split()
    books[parts[0]] = " ".join(parts[1:])
isbn = input().strip()
print(books.get(isbn, "Book Not Found"))
