def search_books(book_records, author_name, genre):
    matching_books = [book for book in book_records if book['author'] == author_name and book['genre'] == genre]
    return matching_books

def main():
    book_records = [{'author': 'Author1', 'genre': 'Genre1', 'title': 'Title1'}, {'author': 'Author1', 'genre': 'Genre1', 'title': 'Title2'}]
    author_name = 'Author1'
    genre = 'Genre1'

    matching_books = search_books(book_records, author_name, genre)

    print('Matching books:')
    for book in matching_books:
        print(book['title'])

if __name__ == "__main__":
    main()

In this solution, we are first defining a function `search_books` that takes in a list of book records, an author name, and a genre. It then filters the book records to only include the books written by the specified author and of the specified genre.

The main function is then defined, and it initializes the book records, the author name and the genre. It calls the `search_books` function with these parameters and stores the returned matching books in a variable. It then prints out the titles of the matching books.

The `main` function is the entry point of the program, and it is always executed when the script is run directly.