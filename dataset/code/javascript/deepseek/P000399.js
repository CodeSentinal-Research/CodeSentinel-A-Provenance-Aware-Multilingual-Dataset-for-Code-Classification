function searchBooksAfterYear(records, year) {
    // filter out books published after the specified year
    let booksAfterYear = records.filter(book => book.publicationYear > year);

    // return the books after filtering
    return booksAfterYear;
}
This function will take an array of book records and a year as inputs. It will return all books that were published after the given year.