function searchBooks(books, author, genre) {
    return books.filter(book => book.author === author && book.genre.includes(genre));
}

// Testing the function with some data
const books = [
    { author: 'J.K. Rowling', title: 'Harry Potter and the Philosopher\'s Stone', genre: ['Fantasy', 'Book series'] },
    { author: 'Stephen King', title: 'The Shining', genre: ['Science fiction', 'Thriller'] },
    { author: 'George R. R. Martin', title: 'A Game of Thrones', genre: ['Fantasy', 'Drama'] },
    { author: 'J.R.R. Tolkien', title: 'The Hobbit', genre: ['Fantasy', 'Adventure'] }
];

console.log(searchBooks(books, 'J.K. Rowling', 'Fantasy')); // Outputs: [ { author: 'J.K. Rowling', title: 'Harry Potter and the Philosopher\'s Stone', genre: [ 'Fantasy', 'Book series' ] } ]
console.log(searchBooks(books, 'Stephen King', 'Science fiction')); // Outputs: [ { author: 'Stephen King', title: 'The Shining', genre: [ 'Science fiction', 'Thriller' ] } ]
console.log(searchBooks(books, 'J.R.R. Tolkien', 'Adventure')); // Outputs: [ { author: 'J.R.R. Tolkien', title: 'The Hobbit', genre: [ 'Fantasy', 'Adventure' ] } ]