Here is a simple Python solution using a dictionary to store book records. The main function `search_book` takes an ISBN as an input and returns the book details if found. If the book is not found, it returns a message "Book Not Found".

def search_book(isbn_dict, isbn):
    if isbn in isbn_dict:
        return isbn_dict[isbn]
    else:
        return "Book Not Found"

isbn_dict = {
    '978-0-470-31214-5': {'title': 'The Great Gatsby', 'author': 'F. Scott Fitzgerald'},
    '978-0-306-40912-2': {'title': 'Moby Dick', 'author': 'Herman Melville'},
    '978-0-670-88348-6': {'title': 'War and Peace', 'author': 'Leo Tolstoy'}
}

isbn = '978-0-670-88348-6'
result = search_book(isbn_dict, isbn)
print(result)

isbn = '978-0-470-31214-6'
result = search_book(isbn_dict, isbn)
print(result)

In this code, `isbn_dict` is a dictionary where each key is an ISBN and the value is another dictionary containing the book details. The `search_book` function uses the ISBN to find the book in the dictionary, and returns the book details if found. If the ISBN is not found, it returns "Book Not Found".