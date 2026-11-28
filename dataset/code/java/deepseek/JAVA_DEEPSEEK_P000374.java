import java.io.*;
import java.util.*;

public class Main {
    static class Book {
        String title;
        String author;
        String isbn;

        Book(String title, String author, String isbn) {
            this.title = title;
            this.author = author;
            this.isbn = isbn;
        }

        @Override
        public String toString() {
            return "Title: " + title + ", Author: " + author + ", ISBN: " + isbn;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        HashMap<String, Book> books = new HashMap<>();

        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(",");
            books.put(input[2], new Book(input[0], input[1], input[2]));
        }

        String isbn = br.readLine();
        Book book = books.get(isbn);
        if (book == null) {
            System.out.println("Book Not Found");
        } else {
            System.out.println(book);
        }
    }
}
