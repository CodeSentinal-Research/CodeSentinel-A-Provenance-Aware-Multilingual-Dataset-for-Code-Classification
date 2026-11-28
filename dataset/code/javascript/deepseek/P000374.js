Here's a JavaScript function that fulfills the problem.

function searchBookByISBN(books, isbn) {
  for (let book of books) {
    if (book.isbn === isbn) {
      return book;
    }
  }
  return "Book Not Found";
}

This function iterates over each book in the provided collection of books. If the book's ISBN matches the input ISBN, it immediately returns the book. If no match is found after iterating through all books, it returns the string "Book Not Found".

You can use this function by passing an array of book objects and the ISBN you are searching for:

let books = [
  { title: 'Book 1', author: 'Author 1', isbn: '1234567890' },
  { title: 'Book 2', author: 'Author 2', isbn: '1112223334' },
  // More books...
];

console.log(searchBookByISBN(books, '1234567890'));  // Logs: { title: 'Book 1', author: 'Author 1', isbn: '1234567890' }
console.log(searchBookByISBN(books, '1112223334'));  // Logs: { title: 'Book 2', author: 'Author 2', isbn: '1112223334' }
console.log(searchBookByISBN(books, '4445556667'));  // Logs: 'Book Not Found'

This code assumes that the input array of books is sorted by ISBN. If it isn't, you'll need to sort the array before calling the function.