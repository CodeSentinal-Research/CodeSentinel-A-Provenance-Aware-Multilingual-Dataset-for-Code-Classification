Here is a Python solution for the given problem using a simple list to store the books:

def search_books(books, year):
    results = list(filter(lambda book: book[1] > year, books.items()))

    for book in results:
        print(book[0])

def main():
    books = {
        'Book1': 2000,
        'Book2': 1990,
        'Book3': 2010,
        'Book4': 1980,
        'Book5': 2020
    }

    year = int(input("Enter the year: "))

    search_books(books, year)

if __name__ == "__main__":
    main()

In this code, we first define a `search_books` function that takes a dictionary of books and a year, and filters out the books that were published after the given year. Then we print the titles of the matching books. In the `main` function, we prompt the user for a year, and call `search_books` with the books and the year.